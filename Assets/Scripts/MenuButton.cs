using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MenuButton : MonoBehaviour {

	// Use this for initialization
	void Start () {
//		//透過処理
//		Image _This = this.GetComponent<Image>();
//		_This.color = new Color(1,1,1,0.5f);
	}
	
//	// Update is called once per frame
//	void Update () {
//		
//	}

	public void OnClickInfo() {
		Debug.Log("OnClickInfo click!");

		GameObject refObj = GameObject.Find("TargetMenuPlane");
		TapEvent tapEvent = refObj.GetComponent<TapEvent>();

		Application.OpenURL (tapEvent.targetURL);
	}

	public void OnClickFullScreen() {
		Debug.Log("OnClickFullScreen click!");
	
//		StartCoroutine ("StartUnityVideo");

		VideoPlaybackBehaviour video = PickVideo ();

		Debug.Log ("fullscreen アイコン");
		Debug.Log (video);

		if (video != null) {
			video.VideoPlayer.Pause ();

			VideoPlayerHelper.MediaState state = VideoPlayerHelper.MediaState.NOT_READY;
			while(state != VideoPlayerHelper.MediaState.PAUSED) {
				state = video.VideoPlayer.UpdateVideoData();

				Debug.Log("OnClickFullScreen:WhileStateCheck:-1- : " + state);

				if (state == VideoPlayerHelper.MediaState.PAUSED) {
					break;
				} 
			}


//			Screen.orientation = ScreenOrientation.LandscapeLeft;

			//video.VideoPlayer.PlayFullScreen();

			StartCoroutine ("StartUnityVideo");

//			GameObject refObj = GameObject.Find("TargetMenuPlane");
//			TapEvent tapEvent = refObj.GetComponent<TapEvent>();
//			Handheld.PlayFullScreenMovie (tapEvent.fullScreenURL, Color.black, FullScreenMovieControlMode.Full, FullScreenMovieScalingMode.AspectFit);
		}
	}

	public void OnClickFacebook() {
		Debug.Log("OnClickFullFacebook click!");
	
		Debug.Log ("fb_icon --1--");

		string fbURL = WWW.EscapeURL ("https://universear.hiliberate.biz/hlar/");
		Debug.Log ("fb_icon --2--");
		Debug.Log (fbURL);

		Application.OpenURL ("https://www.facebook.com/share.php?u=" + fbURL);

		Debug.Log ("fb_icon --3--");

	}

	public void OnClickTwitter() {
		Debug.Log("OnClickFullTwitter click!");
	
		//@ToDo ここでターゲット画像のURLを取得して添付する
		//					string tweetMsg = WWW.EscapeURL ("ARアプリUNIVERSE https://universear.hiliberate.biz/static/images/IMG_1272.JPG");
		string tweetMsg = WWW.EscapeURL ("ARアプリ【UNIVERSE AR】画像と動画を登録するだけで誰でも簡単にオリジナルARコンテンツを作成可能！");
		string tweetURL = WWW.EscapeURL ("https://universear.hiliberate.biz/hlar/");
		//string tweetMsg = "ARアプリUNIVERSE";
		Application.OpenURL ("https://twitter.com/share?text=" + tweetMsg + "&url=" + tweetURL);
	}


	public void OnClickClose() {
		Debug.Log("OnClickClose click!");

		GameObject MessageUI_menu = GameObject.Find ("MessageUI_menu");
		if (MessageUI_menu != null) {
			Debug.Log ("TapEvent updat:MessageUI_menu:false");
			MessageUI_menu.SetActive (false);
		}


	}


	//@ToDo 共通化したい
	private VideoPlaybackBehaviour PickVideo()
	{
		VideoPlaybackBehaviour[] behaviours = GameObject.FindObjectsOfType<VideoPlaybackBehaviour>();
		foreach (VideoPlaybackBehaviour vb in behaviours)
		{
			return vb;
		}
		return null;
	}

	IEnumerator StartUnityVideo()
	{
		yield return new WaitForSeconds(2);
		Debug.Log ("StartUnityVideo");

		GameObject refObj = GameObject.Find("TargetMenuPlane");
		TapEvent tapEvent = refObj.GetComponent<TapEvent>();
		Handheld.PlayFullScreenMovie (tapEvent.fullScreenURL, Color.black, FullScreenMovieControlMode.Full, FullScreenMovieScalingMode.AspectFit);

		Debug.Log ("FIN Iniciando video");
		yield break;
	}
}
