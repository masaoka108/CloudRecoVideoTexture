/*===============================================================================
Copyright (c) 2015-2016 PTC Inc. All Rights Reserved.
 
Copyright (c) 2012-2014 Qualcomm Connected Experiences, Inc. All Rights Reserved.
 
Vuforia is a trademark of PTC Inc., registered in the United States and other 
countries.
==============================================================================*/

using UnityEngine;
using Vuforia;
using System.Collections;

/// <summary>
/// The VideoPlaybackBehaviour manages the appearance of a video that can be superimposed on a target.
/// Playback controls are shown on top of it to control the video. 
/// </summary>
public class VideoPlaybackBehaviour : MonoBehaviour
{
    #region PUBLIC_MEMBER_VARIABLES

    /// <summary>
    /// URL of the video, either a path to a local file or a remote address
    /// </summary>
    public string m_path = null;

    /// <summary>
    /// Texture for the play icon
    /// </summary>
    public Texture m_playTexture = null;

    /// <summary>
    /// Texture for the busy icon
    /// </summary>
    public Texture m_busyTexture = null;

    /// <summary>
    /// Texture for the error icon
    /// </summary>
    public Texture m_errorTexture = null;

    /// <summary>
    /// Define whether video should automatically start
    /// </summary>
    public bool m_autoPlay = false;


	public int textureW = 0;
    #endregion // PUBLIC_MEMBER_VARIABLES



    #region PRIVATE_MEMBER_VARIABLES

    private static bool sLoadingLocked = false;

    private VideoPlayerHelper mVideoPlayer = null;
    public bool mIsInited = false;
    private bool mInitInProgess = false;
    private bool mAppPaused = false;

    private Texture2D mVideoTexture = null;

    [SerializeField]
    [HideInInspector]
    private Texture mKeyframeTexture = null;

    private VideoPlayerHelper.MediaType mMediaType =
            VideoPlayerHelper.MediaType.ON_TEXTURE_FULLSCREEN;

    public VideoPlayerHelper.MediaState mCurrentState =
            VideoPlayerHelper.MediaState.NOT_READY;

    private float mSeekPosition = 0.0f;

    private bool isPlayableOnTexture;

    private GameObject mIconPlane = null;
    private bool mIconPlaneActive = false;

    #endregion // PRIVATE_MEMBER_VARIABLES



    #region PROPERTIES

    /// <summary>
    /// Returns the video player
    /// </summary>
    public VideoPlayerHelper VideoPlayer
    {
        get { return mVideoPlayer; }
    }

    /// <summary>
    /// Returns the current playback state
    /// </summary>
    public VideoPlayerHelper.MediaState CurrentState
    {
        get { return mCurrentState; }
    }

    /// <summary>
    /// Type of playback (on-texture only, fullscreen only, or both)
    /// </summary>
    public VideoPlayerHelper.MediaType MediaType
    {
        get { return mMediaType; }
        set { mMediaType = value; }
    }

    /// <summary>
    /// Texture displayed before video playback begins
    /// </summary>
    public Texture KeyframeTexture
    {
        get { return mKeyframeTexture; }
        set { mKeyframeTexture = value; }
    }


    /// <summary>
    /// Returns whether the video should automatically start
    /// </summary>
    public bool AutoPlay
    {
        get { return m_autoPlay; }
    }

    #endregion // PROPERTIES



    #region UNITY_MONOBEHAVIOUR_METHODS

