using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

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

		//全非表示
		HideMenu();

		//TutorialMenuUl を表示
		GameObject.Find("TutoriaMenulUI").GetComponent<Canvas>().enabled = true;

//		//TutorialUI を表示
//		GameObject refObj = GameObject.Find("TargetMenuPlane");
//		TapEvent tapEvent = refObj.GetComponent<TapEvent>();
//		tapEvent.TutorialUI.SetActive (true);

	}

	// サンプルを試す ボタン クリック時
	public void OnTutorialSample() {
		Debug.Log("OnTutorialSample click!");

		//全非表示
		HideMenu ();

		//TutorialUI を表示
		GameObject refObj = GameObject.Find("TargetMenuPlane");
		TapEvent tapEvent = refObj.GetComponent<TapEvent>();
		tapEvent.TutorialUI.SetActive (true);

	}

	// オリジナルAR作成 ボタン クリック時
	public void OnClickHowToMakeOriginalAR() {
		Debug.Log("OnClickHowToMakeOriginalAR click!");

		//HowToMakeOriginalAR scene を表示
		SceneManager.LoadScene ("HowToMakeOriginalAR");

	}

	//その他の余分なものを非表示
	public void HideMenu() {
		GameObject.Find("Canvas").GetComponent<Canvas>().enabled = false;
		GameObject.Find("CanvasCaptureButton").GetComponent<Canvas>().enabled = false;
		GameObject.Find("TutoriaMenulUI").GetComponent<Canvas>().enabled = false;
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
		
        if (_This != null) {
            _This.color = new Color(1, 1, 1, 0.5f);
        }

	}


	// オリジナルAR作成のチュートリアル でcloseボタン クリック時
	public void OnClickHowToMakeOriginalARClose() {
		Debug.Log("OnClickHowToMakeOriginalARClose click!");

		//HowToMakeOriginalAR scene を表示
		SceneManager.LoadScene ("Vuforia-3-CloudReco");

	}


    // ペイント ボタン
    public void OnClickPaint()
    {
        Debug.Log("OnClickPaint click!");

        GameObject Utility = GameObject.Find("Utility");

        if (!Utility.GetComponent<Paint>().paintFlg || Utility.GetComponent<Paint>().eraserFlg == true){
            //******** ペイント モード

            //Flgを変更
            Utility.GetComponent<Paint>().paintFlg = true;
            Utility.GetComponent<Paint>().eraserFlg = false;


            //消しゴム ボタンを表示
            Utility.GetComponent<Paint>().EraseButton.SetActive(true);
            Utility.GetComponent<Paint>().CanvasPalette.SetActive(true);

            //パレットを表示

        } else {
            //******** ペイント モードを解除

            //Flgを変更
            Utility.GetComponent<Paint>().paintFlg = false;

            //消しゴム ボタンを表示
            Utility.GetComponent<Paint>().EraseButton.SetActive(false);
            Utility.GetComponent<Paint>().CanvasPalette.SetActive(false);

            //パレットを表示

        }



    }

    // 消しゴム ボタン
    public void OnClickEraser()
    {
        Debug.Log("OnClickEraser click!");

        GameObject Utility = GameObject.Find("Utility");

        if (!Utility.GetComponent<Paint>().eraserFlg)
        {
            //******** 消しゴム モード

            //Flgを変更
            Utility.GetComponent<Paint>().eraserFlg = true;

        }
        else
        {
            //******** 消しゴム モードを解除

            //Flgを変更
            Utility.GetComponent<Paint>().eraserFlg = false;

        }

    }


    // パレットカラー選択 ボタン
    public void OnClickPaletteColor()
    {
        Debug.Log("OnClickPaletteColor click!");

        //********* クリックされたオブジェクトを取得
        RaycastHit[] hits;
        //hits = Physics.SphereCastAll(pointer.position, 25.0f, Vector3.back);
        hits = Physics.SphereCastAll(Input.mousePosition, 50.0f, Vector3.back);

        foreach (var obj in hits)
        {
            Color selectColor = obj.collider.gameObject.GetComponent<Image>().color;

            //********* そのカラーを設定
            GameObject Utility = GameObject.Find("Utility");
            Utility.GetComponent<Paint>().selectColor = selectColor;                   
        }


    }


    public void OnClickAllClear()
    {
        Debug.Log("OnClickAllClear click!");

        //********* 全て削除しますか？ ダイアログ
        GameObject Utility = GameObject.Find("Utility");
        Utility.GetComponent<Paint>().AllClearMsgPanel.SetActive(true);


        //********* 全て削除
        //GameObject LineCanvas = GameObject.Find("LineCanvas");

        //foreach (Transform child in LineCanvas.transform)
        //{
        //    Destroy(child.gameObject);
        //}


    }


    public void OnClickAllClearDone()
    {        
        //********* 全て削除しますか？ ダイアログ
        GameObject Utility = GameObject.Find("Utility");
        Utility.GetComponent<Paint>().AllClearMsgPanel.SetActive(false);

        //********* 全て削除
        GameObject LineCanvas = GameObject.Find("LineCanvas");

        foreach (Transform child in LineCanvas.transform)
        {
            Destroy(child.gameObject);
        }


    }

    public void OnClickAllClearNo()
    {
        //********* 全て削除しますか？ ダイアログ
        GameObject Utility = GameObject.Find("Utility");
        Utility.GetComponent<Paint>().AllClearMsgPanel.SetActive(false);

    }


//	// Update is called once per frame
//	void Update () {
//		
//	}
}
