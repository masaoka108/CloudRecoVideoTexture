using UnityEngine;
using UnityEngine.UI;
using System.Collections.Generic;

#if UNITY_EDITOR
using UnityEditor;
#endif

public class LocalizeUIImage : MonoBehaviour {

	[SerializeField] Sprite imageEn;
	[SerializeField] Sprite imageJp;
	[SerializeField] Sprite imageZh;
	[SerializeField] Sprite imageZhCn;
	[SerializeField] Sprite imageZhTw;
	[SerializeField] Sprite imageKo;

	void Awake() {
		Dictionary<SystemLanguage, Sprite>  dict = new Dictionary<SystemLanguage, Sprite>() {
			{ SystemLanguage.English, imageEn},
			{ SystemLanguage.Japanese, imageJp},
			{ SystemLanguage.Chinese, imageZh},
			{ SystemLanguage.ChineseSimplified, imageZhCn},
			{ SystemLanguage.ChineseTraditional, imageZhTw},
			{ SystemLanguage.Korean, imageKo},
		};

		//Change
		SystemLanguage lang = Application.systemLanguage;
		Image mImage = GetComponent<Image>();
		mImage.sprite = dict.ContainsKey(lang) ? dict[lang] : dict[SystemLanguage.English];
	}
}

#if UNITY_EDITOR
[CustomEditor(typeof(LocalizeUIImage))]
[CanEditMultipleObjects]
public class LocalizeEditorImage : Editor {

	SerializedProperty propEn;
	SerializedProperty propJp;
	SerializedProperty propZh;
	SerializedProperty propZhCn;
	SerializedProperty propZhTw;
	SerializedProperty propKo;

	void OnEnable() {
		propEn = serializedObject.FindProperty("imageEn");
		propJp = serializedObject.FindProperty("imageJp");
		propZh = serializedObject.FindProperty("imageZh");
		propZhCn = serializedObject.FindProperty("imageZhCn");
		propZhTw = serializedObject.FindProperty("imageZhTw");
		propKo = serializedObject.FindProperty("imageKo");
	}

	public override void OnInspectorGUI() {
		serializedObject.Update();

		CreateUI("English", propEn, true);
		CreateUI("Japanese", propJp, true);
		CreateUI("Chainese", propZh, true);
		CreateUI("Chainese(Simplified)", propZhCn, true);
		CreateUI("Chainese(Traditional)", propZhTw, true);
		CreateUI("Korean", propKo, false);

		serializedObject.ApplyModifiedProperties();
	}

	private void CreateUI(string label, SerializedProperty prop, bool addSpace) {
		EditorGUILayout.LabelField(label, EditorStyles.boldLabel);
		prop.objectReferenceValue = (Sprite) EditorGUILayout.ObjectField(prop.objectReferenceValue, typeof(Sprite), true);
		if(addSpace) EditorGUILayout.Space();
	}
}
#endif