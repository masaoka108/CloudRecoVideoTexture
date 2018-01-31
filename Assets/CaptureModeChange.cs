using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class CaptureModeChange : MonoBehaviour {

	public GameObject SliderCaptureMode;

	public GameObject ScreenCapture;
	public GameObject VideoCaptureButton;

	public GameObject TextCaptureMode;

	// Use this for initialization
	void Start () {
		SliderCaptureMode = GameObject.Find("SliderCaptureMode");

		VideoCaptureButton = GameObject.Find("VideoCaptureButton");
		ScreenCapture = GameObject.Find("ScreenCapture");

		TextCaptureMode = GameObject.Find("TextCaptureMode");

		ScreenCapture.SetActive (false);
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	public void ChangeCaptureMode () {
		float captureMode = SliderCaptureMode.GetComponent<Slider>().value;			
		Debug.Log (captureMode);
		if (captureMode == 0) {
			VideoCaptureButton.SetActive (true);
			ScreenCapture.SetActive (false);
			TextCaptureMode.GetComponent<Text>().text = "video";
		} else if (captureMode == 1) {
			VideoCaptureButton.SetActive (false);
			ScreenCapture.SetActive (true);
			TextCaptureMode.GetComponent<Text>().text = "photo";
		} 
	}
}
