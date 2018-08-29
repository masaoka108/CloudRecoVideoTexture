using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class ButtonTransparent : MonoBehaviour {

	// Use this for initialization
	void Start () {

        //透過処理
        Image _This = this.GetComponent<Image>();
        if (_This != null && _This.name != "white_round")
        {
            _This.color = new Color(1, 1, 1, 0.5f);
        }

        ////透過処理するボタンのGameObject名
        //string[] buttons = {"PaintButton", "EraseButton"};

        //for (int i = 0; i < buttons.Length; ++i)
        //{
            
        //    Image image = GameObject.Find(buttons[i]).GetComponent<Image>();
        //    image.color = new Color(1, 1, 1, 0.5f);
        //}
		
	}
	
	//// Update is called once per frame
	//void Update () {
		
	//}
}
