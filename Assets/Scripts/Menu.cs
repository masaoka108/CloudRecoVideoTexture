using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Menu : MonoBehaviour {

//	public Shader shader1;
//	public Shader shader2;
//	public Renderer rend;
	public Material material;

	public Texture menu_icon;

	void OnGUI () {
		// ボタンを表示する
//		if ( GUI.Button(new Rect(50, 50, 100, 100), "Button") ) {

		//これは恐らく使用していない(2017/7/23)
//		// ボタンを半透明化
//		GUI.color = new Color(1,1,1,0.5f);
//
//		// ボタン押下時の動き
//		if ( GUI.Button(new Rect(25, 25, 100, 100), menu_icon) ) {
//			Debug.Log("Button is clicked.");
//			Application.OpenURL("https://universe.hiliberate.biz/hlar/target/");
//		}
	}

	// Use this for initialization
	void Start () {
//		this.material = renderer.material;
	}
	
	//// Update is called once per frame
	//void Update () {
		
	//}
}
