/*============================================================================== 
 * Copyright (c) 2012-2015 Qualcomm Connected Experiences, Inc. All Rights Reserved. 
 * ==============================================================================*/
using UnityEngine;
using Vuforia;

/// <summary>
/// A custom handler that implements the ITrackableEventHandler interface.
/// </summary>
public class TrackableEventHandler : MonoBehaviour, ITrackableEventHandler
{
    #region PRIVATE_MEMBERS
    private TrackableBehaviour mTrackableBehaviour;
    private bool mHasBeenFound = false;
    private bool mLostTracking;
    private float mSecondsSinceLost;
	private CloudRecoEventHandler CREH;

	public GameObject MessageUI_err;
	public GameObject CloudRecognition;

	public VideoPlaybackBehaviour video;
    #endregion // PRIVATE_MEMBERS


    #region MONOBEHAVIOUR_METHODS
    void Start()
    {
		video = GetComponentInChildren<VideoPlaybackBehaviour>();

        mTrackableBehaviour = GetComponent<TrackableBehaviour>();
        if (mTrackableBehaviour)
        {
            mTrackableBehaviour.RegisterTrackableEventHandler(this);
        }

		Debug.Log("TrackableEventHandler:Start-0-:aaaaaaaaaaaaaaaa");

//		//とりあえず MessageUI_err を保存しておいて非表示とする。
//		MessageUI_err = GameObject.Find ("MessageUI_err");
//
//		Debug.Log("TrackableEventHandler:Start-1-:" + MessageUI_err);
//
//		//MessageUI_err.SetActive (false);
//
//		Debug.Log("TrackableEventHandler:Start-2-:" + MessageUI_err);

		CREH = CloudRecognition.GetComponent<CloudRecoEventHandler> ();

		Debug.Log ("TrackableEventHandler:Start -1-");
		Debug.Log (CREH);

        OnTrackingLost();
    }

	void Update()
	{
		if (video.CurrentState == VideoPlayerHelper.MediaState.PLAYING) {
			Debug.Log("TrackableEventHandler:Update:-1-");

			VideoPlayerHelper.MediaState state = video.VideoPlayer.GetStatus();
			if (state == VideoPlayerHelper.MediaState.ERROR)
			{
				Debug.Log("TrackableEventHandler:Update:-2-");
				Debug.Log("TrackableEventHandler:Update:-2.5-:" + MessageUI_err);

				if (MessageUI_err != null && MessageUI_err.active == false) {
					Debug.Log("TrackableEventHandler:Update:-3-");
					MessageUI_err.SetActive (true);
				}
			}
		}
	}

//    void Update()
//    {
//		//return;	//@ToDo パフォーマンス テスト
//
//		Debug.Log("TrackableEventHandler:Update-0");
//
//		video.SetState();
//
//
//		// Pause the video if tracking is lost for more than two seconds
//        if (mHasBeenFound && mLostTracking)
//        {
//
//			Debug.Log("TrackableEventHandler:Update-1");
//
//			//if (mSecondsSinceLost > 2.0f)
//			if (mSecondsSinceLost > 0.01f)
//            {
//				Debug.Log("TrackableEventHandler:Update-2");
//				Debug.Log("video:" + video);
//				Debug.Log("video.CurrentState:" + video.CurrentState);
//
//				if (video != null)
//				{
//					Debug.Log("TrackableEventHandler:Update-3");
//					video.VideoPlayer.Pause();
//				}
//
//                mLostTracking = false;
//
//				// Start finder again if we lost the current trackable
//				ObjectTracker objectTracker = TrackerManager.Instance.GetTracker<ObjectTracker>();
//				if (objectTracker != null)
//				{
//					objectTracker.TargetFinder.ClearTrackables(false);
//					objectTracker.TargetFinder.StartRecognition();
//				}
//			}
//
//            mSecondsSinceLost += Time.deltaTime;
//        }
//    }

    #endregion //MONOBEHAVIOUR_METHODS

	public void FoundLostUpdate()
	{
		//return;	//@ToDo パフォーマンス テスト

		Debug.Log("TrackableEventHandler:FoundLostUpdate-0");

		StartCoroutine(video.SetState());


//		// Pause the video if tracking is lost for more than two seconds
//		if (mHasBeenFound && mLostTracking)
//		{
//
//			Debug.Log("TrackableEventHandler:FoundLostUpdate-1");
//
//			//if (mSecondsSinceLost > 2.0f)
//			if (mSecondsSinceLost > 0.01f)
//			{
//				Debug.Log("TrackableEventHandler:FoundLostUpdate-2");
//				Debug.Log("video:" + video);
//				Debug.Log("video.CurrentState:" + video.CurrentState);
//
//				if (video != null)
//				{
//					Debug.Log("TrackableEventHandler:FoundLostUpdate-3");
//					video.VideoPlayer.Pause();
//				}
//
//				mLostTracking = false;
//
//				// Start finder again if we lost the current trackable
//				ObjectTracker objectTracker = TrackerManager.Instance.GetTracker<ObjectTracker>();
//				if (objectTracker != null)
//				{
//					objectTracker.TargetFinder.ClearTrackables(false);
//					objectTracker.TargetFinder.StartRecognition();
//				}
//			}
//
//			mSecondsSinceLost += Time.deltaTime;
//		}
	}

