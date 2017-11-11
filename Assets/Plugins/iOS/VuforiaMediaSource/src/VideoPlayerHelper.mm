/*===============================================================================
Copyright (c) 2015 PTC Inc. All Rights Reserved.

Copyright (c) 2012-2015 Qualcomm Connected Experiences, Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other
countries.
==============================================================================*/

// test coment 20170704

#import "VideoPlayerHelper.h"
#import <AudioToolbox/AudioToolbox.h>
#import <AudioToolbox/AudioServices.h>
#import <AVFoundation/AVPlayer.h>
#import <AVFoundation/AVPlayerItem.h>
#import <AVFoundation/AVAsset.h>

# define ONE_FRAME_DURATION 0.03

#include <dlfcn.h>


#ifdef DEBUG
#define DEBUGLOG(x) NSLog(x)
#else
#define DEBUGLOG(x)
#endif


// Constants
static const int TIMESCALE = 1000;  // 1 millisecond granularity for time

static const float PLAYER_CURSOR_POSITION_MEDIA_START = 0.0f;
static const float PLAYER_CURSOR_REQUEST_COMPLETE = -1.0f;

static const float PLAYER_VOLUME_DEFAULT = 1.0f;

// The number of bytes per texel (when using kCVPixelFormatType_32BGRA)
static const int BYTES_PER_TEXEL = 4;

// Key-value observation contexts
static void* AVPlayerItemStatusObservationContext = &AVPlayerItemStatusObservationContext;

// String constants
static NSString* const kStatusKey = @"status";
static NSString* const kTracksKey = @"tracks";


//@interface VideoPlayerHelper (PrivateMethods)
@interface VideoPlayerHelper ()
- (void)resetData;
- (BOOL)loadLocalMediaFromURL:(NSURL*)url;
- (BOOL)prepareAssetForPlayback;
- (BOOL)prepareAssetForReading:(CMTime)startTime;
- (void)prepareAVPlayer;
- (void)createFrameTimer;
- (void)getNextVideoFrame;
- (void)updatePlayerCursorPosition:(float)position;
- (void)frameTimerFired:(NSTimer*)timer;
- (BOOL)setVolumeLevel:(float)volume;
- (GLuint)createVideoTextureGL;
- (id<MTLTexture>)createVideoTextureMetal;
- (void)doSeekAndPlayAudio;
- (void)waitForFrameTimerThreadToEnd;
//- (void)moviePlayerLoadStateChanged:(NSNotification*)notification;
- (void)moviePlayerPlaybackDidFinish:(NSNotification*)notification;
//- (void)moviePlayerDidExitFullscreen:(NSNotification*)notification;
//- (void)moviePlayerExitAtPosition:(NSTimeInterval)position;

- (void)displayLinkCallback:(CADisplayLink *)sender;
@property CADisplayLink *displayLink;

@end


//------------------------------------------------------------------------------
#pragma mark - MovieViewController

@implementation MovieViewController

//------------------------------------------------------------------------------
#pragma mark - Lifecycle

- (id)init
{
    self = [super init];
    
//    if (nil != self) {
//        _moviePlayer = [[MPMoviePlayerController alloc] init];
//    }
    
    return self;
}


- (void)dealloc
{
//    [_moviePlayer release];
    
    [super dealloc];
}


- (void)loadView
{
//    [self setView:_moviePlayer.view];
}


//------------------------------------------------------------------------------
#pragma mark - Autorotation
- (NSUInteger)supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskAll;
}

-(BOOL)shouldAutorotate
{
    return YES;
}

@end




extern "C" typedef id<MTLDevice> (*MTLCreateSystemDefaultDeviceFunc)();

@implementation VideoPlayerHelper

////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Lifecycle
- (id)initWithMetalRendering:(BOOL)isMetalRendering
{
    NSLog(@"indivestigate:isMetalRendering");

    
    //    //この1セットでXcodeでデバック可能となる。
//    CVPixelBufferRef pixelBuffer;
//    NSLog(@"あああああ");
//    NSLog(@"%@",pixelBuffer); //これをやるとXcodeにこのファイルが表示される！！！！
    
    NSLog(@"MASA --initWithMetalRendering--");

    self = [super init];

    if (nil != self) {
//        rootViewController = viewController; // okamura 4/23 add
//        [rootViewController retain];

        useMetal = isMetalRendering;
        if (useMetal) {
            NSLog(@"VuforiaMedia: using METAL graphics");
            metalBundle = [NSBundle bundleWithPath:@"/System/Library/Frameworks/Metal.framework"];
            if (metalBundle != nil) {
                if (YES == [metalBundle load]) {
                    NSLog(@"VuforiaMedia: successfully loaded Metal framework");
                    metalDevice = ((MTLCreateSystemDefaultDeviceFunc)::dlsym(dlopen(0, RTLD_LOCAL | RTLD_LAZY), "MTLCreateSystemDefaultDevice"))();
                }
            }
            else {
                NSLog(@"VuforiaMedia ERROR: failed to create Metal framework bundle");
            }
        }
        else {
            NSLog(@"Using OpenGL ES graphics");
        }


        // Set up app's audio session
        // **********************************************************************
        // *** MUST DO THIS TO BE ABLE TO GET THE VIDEO SAMPLES WITHOUT ERROR ***
        // **********************************************************************

        AVAudioSession *session = [AVAudioSession sharedInstance];
        
        // スリープモードでも再生
        // オーディオのミックス動作のオーバーライド
        NSError *setCategoryError = nil;
                [session setCategory:AVAudioSessionCategoryPlayback
                         withOptions:AVAudioSessionCategoryOptionMixWithOthers
                               error:&setCategoryError];
        
        [session setActive:YES error:nil];
        

        
        
//        NSError *error = [[NSError alloc] init];
//        BOOL activated = [[AVAudioSession sharedInstance] setActive:YES error:&error];
        //AudioSessionInitialize(NULL, NULL, NULL, NULL);

//        UInt32 sessionCategory = kAudioSessionCategory_MediaPlayback;
//        OSStatus status = AudioSessionSetProperty(kAudioSessionProperty_AudioCategory, sizeof(sessionCategory), &sessionCategory);
//        UInt32 setProperty = 1;
//        status = AudioSessionSetProperty(kAudioSessionProperty_OverrideCategoryMixWithOthers, sizeof(setProperty), &setProperty);

        
        
        // Initialise data
        [self resetData];
        
        // Video sample buffer lock
        latestSampleBufferLock = [[NSLock alloc] init];
        latestSampleBuffer = NULL;
        currentSampleBuffer = NULL;

        // Class data lock
        dataLock = [[NSLock alloc] init];
    }

    return self;
}


- (void)deinit
{
    NSLog(@"indivestigate:deinit");

    // Stop playback
    (void)[self stop];
    [self resetData];
    [latestSampleBufferLock release];
    [dataLock release];
}


- (void)dealloc
{
    NSLog(@"indivestigate:dealloc");

    [super dealloc];
}


////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Class API
// Load a movie
// - (BOOL)load:(NSString*)filename mediaType:(MEDIA_TYPE)requestedType playImmediately:(BOOL)playOnTextureImmediately fromPosition:(float)seekPosition
// {
//     BOOL ret = NO;
//
//     videoType = requestedType;
//
//     // Load only if there is no media currently loaded
//     if (NOT_READY != mediaState && ERROR != mediaState) {
//         NSLog(@"Media already loaded.  Unload current media first.");
//     }
//     else {
//         // ----- Info: additional player threads not running at this point -----
//
//         // Determine the type of file that has been requested (simply checking
//         // for the presence of a "://" in filename for remote files)
//         if (NSNotFound == [filename rangeOfString:@"://"].location  && (ON_TEXTURE == requestedType || ON_TEXTURE_FULLSCREEN == requestedType)) {
//             // For on texture rendering, we need a local file
//             localFile = YES;
//             NSString* fullPath = nil;
//
//             // If filename is an absolute path (starts with a '/'), use it as is
//             if (0 == [filename rangeOfString:@"/"].location) {
//                 fullPath = [NSString stringWithString:filename];
//             }
//             else {
//                 // filename is a relative path, play media from this app's
//                 // resources folder
//                 fullPath = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:filename];
//             }
//
//             mediaURL = [[NSURL alloc] initFileURLWithPath:fullPath];
//
//             if (YES == playOnTextureImmediately) {
//                 playImmediately = playOnTextureImmediately;
//             }
//
//             if (0.0f <= seekPosition) {
//                 // If a valid position has been requested, update the player
//                 // cursor, which will allow playback to begin from the
//                 // correct position
//                 [self updatePlayerCursorPosition:seekPosition];
//             }
//
//             ret = [self loadLocalMediaFromURL:mediaURL];
//         }
//         else {
//             // FULLSCREEN only
//             localFile = NO;
//
//             mediaURL = [[NSURL alloc] initWithString:filename];
//
//             // The media is actually loaded when we initialise the
//             // MPMoviePlayerController, which happens when we start playback
//             mediaState = READY;
//
//             ret = YES;
//         }
//     }
//
//     return ret;
// }

// - (BOOL)load:(NSString*)videoURL playImmediately:(BOOL)playOnTextureImmediately fromPosition:(float)seekPosition
- (BOOL)load:(NSString*)filename mediaType:(MEDIA_TYPE)requestedType playImmediately:(BOOL)playOnTextureImmediately fromPosition:(float)seekPosition
{
    cntNoRender = 0;
    
    NSLog(@"indivestigate:load");
    
	BOOL ret = NO;

    NSLog(@"MASA --VideoPlayerHelper load--");

	// Load only if there is no media currently loaded
	if (NOT_READY != mediaState && ERROR != mediaState) {
		NSLog(@"Media already loaded.  Unload current media first.");
	}
	else {
        
        NSString* fullPath = nil;
        fullPath = [NSString stringWithString:filename];
        //NSURL *urltest = [NSURL URLWithString:fullPath];
//        NSURL *urltest = [NSURL URLWithString:[fullPath stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet alphanumericCharacterSet]]];
        
        
        //url = [fullPath stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet alphanumericCharacterSet]];
        
        
//        mediaURL = [NSURL URLWithString:[fullPath stringByRemovingPercentEncoding]];
        
        
//        mediaURL = [NSURL URLWithString:[fullPath stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet alphanumericCharacterSet]]]; //これで一応セットできた！！！
    
        mediaURL = [NSURL URLWithString:fullPath];
        //mediaURL = [NSURL URLWithString:@"http://zine.hiliberate.biz/movie/hls/master.m3u8"];
        
        
        
        //mediaURL = [[NSURL alloc] initFileURLWithPath:fullPath];

        //mediaURL = [[NSURL alloc] initWithString:filename];
        

        
		if (playOnTextureImmediately) {
			playImmediately = playOnTextureImmediately;
		}

		if (0.0f <= seekPosition) {
			// If a valid position has been requested, update the player
			// cursor, which will allow playback to begin from the
			// correct position
			[self updatePlayerCursorPosition:seekPosition];
		}

		ret = [self loadMediaURL:mediaURL];
	}

	if (!ret) {
		// Some error occurred
		mediaState = ERROR;
	}

	return ret;
}


// 20170429 buk
//- (BOOL)loadMediaURL:(NSURL*)url
//{
//	BOOL ret = NO;
//    asset = [[[AVURLAsset alloc] initWithURL:url options:nil] retain];
//    
//	if (nil != asset) {
//		// We can now attempt to load the media, so report success.  We will
//		// discover if the load actually completes successfully when we are
//		// called back by the system
//		ret = YES;
//
//		[asset loadValuesAsynchronouslyForKeys:@[kTracksKey] completionHandler: ^{
//			// Completion handler block (dispatched on main queue when loading
//			// completes)
//			dispatch_async(dispatch_get_main_queue(),^{
//				NSError* error = nil;
//				AVKeyValueStatus status = [asset statusOfValueForKey:kTracksKey error:&error];
//
//				NSDictionary* settings = @{(id) kCVPixelBufferPixelFormatTypeKey : @(kCVPixelFormatType_32BGRA)};
//                AVPlayerItemVideoOutput *output = [[[AVPlayerItemVideoOutput alloc] initWithPixelBufferAttributes:settings] autorelease];
//                self.videoOutput = output; //ここがエラーになる。
//                
////                //oka
////                NSDictionary *pixBuffAttributes = @{(id)kCVPixelBufferPixelFormatTypeKey: @(kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange)};
////                self.videoOutput = [[AVPlayerItemVideoOutput alloc] initWithPixelBufferAttributes:pixBuffAttributes];
//                
//                //AVKeyValueStatusLoaded  0:unknown 1:loading 2:loaded 3:failed 4:cancelled
//				if (status == AVKeyValueStatusLoaded) {
//
//                    NSLog(@"MASA --loadMediaURL 1--");
//
//                    
//                    // Asset loaded, retrieve info and prepare
//					// for playback
//					if (![self prepareAssetForPlayback]) {
//
//                        NSLog(@"MASA --loadMediaURL 2--");
//
//                        mediaState = ERROR;
//					}
//				}
//				else {
//
//                    NSLog(@"MASA --loadMediaURL 3--");
//
//                    // Error
//					mediaState = ERROR;
//				}
//			});
//		}];
//	}
//
//	return ret;
//}