    void Start()
    {
		Debug.Log ("VideoPlaybackBehaviour:Start:0");	

        // Find the icon plane (child of this object)
        mIconPlane = transform.Find("Icon").gameObject;

        // A filename or url must be set in the inspector
        if (m_path == null || m_path.Length == 0)
        {
            Debug.Log("Please set a video url in the Inspector");
            HandleStateChange(VideoPlayerHelper.MediaState.ERROR);
            mCurrentState = VideoPlayerHelper.MediaState.ERROR;
            this.enabled = false;
        }
        else
        {
            // Set the current state to Not Ready
            HandleStateChange(VideoPlayerHelper.MediaState.NOT_READY);
            mCurrentState = VideoPlayerHelper.MediaState.NOT_READY;
        }

		Debug.Log ("VideoPlaybackBehaviour:Start:0");	
		Debug.Log ("VideoPlaybackBehaviour:Start:1");	
		Debug.Log (m_path);

		// Create the video player and set the filename
        mVideoPlayer = new VideoPlayerHelper();
        mVideoPlayer.SetFilename(m_path);

        // Flip the plane as the video texture is mirrored on the horizontal
        transform.localScale = new Vector3(-1 * Mathf.Abs(transform.localScale.x),
                transform.localScale.y, transform.localScale.z);

        // Scale the icon
        ScaleIcon();
    }

//	//oka add
//	void Update()
//	{
//		Debug.Log ("Update:1");	
//
//		// Update the video texture with the latest video frame
//		VideoPlayerHelper.MediaState state = mVideoPlayer.UpdateVideoData();
//
//		if ((state == VideoPlayerHelper.MediaState.PLAYING)
//			|| (state == VideoPlayerHelper.MediaState.PLAYING_FULLSCREEN))
//		{
//			#if UNITY_WSA_10_0 && !UNITY_EDITOR
//			// For Direct3D video texture update, we need to be on the rendering thread
//			GL.IssuePluginEvent(VideoPlayerHelper.GetNativeRenderEventFunc(), 0);
//			#else
//			GL.InvalidateState();
//			#endif
//		}
//
//		// Check for playback state change
//		if (state != mCurrentState)
//		{
//			HandleStateChange(state);
//			mCurrentState = state;
//		}
//	}


	public void setmIsInited()
	{
		mIsInited = false;
	}

//	//画像認識して動画を再生する(多分)
//    void OnRenderObject()
//    {
//		//return;	//@ToDo パフォーマンス テスト
//
//		Debug.Log ("OnRenderObject:0");	
//		Debug.Log ("mAppPaused:" + mAppPaused);	
//
//		//pause だったら何もしない
//		if (mAppPaused) return;
//
//		Debug.Log ("OnRenderObject:0-1");	
//
//		//Iconの表示/非表示を設定。(多分)
//        CheckIconPlaneVisibility();
//
//		Debug.Log ("OnRenderObject:0-2");	
//		Debug.Log ("mIsInited:" + mIsInited);	
//
//        if (!mIsInited)
//        {
//			//Videoの初期設定が出来ていない場合
//
//			Debug.Log ("OnRenderObject:0-3");
//			Debug.Log ("mInitInProgess:" + mInitInProgess);	
//
//			if (!mInitInProgess)
//            {
//				//Videoの初期設定を実行中でないなら、実行する。
//
//				Debug.Log ("OnRenderObject:0-3");
//				Debug.Log ("mInitInProgess:" + mInitInProgess);	
//
//				mInitInProgess = true;
//
//				//ここから展開していく InitVideoPlayer -> LoadVideo -> PrepareVideo
//				StartCoroutine(InitVideoPlayer()); 
//
//				Debug.Log ("OnRenderObject:0-4");
//			}
//
//            return;
//        }
//
//		Debug.Log ("OnRenderObject:1");
//		Debug.Log ("isPlayableOnTexture" + isPlayableOnTexture);
//
////        if (isPlayableOnTexture)
////        {
//
//			Debug.Log ("OnRenderObject:2");
//
//			// Update the video texture with the latest video frame
//            VideoPlayerHelper.MediaState state = mVideoPlayer.UpdateVideoData();
//
//
//		Debug.Log ("UpdateVideoData return:" + state);
//
//			//@ToDo 一旦、ストップは考えないでとりあえず再生する。 2017/7/3 パフォーマンスを考え修正
//			if (state == VideoPlayerHelper.MediaState.PLAYING)
//            {
//				
//			#if UNITY_WSA_10_0 && !UNITY_EDITOR
//                // For Direct3D video texture update, we need to be on the rendering thread
//                GL.IssuePluginEvent(VideoPlayerHelper.GetNativeRenderEventFunc(), 0);
//#else
//				Debug.Log ("GL.InvalidateState()");
//                GL.InvalidateState();
//#endif
//            }
//
//		Debug.Log ("OnRenderObject:state:" + state);
//		Debug.Log ("OnRenderObject:3:" + mCurrentState);
//
//		// Check for playback state change
//            if (state != mCurrentState)
//            {
//
//				//2017/7/3 パフォーマンスを考え修正
//
////				//@ToDo とりあえず強制的に再生させる。
////				Debug.Log ("HandleStateChange:0");
////                //HandleStateChange(state);
////				HandleStateChange(VideoPlayerHelper.MediaState.PLAYING);
////				
////				//@ToDo ここは強制的にPLAYINGにする。
////				Debug.Log ("HandleStateChange:0");
////                //mCurrentState = state;
////				mCurrentState = VideoPlayerHelper.MediaState.PLAYING;
//
//                HandleStateChange(state);
//                mCurrentState = state;
//            }
//
//
//
////        }
////        else
////        {
////            // Get the current status
////            VideoPlayerHelper.MediaState state = mVideoPlayer.GetStatus();
////            if ((state == VideoPlayerHelper.MediaState.PLAYING)
////               || (state == VideoPlayerHelper.MediaState.PLAYING_FULLSCREEN))
////            {
////                GL.InvalidateState();
////            }
////
////            // Check for playback state change
////            if (state != mCurrentState)
////            {
////                HandleStateChange(state);
////                mCurrentState = state;
////            }
////        }
//    }

