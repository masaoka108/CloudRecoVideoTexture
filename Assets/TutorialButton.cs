using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class TutorialButton : MonoBehaviour {


	// Use this for initialization
	void Start () {
		#if UNITY_EDITOR
		PlayerPrefs.DeleteKey("Init"); 
		#elif UNITY_ANDROID

		#endif
	}

	//	// Update is called once per frame
	//	void Update () {
	//		
	//	}

	public void OnClickFinishTurorial() {
		Debug.Log("OnClickFinishTurorial click!");
		GameObject TutorialUI = GameObject.Find ("TutorialUI");
		TutorialUI.SetActive (false);

		//チュートリアル終了 フラグ
		PlayerPrefs.SetInt("Init", 1); 

		GameObject.Find("Canvas").GetComponent<Canvas>().enabled = true;
		GameObject.Find("CanvasCaptureButton").GetComponent<Canvas>().enabled = true;

	}

	public void OnClickAccessHomepage() {
		Debug.Log("OnAccessHomepage click!");
		Application.OpenURL("https://universear.hiliberate.biz/");
	}

}