//- (BOOL)loadMediaURL:(NSURL*)url
//{
//    BOOL ret = NO;
//    AVURLAsset *assetUrl = [[[AVURLAsset alloc] initWithURL:url options:nil] retain];
//    
//    if (nil != assetUrl) {
//        //******** AVPlayerインスタンス作成
//        player = [[AVPlayer alloc] init];
//        //[self addTimeObserverToPlayer]; //タイムラベルを表示する為の関数
//        
//        //******** Vsyncの度に呼び出すコールバック関数を指定
//        // Setup CADisplayLink which will callback displayPixelBuffer: at every vsync.
//        self.displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(displayLinkCallback:)];
//        [[self displayLink] addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];//run loop(処理の割り込みを受け付ける)と共にdisplay linkを登録する
//        [[self displayLink] setPaused:NO];//displayLinkをポーズするかどうか
//        
//        //******** AVPlayerItemVideoOutputを作成
//        // Setup AVPlayerItemVideoOutput with the required pixelbuffer attributes.
//        // @（アットマーク）は暗黙の型変換を行なってくれる。
//        NSDictionary *pixBuffAttributes = @{(id)kCVPixelBufferPixelFormatTypeKey: @(kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange)};
//        self.videoOutput = [[AVPlayerItemVideoOutput alloc] initWithPixelBufferAttributes:pixBuffAttributes];
//        
//        //******** videoOutput のItemをclearする
//        // Remove video output from old item, if any.
//        [[player currentItem] removeOutput:self.videoOutput];
//        
//        //******** OpenGL セットアップ
//        if ([player currentItem] == nil) {
//            //        [[self playerView2] setupGL];
//        }
//        
//        //******** URLからAVPlayerItem,AVAssetを作成
//        NSURL *URL = [NSURL URLWithString:@"http://zine.hiliberate.biz/movie/lowvision.mp4"];
//        AVPlayerItem *item = [AVPlayerItem playerItemWithURL:URL];
//        //item = [AVPlayerItem playerItemWithURL:URL];
//        asset = [item asset];
//        
//        if (nil != asset) {
//            ret = YES;
//        }
//        
//        [asset loadValuesAsynchronouslyForKeys:@[@"tracks"] completionHandler:^{
//            
//            //tracksのloadが成功した場合
//            if ([asset statusOfValueForKey:@"tracks" error:nil] == AVKeyValueStatusLoaded) {
//                NSArray *tracks = [asset tracksWithMediaType:AVMediaTypeVideo]; //AVAssetのtracksのデータを配列で取得
//                if ([tracks count] > 0) {
//                    // Choose the first video track.
//                    AVAssetTrack *videoTrack = [tracks objectAtIndex:0];
//                    [videoTrack loadValuesAsynchronouslyForKeys:@[@"preferredTransform"] completionHandler:^{
//                        
//                        //preferredTransformのloadが成功した場合
//                        if ([videoTrack statusOfValueForKey:@"preferredTransform" error:nil] == AVKeyValueStatusLoaded) {
//                            
//                            //CGAffineTransformは移動、拡大、縮小などを行う事ができる。
//                            //CGAffineTransform preferredTransform = [videoTrack preferredTransform];
//                            
//                            /*
//                             The orientation of the camera while recording affects the orientation of the images received from an AVPlayerItemVideoOutput. Here we compute a rotation that is used to correctly orientate the video.
//                             */
//                            //self.playerView2.preferredRotation = -1 * atan2(preferredTransform.b, preferredTransform.a); //これ無くても再生はできた。
//                            
//                            //再生が終了した時の挙動を指定
//                            //[self addDidPlayToEndTimeNotificationForPlayerItem:item];
//                            
//                            //非同期実行(非同期でdispatch(急進)する)
//                            dispatch_async(dispatch_get_main_queue(), ^{
//                                [item addOutput:self.videoOutput];
//                                [player replaceCurrentItemWithPlayerItem:item];
//                                [self.videoOutput requestNotificationOfMediaDataChangeWithAdvanceInterval:ONE_FRAME_DURATION];
//                                [player play];
//                            });
//                            
//                        }
//                        
//                    }];
//                }
//            }
//            
//        }];
//    }
//    
//    return ret;
//   
//    
//    
////    BOOL ret = NO;
////    asset = [[[AVURLAsset alloc] initWithURL:url options:nil] retain];
////    
////    if (nil != asset) {
////        // We can now attempt to load the media, so report success.  We will
////        // discover if the load actually completes successfully when we are
////        // called back by the system
////        ret = YES;
////        
////        [asset loadValuesAsynchronouslyForKeys:@[kTracksKey] completionHandler: ^{
////            // Completion handler block (dispatched on main queue when loading
////            // completes)
////            dispatch_async(dispatch_get_main_queue(),^{
////                NSError* error = nil;
////                AVKeyValueStatus status = [asset statusOfValueForKey:kTracksKey error:&error];
////                
////                NSDictionary* settings = @{(id) kCVPixelBufferPixelFormatTypeKey : @(kCVPixelFormatType_32BGRA)};
////                AVPlayerItemVideoOutput *output = [[[AVPlayerItemVideoOutput alloc] initWithPixelBufferAttributes:settings] autorelease];
////                self.videoOutput = output; //ここがエラーになる。
////                
////                //                //oka
////                //                NSDictionary *pixBuffAttributes = @{(id)kCVPixelBufferPixelFormatTypeKey: @(kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange)};
////                //                self.videoOutput = [[AVPlayerItemVideoOutput alloc] initWithPixelBufferAttributes:pixBuffAttributes];
////                
////                //AVKeyValueStatusLoaded  0:unknown 1:loading 2:loaded 3:failed 4:cancelled
////                if (status == AVKeyValueStatusLoaded) {
////                    
////                    NSLog(@"MASA --loadMediaURL 1--");
////                    
////                    
////                    // Asset loaded, retrieve info and prepare
////                    // for playback
////                    if (![self prepareAssetForPlayback]) {
////                        
////                        NSLog(@"MASA --loadMediaURL 2--");
////                        
////                        mediaState = ERROR;
////                    }
////                }
////                else {
////                    
////                    NSLog(@"MASA --loadMediaURL 3--");
////                    
////                    // Error
////                    mediaState = ERROR;
////                }
////            });
////        }];
////    }
////    
////    return ret;
//}

- (BOOL)loadMediaURL:(NSURL*)url
{
    cntNoRender = 0;
    
    NSLog(@"indivestigate:loadMediaURL");

    
    BOOL ret = NO;
    
    NSLog(@"MASA --loadMediaURL 1--");
    
    //******** AVPlayerインスタンス作成
    player = [[AVPlayer alloc] init];
    //[self addTimeObserverToPlayer]; //タイムラベルを表示する為の関数

    NSLog(@"MASA --loadMediaURL 2--");

    //******** Vsyncの度に呼び出すコールバック関数を指定
    // Setup CADisplayLink which will callback displayPixelBuffer: at every vsync.
    self.displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(displayLinkCallback:)];
    [[self displayLink] addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];//run loop(処理の割り込みを受け付ける)と共にdisplay linkを登録する
    [[self displayLink] setPaused:YES];//displayLinkをポーズするかどうか

    NSLog(@"MASA --loadMediaURL 3--");

    //******** AVPlayerItemVideoOutputを作成
    // Setup AVPlayerItemVideoOutput with the required pixelbuffer attributes.
    // @（アットマーク）は暗黙の型変換を行なってくれる。
//    NSDictionary *pixBuffAttributes = @{(id)kCVPixelBufferPixelFormatTypeKey: @(kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange)};
    NSDictionary *pixBuffAttributes = @{(id)kCVPixelBufferPixelFormatTypeKey: @(kCVPixelFormatType_32BGRA)};
    self.videoOutput = [[AVPlayerItemVideoOutput alloc] initWithPixelBufferAttributes:pixBuffAttributes];
    
    //******** videoOutput のItemをclearする
    // Remove video output from old item, if any.
    [[player currentItem] removeOutput:self.videoOutput];

    NSLog(@"MASA --loadMediaURL 4--");

    
    //******** OpenGL セットアップ
    if ([player currentItem] == nil) {
        //        [[self playerView2] setupGL];

        
            //試しに追加してみた
//            videoTextureIdGL = [self createVideoTextureGL];
//            glBindTexture(GL_TEXTURE_2D, videoTextureIdGL);
    }

    NSLog(@"URL:%@\n\n",url);

    //******** URLからAVPlayerItem,AVAssetを作成
    //NSURL *URL = [NSURL URLWithString:@"http://zine.hiliberate.biz/movie/lowvision.mp4"];
    //AVPlayerItem *item = [AVPlayerItem playerItemWithURL:URL];
    AVPlayerItem *item = [AVPlayerItem playerItemWithURL:url];
    //item = [AVPlayerItem playerItemWithURL:URL];
    asset = [item asset];
    
    if (nil != asset) {
        ret = YES;
        //mediaState = READY;
    }

    NSLog(@"MASA --loadMediaURL 5--");
    
    [asset loadValuesAsynchronouslyForKeys:@[@"tracks"] completionHandler:^{
        //tracksのloadが成功した場合
        NSLog(@"MASA --loadMediaURL 6--");
        //mediaState = READY;

        
        if ([asset statusOfValueForKey:@"tracks" error:nil] == AVKeyValueStatusLoaded) {
            //trackのloadが成功した場合
            NSArray *tracks = [asset tracksWithMediaType:AVMediaTypeVideo]; //AVAssetのtracksのデータを配列で取得
            if ([tracks count] > 0) {
                NSLog(@"MASA --loadMediaURL 7--");

                // Choose the first video track.
                AVAssetTrack *videoTrack = [tracks objectAtIndex:0];

//                //textureの準備
//                if (NO == [self prepareAssetForPlayback]) {
//                    NSLog(@"Error - prepareAssetForPlayback");
//                    mediaState = ERROR;
//                }
                videoSize = videoTrack.naturalSize;
                
                [videoTrack loadValuesAsynchronouslyForKeys:@[@"preferredTransform"] completionHandler:^{

                    NSLog(@"MASA --loadMediaURL 8--");

                    //preferredTransformのloadが成功した場合
                    if ([videoTrack statusOfValueForKey:@"preferredTransform" error:nil] == AVKeyValueStatusLoaded) {
                        NSLog(@"MASA --loadMediaURL 9--");

//                        mediaState = READY;

                        //CGAffineTransformは移動、拡大、縮小などを行う事ができる。
                        //CGAffineTransform preferredTransform = [videoTrack preferredTransform];
                        
                        /*
                         The orientation of the camera while recording affects the orientation of the images received from an AVPlayerItemVideoOutput. Here we compute a rotation that is used to correctly orientate the video.
                         */
                        //self.playerView2.preferredRotation = -1 * atan2(preferredTransform.b, preferredTransform.a); //これ無くても再生はできた。
                        
                        //再生が終了した時の挙動を指定
                        //[self addDidPlayToEndTimeNotificationForPlayerItem:item];
                        
                        //非同期実行(非同期でdispatch(急進)する)
                        dispatch_async(dispatch_get_main_queue(), ^{
                            NSLog(@"MASA --loadMediaURL 10--");
                            [item addOutput:self.videoOutput];
                            [player replaceCurrentItemWithPlayerItem:item];
                            [self.videoOutput requestNotificationOfMediaDataChangeWithAdvanceInterval:ONE_FRAME_DURATION];
                            
//                            //**** とりあえず、即再生する。 start
//                            playImmediately = YES;
//                            mediaState = PLAYING;
//                            [self performSelectorInBackground:@selector(createFrameTimer) withObject:nil];
//                            //**** とりあえず、即再生する。 end
//
//                            NSLog(@"mediaState:%u",mediaState);
//
//                            playAudio = YES;
//                            [player play];

                            playImmediately = NO;
                            mediaState = READY;

                            NSLog(@"--loadMediaURL--mediaState-1:%u",mediaState);

                            [self performSelectorInBackground:@selector(createFrameTimer) withObject:nil];
                            
                            NSLog(@"--loadMediaURL--mediaState-2:%u",mediaState);

                            playAudio = YES;
                            
                            [[self displayLink] setPaused:NO];//displayLinkをポーズするかどうか

                            //[player play];
                            
                            
                        });
                        
                    }
                    
                }];
            }
        }
    }];

    return ret;
}


// Unload the movie
- (BOOL)unload
{
    NSLog(@"indivestigate:unload");
    
    // Stop playback
    (void)[self stop];
    [self resetData];

    return YES;
}