	public void VideoRender(string url)
	{
		//Iconの表示/非表示を設定。(多分)
		CheckIconPlaneVisibility();

		Debug.Log ("OnRenderObject:0-2");	
		Debug.Log ("mIsInited:" + mIsInited);	

		if (!mIsInited)
		{
			//Videoの初期設定が出来ていない場合

			Debug.Log ("OnRenderObject:0-3");
			Debug.Log ("mInitInProgess:" + mInitInProgess);	

			if (!mInitInProgess)
			{
				//Videoの初期設定を実行中でないなら、実行する。

				Debug.Log ("OnRenderObject:0-3");
				Debug.Log ("mInitInProgess:" + mInitInProgess);	

				mInitInProgess = true;

				//ここから展開していく InitVideoPlayer -> LoadVideo -> PrepareVideo
				StartCoroutine(InitVideoPlayer()); 

				Debug.Log ("OnRenderObject:0-4");
			}

//			while(mIsInited == false && mInitInProgess == false) {
//				Debug.Log ("OnRenderObject:while-1-");
//
//				VideoPlayer.Load (url, VideoPlayerHelper.MediaType.ON_TEXTURE, true, 0);
//
//				Debug.Log ("OnRenderObject:while-2-");
//
//				mInitInProgess = true;
//
//				//ここから展開していく InitVideoPlayer -> LoadVideo -> PrepareVideo
//				StartCoroutine(InitVideoPlayer()); 
//
//				Debug.Log ("OnRenderObject:while-3-");
//			}


			return;
		}

		Debug.Log ("OnRenderObject:1");
		Debug.Log ("isPlayableOnTexture" + isPlayableOnTexture);

		Debug.Log ("OnRenderObject:2");

//		// Update the video texture with the latest video frame
//		VideoPlayerHelper.MediaState state = mVideoPlayer.UpdateVideoData();
//
//
//		Debug.Log ("UpdateVideoData return:" + state);


//		if (state == VideoPlayerHelper.MediaState.PLAYING)
//		{
//			#if UNITY_WSA_10_0 && !UNITY_EDITOR
//			// For Direct3D video texture update, we need to be on the rendering thread
//			GL.IssuePluginEvent(VideoPlayerHelper.GetNativeRenderEventFunc(), 0);
//			#else
//			Debug.Log ("GL.InvalidateState()");
//			GL.InvalidateState();
//			#endif
//		}
//
//		Debug.Log ("OnRenderObject:state:" + state);
//		Debug.Log ("OnRenderObject:3:" + mCurrentState);
//
//		// Check for playback state change
//		if (state != mCurrentState)
//		{
//			HandleStateChange(state);
//			mCurrentState = state;
//		}
	}

//	public IEnumerator WhileStateCheck(VideoPlayerHelper.MediaState state)
//	{
//		while(state == VideoPlayerHelper.MediaState.NOT_READY) {
//			state = mVideoPlayer.UpdateVideoData();
//
//			Debug.Log("WhileStateCheck:-1- : " + state);
//
//			if (state == VideoPlayerHelper.MediaState.NOT_READY) {
//				yield return null; //次のフレームに送る
//			}
//		}
//
//		Debug.Log("WhileStateCheck:-2-");
//
//		yield break; //coroutine 終了(再開なし)
//	}