	public void FoundLostUpdate2 () {
	
//		// Pause the video if tracking is lost for more than two seconds
//		if (mHasBeenFound && mLostTracking)
//		{
//
//			Debug.Log("TrackableEventHandler:FoundLostUpdate-1");
//
//			if (mLostTracking) {
//				//if (mSecondsSinceLost > 2.0f)
//				//			if (mSecondsSinceLost > 0.01f)
//				//			{
//				Debug.Log("TrackableEventHandler:FoundLostUpdate-2");
//				Debug.Log("video:" + video);
//				Debug.Log("video.CurrentState:" + video.CurrentState);
//
//				if (video != null)
//				{
//					Debug.Log("TrackableEventHandler:FoundLostUpdate-3");
//					video.VideoPlayer.Pause();
//				}
//
//				mLostTracking = false;
//
//				// Start finder again if we lost the current trackable
//				ObjectTracker objectTracker = TrackerManager.Instance.GetTracker<ObjectTracker>();
//				if (objectTracker != null)
//				{
//					objectTracker.TargetFinder.ClearTrackables(false);
//					objectTracker.TargetFinder.StartRecognition();
//				}
//				//			}
//			}
//
//
//			mSecondsSinceLost += Time.deltaTime;
//		}	
	}


//	public void CallbackFoundLostUpdate (string statusStr) {
//		Debug.Log("CallbackFoundLostUpdate:-1");
//		FoundLostUpdate ();
//	}
		

    #region PUBLIC_METHODS
    /// <summary>
    /// Implementation of the ITrackableEventHandler function called when the
    /// tracking state changes.
    /// </summary>
    public void OnTrackableStateChanged(
                                    TrackableBehaviour.Status previousStatus,
                                    TrackableBehaviour.Status newStatus)
    {
		Debug.Log ("OnTrackableStateChanged -1- :" + newStatus);
		Debug.Log ("OnTrackableStateChanged -2- :" + previousStatus);

		if (newStatus == TrackableBehaviour.Status.DETECTED ||
            newStatus == TrackableBehaviour.Status.TRACKED ||
            newStatus == TrackableBehaviour.Status.EXTENDED_TRACKED)
        {
            OnTrackingFound();
        }
        else
        {
			//前後どちらからUNKNOWNの場合は処理なし、とする。
			if (previousStatus == TrackableBehaviour.Status.UNKNOWN ||
			    newStatus == TrackableBehaviour.Status.UNKNOWN) {
			} else {
				OnTrackingLost();
			}
        }
    }
    #endregion //PUBLIC_METHODS


    #region PRIVATE_METHODS
    private void OnTrackingFound()
    {
        Renderer[] rendererComponents = GetComponentsInChildren<Renderer>();
        Collider[] colliderComponents = GetComponentsInChildren<Collider>();

        // Enable rendering:
        foreach (Renderer component in rendererComponents)
        {
            component.enabled = true;
        }

        // Enable colliders:
        foreach (Collider component in colliderComponents)
        {
            component.enabled = true;
        }

		Debug.Log("OnTrackingFound:0-0");
        Debug.Log("Trackable " + mTrackableBehaviour.TrackableName + " found");


		// Stop finder since we have now a result, finder will be restarted again when we lose track of the result
		ObjectTracker objectTracker = TrackerManager.Instance.GetTracker<ObjectTracker>();
		if (objectTracker != null)
		{
			objectTracker.TargetFinder.Stop();
		}


        // Optionally play the video automatically when the target is found

        VideoPlaybackBehaviour video = GetComponentInChildren<VideoPlaybackBehaviour>();


//		//ToDo とりあえず全部のVideoを止める
//		Debug.Log ("StopOtherVideos:start");
		//		PauseOtherVideos (video);
//

// 
//
//		if (video != null && video.AutoPlay)
		if (video != null)
        {
			Debug.Log("OnTrackingFound:0");

//            if (video.VideoPlayer.IsPlayableOnTexture())
//            {
				Debug.Log("OnTrackingFound:1");

				VideoPlayerHelper.MediaState state = video.VideoPlayer.GetStatus();
			if (state == VideoPlayerHelper.MediaState.PAUSED ||
			                 state == VideoPlayerHelper.MediaState.READY ||
			                 state == VideoPlayerHelper.MediaState.STOPPED) {
				Debug.Log ("OnTrackingFound:2");

				// Pause other videos before playing this one
				PauseOtherVideos (video);

				Debug.Log ("OnTrackingFound:video.VideoPlayer.GetCurrentPosition();" + video.VideoPlayer.GetCurrentPosition ());

				// Play this video on texture where it left off
				video.VideoPlayer.Play (false, video.VideoPlayer.GetCurrentPosition ());

				// アイコン非表示
				video.HideIcon();
				video.CheckIconPlaneVisibility();

			} else if (state == VideoPlayerHelper.MediaState.REACHED_END) {
				Debug.Log ("OnTrackingFound:3");

				// Pause other videos before playing this one
				PauseOtherVideos (video);

				// Play this video from the beginning
				video.VideoPlayer.Play (false, 0);
			} else {
				Debug.Log ("OnTrackingFound:3.1");
				Debug.Log (state);

//				video.mCurrentState = VideoPlayerHelper.MediaState.PLAYING;

//				// Play this video on texture where it left off
//				video.VideoPlayer.Play (false, video.VideoPlayer.GetCurrentPosition ());
			}
//            }


			//******** メニューを表示
			GameObject TargetMenuPlane = GameObject.Find ("TargetMenuPlane");
			TapEvent tap = TargetMenuPlane.GetComponent<TapEvent> ();

			//Rec中で無ければメニューを表示
			GameObject Utility = GameObject.Find ("Utility");
			ScreenshotController ssc = Utility.GetComponent<ScreenshotController> ();

			if (ssc.recording == false) {
				tap.MessageUI_menu.SetActive (true);
			}

			Debug.Log("OnTrackingFound:3.5");

			//******** 認識時は自動再生させる仕様とするので、アイコンはここで絶対非表示とする。
			//video.HideIcon();

//			//******** カウントアップ
//			CREH.CountUpReplay();

			Debug.Log("OnTrackingFound:4");

        }

        mHasBeenFound = true;
        mLostTracking = false;
    }