// // Indicates whether the movie is playable on texture
// - (BOOL)isPlayableOnTexture
// {
//     // We can render local files on texture
//     return localFile && (videoType == ON_TEXTURE || videoType == ON_TEXTURE_FULLSCREEN);
// }

// Indicates whether the movie is playable on texture
- (BOOL)isPlayableOnTexture
{
    NSLog(@"indivestigate:isPlayableOnTexture");

    // We can render local files on texture
    return YES;
}


// Indicates whether the movie is playable in fullscreen mode
- (BOOL)isPlayableFullscreen
{
    NSLog(@"indivestigate:isPlayableFullscreen");

    // We can play both local and remote files in fullscreen mode
    return (videoType == FULLSCREEN || videoType == ON_TEXTURE_FULLSCREEN);
}


// Get the current player state
- (MEDIA_STATE)getStatus
{
    NSLog(@"indivestigate:getStatus");

    return mediaState;
}


// // Get the height of the video (on-texture player only)
// - (int)getVideoHeight
// {
//     int ret = -1;
//
//     // Return information only for local files
//     if ([self isPlayableOnTexture]) {
//         if (NOT_READY > mediaState) {
//             ret = videoSize.height;
//         }
//         else {
//             NSLog(@"Video height not available in current state");
//         }
//     }
//     else {
//         NSLog(@"Video height available only for video that is playable on texture");
//     }
//
//     return ret;
// }



//// Get the height of the video (on-texture player only)
//- (int)getVideoHeight
//{
//    int ret = -1;
//    ret = videoSize.height;
//
////    // Return information only for local files
////	if (NOT_READY > mediaState) {
////		ret = videoSize.height;
////	}
//
//    return ret;
//}
//
//
//// Get the width of the video (on-texture player only)
//- (int)getVideoWidth
//{
//    int ret = -1;
//
//    ret = videoSize.width;
//    
////    // Return information only for local files
////    if ([self isPlayableOnTexture]) {
////        if (NOT_READY > mediaState) {
////            ret = videoSize.width;
////        }
////        else {
////            NSLog(@"Video width not available in current state");
////        }
////    }
////    else {
////        NSLog(@"Video width available only for video that is playable on texture");
////    }
//
//    return ret;
//}

// Get the height of the video (on-texture player only)
- (int)getVideoHeight
{
    NSLog(@"indivestigate:getVideoHeight");

    //int ret = 320;  //@ToDo 決め打ち
    int ret = -1;
    
    // Return information only for local files
    if (NOT_READY > mediaState) {
        ret = videoSize.height;
    }
    
    return ret;
}


// Get the width of the video (on-texture player only)
- (int)getVideoWidth
{
    NSLog(@"indivestigate:getVideoWidth");

//    int ret = 460;  //@ToDo 決め打ち
    int ret = -1;
    
    // Return information only for local files
    if ([self isPlayableOnTexture]) {
        if (NOT_READY > mediaState) {
            ret = videoSize.width;
        }
        else {
            NSLog(@"Video width not available in current state");
        }
    }
    else {
        NSLog(@"Video width available only for video that is playable on texture");
    }
    
    return ret;
}





// Get the length of the media (on-texture player only)
- (float)getLength
{
    NSLog(@"indivestigate:getLength");

    
    float ret = -1.0f;

    // Return information only for local files
    if ([self isPlayableOnTexture]) {
        if (NOT_READY > mediaState) {
            ret = (float)videoLengthSeconds;
        }
        else {
            NSLog(@"Video length not available in current state");
        }
    }
    else {
        NSLog(@"Video length available only for video that is playable on texture");
    }

    return ret;
}


//// Play the asset (maybe default)
//- (BOOL)play:(BOOL)fullscreen fromPosition:(float)seekPosition
//{
//    BOOL ret = NO;
//
//    int requestedPlayerType = YES == fullscreen ? PLAYER_TYPE_NATIVE : PLAYER_TYPE_ON_TEXTURE;
//
//    // If switching player type or not currently playing, and not in an unknown
//    // or error state
//    if ((PLAYING != mediaState || playerType != requestedPlayerType) && NOT_READY > mediaState) {
//        if (PLAYER_TYPE_NATIVE == requestedPlayerType) {
//            BOOL playingOnTexture = NO;
//
//            if (PLAYING == mediaState) {
//                // Pause the on-texture player
//                [self pause];
//                playingOnTexture = YES;
//            }
//
//            // ----- Info: additional player threads not running at this point -----
//
//            // Use an MPMoviePlayerController to play the media
//            moviePlayer = [[MPMoviePlayerController alloc] init];
//
//            // Set up observations
//            [[NSNotificationCenter defaultCenter] addObserver:self
//                                                     selector:@selector(moviePlayerPlaybackDidFinish:)
//                                                         name:MPMoviePlayerPlaybackDidFinishNotification
//                                                       object:moviePlayer];
//
//            [[NSNotificationCenter defaultCenter] addObserver:self
//                                                     selector:@selector(moviePlayerLoadStateChanged:)
//                                                         name:MPMoviePlayerLoadStateDidChangeNotification
//                                                       object:moviePlayer];
//
//            [[NSNotificationCenter defaultCenter] addObserver:self
//                                                     selector:@selector(moviePlayerDidExitFullscreen:)
//                                                         name:MPMoviePlayerDidExitFullscreenNotification
//                                                       object:moviePlayer];
//
//            // The native iOS sample enforces continuous play state and seek position between on-texture
//            // and full screen. For Unity we skip this to be consistent with the Android functionality.
//            /*
//            if (YES == localFile) {
//                // Playback state will reflect the current on-texture playback
//                // state (playback will be started, if required, when the media
//                // has loaded)
//                [moviePlayer setShouldAutoplay:NO];
//
//                if (0.0f <= seekPosition) {
//                    // If a valid position has been requested, update the player
//                    // cursor, which will allow playback to begin from the
//                    // correct position (it will be set when the media has
//                    // loaded)
//                    [self updatePlayerCursorPosition:seekPosition];
//                }
//
//                if (YES == playingOnTexture) {
//                    // Store the fact that video was playing on texture when
//                    // fullscreen playback was requested
//                    resumeOnTexturePlayback = YES;
//                }
//            }
//            else {
//                // Always start playback of remote files from the beginning
//                [self updatePlayerCursorPosition:PLAYER_CURSOR_POSITION_MEDIA_START];
//
//                // Play as soon as enough data is buffered
//                [moviePlayer setShouldAutoplay:YES];
//            }
//             */
//
//            // Always start playback of remote files from the beginning
//            [self updatePlayerCursorPosition:PLAYER_CURSOR_POSITION_MEDIA_START];
//
//            // Play as soon as enough data is buffered
//            [moviePlayer setShouldAutoplay:YES];
//
//
//            // Set the movie player's content URL and prepare to play
//            [moviePlayer setContentURL:mediaURL];
//            [moviePlayer prepareToPlay];
//
//            // Add the MPMoviePlayerController's view to the
//            // arParentViewController's view
//            [[[UIApplication sharedApplication] keyWindow] addSubview:moviePlayer.view];
//
//            mediaState = PLAYING_FULLSCREEN;
//
//            ret = YES;
//        }
//        // On texture playback available only for local files
////        else if (YES == localFile) {  //okamura mod
//        else if (YES) {
//            // ----- Info: additional player threads not running at this point -----
//
//            // Seek to the current playback cursor time (this causes the start
//            // and current times to be synchronised as well as starting AVPlayer
//            // playback)
//            seekRequested = YES;
//
//            if (0.0f <= seekPosition) {
//                // If a valid position has been requested, update the player
//                // cursor, which will allow playback to begin from the
//                // correct position
//                [self updatePlayerCursorPosition:seekPosition];
//            }
//
//            mediaState = PLAYING;
//
//            if (nil != assetReader) {
//                // If we have an asset reader, the asset contains video.  Start
//                // a timer to drive the frame pump (on a background thread)
//                [self performSelectorInBackground:@selector(createFrameTimer) withObject:nil];
//            }
//            else {
//                // The asset contains no video.  Play the audio
//                [player play];
//            }
// 
//            
//            ret = YES;
//        }
//    }
//
//    if (YES == ret) {
//        playerType = (tagPLAYER_TYPE)requestedPlayerType;
//    }
//
//    // ----- Info: additional player threads now running (if ret is YES) -----
//
//    return ret;
//}


// bak 20170510
//// Play the asset
//- (BOOL)play:(BOOL)fullscreen fromPosition:(float)seekPosition
//{
//    
//    BOOL ret = NO;
//    
//    int requestedPlayerType = YES == fullscreen ? PLAYER_TYPE_NATIVE : PLAYER_TYPE_ON_TEXTURE;
//    
//    // If switching player type or not currently playing, and not in an unknown
//    // or error state
//    if ((PLAYING != mediaState || playerType != requestedPlayerType) && NOT_READY > mediaState) {
//        if (PLAYER_TYPE_NATIVE == requestedPlayerType) {
//            BOOL playingOnTexture = NO;
//            
//            if (PLAYING == mediaState) {
//                // Pause the on-texture player
//                [self pause];
//                playingOnTexture = YES;
//            }
//            
//            // ----- Info: additional player threads not running at this point -----
//            
//            // Use an MPMoviePlayerController to play the media, owned by our
//            // own MovieViewContrllerClass
//            movieViewController = [[MovieViewController alloc] init];
////            movieViewController = [[MPMoviePlayerController alloc] init];
//            
//            // Set up observations
//            [[NSNotificationCenter defaultCenter] addObserver:self
//                                                     selector:@selector(moviePlayerPlaybackDidFinish:)
//                                                         name:MPMoviePlayerPlaybackDidFinishNotification
//                                                       object:movieViewController.moviePlayer];
//            
//            [[NSNotificationCenter defaultCenter] addObserver:self
//                                                     selector:@selector(moviePlayerLoadStateChanged:)
//                                                         name:MPMoviePlayerLoadStateDidChangeNotification
//                                                       object:movieViewController.moviePlayer];
//            
//            [[NSNotificationCenter defaultCenter] addObserver:self
//                                                     selector:@selector(moviePlayerDidExitFullscreen:)
//                                                         name:MPMoviePlayerDidExitFullscreenNotification
//                                                       object:movieViewController.moviePlayer];
//            
//            if (YES == localFile) {
//                // Playback state will reflect the current on-texture playback
//                // state (playback will be started, if required, when the media
//                // has loaded)
//                [movieViewController.moviePlayer setShouldAutoplay:YES];
//                
//                if (0.0f <= seekPosition) {
//                    // If a valid position has been requested, update the player
//                    // cursor, which will allow playback to begin from the
//                    // correct position (it will be set when the media has
//                    // loaded)
//                    [self updatePlayerCursorPosition:seekPosition];
//                }
//                
//                if (YES == playingOnTexture) {
//                    // Store the fact that video was playing on texture when
//                    // fullscreen playback was requested
//                    resumeOnTexturePlayback = YES;
//                }
//            }
//            else {
//                // Always start playback of remote files from the beginning
//                [self updatePlayerCursorPosition:PLAYER_CURSOR_POSITION_MEDIA_START];
//                
//                // Play as soon as enough data is buffered
//                [movieViewController.moviePlayer setShouldAutoplay:YES];
//            }
//            
//            // Set the movie player's content URL and prepare to play
//            [movieViewController.moviePlayer setContentURL:mediaURL];
//            [movieViewController.moviePlayer prepareToPlay];
//            
//            // Present the MovieViewController in the root view controller
//            [rootViewController rootViewControllerPresentViewController:movieViewController inContext:NO];
//            
//            mediaState = PLAYING_FULLSCREEN;
//            
//            ret = YES;
//        }
//        // On texture playback available only for local files
//        else if (YES) {
//            // ----- Info: additional player threads not running at this point -----
//            
//            // Seek to the current playback cursor time (this causes the start
//            // and current times to be synchronised as well as starting AVPlayer
//            // playback)
//            seekRequested = YES;
//            
//            if (0.0f <= seekPosition) {
//                // If a valid position has been requested, update the player
//                // cursor, which will allow playback to begin from the
//                // correct position
//                [self updatePlayerCursorPosition:seekPosition];
//            }
//            
//            mediaState = PLAYING;
//            
//            if (YES == playVideo) {
//                // Start a timer to drive the frame pump (on a background
//                // thread)
//                [self performSelectorInBackground:@selector(createFrameTimer) withObject:nil];
//            }
//            else {
//                // The asset contains no video.  Play the audio
//                [player play];
//            }
//            
//            ret = YES;
//        }
//    }
//    
//    if (YES == ret) {
//        playerType = (enum tagPLAYER_TYPE)requestedPlayerType;
//    }
//    
//    // ----- Info: additional player threads now running (if ret is YES) -----
//    
//    return ret;
//}
//