	public IEnumerator SetState() {

		// Update the video texture with the latest video frame
//		VideoPlayerHelper.MediaState state = mVideoPlayer.UpdateVideoData();
		VideoPlayerHelper.MediaState state = VideoPlayerHelper.MediaState.NOT_READY;


		while(state == VideoPlayerHelper.MediaState.NOT_READY) {
			state = mVideoPlayer.UpdateVideoData();

			Debug.Log("WhileStateCheck:-1- : " + state);

			if (state == VideoPlayerHelper.MediaState.NOT_READY) {
				yield return null; //次のフレームに送る
			}
		}

		state = mVideoPlayer.UpdateVideoData();

		Debug.Log ("SetState:0:" + state + "  mIsInited:" + mIsInited + " mInitInProgess:" + mInitInProgess);

		if (mIsInited == true && mInitInProgess == false && state == VideoPlayerHelper.MediaState.READY) 
		{
			Debug.Log ("SetState:1");
			//Volume 設定
			GameObject refObjTMP = GameObject.Find("TargetMenuPlane");
			TapEvent tapEvent = refObjTMP.GetComponent<TapEvent>();

			Debug.Log("SetState:1.5:" + tapEvent.bVolumeFlg);

			if (tapEvent.bVolumeFlg) {
				this.VideoPlayer.VolumeOn();
			} else {
				this.VideoPlayer.VolumeOff();
			} 

			//native の　play を実行
			this.VideoPlayer.Play(false, 0);	
			Debug.Log ("SetState:2");
			this.HideIcon ();
			Debug.Log ("SetState:3");
			this.CheckIconPlaneVisibility ();
			Debug.Log ("SetState:4");

			//test ここでplayにしちゃう。
			state = VideoPlayerHelper.MediaState.PLAYING;
		}
			
		if (state == VideoPlayerHelper.MediaState.PLAYING)
		{
			#if UNITY_WSA_10_0 && !UNITY_EDITOR
			// For Direct3D video texture update, we need to be on the rendering thread
			GL.IssuePluginEvent(VideoPlayerHelper.GetNativeRenderEventFunc(), 0);
			#else
			Debug.Log ("GL.InvalidateState()");
			GL.InvalidateState();
			#endif
		}

		// ビデオがstopしているのにiconが表示されていない場合は表示
		if (state == VideoPlayerHelper.MediaState.STOPPED || state == VideoPlayerHelper.MediaState.REACHED_END || state == VideoPlayerHelper.MediaState.PAUSED) {
			Debug.Log ("SetState:5");
			ShowPlayIcon ();
		}


		Debug.Log ("OnRenderObject:state:" + state);
		Debug.Log ("OnRenderObject:mCurrentState:" + mCurrentState);

		// Check for playback state change
		if (state != mCurrentState)
		{
			Debug.Log ("SetState:6");
			Debug.Log (state);
			Debug.Log (mCurrentState);

			HandleStateChange(state);
			mCurrentState = state;
		}
	


		GameObject refObj = GameObject.Find("CloudRecoTarget");
		Debug.Log ("SetState:refObj:" + refObj);
		//TrackableEventHandler teh = refObj.GetComponent<TrackableEventHandler>();
		//Debug.Log ("SetState:teh:" + teh);
		//teh.FoundLostUpdate2();

	}









