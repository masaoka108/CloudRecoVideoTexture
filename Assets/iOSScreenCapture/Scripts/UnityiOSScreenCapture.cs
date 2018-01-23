using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;

public class UnityiOSScreenCapture : MonoBehaviour {

	public UnityEvent OnCompleteCapture;
	public UnityEvent OnFailCapture;

	private GameObject Utility;
	private UnityiOS UiOS;

	private GameObject SuccessMsgPanel;
	private GameObject FailureMsgPanel;



	void Start()
	{
		Utility = GameObject.Find("Utility");
		UiOS = Utility.GetComponent<UnityiOS> ();

		SuccessMsgPanel = GameObject.Find("SuccessMsgPanel");
		FailureMsgPanel = GameObject.Find("FailureMsgPanel");

		SuccessMsgPanel.SetActive(false);
		FailureMsgPanel.SetActive (false);
	}


	public void Execute() {

		//		UnityEditor.EditorUtility.DisplayDialog("Notice", "Hello!", "OK");

		Debug.Log ("Execute");

//		SuccessMsgPanel.SetActive (true);

//		CaptureTextSuccess.SetActive (true);
//		System.Threading.Thread.Sleep(1000);
//		CaptureTextSuccess.SetActive (false);



//		ShowAndHide (CaptureTextSuccess);

		//		Debug.Log ("Execute");
//		Debug.Log (SuccessScript);
//		SuccessScript.ShowAndHide ();

		#if !UNITY_EDITOR
		PHAuthorizationStatus phstatus = (PHAuthorizationStatus)Enum.ToObject(
			typeof(PHAuthorizationStatus), UnityiOS.HasCameraRollPermission());

		//カメラ、カメラロールへのアクセス許可確認
		UiOS.RequestPermissions_forUGUI ();

		//シャッター音
		UnityiOS.PlaySystemShutterSound();

		//キャプチャ
		if(phstatus == PHAuthorizationStatus.Authorized) {
			Handheld.SetActivityIndicatorStyle(UnityEngine.iOS.ActivityIndicatorStyle.Gray);
			Handheld.StartActivityIndicator();
			StartCoroutine(_CaptureScreenShot());
		} else {
			OnFailCapture.Invoke();
		}
#endif
	}

	private IEnumerator _CaptureScreenShot() {
		//canvasGroup.alpha = 0; //みたいな処理を入れておくと撮影時にUIを外すといった事が出来ます
		yield return new WaitForEndOfFrame();

		var width = Screen.width;
		var height = Screen.height;
		var tex = new Texture2D(width, height, TextureFormat.RGB24, false);

		tex.ReadPixels(new Rect(0, 0, width, height), 0, 0);
		tex.Apply();
		byte[] screenshot = tex.EncodeToPNG();

		UnityiOS.SaveTexture(screenshot, screenshot.Length);

		//canvasGrouo.alpha = 1;
	}

	//撮影後コールバックされる関数
	void DidImageWriteToAlbum(string errorDescription) {
		Handheld.StopActivityIndicator();
		if (string.IsNullOrEmpty(errorDescription)) {
			OnCompleteCapture.Invoke();
		}else{
			OnFailCapture.Invoke();
		}
	}


	public void ShowAndHide(GameObject obj) {
		Debug.Log ("ShowAndHide -1-");

		obj.SetActive (true);
		//		CaptureTextSuccess.SetActive (true);

		System.Threading.Thread.Sleep(1000);

		Debug.Log ("ShowAndHide -2-");

		obj.SetActive (false);

		Debug.Log ("ShowAndHide -3-");
	} 
		
	public void SuccessMsgBoxHide() {
		SuccessMsgPanel.SetActive (false);
	}

	public void SuccessMsgBoxShow() {
		SuccessMsgPanel.SetActive (true);
	}

	public void FailureMsgBoxHide() {
		FailureMsgPanel.SetActive (false);
	}

	public void FailureMsgBoxShow() {
		FailureMsgPanel.SetActive (true);
	}


}
