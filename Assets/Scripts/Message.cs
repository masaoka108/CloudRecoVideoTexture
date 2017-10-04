using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Message : MonoBehaviour {

//	public MessageBoxButtons buttons = MessageBoxButtons.YesNo;
//	public MessageBoxIcon icon = MessageBoxIcon.None;
//	public MessageBoxDefaultButton defaultButton = MessageBoxDefaultButton.Button1;


	// Use this for initialization
	void Start () {

		Debug.Log("Message.cs:start");

//		if (UnityEditor.EditorUtility.DisplayDialog("Game Over", "Again?", "Restart", "Exit"))
//		{
//			Application.LoadLevel (0); 
//		}
//		else
//		{
//			Application.Quit();
//		}

//		MessageBox.Show(Callback, "Hello World!", "Hello", buttons, icon, defaultButton);

//		//using UnityEditor;を記述しておけば、最初のUnityEditorは省略可
//		//引数はタイトル,メッセージ,OKボタンのテキスト,Canselボタンのテキスト
//		//OKボタンのみ
//		UnityEditor.EditorUtility.DisplayDialog("Notice", "Hello!", "OK");
//		//Canselボタンあり、OKかCanselかで処理分けする場合
//		bool b = UnityEditor.EditorUtility.DisplayDialog("Notice", "Do you buy?", "yes", "no");
//		if(b) {
//			//購入する
//		} else {
//			//購入しない
//		}
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