    private IEnumerator InitVideoPlayer()
    {

		//この時点で以前のVideoPlaybackBehaviorとは別インスタンス
//		//今のビデオをストップ
		Debug.Log ("InitVideoPlayer:0");
//		this.VideoPlayer.Stop ();


        // Initialize the video player
//        VuforiaRenderer.RendererAPI rendererAPI = VuforiaRenderer.Instance.GetRendererAPI();
        
//		//このInitでnativeのvideoPlayerInitIOS -> initWithMetalRendering 実行している。
//		if (mVideoPlayer.Init(rendererAPI))
//        {
            yield return new WaitForEndOfFrame();
            
            // Wait in case other videos are loading at the same time
            while (sLoadingLocked)
            {
                yield return new WaitForSeconds(0.5f);
            }

            // Now we can proceed to load the video
            StartCoroutine(LoadVideo());

//        }
//        else
//        {
//            Debug.Log("Could not initialize video player");
//            HandleStateChange(VideoPlayerHelper.MediaState.ERROR);
//            this.enabled = false;
//        }
    }

	//bak20170514
//	private IEnumerator LoadVideo()
//    {
//        // Lock file loading
//        sLoadingLocked = true;
//
//		Debug.Log("mMediaType:" + mMediaType);
//		Debug.Log("m_path:" + m_path);
//
//        // Load the video ここでnativeのloadを呼び出している。
//        if (mVideoPlayer.Load(m_path, mMediaType, false, 0))
//        {
//            yield return new WaitForEndOfFrame();
//
//#if UNITY_WSA_10_0 && !UNITY_EDITOR
//            // On Windows 10 (WSA), we need to wait a little bit after loading a video,
//            // to avoid potential conflicts when loading multiple videos
//            yield return new WaitForSeconds(1.5f);
//#endif
//
//            // Unlock file loading
//            sLoadingLocked = false;
//
//            // Proceed to video preparation
//            StartCoroutine( PrepareVideo() );
//        }
//        else
//        {
//            // Unlock file loading
//            sLoadingLocked = false;
//
//            Debug.Log("Could not load video '" + m_path + "' for media type " + mMediaType);
//            HandleStateChange(VideoPlayerHelper.MediaState.ERROR);
//            this.enabled = false;
//        }
//    } 

	private IEnumerator LoadVideo()
	{
		// Lock file loading
		sLoadingLocked = true;

		Debug.Log("mMediaType:" + mMediaType);
		Debug.Log("m_path:" + m_path);

//		// Load the video ここでnativeのloadを呼び出している。
//		if (mVideoPlayer.Load(m_path, mMediaType, false, 0))
//		{
			yield return new WaitForEndOfFrame();

			#if UNITY_WSA_10_0 && !UNITY_EDITOR
			// On Windows 10 (WSA), we need to wait a little bit after loading a video,
			// to avoid potential conflicts when loading multiple videos
			yield return new WaitForSeconds(1.5f);
			#endif

			// Unlock file loading
			sLoadingLocked = false;

			// Proceed to video preparation
			StartCoroutine( PrepareVideo() );
//		}
//		else
//		{
//			// Unlock file loading
//			sLoadingLocked = false;
//
//			Debug.Log("Could not load video '" + m_path + "' for media type " + mMediaType);
//			HandleStateChange(VideoPlayerHelper.MediaState.ERROR);
//			this.enabled = false;
//		}
	} 


//bak20170502
//    private IEnumerator PrepareVideo()
//    {
//        // Get the video player status
//        VideoPlayerHelper.MediaState state = mVideoPlayer.GetStatus();
//
//        if (state == VideoPlayerHelper.MediaState.ERROR)
//        {
//            Debug.Log("Cannot prepare video, as the player is in error state.");
//            HandleStateChange(VideoPlayerHelper.MediaState.ERROR);
//            this.enabled = false;
//        }
//        else
//        {
//            // Not in error state, we can move on...
//            while (mVideoPlayer.GetStatus() == VideoPlayerHelper.MediaState.NOT_READY)
//            {
//                // Wait one or few frames for video state to become ready
//                yield return new WaitForEndOfFrame();
//            }
//
//            // Video player is ready
//            Debug.Log("VideoPlayer ready.");
//
//            // Initialize the video texture
//            bool isOpenGLRendering = (
//                VuforiaRenderer.Instance.GetRendererAPI() == VuforiaRenderer.RendererAPI.GL_20
//                || VuforiaRenderer.Instance.GetRendererAPI() == VuforiaRenderer.RendererAPI.GL_30);
//			
//            InitVideoTexture(isOpenGLRendering);
//
//            // Can we play this video on a texture?
//            isPlayableOnTexture = mVideoPlayer.IsPlayableOnTexture();
//
//            if (isPlayableOnTexture)
//            {
//                // Pass the video texture id to the video player
//                mVideoPlayer.SetVideoTexturePtr(mVideoTexture.GetNativeTexturePtr());
//
//                // Get the video width and height
//                int videoWidth = mVideoPlayer.GetVideoWidth();
//                int videoHeight = mVideoPlayer.GetVideoHeight();
//
//                if (videoWidth > 0 && videoHeight > 0)
//                {
//                    // Scale the video plane to match the video aspect ratio
//                    float aspect = videoHeight / (float)videoWidth;
//
//                    // Flip the plane as the video texture is mirrored on the horizontal
//                    transform.localScale = new Vector3(-0.1f, 0.1f, 0.1f * aspect);
//                }
//
//                // Seek ahead if necessary
//                if (mSeekPosition > 0)
//                {
//                    mVideoPlayer.SeekTo(mSeekPosition);
//                }
//            }
//            else
//            {
//                // Handle the state change
//                state = mVideoPlayer.GetStatus();
//                HandleStateChange(state);
//                mCurrentState = state;
//            }
//
//            // Scale the icon
//            ScaleIcon();
//            
//            mIsInited = true;
//        }
//
//        mInitInProgess = false;
//        yield return new WaitForEndOfFrame();
//    }

