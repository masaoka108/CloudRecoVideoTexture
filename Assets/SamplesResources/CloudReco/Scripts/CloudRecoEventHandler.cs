/*===============================================================================
Copyright (c) 2015-2016 PTC Inc. All Rights Reserved.
 
Copyright (c) 2012-2015 Qualcomm Connected Experiences, Inc. All Rights Reserved.
 
Vuforia is a trademark of PTC Inc., registered in the United States and other 
countries.
===============================================================================*/
using System;
using UnityEngine;
using Vuforia;
using System.Collections;

//using Newtonsoft.Json;
//using Newtonsoft.Json.Linq;

/// <summary>
/// This MonoBehaviour implements the Cloud Reco Event handling for this sample.
/// It registers itself at the CloudRecoBehaviour and is notified of new search results as well as error messages
/// The current state is visualized and new results are enabled using the TargetFinder API.
/// </summary>
public class CloudRecoEventHandler : MonoBehaviour, ICloudRecoEventHandler
{
    #region PRIVATE_MEMBERS
    // ObjectTracker reference to avoid lookups
    private ObjectTracker mObjectTracker;
    private ContentManager mContentManager;
    private TrackableSettings mTrackableSettings;
    private bool mMustRestartApp = false;

    // the parent gameobject of the referenced ImageTargetTemplate - reused for all target search results
    private GameObject mParentOfImageTargetTemplate;
    #endregion // PRIVATE_MEMBERS


    #region PUBLIC_MEMBERS
    /// <summary>
    /// Can be set in the Unity inspector to reference a ImageTargetBehaviour that is used for augmentations of new cloud reco results.
    /// </summary>
    public ImageTargetBehaviour ImageTargetTemplate;
    /// <summary>
    /// The scan-line rendered in overlay when Cloud Reco is in scanning mode.
    /// </summary>
    public ScanLine scanLine;
    /// <summary>
    /// Cloud Reco error UI elements.
    /// </summary>
    public Canvas cloudErrorCanvas;
    public UnityEngine.UI.Text cloudErrorTitle;
    public UnityEngine.UI.Text cloudErrorText;
    #endregion //PUBLIC_MEMBERS


    #region MONOBEHAVIOUR_METHODS
    /// <summary>
    /// register for events at the CloudRecoBehaviour
    /// </summary>
    void Start()
    {
        mTrackableSettings = FindObjectOfType<TrackableSettings>();

        // look up the gameobject containing the ImageTargetTemplate:
        mParentOfImageTargetTemplate = ImageTargetTemplate.gameObject;

        // register this event handler at the cloud reco behaviour
        CloudRecoBehaviour cloudRecoBehaviour = GetComponent<CloudRecoBehaviour>();
        if (cloudRecoBehaviour)
        {
            cloudRecoBehaviour.RegisterEventHandler(this);
        }
    }
    #endregion //MONOBEHAVIOUR_METHODS


    #region ICloudRecoEventHandler_implementation
    /// <summary>
    /// Called when TargetFinder has been initialized successfully
    /// </summary>
    public void OnInitialized()
    {
        Debug.Log("Cloud Reco initialized successfully.");

        // get a reference to the Object Tracker, remember it
        mObjectTracker = TrackerManager.Instance.GetTracker<ObjectTracker>();
        mContentManager = FindObjectOfType<ContentManager>();
    }

    /// <summary>
    /// Called if Cloud Reco initialization fails
    /// </summary>
    public void OnInitError(TargetFinder.InitState initError)
    {
        Debug.Log("Cloud Reco initialization error: " + initError.ToString());
        switch (initError)
        {
            case TargetFinder.InitState.INIT_ERROR_NO_NETWORK_CONNECTION:
                {
                    mMustRestartApp = true;
                    ShowError("Network Unavailable", "Please check your internet connection and try again.");
                    break;
                }
            case TargetFinder.InitState.INIT_ERROR_SERVICE_NOT_AVAILABLE:
                ShowError("Service Unavailable", "Failed to initialize app because the service is not available.");
                break;
        }
    }
    
