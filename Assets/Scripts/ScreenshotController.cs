using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;
using System.IO;

#if UNITY_IPHONE
using UnityEngine.iOS;
using UnityEngine.Apple.ReplayKit;
#endif

public class ScreenshotController : MonoBehaviour {

	// Used so that Xcode can identify these functions being called within Unity
	[DllImport ("__Internal")]
	private static extern void ScreenShotFunction();

	// Has to be the same as the one in Xcode(screenshot.mm)
	private string pictureName;

	// Has to be whole canvas object to remove all buttons from view while screenshot takes place
	public GameObject canvasObject;

	// Screenshot and video buttons
	public GameObject cameraButton;
	public GameObject videoButton;

	// Recording red circle image
	public GameObject feedbackImage;

	// Confirm Buttons
	public GameObject confirmScreenshotButton;
	public GameObject confirmVideoButton;

	public GameObject VideoRecText;

	// Used for video recording
	public bool recording;
	private bool videoPressed;

	private GameObject VideoCaptureFinishMsgPanel;

	void Start() {
		videoPressed = false;

		confirmVideoButton.SetActive (false);
		VideoRecText.SetActive (false);

		VideoCaptureFinishMsgPanel = GameObject.Find("VideoCaptureFinishMsgPanel");
		VideoCaptureFinishMsgPanel.SetActive(false);
	}


	// Camera Button Event Trigger on Pointer Down
	public void Screenshot_PointerDown() {
		canvasObject.GetComponent <Canvas>().enabled = false;

		pictureName = "Picture.png";
		//ScreenCapture.CaptureScreenshot (pictureName);
		Application.CaptureScreenshot (pictureName);
	}

	public void Screenshot_PointerUp() {
		canvasObject.GetComponent <Canvas>().enabled = true;
		confirmScreenshotButton.SetActive (true);

		cameraButton.SetActive (false);
		videoButton.SetActive (false);
	}

	// Used on confirm button so that there are no race conditions in image saving
	public void ScreenshotConfirm() {
		// Run on Xcode function
		if (Application.platform != RuntimePlatform.OSXEditor) {
			ScreenShotFunction ();
		}

		// Delete file after save
		if (File.Exists (Application.persistentDataPath + "/" + pictureName)) {
			File.Delete ((Application.persistentDataPath + "/" + pictureName));
		}

		// Go back to normal GUI operation
		confirmScreenshotButton.SetActive (false);
		cameraButton.SetActive (true);
		videoButton.SetActive (true);
	}

	// Video Button OnClick 
	public void VideoShotClick() {
		Debug.Log ("start VideoShotClick -1-");

		#if UNITY_IPHONE
		if (!ReplayKit.APIAvailable) {
			Debug.Log ("API not available! ");
			return;
		}

		Debug.Log ("VideoShotClick -2-");
		Debug.Log (videoPressed);


		if (videoPressed) {
			Debug.Log ("VideoShotClick -3-");

			videoPressed = false;

			// Turn off GUI
			//feedbackImage.SetActive (false);
			//videoButton.SetActive (false);

			// Show confirmation button
			confirmVideoButton.SetActive (true);

			VideoCaptureFinishMsgPanel.SetActive(true);

		} else {
			Debug.Log ("VideoShotClick -4-");

			videoPressed = true;

			// Begin recording mode
//			feedbackImage.SetActive (true);
//			cameraButton.SetActive (false);

		}

		Debug.Log ("VideoShotClick -5-");

		// Recording 
		recording = ReplayKit.isRecording;
		recording = !recording;
		if (recording) {
			Debug.Log ("VideoShotClick -6-");

			VideoRecText.SetActive(true);
			Debug.Log ("I am starting a recording");

			//無駄なUIを非表示にする
			GameObject.Find("Canvas").GetComponent<Canvas>().enabled = false;


			//GameObject.Find("CanvasCaptureButton").GetComponent<Canvas>().enabled = false;
			GameObject.Find("MenuButton").GetComponent<AdMob>().BannerHide();
			GameObject TargetMenuPlane = GameObject.Find ("TargetMenuPlane");
			TapEvent tap = TargetMenuPlane.GetComponent<TapEvent> ();
			tap.MessageUI_menu.SetActive (false);


			ReplayKit.StartRecording(true);	//1st arg = enable microphone
		}
		else {
			Debug.Log ("VideoShotClick -7-");

			Debug.Log ("I am ending a recording");
			ReplayKit.StopRecording();

			VideoRecText.SetActive(false);

			//非表示にしたUIを再表示
			GameObject.Find("Canvas").GetComponent<Canvas>().enabled = true;
			//GameObject.Find("CanvasCaptureButton").GetComponent<Canvas>().enabled = true;
			GameObject.Find("MenuButton").GetComponent<AdMob>().BannerShow();
		}
		#endif
	}

	public void VideoConfirm(){
		#if UNITY_IPHONE

		if (ReplayKit.recordingAvailable) {
			ReplayKit.Preview();
		}

		// Go back to normal GUI operation
		confirmVideoButton.SetActive (false);
//		cameraButton.SetActive (true);
		videoButton.SetActive (true);

		VideoCaptureFinishMsgPanel.SetActive(false);

		#endif
	}

	public void VideoCaptureFinishMsgPanelHide(){
		VideoCaptureFinishMsgPanel.SetActive(false);
	}

}