// Play the asset
- (BOOL)play:(BOOL)fullscreen fromPosition:(float)seekPosition
{
    NSLog(@"indivestigate:play");


//    [player play];
////    mediaState = PLAYING;
//    mediaState = PLAYING;
    BOOL ret = NO;

    // Seek to the current playback cursor time (this causes the start
    // and current times to be synchronised as well as starting AVPlayer
    // playback)
    seekRequested = YES;

    if (0.0f <= seekPosition) {
        // If a valid position has been requested, update the player
        // cursor, which will allow playback to begin from the
        // correct position
        [self updatePlayerCursorPosition:seekPosition];
    }

    mediaState = PLAYING;

    if (YES == playVideo) {
        NSLog(@"play -1-");

        // Start a timer to drive the frame pump (on a background
        // thread)
        [self performSelectorInBackground:@selector(createFrameTimer) withObject:nil];
    }
    else {
        NSLog(@"play -2-");
        
        //20171101 test
        // The asset contains no video.  Play the audio
        [[self displayLink] setPaused:NO];
        [player play];
    }
    
    //動画再生終了時 onVideoEnd を実行する。
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(onVideoEnd)
                                                 name:AVPlayerItemDidPlayToEndTimeNotification
                                               object:nil];
    
    ret = YES;

//    UnitySendMessage("gameObjectName", "callbackMethodName", "Message");
    
    NSLog(@"play -3- UnitySendMessage");
//    UnitySendMessage("CloudRecoTarget", "CallbackFoundLostUpdate", "これは引数");
    
    
//    BOOL ret = NO;
//
//    int requestedPlayerType = YES == fullscreen ? PLAYER_TYPE_NATIVE : PLAYER_TYPE_ON_TEXTURE;
//    
//    // If switching player type or not currently playing, and not in an unknown
//    // or error state
//    if ((PLAYING != mediaState || playerType != requestedPlayerType) && NOT_READY > mediaState) {
//        if (PLAYER_TYPE_NATIVE == requestedPlayerType) {
//            BOOL playingOnTexture = NO;
//            
//            if (PLAYING == mediaState) {
//                // Pause the on-texture player
//                [self pause];
//                playingOnTexture = YES;
//            }
//            
//            // ----- Info: additional player threads not running at this point -----
//            
//            // Use an MPMoviePlayerController to play the media, owned by our
//            // own MovieViewContrllerClass
//            movieViewController = [[MovieViewController alloc] init];
//            //            movieViewController = [[MPMoviePlayerController alloc] init];
//            
//            // Set up observations
//            [[NSNotificationCenter defaultCenter] addObserver:self
//                                                     selector:@selector(moviePlayerPlaybackDidFinish:)
//                                                         name:MPMoviePlayerPlaybackDidFinishNotification
//                                                       object:movieViewController.moviePlayer];
//            
//            [[NSNotificationCenter defaultCenter] addObserver:self
//                                                     selector:@selector(moviePlayerLoadStateChanged:)
//                                                         name:MPMoviePlayerLoadStateDidChangeNotification
//                                                       object:movieViewController.moviePlayer];
//            
//            [[NSNotificationCenter defaultCenter] addObserver:self
//                                                     selector:@selector(moviePlayerDidExitFullscreen:)
//                                                         name:MPMoviePlayerDidExitFullscreenNotification
//                                                       object:movieViewController.moviePlayer];
//            
//            if (YES == localFile) {
//                // Playback state will reflect the current on-texture playback
//                // state (playback will be started, if required, when the media
//                // has loaded)
//                [movieViewController.moviePlayer setShouldAutoplay:YES];
//                
//                if (0.0f <= seekPosition) {
//                    // If a valid position has been requested, update the player
//                    // cursor, which will allow playback to begin from the
//                    // correct position (it will be set when the media has
//                    // loaded)
//                    [self updatePlayerCursorPosition:seekPosition];
//                }
//                
//                if (YES == playingOnTexture) {
//                    // Store the fact that video was playing on texture when
//                    // fullscreen playback was requested
//                    resumeOnTexturePlayback = YES;
//                }
//            }
//            else {
//                // Always start playback of remote files from the beginning
//                [self updatePlayerCursorPosition:PLAYER_CURSOR_POSITION_MEDIA_START];
//                
//                // Play as soon as enough data is buffered
//                [movieViewController.moviePlayer setShouldAutoplay:YES];
//            }
//            
//            // Set the movie player's content URL and prepare to play
//            [movieViewController.moviePlayer setContentURL:mediaURL];
//            [movieViewController.moviePlayer prepareToPlay];
//            
//            // Present the MovieViewController in the root view controller
//            [rootViewController rootViewControllerPresentViewController:movieViewController inContext:NO];
//            
//            mediaState = PLAYING_FULLSCREEN;
//            
//            ret = YES;
//        }
//        // On texture playback available only for local files
//        else if (YES) {
//            // ----- Info: additional player threads not running at this point -----
//            
//            // Seek to the current playback cursor time (this causes the start
//            // and current times to be synchronised as well as starting AVPlayer
//            // playback)
//            seekRequested = YES;
//            
//            if (0.0f <= seekPosition) {
//                // If a valid position has been requested, update the player
//                // cursor, which will allow playback to begin from the
//                // correct position
//                [self updatePlayerCursorPosition:seekPosition];
//            }
//            
//            mediaState = PLAYING;
//            
//            if (YES == playVideo) {
//                // Start a timer to drive the frame pump (on a background
//                // thread)
//                [self performSelectorInBackground:@selector(createFrameTimer) withObject:nil];
//            }
//            else {
//                // The asset contains no video.  Play the audio
//                [player play];
//            }
//            
//            ret = YES;
//        }
//    }
//    
//    if (YES == ret) {
//        playerType = (enum tagPLAYER_TYPE)requestedPlayerType;
//    }
//    
    // ----- Info: additional player threads now running (if ret is YES) -----
    
    return ret;
}




// Pause playback (on-texture player only)
- (BOOL)pause
{
    NSLog(@"indivestigate:pause");

//    BOOL ret = YES;
    
    BOOL ret = NO;
    
    NSLog(@"pause-0:mediaState:%u",mediaState);
    NSLog(@"pause-0");
    
    
    // Control available only when playing on texture (not the native player)
    if (PLAYING == mediaState) {
//        if (PLAYER_TYPE_ON_TEXTURE == playerType) {
            [dataLock lock];

            // Stop the audio (if there is any)
            if (YES == playAudio) {
                [player pause];
                [[self displayLink] setPaused:YES];

                NSLog(@"pause-1:mediaState:%u",mediaState);
                NSLog(@"pause-1");

            }

            // Stop the frame pump thread
            //[self waitForFrameTimerThreadToEnd];
            mediaState = PAUSED;

        NSLog(@"pause-2:mediaState:%u",mediaState);
        NSLog(@"pause-2");

            [dataLock unlock];
            ret = YES;
//        }
//        else {
//            NSLog(@"Pause control available only when playing video on texture");
//        }
    }

    return ret;
}


- (void)onVideoEnd
{
    NSLog(@"video end");

//    Float64 seconds = 500.0f;
    Float64 seconds = 0.0f;
    CMTime targetTime = CMTimeMakeWithSeconds(seconds, NSEC_PER_SEC);
    [player seekToTime:targetTime
            toleranceBefore:kCMTimeZero toleranceAfter:kCMTimeZero];
    
    resumeOnTexturePlayback = NO;
    mediaState = REACHED_END;
    (void)[self stop];
    
    
    
//    player = [[[AVPlayer alloc] initWithPlayerItem:self.playerItem] autorelease];

    //    self.videoPlayer = [[[AVPlayer alloc] initWithPlayerItem:self.playerItem] autorelease];
    
//    AVPlayerLayer* layer = ( AVPlayerLayer* )self.videoPlayerView.layer;
//    layer.videoGravity = AVLayerVideoGravityResizeAspect;
//    layer.player       = self.videoPlayer;
    
    
//
//        
//        DEBUGLOG(@"moviePlayerPlaybackDidFinish");
//        // Determine the reason the playback finished
//        NSDictionary* dict = [notification userInfo];
//        NSNumber* reason = (NSNumber*)[dict objectForKey:@"MPMoviePlayerPlaybackDidFinishReasonUserInfoKey"];
//    
//        CFTimeInterval cursorPosition = PLAYER_CURSOR_POSITION_MEDIA_START;
//    
//        switch ([reason intValue]) {
//            case MPMovieFinishReasonPlaybackEnded:
//                DEBUGLOG(@"moviePlayerPlaybackDidFinish -> MPMovieFinishReasonPlaybackEnded");
//                break;
//            case MPMovieFinishReasonPlaybackError:
//                DEBUGLOG(@"moviePlayerPlaybackDidFinish -> MPMovieFinishReasonPlaybackError");
//                break;
//            case MPMovieFinishReasonUserExited:
//                DEBUGLOG(@"moviePlayerPlaybackDidFinish -> MPMovieFinishReasonUserExited");
//                cursorPosition = [movieViewController.moviePlayer currentPlaybackTime];
//                break;
//            default:
//                DEBUGLOG(@"moviePlayerPlaybackDidFinish -> Unknown");
//                break;
//        }
//    
//        // no need to resume player if going back to texture
//        resumeOnTexturePlayback = NO;
//        [self moviePlayerExitAtPosition:cursorPosition];
    
}

// Stop playback (on-texture player only)
//- (BOOL)stop
//{
//    BOOL ret = NO;
//
//    NSLog(@"stop-0:mediaState:%u",mediaState);
//    NSLog(@"stop-0");
//    
//    // Control available only when playing on texture (not the native player)
//    if (PLAYING == mediaState) {
//        if (PLAYER_TYPE_ON_TEXTURE == playerType) {
//            [dataLock lock];
//
//            // Stop the audio (if there is any)
//            if (YES == playAudio) {
//                [player pause];
//            }
//
//
//            // Stop the frame pump thread
//            [self waitForFrameTimerThreadToEnd];
//            mediaState = STOPPED;
//
//        NSLog(@"stop-1:mediaState:%u",mediaState);
//        NSLog(@"stop-1");
//
//            // Reset the playback cursor position
//  //          [self updatePlayerCursorPosition:PLAYER_CURSOR_POSITION_MEDIA_START];
//
//            [dataLock unlock];
//            ret = YES;
//        }
//        else {
//            NSLog(@"Stop control available only when playing video on texture");
//        }
//    }
//
//    return ret;
//}

- (BOOL)stop
{
    NSLog(@"indivestigate:stop");

    BOOL ret = NO;
    
    NSLog(@"stop-0:mediaState:%u",mediaState);
    NSLog(@"stop-0");
    [dataLock lock];
    
    [player pause];
    mediaState = PAUSED;
            
    NSLog(@"stop-1:mediaState:%u",mediaState);
    NSLog(@"stop-1");
    
    [dataLock unlock];
    ret = YES;
    
    return ret;
}


// Seek to a particular playback cursor position (on-texture player only)
- (BOOL)seekTo:(float)position
{
    NSLog(@"indivestigate:seekTo");

    BOOL ret = NO;

    // Control available only when playing on texture (not the native player)
    if (PLAYER_TYPE_ON_TEXTURE == playerType) {
        if (NOT_READY > mediaState) {
            if (position < videoLengthSeconds) {
                // Set the new time (the actual seek occurs in getNextVideoFrame)
                [dataLock lock];
                [self updatePlayerCursorPosition:position];
                seekRequested = YES;
                [dataLock unlock];
                ret = YES;
            }
            else {
                NSLog(@"Requested seek position greater than video length");
            }
        }
        else {
            NSLog(@"Seek control not available in current state");
        }
    }
    else {
        NSLog(@"Seek control available only when playing video on texture");
    }

    return ret;
}


// Get the current playback cursor position (on-texture player only)
- (float)getCurrentPosition
{
    NSLog(@"indivestigate:getCurrentPosition");

    float ret = -1.0f;

    // Return information only when playing on texture (not the native player)
    if (PLAYER_TYPE_ON_TEXTURE == playerType) {
        if (NOT_READY > mediaState) {
            [dataLock lock];
            ret = (float)playerCursorPosition;
            [dataLock unlock];
        }
        else {
            NSLog(@"Current playback position not available in current state");
        }
    }
    else {
        NSLog(@"Current playback position available only when playing video on texture");
    }

    return ret;
}


// Set the volume level (on-texture player only)
- (BOOL)setVolume:(float)volume
{
    NSLog(@"indivestigate:setVolume");

    BOOL ret = NO;

    // Control available only when playing on texture (not the native player)
    if (PLAYER_TYPE_ON_TEXTURE == playerType) {
        if (NOT_READY > mediaState) {
            [dataLock lock];
            ret = [self setVolumeLevel:volume];
            [dataLock unlock];
        }
        else {
            NSLog(@"Volume control not available in current state");
        }
    }
    else {
        NSLog(@"Volume control available only when playing video on texture");
    }

    return ret;
}