    /// <summary>
    /// Called if a Cloud Reco update error occurs
    /// </summary>
    public void OnUpdateError(TargetFinder.UpdateState updateError)
    {
        Debug.Log("Cloud Reco update error: " + updateError.ToString());
        switch (updateError)
        {
            case TargetFinder.UpdateState.UPDATE_ERROR_AUTHORIZATION_FAILED:
                ShowError("Authorization Error", "The cloud recognition service access keys are incorrect or have expired.");
                break;
            case TargetFinder.UpdateState.UPDATE_ERROR_NO_NETWORK_CONNECTION:
                ShowError("Network Unavailable", "Please check your internet connection and try again.");
                break;
            case TargetFinder.UpdateState.UPDATE_ERROR_PROJECT_SUSPENDED:
                ShowError("Authorization Error", "The cloud recognition service has been suspended.");
                break;
            case TargetFinder.UpdateState.UPDATE_ERROR_REQUEST_TIMEOUT:
                ShowError("Request Timeout", "The network request has timed out, please check your internet connection and try again.");
                break;
            case TargetFinder.UpdateState.UPDATE_ERROR_SERVICE_NOT_AVAILABLE:
                ShowError("Service Unavailable", "The service is unavailable, please try again later.");
                break;
            case TargetFinder.UpdateState.UPDATE_ERROR_TIMESTAMP_OUT_OF_RANGE:
                ShowError("Clock Sync Error", "Please update the date and time and try again.");
                break;
            case TargetFinder.UpdateState.UPDATE_ERROR_UPDATE_SDK:
                ShowError("Unsupported Version", "The application is using an unsupported version of Vuforia.");
                break;
        }
    }

    /// <summary>
    /// when we start scanning, unregister Trackable from the ImageTargetTemplate, then delete all trackables
    /// </summary>
    public void OnStateChanged(bool scanning)
    {
        if (scanning)
        {
            // clear all known trackables
            mObjectTracker.TargetFinder.ClearTrackables(false);

            // hide the ImageTargetTemplate
            mContentManager.ShowObject(false);
        }

        //ShowScanLine(scanning);
    }

	[Serializable]
	class CloudMetaData
	{
		public string  title;
		public string  url;
	}
		
	public IEnumerator timeStop(){

		Debug.Log("timeStop:start");
		yield return new WaitForSeconds(3);
		Debug.Log("5秒経ちました");

	}

	public void OnNewSearchResult(TargetFinder.TargetSearchResult targetSearchResult)
	{
		//targetを発見したら画像認識機能をStop
		mObjectTracker.TargetFinder.Stop ();


		//video表示エフェクト particle systemを表示
		GameObject Particle_video = GameObject.Find("Particle_video");
		Debug.Log ("Particle_video:" + Particle_video);

//		ParticleSystem PS = Particle_video.GetComponent<ParticleSystem> ();
//		PS.Play ();

		GameObject SimpleFlame2 = GameObject.Find("SimpleFlame2(Green)");
		ParticleSystem PS = SimpleFlame2.GetComponent<ParticleSystem> ();
		PS.Play ();



		//HLARのdbカウントアップ APIへアクセス(制限回数を超えていたらターゲットをinactiveに更新)
		Debug.Log("targetSearchResult.UniqueTargetId: " + targetSearchResult.UniqueTargetId);
//		StartCoroutine (CountUp (targetSearchResult.UniqueTargetId));
		CountUp (targetSearchResult.UniqueTargetId);


		VideoPlaybackBehaviour video = ImageTargetTemplate.gameObject.GetComponentInChildren<VideoPlaybackBehaviour>();

		var targetMenuURL = "";

		if(targetSearchResult.MetaData == null){
			return;
		} else {
//			VideoPlaybackBehaviour video = ImageTargetTemplate.gameObject.GetComponentInChildren<VideoPlaybackBehaviour>();

			VuforiaRenderer.RendererAPI rendererAPI = VuforiaRenderer.Instance.GetRendererAPI();

			//nativeの initWithMetalRendering へアクセス
			if (video.VideoPlayer.Init (rendererAPI)) {
			} else {
				Debug.Log ("video.VideoPlayer.Init false");
			}

			//新しいVideoを再生するのでinitフラグをfalseにするなど操作。okamura 2017/5/14
//			video.VideoPlayer.Pause ();			//video をpause
			PauseOtherVideos (video);			//video 以外のものをpauseする
			video.OnApplicationPause (true);	//init flgなどの制御

			//StartCoroutine("timeStop");	//時間を停止させる

			Debug.Log ("targetSearchResult.MetaData" + targetSearchResult.MetaData);

			var data2 = JsonUtility.FromJson<CloudMetaData> (targetSearchResult.MetaData);

			Debug.Log("We got a target metadata title: " + data2.title);
			Debug.Log("We got a target metadata url: " + data2.url);
			targetMenuURL = data2.url; 
			video.m_path = data2.url;

			if(video != null) {
				Debug.Log("Unload:0");
				video.VideoPlayer.Unload();

				//ここでVideoPlayerHelper.mm のload にアクセスしている。
				if (video.VideoPlayer.Load (data2.url, VideoPlayerHelper.MediaType.ON_TEXTURE, true, 0) == false) {
					Debug.Log ("fail from title......");
				} else {
					Debug.Log ("success from title......!!!");
				}
			}
		}

		// First clear all trackables
		mObjectTracker.TargetFinder.ClearTrackables(false);

		// enable the new result with the same ImageTargetBehaviour:
		ImageTargetBehaviour imageTargetBehaviour = mObjectTracker.TargetFinder.EnableTracking(targetSearchResult, mParentOfImageTargetTemplate) as ImageTargetBehaviour;





		//20170704 okamura add
		video.VideoRender();

		// ターゲットのメニューを設定
		//ターゲット メニューボタンのURLを設定
		GameObject TargetMenuPlane = GameObject.Find("TargetMenuPlane");
		Debug.Log ("TargetMenuPlane:" + TargetMenuPlane);
		TapEvent tap = TargetMenuPlane.GetComponent<TapEvent> ();
		tap.targetURL = targetMenuURL;	//@ToDo 今、動画のURLとなっているのでそれぞれの誘導URLへ変更

		//ターゲットメニュー はメイン以外は初期は非表示
		GameObject www_icon = GameObject.Find("www_icon");
		GameObject fullscreen_icon = GameObject.Find("fullscreen_icon");
		GameObject twitter_icon = GameObject.Find("twitter_icon");
		GameObject fb_icon = GameObject.Find("fb_icon");
		//GameObject insta_icon = GameObject.Find("insta_icon");

		showHideGameObject (www_icon);
		showHideGameObject (fullscreen_icon);
		showHideGameObject (twitter_icon);
		showHideGameObject (fb_icon);
		//showHideGameObject (insta_icon);




		//if extended tracking was enabled from the menu, we need to start the extendedtracking on the newly found trackble.
//		if (mTrackableSettings && mTrackableSettings.IsExtendedTrackingEnabled()) {
//			imageTargetBehaviour.ImageTarget.StartExtendedTracking();
//		}
	}