    private void OnTrackingLost()
    {
        Renderer[] rendererComponents = GetComponentsInChildren<Renderer>();
        Collider[] colliderComponents = GetComponentsInChildren<Collider>();

        // Disable rendering:
        foreach (Renderer component in rendererComponents)
        {
            component.enabled = false;
        }

        // Disable colliders:
        foreach (Collider component in colliderComponents)
        {
            component.enabled = false;
        }

		Debug.Log("OnTrackingLost:0");
        Debug.Log("Trackable " + mTrackableBehaviour.TrackableName + " lost");


//		// Start finder again if we lost the current trackable
//		ObjectTracker objectTracker = TrackerManager.Instance.GetTracker<ObjectTracker>();
//		if (objectTracker != null)
//		{
//			objectTracker.TargetFinder.ClearTrackables(false);
//			objectTracker.TargetFinder.StartRecognition();
//		}


        mLostTracking = true;
        mSecondsSinceLost = 0;

		//okamura add 
		PauseOtherVideos (video);
		video.VideoPlayer.Pause();

		Debug.Log("OnTrackingLost:video.mCurrentState:1");
		Debug.Log(video.mCurrentState);

		// Start finder again if we lost the current trackable
		ObjectTracker objectTracker = TrackerManager.Instance.GetTracker<ObjectTracker>();
		if (objectTracker != null)
		{
			//objectTracker.TargetFinder.ClearTrackables(false);
			objectTracker.TargetFinder.StartRecognition();
		}

		//メニュー非表示
		GameObject TargetMenuPlane = GameObject.Find ("TargetMenuPlane");
		TapEvent tap = TargetMenuPlane.GetComponent<TapEvent> ();
		tap.MessageUI_menu.SetActive (false);


		//FoundLostUpdate okamura add
		FoundLostUpdate();

		Debug.Log("OnTrackingLost:video.mCurrentState:2");
		Debug.Log(video.mCurrentState);
    }

    // Pause all videos except this one
	private void PauseOtherVideos(VideoPlaybackBehaviour currentVideo)
    {
        VideoPlaybackBehaviour[] videos = (VideoPlaybackBehaviour[])
                FindObjectsOfType(typeof(VideoPlaybackBehaviour));

        foreach (VideoPlaybackBehaviour video in videos)
        {
            if (video != currentVideo)
            {
                if (video.CurrentState == VideoPlayerHelper.MediaState.PLAYING)
                {
                    //video.VideoPlayer.Pause();
					video.VideoPlayer.Stop();
                }
            }
        }
    }

//	private void StopOtherVideos(VideoPlaybackBehaviour currentVideo)
//	{
//		VideoPlaybackBehaviour[] videos = (VideoPlaybackBehaviour[])
//			FindObjectsOfType(typeof(VideoPlaybackBehaviour));
//
//		foreach (VideoPlaybackBehaviour video in videos)
//		{
//			Debug.Log("StopOtherVideos");
////			if (video != currentVideo)
////			{
////				if (video.CurrentState == VideoPlayerHelper.MediaState.PLAYING)
////				{
//					video.VideoPlayer.Stop();
////				}
////			}
//		}
//	}

	#endregion //PRIVATE_METHODS
}
