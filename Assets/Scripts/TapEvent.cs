using System.Collections;
using System.Collections.Generic;
using UnityEngine;


//20170225 okamura作成
public class TapEvent : MonoBehaviour {

	public string targetURL = "https://universe.hiliberate.biz/hlar/";

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {

//		//タップ回数が０を超えたら
//		if (0 < Input.touchCount)
//		{
//			//タッチした回数までループする
//			for (int i = 0; i < Input.touchCount; i++) {
//
//				// タッチ情報をコピー
//				Touch t = Input.GetTouch(i);
//				//タッチした座標を取得
//				Vector2 worldPoint = Camera.main.ScreenToWorldPoint(t.position);
//
//				//タッチした座標にレイを飛ばす
//				RaycastHit2D hit = Physics2D.Raycast (worldPoint, Vector2.zero);
//
//				//レイを飛ばしてオブジェクトがあったら
//				if (hit.collider != null) {
//
//					//ゲームオブジェクトの名前表示
//					Debug.Log(hit.collider.gameObject.name);
//
//					//ここにタップされた時の処理を書いていく
//				}
//			}
//		}

		GameObject obj = getClickObject ();
		if (obj != null) {
			if (obj.name == "TargetMenuPlane") {

				// 以下オブジェクトがクリックされた時の処理
				Application.OpenURL(targetURL);
			}
		}
	
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

}