	private IEnumerator PrepareVideo()
	{
		// Get the video player status
		VideoPlayerHelper.MediaState state = mVideoPlayer.GetStatus();

		if (state == VideoPlayerHelper.MediaState.ERROR)
		{
			Debug.Log("Cannot prepare video, as the player is in error state.");
			HandleStateChange(VideoPlayerHelper.MediaState.ERROR);
			this.enabled = false;
		}
		else
		{
			Debug.Log("PrepareVideo-0:mVideoPlayer.GetStatus():" + mVideoPlayer.GetStatus());

			// Not in error state, we can move on...
			//while (mVideoPlayer.GetStatus() == VideoPlayerHelper.MediaState.NOT_READY)
			while (state == VideoPlayerHelper.MediaState.NOT_READY)
			{
				Debug.Log("PrepareVideo-0-1:mVideoPlayer.GetStatus():" + mVideoPlayer.GetStatus());

				state = mVideoPlayer.GetStatus ();

				// Wait one or few frames for video state to become ready
				yield return new WaitForEndOfFrame();
			}
				
			// Video player is ready
			Debug.Log("VideoPlayer ready.");

			// Initialize the video texture
			bool isOpenGLRendering = (
				VuforiaRenderer.Instance.GetRendererAPI() == VuforiaRenderer.RendererAPI.GL_20
				|| VuforiaRenderer.Instance.GetRendererAPI() == VuforiaRenderer.RendererAPI.GL_30);

			//Texture 初期化
			Debug.Log("isOpenGLRendering:" + isOpenGLRendering);
			bool InitTextureRet = InitVideoTexture(isOpenGLRendering);
			if (!InitTextureRet) {
				// textureの準備が出来ていないと判断
				Debug.Log("InitTextureRet:false");
				Debug.Log("InitTextureRet:mIsInited" + mIsInited);
				mInitInProgess = false;
				yield break;
			}

			// Can we play this video on a texture?
			isPlayableOnTexture = mVideoPlayer.IsPlayableOnTexture();

			Debug.Log("isPlayableOnTexture:" + isPlayableOnTexture);

//			if (isPlayableOnTexture)
//			{

				Debug.Log("PrepareVideo1");

				Debug.Log("mVideoTexture.GetNativeTexturePtr():" + mVideoTexture.GetNativeTexturePtr());

				// Pass the video texture id to the video player
				//ここでnativeのsetVideoTexturePtr へアクセス
				mVideoPlayer.SetVideoTexturePtr(mVideoTexture.GetNativeTexturePtr());

				// Get the video width and height
				// nativeへアクセス
				int videoWidth = mVideoPlayer.GetVideoWidth();
				int videoHeight = mVideoPlayer.GetVideoHeight();

				if (videoWidth > 0 && videoHeight > 0)
				{
					// Scale the video plane to match the video aspect ratio
					float aspect = videoHeight / (float)videoWidth;

					// Flip the plane as the video texture is mirrored on the horizontal
					transform.localScale = new Vector3(-0.1f, 0.1f, 0.1f * aspect);
				}

				// Seek ahead if necessary
				if (mSeekPosition > 0)
				{
					mVideoPlayer.SeekTo(mSeekPosition);
				}
//			}
//			else
//			{
//				// Handle the state change
//				state = mVideoPlayer.GetStatus();
//				HandleStateChange(state);
//				mCurrentState = state;
//			}

			// Scale the icon
			ScaleIcon();

			mIsInited = true;
		}

		mInitInProgess = false;
		yield return new WaitForEndOfFrame();

		// okamura add
		StartCoroutine(SetState());

	}