// // Update the OpenGL video texture with the latest available video data
// - (MEDIA_STATE)updateVideoData
// {
//     // If currently playing on texture
//     if (PLAYING == mediaState && PLAYER_TYPE_ON_TEXTURE == playerType) {
//         [latestSampleBufferLock lock];
//
//         unsigned char* pixelBufferBaseAddress = NULL;
//         CVImageBufferRef pixelBuffer;
//
//         // If we have a valid buffer, lock the base address of its pixel buffer
//         if (NULL != latestSampleBuffer) {
//             pixelBuffer = CMSampleBufferGetImageBuffer(latestSampleBuffer);
//             CVPixelBufferLockBaseAddress(pixelBuffer, 0);
//             pixelBufferBaseAddress = (unsigned char*)CVPixelBufferGetBaseAddress(pixelBuffer);
//         }
//         else {
//             // No video sample buffer available: we may have been asked to
//             // provide one before any are available, or we may have read all
//             // available frames
//             DEBUGLOG(@"No video sample buffer available");
//         }
//
//         if (NULL != pixelBufferBaseAddress) {
//             // If we haven't created the video texture, do so now
//             if (useMetal) {
//                 if (nil == videoTextureMetal) {
//                     videoTextureMetal = [self createVideoTextureMetal];
//                 }
//             }
//             else {
//                 // OpenGL ES
//                 if (0 == videoTextureIdGL) {
//                     videoTextureIdGL = [self createVideoTextureGL];
//                 }
//                 glBindTexture(GL_TEXTURE_2D, videoTextureIdGL);
//             }
//
//             const size_t bytesPerRow = CVPixelBufferGetBytesPerRow(pixelBuffer);
//
//             if (bytesPerRow / BYTES_PER_TEXEL == videoSize.width) {
//                 // No padding between lines of decoded video
//                 if (useMetal) {
//                     MTLRegion videoRegion = MTLRegionMake2D(0, 0, videoSize.width, videoSize.height);
//                     [videoTextureMetal replaceRegion:videoRegion mipmapLevel:0 withBytes:pixelBufferBaseAddress bytesPerRow:bytesPerRow];
//                 }
//                 else {
//                     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, videoSize.width, videoSize.height, 0, GL_BGRA, GL_UNSIGNED_BYTE, pixelBufferBaseAddress);
//                 }
//             }
//             else {
//                 // Decoded video contains padding between lines.  We must not
//                 // upload it to graphics memory as we do not want to display it
//                 if (useMetal) {
//                     for (int i = 0; i < videoSize.height; ++i) {
//                         unsigned char* line = pixelBufferBaseAddress + i * bytesPerRow;
//                         MTLRegion lineRegion = MTLRegionMake2D(0, 0, videoSize.width, 1);
//                         [videoTextureMetal replaceRegion:lineRegion mipmapLevel:0 withBytes:line bytesPerRow:bytesPerRow];
//                     }
//                 }
//                 else {
//                     // Allocate storage for the OpenGL texture (correctly sized)
//                     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, videoSize.width, videoSize.height, 0, GL_BGRA, GL_UNSIGNED_BYTE, NULL);
//
//                     // Now upload each line of texture data as a sub-image
//                     for (int i = 0; i < videoSize.height; ++i) {
//                         GLubyte* line = pixelBufferBaseAddress + i * bytesPerRow;
//                         glTexSubImage2D(GL_TEXTURE_2D, 0, 0, i, videoSize.width, 1, GL_BGRA, GL_UNSIGNED_BYTE, line);
//                     }
//                 }
//             }
//
//             if (!useMetal) {
//                 // Unbind OpenGL texture
//                 glBindTexture(GL_TEXTURE_2D, 0);
//             }
//
//             // Unlock the buffers
//             CVPixelBufferUnlockBaseAddress(pixelBuffer, 0);
//         }
//
//         [latestSampleBufferLock unlock];
//     }
//
//     return mediaState;
// }

// 20170430_bak
//// Update the OpenGL video texture with the latest available video data
//- (GLuint)updateVideoData
//{
//    NSLog(@"MASA -updateVideoData 1-");
//    
//	GLuint textureID = 0;
//
//	// If currently playing on texture
//	if (PLAYING == mediaState && PLAYER_TYPE_ON_TEXTURE == playerType) {
//
//        NSLog(@"MASA -updateVideoData 2-");
//        
//        [latestSampleBufferLock lock];
//
//		playerCursorPosition = CACurrentMediaTime() - mediaStartTime;
////		self.playerCursorCurrentCMTIME = self.player.currentTime;
//		//		CMTime caCurrentTime = CMTimeMake(self.playerCursorPosition * TIMESCALE, TIMESCALE);
//
//		unsigned char* pixelBufferBaseAddress = NULL;
//		CVPixelBufferRef pixelBuffer;
//
//        //NSLog(@"%@",pixelBuffer); //これをやるとXcodeにこのファイルが表示される！！！！
//
//		// If we have a valid buffer, lock the base address of its pixel buffer
//		//        if (NULL != latestSampleBuffer) {
//		//            pixelBuffer = CMSampleBufferGetImageBuffer(latestSampleBuffer);
//		//pixelBuffer = [[self videoOutput] copyPixelBufferForItemTime:player.currentItem.currentTime itemTimeForDisplay:nil];  //oka
//        
//
////        int valTimeScale;
////        valTimeScale = 1000;
////        CMTime caCurrentTime = CMTimeMake(1 * valTimeScale, valTimeScale);
////        CMTime time = CMTimeMake(1800, 600);
////        double seconds = CMTimeGetSeconds([player currentTime]);    //実はcurrentTime取れてるんじゃないの疑惑
//        //pixelBuffer = [self.videoOutput copyPixelBufferForItemTime:time itemTimeForDisplay:nil];
//        pixelBuffer = [self.videoOutput copyPixelBufferForItemTime:player.currentItem.currentTime itemTimeForDisplay:nil];
//
//        
//		CVPixelBufferLockBaseAddress(pixelBuffer, 0);
//		pixelBufferBaseAddress = (unsigned char*)CVPixelBufferGetBaseAddress(pixelBuffer);
//		//        }
//		//        else {
//		// No video sample buffer available: we may have been asked to
//		// provide one before any are available, or we may have read all
//		// available frames
//		//            DEBUGLOG(@"No video sample buffer available");
//		//        }
//
//        NSLog(@"MASA -updateVideoData 3-");
//
//        videoLengthSeconds = CMTimeGetSeconds([asset duration]);
//        
//		if (NULL != pixelBufferBaseAddress) {
//
//            NSLog(@"MASA -updateVideoData 4-");
//            
//            // If we haven't created the video texture, do so now
//			if (0 == videoTextureIdGL) {
//
//                NSLog(@"MASA -updateVideoData 5-");
//                
//                videoTextureIdGL = [self createVideoTexture];
//			}
//
//			glBindTexture(GL_TEXTURE_2D, videoTextureIdGL);
//			const size_t bytesPerRow = CVPixelBufferGetBytesPerRow(pixelBuffer);
//
//			if (bytesPerRow / BYTES_PER_TEXEL == videoSize.width) {
//                NSLog(@"MASA -updateVideoData 6-");
//                
//                // No padding between lines of decoded video
//				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei) videoSize.width, (GLsizei) videoSize.height, 0, GL_BGRA, GL_UNSIGNED_BYTE, pixelBufferBaseAddress);
//			}
//			else {
//                NSLog(@"MASA -updateVideoData 7-");
//                
//                // Decoded video contains padding between lines.  We must not
//				// upload it to graphics memory as we do not want to display it
//
//				// Allocate storage for the texture (correctly sized)
//				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei) videoSize.width, (GLsizei) videoSize.height, 0, GL_BGRA, GL_UNSIGNED_BYTE, NULL);
//
//				// Now upload each line of texture data as a sub-image
//				for (int i = 0; i < videoSize.height; ++i) {
//					GLubyte* line = pixelBufferBaseAddress + i * bytesPerRow;
//					glTexSubImage2D(GL_TEXTURE_2D, 0, 0, i, (GLsizei) videoSize.width, 1, GL_BGRA, GL_UNSIGNED_BYTE, line);
//				}
//			}
//
//			glBindTexture(GL_TEXTURE_2D, 0);
//
//			// Unlock the buffers
//			CVPixelBufferUnlockBaseAddress(pixelBuffer, 0);
//
//            NSLog(@"MASA -updateVideoData 8-");
//            
//			textureID = videoTextureIdGL;
// 		}
//
//		if (pixelBuffer) {
//			CFRelease(pixelBuffer);
//		}
//
//        NSLog(@"MASA -updateVideoData 9-");
//
//
//		[latestSampleBufferLock unlock];
// 	}
//
//	return textureID;
//}


// Update the OpenGL video texture with the latest available video data
- (GLuint)updateVideoData
{
    NSLog(@"indivestigate:updateVideoData");

    return mediaState;
    //return textureID;
}


// Create an OpenGL texture for the video data
- (GLuint)createVideoTexture
{
    NSLog(@"indivestigate:createVideoTexture");

	 GLuint handle;
	 glGenTextures(1, &handle);
	 glBindTexture(GL_TEXTURE_2D, handle);
	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	 glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	 glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	 glBindTexture(GL_TEXTURE_2D, 0);

	return handle;
}



////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark AVPlayer observation
// Called when the value at the specified key path relative to the given object
// has changed.  Note, this method is invoked on the main queue
- (void)observeValueForKeyPath:(NSString*) path
                      ofObject:(id)object
                        change:(NSDictionary*)change
                       context:(void*)context
{
    NSLog(@"indivestigate:observeValueForKeyPath");

    
    if (AVPlayerItemStatusObservationContext == context) {
        AVPlayerItemStatus status = [[change objectForKey:NSKeyValueChangeNewKey] integerValue];
        switch (status) {
            case AVPlayerItemStatusUnknown:
                DEBUGLOG(@"AVPlayerItemStatusObservationContext -> AVPlayerItemStatusUnknown");
                if (mediaState != PLAYING) {
                    mediaState = NOT_READY;
                }
                break;
            case AVPlayerItemStatusReadyToPlay:
                DEBUGLOG(@"AVPlayerItemStatusObservationContext -> AVPlayerItemStatusReadyToPlay");
                if (mediaState != PLAYING) {
                    mediaState = READY;
                }

                // If immediate on-texture playback has been requested, start
                // playback
                if (YES == playImmediately) {
                    [self play:NO fromPosition:VIDEO_PLAYBACK_CURRENT_POSITION];
                }

                break;
            case AVPlayerItemStatusFailed:
                DEBUGLOG(@"AVPlayerItemStatusObservationContext -> AVPlayerItemStatusFailed");
                NSLog(@"Error - AVPlayer unable to play media: %@", [[[player currentItem] error] localizedDescription]);
                mediaState = ERROR;
                break;
            default:
                DEBUGLOG(@"AVPlayerItemStatusObservationContext -> Unknown");
                mediaState = NOT_READY;
                break;
        }
    }
}


////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark MPMoviePlayerController observation
// Called when the movie player's media load state changes
//- (void)moviePlayerLoadStateChanged:(NSNotification*)notification;
//{
//    DEBUGLOG(@"moviePlayerLoadStateChanged");
//    if (MPMovieLoadStatePlayable & [moviePlayer loadState]) {
//        // If the movie is playable, set the playback time to the current cursor
//        // position (in case the on texture player is passing responsibility for
//        // playing the current media to the native player) and start playback
//        [moviePlayer setCurrentPlaybackTime:playerCursorPosition];
//
//        // Use fullscreen mode
//        [moviePlayer setFullscreen:YES];
//
//        // If video was playing on texture before switching to fullscreen mode,
//        // start playback
//        if (YES == resumeOnTexturePlayback) {
//            [moviePlayer play];
//        }
//    }
//}
#pragma mark - MPMoviePlayerController observation
// Called when the movie player's media load state changes
//- (void)moviePlayerLoadStateChanged:(NSNotification*)notification;
//{
//    NSLog(@"indivestigate:moviePlayerLoadStateChanged");
//
//    
//    DEBUGLOG(@"moviePlayerLoadStateChanged");
//    if (MPMovieLoadStatePlayable & [movieViewController.moviePlayer loadState]) {
//        // If the movie is playable, set the playback time to the current cursor
//        // position (in case the on texture player is passing responsibility for
//        // playing the current media to the native player) and start playback
//        [movieViewController.moviePlayer setCurrentPlaybackTime:playerCursorPosition];
//        
//        // Use fullscreen mode
//        [movieViewController.moviePlayer setFullscreen:YES];
//        
//        // If video was playing on texture before switching to fullscreen mode,
//        // start playback
//        if (YES == resumeOnTexturePlayback) {
//            [movieViewController.moviePlayer play];
//        }
//    }
//}

