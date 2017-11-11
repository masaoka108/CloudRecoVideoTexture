using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//20170225 okamura作成
public class TapEvent : MonoBehaviour {

	public string targetURL = "https://universear.hiliberate.biz/hlar/";
	public string fullScreenURL = "";
	// Use this for initialization
	void Start () {
		Debug.Log ("TapEvent start");
	}
	
	// Update is called once per frame
	void Update () {

		GameObject obj = getClickObject ();
		if (obj != null) {
			
			if (obj.name == "TargetMenuPlane") {
				GameObject www_icon = GameObject.Find ("www_icon");
				GameObject fullscreen_icon = GameObject.Find ("fullscreen_icon");
				GameObject twitter_icon = GameObject.Find ("twitter_icon");
				GameObject fb_icon = GameObject.Find ("fb_icon");
				//GameObject insta_icon = GameObject.Find("insta_icon");

				showHideGameObject (www_icon);
				showHideGameObject (fullscreen_icon);
				showHideGameObject (twitter_icon);
				showHideGameObject (fb_icon);
				//showHideGameObject (insta_icon);

			} else if (obj.name == "www_icon") {
				//www アイコン
				if (getVisibleGameObject (obj)) {
					Application.OpenURL (targetURL);
				}
			} else if (obj.name == "fullscreen_icon") {
				//fullscreen アイコン
				if (getVisibleGameObject (obj)) {
					VideoPlaybackBehaviour video = PickVideo ();

					Debug.Log ("fullscreen アイコン");
					Debug.Log (video);

					if (video != null) {
						video.VideoPlayer.Pause ();
						Handheld.PlayFullScreenMovie (fullScreenURL, Color.black, FullScreenMovieControlMode.Full, FullScreenMovieScalingMode.AspectFit);
					}

				}
			} else if (obj.name == "twitter_icon") {
				//twitter アイコン
				if (getVisibleGameObject (obj)) {
					//@ToDo ここでターゲット画像のURLを取得して添付する
//					string tweetMsg = WWW.EscapeURL ("ARアプリUNIVERSE https://universear.hiliberate.biz/static/images/IMG_1272.JPG");
					string tweetMsg = WWW.EscapeURL ("ARアプリ【UNIVERSE AR】画像と動画を登録するだけで誰でも簡単にオリジナルARコンテンツを作成可能！");
					string tweetURL = WWW.EscapeURL ("https://universear.hiliberate.biz/hlar/");
					//string tweetMsg = "ARアプリUNIVERSE";
					Application.OpenURL ("https://twitter.com/share?text=" + tweetMsg + "&url=" + tweetURL);
				}
			} else if (obj.name == "fb_icon") {
				Debug.Log ("fb_icon");
				//fb アイコン
				if (getVisibleGameObject (obj)) {
					Debug.Log ("fb_icon --1--");

					string fbURL = WWW.EscapeURL ("https://universear.hiliberate.biz/hlar/");
					Debug.Log ("fb_icon --2--");
					Debug.Log (fbURL);

					Application.OpenURL ("https://www.facebook.com/share.php?u=" + fbURL);

					Debug.Log ("fb_icon --3--");

				}
			} else if (obj.name == "insta_icon") {
				//insta アイコン
				if (getVisibleGameObject (obj)) {

				}
			}

		} else {

			if (Input.GetMouseButtonDown (0) || 0 < Input.touchCount) {
				Debug.Log ("message:del");
				GameObject MessageUI = GameObject.Find ("MessageUI");
				if (MessageUI != null) {
					MessageUI.SetActive (false);
				}
			}
		}
	}

	public bool getVisibleGameObject(GameObject obj)
	{
		bool ret = false;
		Material m = obj.GetComponent<Renderer> ().material;

		if (m.color.a == 0) {
		} else {
			ret = true;
		}

		return ret;
	}

	public void showHideGameObject(GameObject obj)
	{
		Material m = obj.GetComponent<Renderer> ().material;

		if (m.color.a == 0) {
			//fade in
			fadeInGameObject(obj);
		} else if (m.color.a == 1) {
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


	// 左クリックしたオブジェクトを取得する関数(3D)
	public GameObject getClickObject() {
		GameObject result = null;
		// 左クリックされた場所のオブジェクトを取得

		if(Input.GetMouseButtonDown(0) || 0 < Input.touchCount) {
		
			Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
			RaycastHit hit = new RaycastHit();

			if (Physics.Raycast(ray, out hit)){
				result = hit.collider.gameObject;
			}

		}
		return result;
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


}