	//oka public を付け足した。
    public void OnApplicationPause(bool pause)
    {
//        mAppPaused = pause;

        if (!mIsInited)
            return;

        if (pause)
        {
//            // Handle pause event natively
//            mVideoPlayer.OnPause();
//
//            // Store the playback position for later
//            mSeekPosition = mVideoPlayer.GetCurrentPosition();
//
//            // Deinit the video
//            mVideoPlayer.Deinit();

            // Reset initialization parameters
            mIsInited = false;
            mInitInProgess = false;

			Debug.Log("OnApplicationPause:mIsInited:" + mIsInited);

            // Set the current state to Not Ready
            HandleStateChange(VideoPlayerHelper.MediaState.NOT_READY);
            mCurrentState = VideoPlayerHelper.MediaState.NOT_READY;
        }
    }


    void OnDestroy()
    {
        // Deinit the video
        mVideoPlayer.Deinit();
    }

    #endregion // UNITY_MONOBEHAVIOUR_METHODS



    #region PUBLIC_METHODS

    /// <summary>
    /// Displays the busy icon on top of the video
    /// </summary>
    public void ShowBusyIcon()
    {
        mIconPlane.GetComponent<Renderer>().material.mainTexture = m_busyTexture;
    }

    /// <summary>
    /// Displays the play icon on top of the video
    /// </summary>
    public void ShowPlayIcon()
    {
        mIconPlane.GetComponent<Renderer>().material.mainTexture = m_playTexture;
		mIconPlaneActive = true;	//oka add 20170510
	}

	//oka add 20170510
	public void HideIcon()
	{
		Debug.Log ("HideIcon -1-");
		mIconPlaneActive = false;	
	}

    #endregion // PUBLIC_METHODS



    #region PRIVATE_METHODS

    // Initialize the video texture
    private bool InitVideoTexture(bool isOpenGLRendering)
    {
        // Create texture whose content will be updated in native plugin code.
        // Note: width and height don't matter and may be zero for OpenGL textures,
        // as we update the texture content via glTexImage;
        // however they MUST be correctly initialized for iOS METAL and D3D textures;
        // similarly, the format must be correctly initialized to 4 bytes (BGRA32) per pixel
        int w = mVideoPlayer.GetVideoWidth();
        int h = mVideoPlayer.GetVideoHeight();

        Debug.Log("InitVideoTexture with size: " + w + " x " + h);

        mVideoTexture = isOpenGLRendering ? 
            new Texture2D(0, 0, TextureFormat.RGB565, false) :
            new Texture2D(w, h, TextureFormat.BGRA32, false);
        mVideoTexture.filterMode = FilterMode.Bilinear;
        mVideoTexture.wrapMode = TextureWrapMode.Clamp;

		textureW = w;

		if (w == 0 && h == 0) {
			return false;
		} else {
			return true;
		}
    }

