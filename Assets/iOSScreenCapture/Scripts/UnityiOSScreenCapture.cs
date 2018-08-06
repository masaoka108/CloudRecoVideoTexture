﻿using System;
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

    private GameObject AndroidMsgPanel;
        
	private bool bMenuActive;
    private bool isRecognize = false;

	void Start()
	{
        Utility = GameObject.Find("Utility");

        SuccessMsgPanel = GameObject.Find("SuccessMsgPanel");
        FailureMsgPanel = GameObject.Find("FailureMsgPanel");
        AndroidMsgPanel = GameObject.Find("AndroidMsgPanel");

        SuccessMsgPanel.SetActive(false);
        FailureMsgPanel.SetActive(false);
        AndroidMsgPanel.SetActive(false);

#if UNITY_IPHONE
        UiOS = Utility.GetComponent<UnityiOS>();
        UnityiOS.RequestPermissions();
#endif
	}


	public void Execute() {

#if UNITY_ANDROID
        AndroidMsgBoxShow();
        return;
#endif

        Debug.Log ("Execute");

#if (UNITY_IPHONE || UNITY_IOS)
		PHAuthorizationStatus phstatus = (PHAuthorizationStatus)Enum.ToObject(
			typeof(PHAuthorizationStatus), UnityiOS.HasCameraRollPermission());

		//キャプチャ
		if(phstatus == PHAuthorizationStatus.Authorized) {
			//シャッター音
			UnityiOS.PlaySystemShutterSound();

			Handheld.SetActivityIndicatorStyle(UnityEngine.iOS.ActivityIndicatorStyle.Gray);
			Handheld.StartActivityIndicator();
			StartCoroutine(_CaptureScreenShot());
		} else {
			//カメラ、カメラロールへのアクセス許可確認
			UiOS.RequestPermissions_forUGUI ();
			//UnityiOS.RequestPermissions();

			OnFailCapture.Invoke();
		}
#endif
	}

	private IEnumerator _CaptureScreenShot() {
		//canvasGroup.alpha = 0; //みたいな処理を入れておくと撮影時にUIを外すといった事が出来ます

        try {
    		//無駄なUIを非表示にする
    		GameObject.Find("Canvas").GetComponent<Canvas>().enabled = false;
    		GameObject.Find("CanvasCaptureButton").GetComponent<Canvas>().enabled = false;
    		GameObject.Find("MenuButton").GetComponent<AdMob>().BannerHide();
    		//GameObject TargetMenuPlane = GameObject.Find ("TargetMenuPlane");
    		//TapEvent tap = TargetMenuPlane.GetComponent<TapEvent> ();
    		//bMenuActive = tap.MessageUI_menu.active;
    		//tap.MessageUI_menu.SetActive (false);
            //GameObject.Find("MessageUI_menu").GetComponent<Canvas>().enabled = false;

            //パレットが開かれていたら非表示にする
            Utility.GetComponent<Paint>().CanvasPalette.SetActive(false);

            //Twitter,FBボタンを非表示
            GameObject TargetMenuPlane = GameObject.Find("TargetMenuPlane");
            TapEvent tap = TargetMenuPlane.GetComponent<TapEvent>();
            if (tap.MessageUI_menu != null)
            {
                isRecognize = true;
                tap.MessageUI_menu.SetActive(false);
            }

        } catch (NullReferenceException ex) {
            Debug.Log("NullReferenceException");
        }


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


        try{
            //UIを再表示にする
            GameObject.Find("Canvas").GetComponent<Canvas>().enabled = true;
            GameObject.Find("CanvasCaptureButton").GetComponent<Canvas>().enabled = true;
            GameObject.Find("MenuButton").GetComponent<AdMob>().BannerShow();

            //GameObject.Find("CanvasPalette").GetComponent<Canvas>().enabled = true;
            //GameObject TargetMenuPlane = GameObject.Find("TargetMenuPlane");
            //TapEvent tap = TargetMenuPlane.GetComponent<TapEvent>();
            //tap.MessageUI_menu.SetActive(bMenuActive);
            //GameObject.Find("MessageUI_menu").GetComponent<Canvas>().enabled = true;

            //パレット
            if (Utility.GetComponent<Paint>().paintFlg == true || Utility.GetComponent<Paint>().eraserFlg == true)
            {
                Utility.GetComponent<Paint>().CanvasPalette.SetActive(true);
            }
            Utility.GetComponent<Paint>().CanvasPalette.SetActive(false);

            //Twitter,FBボタンを非表示
            if (isRecognize)
            {
                GameObject TargetMenuPlane = GameObject.Find("TargetMenuPlane");
                TapEvent tap = TargetMenuPlane.GetComponent<TapEvent>();
                if (tap.MessageUI_menu != null)
                {
                    tap.MessageUI_menu.SetActive(true);
                }
            }


        }
        catch (NullReferenceException ex)
        {
            Debug.Log("NullReferenceException");
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

    public void AndroidMsgBoxHide()
    {
        AndroidMsgPanel.SetActive(false);
    }

    public void AndroidMsgBoxShow()
    {
        AndroidMsgPanel.SetActive(true);
    }


}
