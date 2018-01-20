using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Transparent : MonoBehaviour {

	// Use this for initialization
	void Start () {
		//******** 透過処理

		Image _This = this.GetComponent<Image>();
		_This.color = new Color(1,1,1,0.5f);

	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