    // Handle video playback state changes
    private void HandleStateChange(VideoPlayerHelper.MediaState newState)
    {
		Debug.Log("HandleStateChange -1-");

		// If the movie is playing or paused render the video texture
        // Otherwise render the keyframe
        if (newState == VideoPlayerHelper.MediaState.PLAYING ||
            newState == VideoPlayerHelper.MediaState.PAUSED)
        {
			Debug.Log("HandleStateChange -2-");

            Material mat = GetComponent<Renderer>().material;
            mat.mainTexture = mVideoTexture;
            mat.mainTextureScale = new Vector2(1, 1);
        }
        else
        {
			Debug.Log("HandleStateChange -3-");

			if (mKeyframeTexture != null)
            {
                Material mat = GetComponent<Renderer>().material;
                mat.mainTexture = mKeyframeTexture;
                mat.mainTextureScale = new Vector2(1, -1);
            }
        }

        // Display the appropriate icon, or disable if not needed
        switch (newState)
        {
			case VideoPlayerHelper.MediaState.READY:
			case VideoPlayerHelper.MediaState.REACHED_END:
			case VideoPlayerHelper.MediaState.PAUSED:
			case VideoPlayerHelper.MediaState.STOPPED:
				Debug.Log ("HandleStateChange-0-:" + m_playTexture);
                mIconPlane.GetComponent<Renderer>().material.mainTexture = m_playTexture;
                mIconPlaneActive = true;
                break;

            case VideoPlayerHelper.MediaState.NOT_READY:
            case VideoPlayerHelper.MediaState.PLAYING_FULLSCREEN:
                mIconPlane.GetComponent<Renderer>().material.mainTexture = m_busyTexture;
                mIconPlaneActive = true;
                break;

            case VideoPlayerHelper.MediaState.ERROR:
                mIconPlane.GetComponent<Renderer>().material.mainTexture = m_errorTexture;
                mIconPlaneActive = true;
                break;

            default:
                mIconPlaneActive = false;
                break;
        }

//		if (newState == VideoPlayerHelper.MediaState.PAUSED) {
//			//okamura add 
//			this.VideoPlayer.Pause ();
//		}


        if (newState == VideoPlayerHelper.MediaState.PLAYING_FULLSCREEN)
        {
            // Switching to full screen, disable VuforiaBehaviour (only applicable for iOS)
            VuforiaBehaviour.Instance.enabled = false;
        }
        else if (mCurrentState == VideoPlayerHelper.MediaState.PLAYING_FULLSCREEN)
        {
            // Switching away from full screen, enable VuforiaBehaviour (only applicable for iOS)
            VuforiaBehaviour.Instance.enabled = true;
        }
    }

    private void ScaleIcon()
    {
        // Icon should fill 50% of the narrowest side of the video

        float videoWidth = Mathf.Abs(transform.localScale.x);
        float videoHeight = Mathf.Abs(transform.localScale.z);
        float iconWidth, iconHeight;

        if (videoWidth > videoHeight)
        {
            iconWidth = 0.5f * videoHeight / videoWidth;
            iconHeight = 0.5f;
        }
        else
        {
            iconWidth = 0.5f;
            iconHeight = 0.5f * videoWidth / videoHeight;
        }

        mIconPlane.transform.localScale = new Vector3(-iconWidth, 1.0f, iconHeight);
    }


    public void CheckIconPlaneVisibility()
    {
        // If the video object renderer is currently enabled, we might need to toggle the icon plane visibility
        if (GetComponent<Renderer>().enabled)
        {
			Debug.Log("CheckIconPlaneVisibility:1");		

			// Check if the icon plane renderer has to be disabled explicitly in case it was enabled by another script (e.g. TrackableEventHandler)
            Renderer rendererComp = mIconPlane.GetComponent<Renderer>();
            if (rendererComp.enabled != mIconPlaneActive)
                rendererComp.enabled = mIconPlaneActive;

			Debug.Log("CheckIconPlaneVisibility: " + rendererComp.enabled);		
		}
    }

    #endregion // PRIVATE_METHODS
}
