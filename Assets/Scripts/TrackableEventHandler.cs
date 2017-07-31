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

	private VideoPlaybackBehaviour video;
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

        OnTrackingLost();
    }

    void Update()
    {
		//return;	//@ToDo パフォーマンス テスト

//		Debug.Log("TrackableEventHandler:Update-0");

		video.SetState();

//		Debug.Log("TrackableEventHandler:Update-0-1");

		// Pause the video if tracking is lost for more than two seconds
        if (mHasBeenFound && mLostTracking)
        {

			Debug.Log("TrackableEventHandler:Update-1");

			//if (mSecondsSinceLost > 2.0f)
			if (mSecondsSinceLost > 0.01f)
            {
				Debug.Log("TrackableEventHandler:Update-2");

//				VideoPlaybackBehaviour video = GetComponentInChildren<VideoPlaybackBehaviour>();

				Debug.Log("video:" + video);
				Debug.Log("video.CurrentState:" + video.CurrentState);

				if (video != null &&
                    video.CurrentState == VideoPlayerHelper.MediaState.PLAYING)
                {
					Debug.Log("TrackableEventHandler:Update-3");
					video.VideoPlayer.Pause();
                }

                mLostTracking = false;

				// Start finder again if we lost the current trackable
				ObjectTracker objectTracker = TrackerManager.Instance.GetTracker<ObjectTracker>();
				if (objectTracker != null)
				{
					objectTracker.TargetFinder.ClearTrackables(false);
					objectTracker.TargetFinder.StartRecognition();
				}


            }

            mSecondsSinceLost += Time.deltaTime;
        }
    }

    #endregion //MONOBEHAVIOUR_METHODS


    #region PUBLIC_METHODS
    /// <summary>
    /// Implementation of the ITrackableEventHandler function called when the
    /// tracking state changes.
    /// </summary>
    public void OnTrackableStateChanged(
                                    TrackableBehaviour.Status previousStatus,
                                    TrackableBehaviour.Status newStatus)
    {
        if (newStatus == TrackableBehaviour.Status.DETECTED ||
            newStatus == TrackableBehaviour.Status.TRACKED ||
            newStatus == TrackableBehaviour.Status.EXTENDED_TRACKED)
        {
            OnTrackingFound();
        }
        else
        {
            OnTrackingLost();
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


//		// Stop finder since we have now a result, finder will be restarted again when we lose track of the result
//		ObjectTracker objectTracker = TrackerManager.Instance.GetTracker<ObjectTracker>();
//		if (objectTracker != null)
//		{
//			objectTracker.TargetFinder.Stop();
//		}



        // Optionally play the video automatically when the target is found

        VideoPlaybackBehaviour video = GetComponentInChildren<VideoPlaybackBehaviour>();

//		//ToDo とりあえず全部のVideoを止める
//		Debug.Log ("StopOtherVideos:start");
//		StopOtherVideos (video);
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
                    state == VideoPlayerHelper.MediaState.STOPPED)
                {
					Debug.Log("OnTrackingFound:2");

					// Pause other videos before playing this one
                    PauseOtherVideos(video);

                    // Play this video on texture where it left off
                    video.VideoPlayer.Play(false, video.VideoPlayer.GetCurrentPosition());
                }
                else if (state == VideoPlayerHelper.MediaState.REACHED_END)
                {
					Debug.Log("OnTrackingFound:3");

					// Pause other videos before playing this one
                    PauseOtherVideos(video);

                    // Play this video from the beginning
                    video.VideoPlayer.Play(false, 0);
                }
//            }
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
