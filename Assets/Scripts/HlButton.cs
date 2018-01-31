using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class HlButton : MonoBehaviour {

	/// ボタンをクリックした時の処理
	public void OnClick() {
		Debug.Log("Button click!");
		Application.OpenURL("https://universear.hiliberate.biz/");
	}

	/// ボタンをクリックした時の処理
	public void OnClickVolumeOn() {
		Debug.Log("Button ON click!");
		GameObject refObj = GameObject.Find("TargetMenuPlane");
		TapEvent tapEvent = refObj.GetComponent<TapEvent>();

		tapEvent.VolumeOnButton.SetActive (false);
		tapEvent.VolumeOffButton.SetActive (true);

		GameObject refObj2 = GameObject.Find("CloudRecoTarget");
		TrackableEventHandler teh = refObj2.GetComponent<TrackableEventHandler>();
		teh.video.VideoPlayer.VolumeOff ();

//		video.VideoPlayer.GetStatus();
	}

	/// ボタンをクリックした時の処理
	public void OnClickVolumeOff() {
		Debug.Log("Button OFF click!");
		GameObject refObj = GameObject.Find("TargetMenuPlane");
		TapEvent tapEvent = refObj.GetComponent<TapEvent>();

		tapEvent.VolumeOnButton.SetActive (true);
		tapEvent.VolumeOffButton.SetActive (false);

		GameObject refObj2 = GameObject.Find("CloudRecoTarget");
		TrackableEventHandler teh = refObj2.GetComponent<TrackableEventHandler>();
		teh.video.VideoPlayer.VolumeOn ();
	}

	/// ボタンをクリックした時の処理
	public void OnTutorial() {
		Debug.Log("OnTutorial click!");

		GameObject refObj = GameObject.Find("TargetMenuPlane");
		TapEvent tapEvent = refObj.GetComponent<TapEvent>();

		tapEvent.TutorialUI.SetActive (true);
		GameObject.Find("Canvas").GetComponent<Canvas>().enabled = false;
		GameObject.Find("CanvasCaptureButton").GetComponent<Canvas>().enabled = false;
		GameObject TargetMenuPlane = GameObject.Find ("TargetMenuPlane");
		TapEvent tap = TargetMenuPlane.GetComponent<TapEvent> ();
		tap.MessageUI_menu.SetActive (false);
	}


	// Use this for initialization
	void Start () {
		//******** 透過処理

//		if (this.name == "MenuButton") {
//			Image _This = this.GetComponent<Image>();
//			_This.color = new Color(1,1,1,0.5f);
//		} else if (this.name == "VolumeOnButton") {
//			Image _This = this.GetComponent<Image>();
//			_This.color = new Color(1,1,1,0.8f);
//		} else if (this.name == "VolumeOffButton") {
//			Image _This = this.GetComponent<Image>();
//			_This.color = new Color(1,1,1,0.8f);
//		}

//		//**** メニューボタン
//		GameObject refMenuButton = GameObject.Find("MenuButton");
//		Image MenuButtonImage = refMenuButton.GetComponent<Image>();
//		MenuButtonImage.color = new Color(1,1,1,0.5f);
//
//		//**** Volume ONボタン
//		GameObject refVolumeOnButton = GameObject.Find("VolumeOnButton");
//		Image VolumeOnButtonImage = refMenuButton.GetComponent<Image>();
//		VolumeOnButtonImage.color = new Color(1,1,1,0.8f);
//
//		//**** Volume OFFボタン
//		GameObject refVolumeOffButton = GameObject.Find("VolumeOffButton");
//		Image VolumeOffButtonImage = refMenuButton.GetComponent<Image>();
//		VolumeOffButtonImage.color = new Color(1,1,1,0.8f);
//
//		Debug.Log("HlButton:this.name:" + this.name);
//
		Image _This = this.GetComponent<Image>();
		_This.color = new Color(1,1,1,0.5f);

	}



//	// Update is called once per frame
//	void Update () {
//		
//	}
}
