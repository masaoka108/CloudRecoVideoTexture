/*===============================================================================
Copyright (c) 2015 PTC Inc. All Rights Reserved.

Copyright (c) 2012-2015 Qualcomm Connected Experiences, Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other
countries.
==============================================================================*/

#import <AVFoundation/AVFoundation.h>
#import <MediaPlayer/MediaPlayer.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#import <Metal/Metal.h>

//void    UnitySendMessage(const char* obj, const char* method, const char* msg);

// #import <AVFoundation/AVFoundation.h>
// #import <MediaPlayer/MediaPlayer.h>
// #import <OpenGLES/EAGL.h>
// #import <OpenGLES/ES1/gl.h>
// #import <OpenGLES/ES1/glext.h>
// #import <OpenGLES/ES2/gl.h>
// #import <OpenGLES/ES2/glext.h>
//

@class VideoPlaybackViewController;

//
//@protocol AVPlayerItemOutputPullDelegate <NSObject>
//@optional
//- (void)outputMediaDataWillChange:(AVPlayerItemOutput *)sender;
//
////-(void)outputMediaDataWillChange:(id)arg1;
////-(void)outputSequenceWasFlushed:(id)arg1;
////
//@end



// Media types
typedef enum tagMEDIA_TYPE {
    ON_TEXTURE,
    FULLSCREEN,
    ON_TEXTURE_FULLSCREEN
} MEDIA_TYPE;

// Media states
typedef enum tagMEDIA_STATE {
    REACHED_END         = 0,
    PAUSED              = 1,
    STOPPED             = 2,
    PLAYING             = 3,
    READY               = 4,
    NOT_READY           = 5,
    ERROR               = 6,
    PLAYING_FULLSCREEN  = 7
} MEDIA_STATE;


// Used to specify that playback should start from the current position when
// calling the load and play methods
static const float VIDEO_PLAYBACK_CURRENT_POSITION = -1.0f;

// Use our own view controller instead of MPMoviePlayerViewController so we can
// control its behaviour exactly as we want it
@interface MovieViewController : UIViewController<AVPlayerItemOutputPullDelegate>
{
    BOOL volumeFlg;
}
//@property (nonatomic, readonly) MPMoviePlayerController* moviePlayer;

-(BOOL) volumeFlg;
-(void) setVolumeFlg:(BOOL)value;

@end


//@interface NSObject:AVPlayerItemOutputPullDelegate {
//@private
//    int cntNoRender;
//}
//@end




@interface VideoPlayerHelper : NSObject <AVPlayerItemOutputPullDelegate> {

    dispatch_queue_t outputQueue;

@private
    int cntNoRender;
    int cntNoRenderReady;
    int cntRestartVideo;
    bool resetFlg;
    bool restartFlg;

    VideoPlaybackViewController *rootViewController;
    
    BOOL useMetal;
    NSBundle *metalBundle;

    // AVPlayer
    AVPlayer* player;
    CMTime playerCursorStartPosition;

//    // Native playback(default)
//    MPMoviePlayerController* moviePlayer;
//    BOOL resumeOnTexturePlayback;
    //okamura add 4/22 start
    // Native playback
    MovieViewController* movieViewController;
    BOOL resumeOnTexturePlayback;
    //okamura add 4/22 end

    
    
    // Timing
    CFTimeInterval mediaStartTime;
    CFTimeInterval playerCursorPosition;
    NSTimer* frameTimer;
    BOOL stopFrameTimer;

    // Asset
    NSURL* mediaURL;
    AVAssetReader* assetReader;
    AVAssetReaderTrackOutput* assetReaderTrackOutputVideo;
    //AVURLAsset *asset;
    AVAsset *asset;
    BOOL seekRequested;
    float requestedCursorPosition;
    BOOL localFile;
    BOOL playImmediately;

    // Requested video type
    MEDIA_TYPE videoType;

    // Playback status
    MEDIA_STATE mediaState;

    BOOL volumeFlg;
    
    // Class data lock
    NSLock* dataLock;

    // Sample and pixel buffers for video frames
    CMSampleBufferRef latestSampleBuffer;
    CMSampleBufferRef currentSampleBuffer;
    NSLock* latestSampleBufferLock;

    // Video properties
    CGSize videoSize;
    Float64 videoLengthSeconds;
    float videoFrameRate;
    BOOL playVideo;


    // Audio properties
    float currentVolume;
    BOOL playAudio;

    // OpenGL / Metal data
    GLuint videoTextureIdGL;
    id<MTLTexture> videoTextureMetal;
    id<MTLDevice> metalDevice;
    Class MTLTextureDescriptorClass;

    GLuint textureID;
    
    // Audio/video synchronisation state
    enum tagSyncState {
        SYNC_DEFAULT,
        SYNC_READY,
        SYNC_AHEAD,
        SYNC_BEHIND
    } syncStatus;

    // Media player type
    enum tagPLAYER_TYPE {
        PLAYER_TYPE_ON_TEXTURE,
        PLAYER_TYPE_NATIVE
    } playerType;

}

@property (nonatomic, retain) AVPlayerItemVideoOutput *videoOutput;
@property(nonatomic, weak)AVPlayerItemOutput <AVPlayerItemOutputPullDelegate>* delegate;

- (id)initWithMetalRendering:(BOOL)isMetalRendering;
- (void)deinit;
- (BOOL)load:(NSString*)filename mediaType:(MEDIA_TYPE)requestedType playImmediately:(BOOL)playOnTextureImmediately fromPosition:(float)seekPosition;
- (BOOL)unload;
- (BOOL)isPlayableOnTexture;
- (BOOL)isPlayableFullscreen;
- (MEDIA_STATE)getStatus;
- (BOOL)VolumeOn;
- (BOOL)VolumeOff;
- (int)getVideoHeight;
- (int)getVideoWidth;
- (float)getLength;
- (BOOL)play:(BOOL)fullscreen fromPosition:(float)seekPosition;
- (BOOL)pause;
- (BOOL)stop;
- (GLuint)updateVideoData;
- (BOOL)seekTo:(float)position;
- (float)getCurrentPosition;
- (BOOL)setVolume:(float)volume;
- (BOOL)setVideoTexturePtr:(void*)texturePtr;
- (void)onPause;
//- (void)outputMediaDataWillChange;
//- (void)outputMediaDataWillChange:(AVPlayerItemOutput *)sender;

@end


