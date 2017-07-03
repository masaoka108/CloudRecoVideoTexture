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
		GUI.color = new Color(1,1,1,0.5f);
		if ( GUI.Button(new Rect(25, 25, 100, 100), menu_icon) ) {
			Debug.Log("Button is clicked.");
			Application.OpenURL("http://52.54.232.130:8000/hlar/target/");
		}
	}

	// Use this for initialization
	void Start () {
//		this.material = renderer.material;
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
