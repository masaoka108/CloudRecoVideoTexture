using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

using System;
using System.IO;

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

		GameObject CloudRecognition = GameObject.Find ("CloudRecognition");
		CloudRecoEventHandler creh = CloudRecognition.GetComponent<CloudRecoEventHandler> ();

		string fbURL = WWW.EscapeURL ("https://universear.hiliberate.biz/hlar/target/preview_img/" + creh.targetFileName);
		Debug.Log ("fb_icon --2--");
		Debug.Log (fbURL);

		Application.OpenURL ("https://www.facebook.com/share.php?u=" + fbURL);

		Debug.Log ("fb_icon --3--");

	}

	public void OnClickTwitter() {
		Debug.Log("OnClickFullTwitter click!");

		GameObject CloudRecognition = GameObject.Find ("CloudRecognition");
		CloudRecoEventHandler creh = CloudRecognition.GetComponent<CloudRecoEventHandler> ();

		//@ToDo ここでターゲット画像のURLを取得して添付する
		//					string tweetMsg = WWW.EscapeURL ("ARアプリUNIVERSE https://universear.hiliberate.biz/static/images/IMG_1272.JPG");

		string tweetMsg = "";
		string deviceLanguage = Application.systemLanguage.ToString();
		Debug.Log (deviceLanguage);
		if(deviceLanguage == "Japanese"){
			Debug.Log ("日本語だよ");
			tweetMsg = WWW.EscapeURL ("ARアプリ【UNIVERSE AR】でこの画像を読み取ってみましょう！ #universear");
		}  else if (deviceLanguage == "English"){
			Debug.Log ("英語だよ");
			tweetMsg = WWW.EscapeURL ("Let's read this image by【UNIVERSE.AR】app! #universear");
		} else {
			Debug.Log ("他の言語だよ");
			tweetMsg = WWW.EscapeURL ("Let's read this image by【UNIVERSE.AR】app! #universear");
		}

		string tweetURL = WWW.EscapeURL ("https://universear.hiliberate.biz/hlar/target/preview_img/" + creh.targetFileName);
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