	//bak
//	public void OnNewSearchResult(TargetFinder.TargetSearchResult targetSearchResult)
//	{
//		if(targetSearchResult.MetaData == null){
//			return;
//		} else {
//			//no neccesory to apply SerializeObject here...
//			string output = JsonConvert.SerializeObject (targetSearchResult.MetaData);
//
//			JObject dict = JsonConvert.DeserializeObject<JObject> (targetSearchResult.MetaData);
//			Debug.Log("We got a target metadata title: " + dict["title"]);
//			Debug.Log("We got a target metadata url: " + dict["url"]);
//			VideoPlaybackBehaviour video = ImageTargetTemplate.gameObject.GetComponentInChildren<VideoPlaybackBehaviour>();
//
//			if(video != null) {
//				video.VideoPlayer.Unload();
//				if(video.VideoPlayer.Load((string) dict["title"], VideoPlayerHelper.MediaType.ON_TEXTURE, false, 0) == false) {
//					Debug.Log ("fail from title......");
//					if (video.VideoPlayer.Load ((string)dict ["url"], VideoPlayerHelper.MediaType.ON_TEXTURE, false, 0) == false) {
//						Debug.Log ("fail from url......");
//					}
//				}
//			}
//		}
//
//		// First clear all trackables
//		mObjectTracker.TargetFinder.ClearTrackables(false);
//
//		// enable the new result with the same ImageTargetBehaviour:
//		ImageTargetBehaviour imageTargetBehaviour = mObjectTracker.TargetFinder.EnableTracking(targetSearchResult, mParentOfImageTargetTemplate) as ImageTargetBehaviour;
//
//		//if extended tracking was enabled from the menu, we need to start the extendedtracking on the newly found trackble.
//		if (mTrackableSettings && mTrackableSettings.IsExtendedTrackingEnabled()) {
//			imageTargetBehaviour.ImageTarget.StartExtendedTracking();
//		}
//	}


//	public void OnNewSearchResult(TargetFinder.TargetSearchResult targetSearchResult)
//	{
//		if(targetSearchResult.MetaData == null)
//		{
//			return;
//		}
//		else
//		{
//			Json.
//			var dict = Json.Deserialize(targetSearchResult.MetaData) as Dictionary<string,object>;
//
//			VideoPlaybackBehaviour video = ImageTargetTemplate.gameObject.GetComponentInChildren<VideoPlaybackBehaviour>();
//			if(video != null)
//			{
//				video.VideoPlayer.Unload();
//
//				if(video.VideoPlayer.Load((string) dict["video"], VideoPlayerHelper.MediaType.ON_TEXTURE, false, 0) == false)
//				{
//
//				}
//			}
//		}
//
//		mObjectTracker.TargetFinder.ClearTrackables(false);
//
//		ImageTargetBehaviour imageTargetBehaviour = mObjectTracker.TargetFinder.EnableTracking(targetSearchResult, mParentOfImageTargetTemplate) as ImageTargetBehaviour;
//
//		if(CloudRecognitionUIEventHandler.ExtendedTrackingIsEnabled)
//		{
//			imageTargetBehaviour.ImageTarget.StartExtendedTracking();
//		}
//	}


//    /// <summary>
//    /// Handles new search results
//    /// </summary>
//    /// <param name="targetSearchResult"></param>
//    public void OnNewSearchResult(TargetFinder.TargetSearchResult targetSearchResult)
//    {
//        // This code demonstrates how to reuse an ImageTargetBehaviour for new search results and modifying it according to the metadata
//        // Depending on your application, it can make more sense to duplicate the ImageTargetBehaviour using Instantiate(), 
//        // or to create a new ImageTargetBehaviour for each new result
//
//        // Vuforia will return a new object with the right script automatically if you use
//        // TargetFinder.EnableTracking(TargetSearchResult result, string gameObjectName)
//        
//        //Check if the metadata isn't null
//        if (targetSearchResult.MetaData == null)
//        {
//            Debug.Log("Target metadata not available.");
//            return;
//        }
//
//        // First clear all trackables
//        mObjectTracker.TargetFinder.ClearTrackables(false);
//
//        // enable the new result with the same ImageTargetBehaviour:
//        ImageTargetBehaviour imageTargetBehaviour = mObjectTracker.TargetFinder.EnableTracking(targetSearchResult, mParentOfImageTargetTemplate) as ImageTargetBehaviour;
//        
//        //if extended tracking was enabled from the menu, we need to start the extendedtracking on the newly found trackble.
//        if (mTrackableSettings && mTrackableSettings.IsExtendedTrackingEnabled())
//        {
//            imageTargetBehaviour.ImageTarget.StartExtendedTracking();
//        }
//    }
    #endregion //ICloudRecoEventHandler_implementation


