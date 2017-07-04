﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class HlButton : MonoBehaviour {

	/// ボタンをクリックした時の処理
	public void OnClick() {
		Debug.Log("Button click!");
		Application.OpenURL("http://52.54.232.130:8000/hlar/target/");
	}

	// Use this for initialization
	void Start () {
		Image _This = this.GetComponent<Image>();
		_This.color = new Color(1,1,1,0.5f);

	}
	
//	// Update is called once per frame
//	void Update () {
//		
//	}
}