//
//// Called when the movie player's media playback ends
//- (void)moviePlayerPlaybackDidFinish:(NSNotification*)notification
//{
//    DEBUGLOG(@"moviePlayerPlaybackDidFinish");
//    // Determine the reason the playback finished
//    NSDictionary* dict = [notification userInfo];
//    NSNumber* reason = (NSNumber*)[dict objectForKey:@"MPMoviePlayerPlaybackDidFinishReasonUserInfoKey"];
//
//    CFTimeInterval cursorPosition = PLAYER_CURSOR_POSITION_MEDIA_START;
//
//    switch ([reason intValue]) {
//        case MPMovieFinishReasonPlaybackEnded:
//            DEBUGLOG(@"moviePlayerPlaybackDidFinish -> MPMovieFinishReasonPlaybackEnded");
//            break;
//        case MPMovieFinishReasonPlaybackError:
//            DEBUGLOG(@"moviePlayerPlaybackDidFinish -> MPMovieFinishReasonPlaybackError");
//            break;
//        case MPMovieFinishReasonUserExited:
//            DEBUGLOG(@"moviePlayerPlaybackDidFinish -> MPMovieFinishReasonUserExited");
//            cursorPosition = [moviePlayer currentPlaybackTime];
//            break;
//        default:
//            DEBUGLOG(@"moviePlayerPlaybackDidFinish -> Unknown");
//            break;
//    }
//
//    [self moviePlayerExitAtPosition:cursorPosition];
//}
// Called when the movie player's media playback ends

//- (void)moviePlayerPlaybackDidFinish:(NSNotification*)notification
//{
//    NSLog(@"indivestigate:moviePlayerPlaybackDidFinish");
//
//    
//    DEBUGLOG(@"moviePlayerPlaybackDidFinish");
//    // Determine the reason the playback finished
//    NSDictionary* dict = [notification userInfo];
//    NSNumber* reason = (NSNumber*)[dict objectForKey:@"MPMoviePlayerPlaybackDidFinishReasonUserInfoKey"];
//    
//    CFTimeInterval cursorPosition = PLAYER_CURSOR_POSITION_MEDIA_START;
//    
//    switch ([reason intValue]) {
//        case MPMovieFinishReasonPlaybackEnded:
//            DEBUGLOG(@"moviePlayerPlaybackDidFinish -> MPMovieFinishReasonPlaybackEnded");
//            break;
//        case MPMovieFinishReasonPlaybackError:
//            DEBUGLOG(@"moviePlayerPlaybackDidFinish -> MPMovieFinishReasonPlaybackError");
//            break;
//        case MPMovieFinishReasonUserExited:
//            DEBUGLOG(@"moviePlayerPlaybackDidFinish -> MPMovieFinishReasonUserExited");
//            cursorPosition = [movieViewController.moviePlayer currentPlaybackTime];
//            break;
//        default:
//            DEBUGLOG(@"moviePlayerPlaybackDidFinish -> Unknown");
//            break;
//    }
//    
//    // no need to resume player if going back to texture
//    resumeOnTexturePlayback = NO;
//    [self moviePlayerExitAtPosition:cursorPosition];
//}


//- (void)moviePlayerDidExitFullscreen:(NSNotification*)notification
//{
//    DEBUGLOG(@"moviePlayerDidExitFullscreen");
//    [self moviePlayerExitAtPosition:[moviePlayer currentPlaybackTime]];
//}

//- (void)moviePlayerDidExitFullscreen:(NSNotification*)notification
//{
//    NSLog(@"indivestigate:moviePlayerDidExitFullscreen");
//
//    
//    DEBUGLOG(@"moviePlayerDidExitFullscreen");
//    [self moviePlayerExitAtPosition:[movieViewController.moviePlayer currentPlaybackTime]];
//}


//- (void)moviePlayerExitAtPosition:(NSTimeInterval)position
//{
//#ifdef DEBUG
//    NSLog(@"moviePlayerExitAtPosition: %f", position);
//#endif
//    // Stop receiving notifications
//    [[NSNotificationCenter defaultCenter] removeObserver:self name:MPMoviePlayerPlaybackDidFinishNotification object:moviePlayer];
//    [[NSNotificationCenter defaultCenter] removeObserver:self name:MPMoviePlayerLoadStateDidChangeNotification object:moviePlayer];
//    [[NSNotificationCenter defaultCenter] removeObserver:self name:MPMoviePlayerDidExitFullscreenNotification object:moviePlayer];
//
//    // Stop the movie just in case
//    [moviePlayer stop];
//
//    // Remove the MPMoviePlayerController's view.  Note, on iOS 6 we need to
//    // stop the movie player being fullscreen before we remove its view,
//    // otherwise it does not remove properly
//    [moviePlayer setFullscreen:NO];
//    [moviePlayer.view removeFromSuperview];
//    [moviePlayer release];
//    moviePlayer = nil;
//
//    [dataLock lock];
//    // Update the playback cursor position
//    //[self updatePlayerCursorPosition:position];
//    [self updatePlayerCursorPosition:PLAYER_CURSOR_POSITION_MEDIA_START];
//    [dataLock unlock];
//
//    // If video was playing on texture before switching to fullscreen mode,
//    // restart playback
//    /*
//    if (YES == resumeOnTexturePlayback) {
//        resumeOnTexturePlayback = NO;
//        [self play:NO fromPosition:VIDEO_PLAYBACK_CURRENT_POSITION];
//    }
//    else {
//        mediaState = PAUSED;
//    }
//     */
//    playerType = PLAYER_TYPE_ON_TEXTURE;
//    mediaState = READY;
//}

//- (void)moviePlayerExitAtPosition:(NSTimeInterval)position
//{
//    NSLog(@"indivestigate:moviePlayerExitAtPosition");
//
//    
//#ifdef DEBUG
//    NSLog(@"moviePlayerExitAtPosition: %lf", position);
//#endif
//    // Stop receiving notifications
//    [[NSNotificationCenter defaultCenter] removeObserver:self name:MPMoviePlayerPlaybackDidFinishNotification object:movieViewController.moviePlayer];
//    [[NSNotificationCenter defaultCenter] removeObserver:self name:MPMoviePlayerLoadStateDidChangeNotification object:movieViewController.moviePlayer];
//    [[NSNotificationCenter defaultCenter] removeObserver:self name:MPMoviePlayerDidExitFullscreenNotification object:movieViewController.moviePlayer];
//    
//    // Stop fullscreen mode
//    [movieViewController.moviePlayer setFullscreen:NO];
//    
//    // Dismiss the MovieViewController
//    [rootViewController rootViewControllerDismissPresentedViewController];
//    
//    [movieViewController release];
//    movieViewController = nil;
//    
//    [dataLock lock];
//    // Update the playback cursor position
//    [self updatePlayerCursorPosition:position];
//    [dataLock unlock];
//    
//    // If video was playing on texture before switching to fullscreen mode,
//    // restart playback
//    if (YES == resumeOnTexturePlayback) {
//        resumeOnTexturePlayback = NO;
//        [self play:NO fromPosition:VIDEO_PLAYBACK_CURRENT_POSITION];
//    }
//    else {
//        mediaState = PAUSED;
//    }
//}



////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Private methods
- (void)resetData
{
    NSLog(@"indivestigate:resetData");

    
//    if (PLAYING == mediaState || REACHED_END == mediaState) {
//        [player pause];
//        [[self displayLink] setPaused:YES];
//    }

//    [[self displayLink] setPaused:YES];
//    [[self displayLink] setPaused:NO];

    
    // ----- Info: additional player threads not running at this point -----

    // Reset media state and information
    mediaState = NOT_READY;
    syncStatus = SYNC_DEFAULT;
    playerType = PLAYER_TYPE_ON_TEXTURE;
    requestedCursorPosition = PLAYER_CURSOR_REQUEST_COMPLETE;
    playerCursorPosition = PLAYER_CURSOR_POSITION_MEDIA_START;
    playImmediately = NO;
    videoSize.width = 0.0f;
    videoSize.height = 0.0f;
    videoLengthSeconds = 0.0f;
    videoFrameRate = 0.0f;

    // Remove KVO observers
    [[player currentItem] removeObserver:self forKeyPath:kStatusKey];
    
    // Release AVPlayer, AVAsset, etc.
//    [player release];
//    player = nil;
    [asset release];
    asset = nil;

    [assetReader release];
    assetReader = nil;
    [assetReaderTrackOutputVideo release];
    assetReaderTrackOutputVideo = nil;
//    [moviePlayer release];
//    moviePlayer = nil;
    [movieViewController release];
    movieViewController = nil;

    [mediaURL release];
    mediaURL = nil;
    
    //ダメだった。
//    [self.displayLink removeFromRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
//    [self.displayLink release];
//    self.displayLink = nil;
//    videoTextureMetal = nil;

    
    
    
//    [dataLock lock];
    
    // Stop the audio (if there is any)
//    [player pause];
    
//    // Stop the frame pump thread
//    [self waitForFrameTimerThreadToEnd];
//    mediaState = STOPPED;
    
    // Reset the playback cursor position
//    [self updatePlayerCursorPosition:PLAYER_CURSOR_POSITION_MEDIA_START];
    
//    [dataLock unlock];


}


- (BOOL)loadLocalMediaFromURL:(NSURL*)url
{
    NSLog(@"indivestigate:loadLocalMediaFromURL");

    
    BOOL ret = NO;
    asset = [[AVURLAsset alloc] initWithURL:url options:nil];

    if (nil != asset) {
        // We can now attempt to load the media, so report success.  We will
        // discover if the load actually completes successfully when we are
        // called back by the system
        ret = YES;

        [asset loadValuesAsynchronouslyForKeys:[NSArray arrayWithObject:kTracksKey] completionHandler:
         ^{
             // Completion handler block (dispatched on main queue when loading
             // completes)
             dispatch_async(dispatch_get_main_queue(),
                            ^{
                                NSError *error = nil;
                                AVKeyValueStatus status = [asset statusOfValueForKey:kTracksKey error:&error];

                                if (status == AVKeyValueStatusLoaded) {
                                    // Asset loaded, retrieve info and prepare
                                    // for playback
                                    if (NO == [self prepareAssetForPlayback]) {
                                        NSLog(@"Error - Unable to prepare media for playback");
                                        mediaState = ERROR;
                                    }
                                }
                                else {
                                    // Error
                                    NSLog(@"Error - The asset's tracks were not loaded: %@", [error localizedDescription]);
                                }
                            });
         }];
    }

    return ret;
}


 // Prepare the AVURLAsset for playback
 - (BOOL)prepareAssetForPlayback
 {
     NSLog(@"indivestigate:prepareAssetForPlayback");

     // Get video properties
     videoSize = [[[asset tracksWithMediaType:AVMediaTypeVideo] objectAtIndex:0] naturalSize];

     videoLengthSeconds = CMTimeGetSeconds([asset duration]);

     // Start playback at time 0.0
     playerCursorStartPosition = kCMTimeZero;

     // Start playback at full volume (audio mix level, not system volume level)
     currentVolume = PLAYER_VOLUME_DEFAULT;

     // Create asset tracks for reading
     BOOL ret = [self prepareAssetForReading:playerCursorStartPosition];

     if (YES == ret) {
         if (YES == playAudio) {
             // Prepare the AVPlayer to play the audio
             [self prepareAVPlayer];
         }
         else {
             // Inform our client that the asset is ready to play
             mediaState = READY;
         }
     }

     return ret;
 }
//
//
// // Prepare the AVURLAsset for reading so we can obtain video frame data from it
// - (BOOL)prepareAssetForReading:(CMTime)startTime
// {
//     BOOL ret = YES;
//     NSError* error = nil;
//
//     // ===== Video =====
//     // Get the first video track
//     AVAssetTrack* assetTrackVideo = nil;
//     NSArray* arrayTracks = [asset tracksWithMediaType:AVMediaTypeVideo];
//     if (0 < [arrayTracks count]) {
//         assetTrackVideo = [arrayTracks objectAtIndex:0];
//         videoFrameRate = [assetTrackVideo nominalFrameRate];
//
//         // Release any existing asset reader-related resources]
//         [assetReader release];
//         [assetReaderTrackOutputVideo release];
//
//         // Create an asset reader for the video track
//         assetReader = [[AVAssetReader alloc] initWithAsset:asset error:&error];
//
//         // Create an output for the video track
//         NSDictionary* outputSettings = [NSDictionary dictionaryWithObject:[NSNumber numberWithInt:kCVPixelFormatType_32BGRA] forKey:(NSString *)kCVPixelBufferPixelFormatTypeKey];
//         assetReaderTrackOutputVideo = [[AVAssetReaderTrackOutput alloc] initWithTrack:assetTrackVideo outputSettings:outputSettings];
//
//         // Add the video output to the asset reader
//         if ([assetReader canAddOutput:assetReaderTrackOutputVideo]) {
//             [assetReader addOutput:assetReaderTrackOutputVideo];
//         }
//
//         // Set the time range
//         CMTimeRange requiredTimeRange = CMTimeRangeMake(startTime, kCMTimePositiveInfinity);
//         [assetReader setTimeRange:requiredTimeRange];
//
//         // Start reading the track
//         [assetReader startReading];
//
//         if (AVAssetReaderStatusReading != [assetReader status]) {
//             NSLog(@"Error - AVAssetReader not in reading state");
//             ret = NO;
//         }
//     }
//     else {
//         NSLog(@"***** No video tracks in asset *****");
//     }
//
//     // ===== Audio =====
//     // Get the first audio track
//     arrayTracks = [asset tracksWithMediaType:AVMediaTypeAudio];
//     if (0 < [arrayTracks count]) {
//         playAudio = YES;
//         AVAssetTrack* assetTrackAudio = [arrayTracks objectAtIndex:0];
//
//         AVMutableAudioMixInputParameters* audioInputParams = [AVMutableAudioMixInputParameters audioMixInputParameters];
//         [audioInputParams setVolume:currentVolume atTime:playerCursorStartPosition];
//         [audioInputParams setTrackID:[assetTrackAudio trackID]];
//
//         NSArray* audioParams = [NSArray arrayWithObject:audioInputParams];
//         AVMutableAudioMix* audioMix = [AVMutableAudioMix audioMix];
//         [audioMix setInputParameters:audioParams];
//
//         AVPlayerItem* item = [player currentItem];
//         [item setAudioMix:audioMix];
//     }
//     else {
//         NSLog(@"***** No audio tracks in asset *****");
//     }
//
//     return ret;
// }