    #region PUBLIC_METHODS
    public void CloseErrorDialog()
    {
        if (cloudErrorCanvas)
        {
            cloudErrorCanvas.transform.parent.position = Vector3.right * 2 * Screen.width;
            cloudErrorCanvas.gameObject.SetActive(false);
            cloudErrorCanvas.enabled = false;

            if (mMustRestartApp)
            {
				mMustRestartApp = false;
                RestartApplication();
            }
        }
    }
    #endregion //PUBLIC_METHODS

    #region PRIVATE_METHODS
    private void ShowScanLine(bool show)
    {
		Renderer scanLineRenderer = scanLine.GetComponent<Renderer>();
		scanLineRenderer.enabled = false;


//		// Toggle scanline rendering
//        if (scanLine != null)
//        {
//            Renderer scanLineRenderer = scanLine.GetComponent<Renderer>();
//            if (show)
//            {
//                // Enable scan line rendering
//                if (!scanLineRenderer.enabled)
//                    scanLineRenderer.enabled = true;
//
//                scanLine.ResetAnimation();
//            }
//            else
//            {
//                // Disable scanline rendering
//                if (scanLineRenderer.enabled)
//                    scanLineRenderer.enabled = false;
//            }
//        }
    }

    private void ShowError(string title, string msg)
    {
        if (!cloudErrorCanvas) return;

        if (cloudErrorTitle)
            cloudErrorTitle.text = title;

        if (cloudErrorText)
            cloudErrorText.text = msg;

        // Show the error canvas
        cloudErrorCanvas.transform.parent.position = Vector3.zero;
        cloudErrorCanvas.gameObject.SetActive(true);
        cloudErrorCanvas.enabled = true;
    }

    // Callback for network-not-available error message
    private void RestartApplication()
    {
#if (UNITY_5_2 || UNITY_5_1 || UNITY_5_0)
        int startLevel = Application.loadedLevel - 2;
        if (startLevel < 0) startLevel = 0;
        Application.LoadLevel(startLevel);
#else // UNITY_5_3 or above
        int startLevel = UnityEngine.SceneManagement.SceneManager.GetActiveScene().buildIndex - 2;
        if (startLevel < 0) startLevel = 0;
        UnityEngine.SceneManagement.SceneManager.LoadScene(startLevel);
#endif
    }



