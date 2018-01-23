using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CaptureTextSuccessScript : MonoBehaviour {

	private GameObject CaptureTextSuccess;

	// Use this for initialization
	void Start () {
		CaptureTextSuccess = GameObject.Find("CaptureTextSuccess");

//		CaptureTextSuccess.SetActive (false);
		this.gameObject.SetActive (false);
	}
	
//	// Update is called once per frame
//	void Update () {
//		
//	}

	public void ShowAndHide() {
		Debug.Log ("ShowAndHide -1-");

		this.gameObject.SetActive (true);
		//		CaptureTextSuccess.SetActive (true);

		System.Threading.Thread.Sleep(1000);

		Debug.Log ("ShowAndHide -2-");

		CaptureTextSuccess.SetActive (false);

		Debug.Log ("ShowAndHide -3-");
	} 
}