//// Prepare the AVURLAsset for playback
//- (BOOL)prepareAssetForPlayback
//{
//    // BOOL ret = YES;
//
//    // Get video properties
//    NSArray* videoTracks = [asset tracksWithMediaType:AVMediaTypeVideo];
//	AVAssetTrack* videoTrack = videoTracks[0];
//    videoSize = videoTrack.naturalSize;
//
//    videoLengthSeconds = CMTimeGetSeconds([asset duration]);
//
//    // Start playback at time 0.0
//    playerCursorStartPosition = kCMTimeZero;
//
//    // Start playback at full volume (audio mix level, not system volume level)
//    currentVolume = PLAYER_VOLUME_DEFAULT;
//
//    // Create asset tracks for reading
//    BOOL ret = [self prepareAssetForReading:playerCursorStartPosition];
//
//    if (ret) {
//        // Prepare the AVPlayer to play the audio
//        [self prepareAVPlayer];
//        // Inform our client that the asset is ready to play
//        mediaState = READY;
//    }
//
//    return ret;
//}


// Prepare the AVURLAsset for reading so we can obtain video frame data from it
- (BOOL)prepareAssetForReading:(CMTime)startTime
{
    NSLog(@"indivestigate:prepareAssetForReading");

    
    BOOL ret = YES;

    // ===== Audio =====
    // Get the first audio track
   NSArray * arrayTracks = [asset tracksWithMediaType:AVMediaTypeAudio];
    if (0 < [arrayTracks count]) {

//        //4/22 okamura add start
//        // Release any existing asset reader-related resources]
//        [assetReader release];
//        [assetReaderTrackOutputVideo release];
//        // Create an asset reader for the video track
//        assetReader = [[AVAssetReader alloc] initWithAsset:asset error:&error];
//        //4/22 okamura add end
        
        playAudio = YES;
        AVAssetTrack* assetTrackAudio = arrayTracks[0];

        AVMutableAudioMixInputParameters* audioInputParams = [AVMutableAudioMixInputParameters audioMixInputParameters];
        [audioInputParams setVolume:currentVolume atTime:playerCursorStartPosition];
        [audioInputParams setTrackID:[assetTrackAudio trackID]];

        NSArray* audioParams = @[audioInputParams];
        AVMutableAudioMix* audioMix = [AVMutableAudioMix audioMix];
        [audioMix setInputParameters:audioParams];

        AVPlayerItem* item = [player currentItem];
        [item setAudioMix:audioMix];
        
    }

    return ret;
}



// Prepare the AVPlayer object for media playback
- (void)prepareAVPlayer
{
    NSLog(@"indivestigate:prepareAVPlayer");

    
    // Create a player item
    AVPlayerItem* item = [AVPlayerItem playerItemWithAsset:asset];

    // Add player item status KVO observer
    NSKeyValueObservingOptions opts = NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld | NSKeyValueObservingOptionPrior | NSKeyValueObservingOptionInitial;
    [item addObserver:self forKeyPath:kStatusKey options:opts context:AVPlayerItemStatusObservationContext];

    // Create an AV player
    player = [[AVPlayer alloc] initWithPlayerItem:item];
}


// Video frame pump timer callback
- (void)frameTimerFired:(NSTimer*)timer;
{
    NSLog(@"indivestigate:frameTimerFired");

    
    if (NO == stopFrameTimer) {
        [self getNextVideoFrame];
    }
    else {
        // NSTimer invalidate must be called on the timer's thread
        [frameTimer invalidate];
    }
}


// Decode the next video frame and make it available for use (do not assume the
// timer driving the frame pump will be accurate)
- (void)getNextVideoFrame
{
    NSLog(@"indivestigate:getNextVideoFrame");

    
    // Synchronise access to publicly accessible internal data.  We use tryLock
    // here to prevent possible deadlock when pause or stop are called on
    // another thread
    if (NO == [dataLock tryLock]) {
        return;
    }

    @try {
        // If we've been told to seek to a new time, do so now
        if (YES == seekRequested) {
            seekRequested = NO;
            [self doSeekAndPlayAudio];
        }

        // Simple video synchronisation mechanism:
        // If the video frame time is within tolerance, make it available to our
        // client.  This state is SYNC_READY.
        // If the video frame is behind, throw it away and get the next one.  We
        // will either catch up with the reference time (and become SYNC_READY),
        // or run out of frames.  This state is SYNC_BEHIND.
        // If the video frame is ahead, make it available to the client, but do
        // not retrieve more frames until the reference time catches up.  This
        // state is SYNC_AHEAD.

        while (SYNC_READY != syncStatus) {
            Float64 delta;

            if (SYNC_AHEAD != syncStatus) {
                currentSampleBuffer = [assetReaderTrackOutputVideo copyNextSampleBuffer];
            }

            if (NULL == currentSampleBuffer) {
                // Failed to read the next sample buffer
                break;
            }

            // Get the time stamp of the video frame
            CMTime frameTimeStamp = CMSampleBufferGetPresentationTimeStamp(currentSampleBuffer);

            // Get the time since playback began
            playerCursorPosition = CACurrentMediaTime() - mediaStartTime;
            CMTime caCurrentTime = CMTimeMake(playerCursorPosition * TIMESCALE, TIMESCALE);

            // Compute delta of video frame and current playback times
            delta = CMTimeGetSeconds(caCurrentTime) - CMTimeGetSeconds(frameTimeStamp);

            if (delta < 0) {
                delta *= -1;
                syncStatus = SYNC_AHEAD;
            }
            else {
                syncStatus = SYNC_BEHIND;
            }

            if (delta < 1 / videoFrameRate) {
                // Video in sync with audio
                syncStatus = SYNC_READY;
            }
            else if (SYNC_AHEAD == syncStatus) {
                // Video ahead of audio: stay in SYNC_AHEAD state, exit loop
                break;
            }
            else {
                // Video behind audio (SYNC_BEHIND): stay in loop
                CFRelease(currentSampleBuffer);
            }
        }
    }
    @catch (NSException* e) {
        // Assuming no other error, we are trying to read past the last sample
        // buffer
        DEBUGLOG(@"Failed to copyNextSampleBuffer");
        currentSampleBuffer = NULL;
    }

    if (NULL == currentSampleBuffer) {
        switch ([assetReader status]) {
            case AVAssetReaderStatusCompleted:
                DEBUGLOG(@"getNextVideoFrame -> AVAssetReaderStatusCompleted");
                mediaState = REACHED_END;
                break;
            case AVAssetReaderStatusFailed: {
                NSError* error = [assetReader error];
                NSLog(@"getNextVideoFrame -> AVAssetReaderStatusFailed: %@", [error localizedDescription]);
                mediaState = ERROR;
                break;
            }
            default:
                DEBUGLOG(@"getNextVideoFrame -> Unknown");
                break;
        }

        // Stop the frame pump
        [frameTimer invalidate];

        // Reset the playback cursor position
        [self updatePlayerCursorPosition:PLAYER_CURSOR_POSITION_MEDIA_START];
    }

    [latestSampleBufferLock lock];

    if (NULL != latestSampleBuffer) {
        // Release the latest sample buffer
        CFRelease(latestSampleBuffer);
    }

    if (SYNC_READY == syncStatus) {
        // Audio and video are synchronised, so transfer ownership of
        // currentSampleBuffer to latestSampleBuffer
        latestSampleBuffer = currentSampleBuffer;
    }
    else {
        // Audio and video not synchronised, do not supply a sample buffer
        latestSampleBuffer = NULL;
    }

    [latestSampleBufferLock unlock];

    // Reset the sync status, unless video is ahead of the reference time
    if (SYNC_AHEAD != syncStatus) {
        syncStatus = SYNC_DEFAULT;
    }

    [dataLock unlock];
}


// Create a timer to drive the video frame pump
- (void)createFrameTimer
{
    NSLog(@"indivestigate:createFrameTimer");

    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];

    frameTimer = [[NSTimer scheduledTimerWithTimeInterval:(1 / videoFrameRate) target:self selector:@selector(frameTimerFired:) userInfo:nil repeats:YES] retain];

    // Set thread priority explicitly to the default value (0.5),
    // to ensure that the frameTimer can tick at the expected rate.
    [[NSThread currentThread] setThreadPriority:0.5];

    // Execute the current run loop (it will terminate when its associated timer
    // becomes invalid)
    [[NSRunLoop currentRunLoop] run];

    // Release frameTimer (set to nil to notify any threads waiting for the
    // frame pump to stop)
    [frameTimer release];
    frameTimer = nil;

    // Make sure we do not leak a sample buffer
    [latestSampleBufferLock lock];

    if (NULL != latestSampleBuffer) {
        // Release the latest sample buffer
        CFRelease(latestSampleBuffer);
        latestSampleBuffer = NULL;
    }

    [latestSampleBufferLock unlock];

    [pool release];
}


// Create an OpenGL texture for the video data
- (GLuint)createVideoTextureGL
{
    NSLog(@"indivestigate:createVideoTextureGL");

    GLuint handle;
    glGenTextures(1, &handle);
    glBindTexture(GL_TEXTURE_2D, handle);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glBindTexture(GL_TEXTURE_2D, 0);
    return handle;
}

// Create a Metal texture for the video data
- (id<MTLTexture>)createVideoTextureMetal
{
    NSLog(@"indivestigate:createVideoTextureMetal");

    if (metalDevice != nil)
    {
        if (MTLTextureDescriptorClass == nil) {
            MTLTextureDescriptorClass = [metalBundle classNamed:@"MTLTextureDescriptor"];
        }
        MTLTextureDescriptor *texDesc = [MTLTextureDescriptorClass texture2DDescriptorWithPixelFormat:MTLPixelFormatB5G6R5Unorm
                                                                                                width:videoSize.width
                                                                                               height:videoSize.height
                                                                                            mipmapped:NO];

        return [metalDevice newTextureWithDescriptor:texDesc];

    }
    else
    {
        NSLog(@"VuforiaMedia ERROR: could not create Metal texture as MTLDevice was not created.");
        return nil;
    }
}


// Update the playback cursor position
// [Always called with dataLock locked]
- (void)updatePlayerCursorPosition:(float)position
{
    NSLog(@"indivestigate:updatePlayerCursorPosition");

    // Set the player cursor position so the native player can restart from the
    // appropriate time if play (fullscreen) is called again
    playerCursorPosition = position;

    // Set the requested cursor position to cause the on texture player to seek
    // to the appropriate time if play (on texture) is called again
    requestedCursorPosition = position;
}


// Set the volume level (on-texture player only)
// [Always called with dataLock locked]
- (BOOL)setVolumeLevel:(float)volume
{
    NSLog(@"indivestigate:setVolumeLevel");

    BOOL ret = NO;
    NSArray* arrayTracks = [asset tracksWithMediaType:AVMediaTypeAudio];

    if (0 < [arrayTracks count]) {
        // Get the asset's audio track
        AVAssetTrack* assetTrackAudio = [arrayTracks objectAtIndex:0];

        if (nil != assetTrackAudio) {
            // Set up the audio mix
            AVMutableAudioMixInputParameters* audioInputParams = [AVMutableAudioMixInputParameters audioMixInputParameters];
            [audioInputParams setVolume:volume atTime:playerCursorStartPosition];
            [audioInputParams setTrackID:[assetTrackAudio trackID]];
            NSArray* audioParams = [NSArray arrayWithObject:audioInputParams];
            AVMutableAudioMix* audioMix = [AVMutableAudioMix audioMix];
            [audioMix setInputParameters:audioParams];

            // Apply the audio mix the the AVPlayer's current item
            [[player currentItem] setAudioMix:audioMix];

            // Store the current volume level
            currentVolume = volume;
            ret = YES;
        }
    }

    return ret;
}