	public GameObject[] respawns;

	// Pause all videos except this one
	private void PauseOtherVideos(VideoPlaybackBehaviour currentVideo)
	{
//		VideoPlaybackBehaviour[] videos = (VideoPlaybackBehaviour[])
//			FindObjectsOfType(typeof(VideoPlaybackBehaviour));
//
//		foreach (VideoPlaybackBehaviour video in videos)
//		{
//			Debug.Log ("PauseOtherVideos:" + video);
//			Debug.Log ("video.CurrentState:" + video.CurrentState);
//
//
////			if (video != currentVideo)
////			{
////				if (video.CurrentState == VideoPlayerHelper.MediaState.PLAYING)
////				{
//					video.VideoPlayer.Pause();
////				}
////			}
//		}

//		VideoPlaybackBehaviour[] videos = FindObjectsOfType<VideoPlaybackBehaviour>();
//		foreach (VideoPlaybackBehaviour video in videos)
//		{
//			Debug.Log ("PauseOtherVideos:" + video);
//			Debug.Log ("video.CurrentState:" + video.CurrentState);
//
////			if (video != currentVideo &&
////				video.CurrentState == VideoPlayerHelper.MediaState.PLAYING)
////			{
//			if (video.CurrentState == VideoPlayerHelper.MediaState.PLAYING)
//			{
//				Debug.Log ("PauseOtherVideos0:");
//				//video.VideoPlayer.Pause();
//				video.VideoPlayer.Stop();
//			}
//		}


		Debug.Log ("FindGameObjectsWithTag:0");
		respawns = GameObject.FindGameObjectsWithTag("VideoGameObject");

		Debug.Log ("respawns.Length:" + respawns.Length);

		foreach (GameObject respawn in respawns) {
			VideoPlaybackBehaviour video = respawn.GetComponent( typeof(VideoPlaybackBehaviour) ) as VideoPlaybackBehaviour;

			Debug.Log ("PauseOtherVideos:video:" + video);

			video.VideoPlayer.Stop ();
			//Instantiate(respawnPrefab, respawn.transform.position, respawn.transform.rotation);
		}
	
	}




	public void CountUp(string targetId)
	{
		WWWForm form = new WWWForm();
		form.AddField("targetId", targetId);
		string POST_URL = "https://universe.hiliberate.biz/api/targets/" + targetId + "/set_count_up_and_inactive/";
		WWW www = new WWW(POST_URL, form);
		StartCoroutine("WaitForRequest", www);
	}

	//通信の処理待ち
	private IEnumerator WaitForRequest(WWW www)
	{
		yield return www;
		connectionEnd(www);
	}

	//通信終了後の処理
	private void connectionEnd(WWW www)
	{
		//通信結果をLogで出す
		if (www.error != null)
		{			
			//エラー内容 -> www.error
			Debug.Log("www.error");
			Debug.Log(www.error);
		}
		else
		{
			//通信結果 -> www.text
			Debug.Log("www.text");
			Debug.Log(www.text);
		}
	}


	IEnumerator CountUp2 (string targetId) {
		string url = "https://universe.hiliberate.biz/api/targets/" + targetId + "/set_count_up_and_inactive/";
		Debug.Log (url);

		WWWForm form = new WWWForm ();
		//form.AddField ("jsondata", jsondata);
		var www = new WWW (url, form);
		yield return www;
//		print (www.text);



//		userData.name = "Yamada";
//		userData.age = 20;
//		string jsondata = JsonMapper.ToJson (userData);
//		print (jsondata);
//		WWWForm form = new WWWForm ();
//		form.AddField ("jsondata", jsondata);
//		var www = new WWW (url, form);
//		yield return www;
//		print (www.text);
	}


	//@ToDo 共通化したい
	public void showHideGameObject(GameObject obj)
	{
		Material m = obj.GetComponent<Renderer> ().material;

		if (m.color.a == 0) {
			//fade in
			fadeInGameObject(obj);
		} else {
			//fade out
			fadeOutGameObject(obj);
		}
	}

	public void fadeInGameObject(GameObject obj)
	{
		iTween.FadeTo(obj, iTween.Hash("alpha", 1, "time", 1, "delay", 0));
	}

	public void fadeOutGameObject(GameObject obj)
	{
		iTween.FadeTo(obj, iTween.Hash("alpha", 0, "time", 1));
	}

    #endregion //PRIVATE_METHODS
}