// Seek to a particular playback position (when playing on texture)
// [Always called with dataLock locked]
- (void)doSeekAndPlayAudio
{
    NSLog(@"indivestigate:doSeekAndPlayAudio");

    if (PLAYER_CURSOR_REQUEST_COMPLETE < requestedCursorPosition) {
        // Store the cursor position from which playback will start
        playerCursorStartPosition = CMTimeMake(requestedCursorPosition * TIMESCALE, TIMESCALE);

        // Ensure the volume continues at the current level
        [self setVolumeLevel:currentVolume];

        if (YES == playAudio) {
            // Set AVPlayer cursor position (audio)
            [player seekToTime:playerCursorStartPosition];
        }

        // Set the asset reader's start time to the new time (video)
        [self prepareAssetForReading:playerCursorStartPosition];

        // Indicate seek request is complete
        requestedCursorPosition = PLAYER_CURSOR_REQUEST_COMPLETE;
    }

    if (YES == playAudio) {
        // Play the audio (if there is any)
        [player play];
    }

    // Store the media start time for reference
    mediaStartTime = CACurrentMediaTime() - playerCursorPosition;
}


// Request the frame timer to terminate and wait for its thread to end
- (void)waitForFrameTimerThreadToEnd
{
    NSLog(@"indivestigate:waitForFrameTimerThreadToEnd");

    stopFrameTimer = YES;

    // Wait for the frame pump thread to stop
    while (nil != frameTimer) {
        [NSThread sleepForTimeInterval:0.01];
    }

    stopFrameTimer = NO;
}


// Set the video texture handle
- (BOOL)setVideoTexturePtr:(void*)texturePtr
{
    NSLog(@"indivestigate:setVideoTexturePtr");

    if (useMetal) {
        videoTextureMetal = (id<MTLTexture>)texturePtr;
        return YES;
    }
    else {
        videoTextureIdGL = (int)((long)texturePtr);
        return YES;
    }
}


- (void)onPause
{
    NSLog(@"indivestigate:onPause");

//    if (moviePlayer != nil)
//    {
//        [self moviePlayerExitAtPosition:[moviePlayer currentPlaybackTime]];
//    }
}


- (void)displayLinkCallback:(CADisplayLink *)sender
{
    NSLog(@"indivestigate:displayLinkCallback");
    
    /*
     The callback gets called once every Vsync.
     Using the display link's timestamp and duration we can compute the next time the screen will be refreshed, and copy the pixel buffer for that time
     This pixel buffer can then be processed and later rendered on screen.
     */
    CMTime outputItemTime = kCMTimeInvalid;
    
    // Calculate the nextVsync time which is when the screen will be refreshed next.
    CFTimeInterval nextVSync = ([sender timestamp] + [sender duration]);
    
    outputItemTime = [[self videoOutput] itemTimeForHostTime:nextVSync];
    
    NSLog(@"seconds = %f", CMTimeGetSeconds(outputItemTime));
    NSLog(@"videoOutput = %@", [self videoOutput]);

    if ([[self videoOutput] hasNewPixelBufferForItemTime:outputItemTime]) {
        //outputする適切なデータがある場合
        cntNoRender = 0;
        NSLog(@"nctNoRender is set zero");
        
        [latestSampleBufferLock lock];
        
        CVPixelBufferRef pixelBuffer = NULL;
        
        //pixelBuffer を取得。(瞬間瞬間の画像データ)
        pixelBuffer = [[self videoOutput] copyPixelBufferForItemTime:outputItemTime itemTimeForDisplay:NULL];
        
        //pixelBuffer を適用
        //[[self playerView2] displayPixelBuffer:pixelBuffer];
        
        //**** vuforiaで取得しているopenGL適用 start
        
        //** textureID を取得してグローバル変数に入れておく。
        textureID = 0;
        
        unsigned char* pixelBufferBaseAddress = NULL;
        CVPixelBufferLockBaseAddress(pixelBuffer, 0);   //ロック
        //pixelBufferBaseAddress = (unsigned char*)CVPixelBufferGetBaseAddress(pixelBuffer);
        
        CVImageBufferRef cvimgRef = (CVImageBufferRef)pixelBuffer;
        pixelBufferBaseAddress = (unsigned char*)CVPixelBufferGetBaseAddress(cvimgRef);
        
        // If we haven't created the video texture, do so now
        if (useMetal) {
            // Metal
            if (nil == videoTextureMetal) {
                videoTextureMetal = [self createVideoTextureMetal];
            }
        }
        else {
            // OpenGL ES
            if (0 == videoTextureIdGL) {
                
                NSLog(@"MASA -displayLinkCallback 1-");
                videoTextureIdGL = [self createVideoTexture];
            }
            glBindTexture(GL_TEXTURE_2D, videoTextureIdGL);
            
        }
        
        
        const size_t bytesPerRow = CVPixelBufferGetBytesPerRow(pixelBuffer);
        
        //if (bytesPerRow / BYTES_PER_TEXEL == videoSize.width) {
        
        NSLog(@"%ld",bytesPerRow);
        NSLog(@"%d",BYTES_PER_TEXEL);
        NSLog(@"%ld",CVPixelBufferGetWidth(pixelBuffer));
        
        NSLog(@"MASA -displayLinkCallback 2-");
        
        
        if (bytesPerRow / BYTES_PER_TEXEL == CVPixelBufferGetWidth(pixelBuffer)) {
            // No padding between lines of decoded video
            
            NSLog(@"MASA -displayLinkCallback 2-");
            
            if (useMetal) {
                NSLog(@"MASA -displayLinkCallback 2 useMetal-");
                
                // MTLRegion videoRegion = MTLRegionMake2D(0, 0, videoSize.width, videoSize.height);
                MTLRegion videoRegion = MTLRegionMake2D(0, 0, CVPixelBufferGetWidth(pixelBuffer), CVPixelBufferGetHeight(pixelBuffer));
                [videoTextureMetal replaceRegion:videoRegion mipmapLevel:0 withBytes:pixelBufferBaseAddress bytesPerRow:bytesPerRow];
            }
            else {
                //            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei) videoSize.width, (GLsizei) videoSize.height, 0, GL_BGRA, GL_UNSIGNED_BYTE, pixelBufferBaseAddress); //original
                
                glTexImage2D(GL_TEXTURE_2D,
                             0,
                             GL_RGBA,
                             (GLsizei) CVPixelBufferGetWidth(pixelBuffer),
                             (GLsizei) CVPixelBufferGetHeight(pixelBuffer),
                             0,
                             GL_BGRA,
                             GL_UNSIGNED_BYTE,
                             pixelBufferBaseAddress);//oka
            }
        }
        else {
            NSLog(@"MASA -displayLinkCallback 3-");
            
            // Decoded video contains padding between lines.  We must not
            // upload it to graphics memory as we do not want to display it
            
            if (useMetal) {
                //                for (int i = 0; i < videoSize.height; ++i) {
                //                    unsigned char* line = pixelBufferBaseAddress + i * bytesPerRow;
                //                    MTLRegion lineRegion = MTLRegionMake2D(0, 0, videoSize.width, 1);
                //                    [videoTextureMetal replaceRegion:lineRegion mipmapLevel:0 withBytes:line bytesPerRow:bytesPerRow];
                //                }
                
                
                NSLog(@"MASA -displayLinkCallback 3 useMetal-");
                
                
                
                //これでいけるはずだったが、、、
                //                for (int i = 0; i < CVPixelBufferGetHeight(pixelBuffer); ++i) {
                //                    unsigned char* line = pixelBufferBaseAddress + i * bytesPerRow;
                //                    MTLRegion lineRegion = MTLRegionMake2D(0, 0, videoSize.width, 1);
                //                    [videoTextureMetal replaceRegion:lineRegion mipmapLevel:0 withBytes:line bytesPerRow:bytesPerRow];
                //                }
                
                NSLog(@"MASA -displayLinkCallback 2 useMetal-");
                
                // 試しに上のコードで処理してみる。
                MTLRegion videoRegion = MTLRegionMake2D(0, 0, CVPixelBufferGetWidth(pixelBuffer), CVPixelBufferGetHeight(pixelBuffer));
                [videoTextureMetal replaceRegion:videoRegion mipmapLevel:0 withBytes:pixelBufferBaseAddress bytesPerRow:bytesPerRow];
            }
            else {
                // Allocate storage for the texture (correctly sized)
                //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei) videoSize.width, (GLsizei) videoSize.height, 0, GL_BGRA, GL_UNSIGNED_BYTE, NULL); //original
                
                glTexImage2D(GL_TEXTURE_2D,
                             0,
                             GL_RGBA,
                             (GLsizei) CVPixelBufferGetWidth(pixelBuffer),
                             (GLsizei) CVPixelBufferGetHeight(pixelBuffer),
                             0,
                             GL_BGRA,
                             GL_UNSIGNED_BYTE,
                             NULL);
                
                
                // Now upload each line of texture data as a sub-image
                
                //original
                //            for (int i = 0; i < videoSize.height; ++i) {
                //                GLubyte* line = pixelBufferBaseAddress + i * bytesPerRow;
                //
                //                //textureを上書き
                //                glTexSubImage2D(GL_TEXTURE_2D, 0, 0, i, (GLsizei) videoSize.width, 1, GL_BGRA, GL_UNSIGNED_BYTE, line);
                //            }
                
                //oka
                for (int i = 0; i < CVPixelBufferGetHeight(pixelBuffer); ++i) {
                    GLubyte* line = pixelBufferBaseAddress + i * bytesPerRow;
                    
                    //textureを上書き
                    glTexSubImage2D(GL_TEXTURE_2D,
                                    0,
                                    0,
                                    i,
                                    (GLsizei) CVPixelBufferGetWidth(pixelBuffer),
                                    1,
                                    GL_BGRA,
                                    GL_UNSIGNED_BYTE,
                                    line);
                }
            }
        }
        
        
        if (!useMetal) {
            NSLog(@"MASA -displayLinkCallback !useMetal-");
            
            // Unbind OpenGL texture
            glBindTexture(GL_TEXTURE_2D, 0);
        }
        
        //        glBindTexture(GL_TEXTURE_2D, 0);
        
        // Unlock the buffers
        CVPixelBufferUnlockBaseAddress(pixelBuffer, 0);
        
        NSLog(@"MASA -displayLinkCallback 4-");
        
        textureID = videoTextureIdGL;
        //**** vuforiaで取得しているopenGL適用 end
        
        
        if (pixelBuffer != NULL) {
            CFRelease(pixelBuffer); //メモリ解放
        }
        
        [latestSampleBufferLock unlock];
    } else {
        NSLog(@"MASA -displayLinkCallback -no-");
        NSLog(@"MASA -displayLinkCallback -no- mediaState %u", mediaState);


        
//        if (CMTimeGetSeconds(outputItemTime) > 0 || ((CMTimeGetSeconds(outputItemTime) == 0 || isnan(CMTimeGetSeconds(outputItemTime)) ) && (mediaState == READY || mediaState == PAUSED))) {
//            NSLog(@"MASA -displayLinkCallback -no- seconds > 0");
//
//            if (mediaState == PLAYING || mediaState == READY || mediaState == PAUSED) {
//                cntNoRender = cntNoRender + 1;
//                NSLog(@"MASA -displayLinkCallback -no- count1 %u", cntNoRender);
//            }
//
//            NSLog(@"MASA -displayLinkCallback -no- count2 %u", cntNoRender);
//
//            if ((mediaState == PLAYING || mediaState == READY || mediaState == PAUSED) && cntNoRender > 30) {
//                NSLog(@"MASA -displayLinkCallback -no- stop");
//
//                // 一旦、ビデオはストップ。再度、video読み込む。
//                (void)[self stop];
//                mediaState = NOT_READY;
//                [self loadMediaURL:mediaURL];
//                //[self play:NO fromPosition:VIDEO_PLAYBACK_CURRENT_POSITION];
//            }
//        }

    
    }
    

    
//    - (void)outputMediaDataWillChange:(AVPlayerItemOutput *)sender {
//        if (![self.videoOutput hasNewPixelBufferForItemTime:CMTimeMake(1, 10)]) {
//            [self.displayLink setPaused:YES];
//            [self configVideoOutput];
//        }
//        [self.displayLink setPaused:NO];
//    }

    
    
}


- (void)outputMediaDataWillChange:(AVPlayerItemOutput *)sender {
    NSLog(@"indivestigate:outputMediaDataWillChange");
    
    if (![self.videoOutput hasNewPixelBufferForItemTime:CMTimeMake(1, 10)]) {
        NSLog(@"indivestigate:outputMediaDataWillChange -1-");
        
        [self.displayLink setPaused:YES];
        
        //[self configVideoOutput];
        [self loadMediaURL:mediaURL];
    }
    [self.displayLink setPaused:NO];
}

@end
