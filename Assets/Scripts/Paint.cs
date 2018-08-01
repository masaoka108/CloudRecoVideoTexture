using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class Paint : MonoBehaviour
{
    public GameObject blockPrefab;
    public GameObject linePrefab;
    public Camera cameraObj;
    public GameObject parentObj;

    public bool paintFlg = false; // trueでペイント状態
    public bool eraserFlg = false; // trueで消しゴム状態

    public GameObject EraseButton = null;
    public GameObject CanvasPalette = null;

    public Color selectColor = Color.black;

    public Camera CameraNow = null;

    private RaycastHit Hit;

    private Vector3 beforePos = new Vector3(0, 0, 0);

    public GameObject AllClearMsgPanel;

    void Start()
    {
        //消しゴム ボタンを非表示
        EraseButton = GameObject.Find("EraseButton");
        EraseButton.SetActive(false);

        CanvasPalette = GameObject.Find("CanvasPalette");
        CanvasPalette.SetActive(false);

        //メッセージBOX を非表示
        AllClearMsgPanel.SetActive(false);
    }

    // マウスボタンを離した時にコールされる
    void OnMouseUp()
    {
        print("MouseUp!");
        beforePos = new Vector3(0, 0, 0);
    }

    void Update()
    {

        if (Input.GetMouseButtonUp(0))
        {
            beforePos = new Vector3(0, 0, 0);
        }
        

        if (Input.GetMouseButton(0))
        {

            bool raycastflg = false;
            PointerEventData pointer = new PointerEventData(EventSystem.current);
            pointer.position = Input.mousePosition;
            List<RaycastResult> result = new List<RaycastResult>();
            EventSystem.current.RaycastAll(pointer, result);


            foreach (RaycastResult raycastResult in result)
            {
                //Debug.Log(raycastResult.gameObject.name);
                raycastflg = true;
            }

    
            // 消しゴム モードの場合は削除
            if (eraserFlg) {

                RaycastHit[] hits;
                //hits = Physics.SphereCastAll(pointer.position, 25.0f, Vector3.back);
                hits = Physics.SphereCastAll(pointer.position, 50.0f, Vector3.back);

                foreach (var obj in hits)
                {
                    raycastflg = true;

                    if (eraserFlg == true && obj.collider.gameObject.name == "WhiteRounded(Clone)")
                    {
                        Destroy(obj.collider.gameObject);
                    }
                }
             }



            //******** UI オブジェクトがある場合は何もしない
            if (paintFlg && !eraserFlg && !raycastflg)
            {

                //******** ペイントする
                //前回のpositionと今回のポジションを線で結ぶ

                if(beforePos == new Vector3(0, 0, 0)) {
                    //初期の場合
                    beforePos = Input.mousePosition;

                    //**** クリックされた場所を取得
                    var placePosition = Input.mousePosition;

                    //**** 色替え
                    Color lineColor = selectColor;
                    blockPrefab.GetComponent<Image>().color = lineColor;

                    GameObject blackDots = Instantiate(blockPrefab, placePosition, Quaternion.identity);
                    blackDots.layer = 2;
                    blackDots.transform.parent = parentObj.transform;

                } else {
                    //すでに前回情報がある場合



                    //******** ペイントする 画像を置く方法
                    //Debug.Log("click!");

                    //**** クリックされた場所を取得
                    var placePosition = Input.mousePosition;

                    //**** 色替え
                    //Color lineColor = new Color(93.0f / 255.0f, 93.0f / 255.0f, 93.0f / 255.0f, 120.0f / 255.0f);
                    Color lineColor = selectColor;
                    blockPrefab.GetComponent<Image>().color = lineColor;

                    //**** サイズ、位置、角度を変える
                    RectTransform rt = blockPrefab.GetComponent(typeof(RectTransform)) as RectTransform;
                    rt.sizeDelta = new Vector2(10, (beforePos - placePosition).magnitude * 1.2f);
                    var degree = GetAim(beforePos, placePosition);
                    if (degree > 0.0f) {
                        Debug.Log(degree);
                    }
                    Debug.Log("rotate_set");
                    Debug.Log(degree);
                    //blockPrefab.transform.Rotate(new Vector3(0, 0, degree));
                    //blockPrefab.transform.eulerAngles = new Vector3(0, 0, degree);
                        

                    //**** その場所にオブジェクトを置く
                    var midPos = new Vector3((beforePos.x + placePosition.x) / 2, (beforePos.y + placePosition.y) / 2, (beforePos.z + placePosition.z) / 2);
                    GameObject blackDots = Instantiate(blockPrefab, midPos, Quaternion.identity);
                    blackDots.transform.parent = parentObj.transform;

                    //**** 角度をつける
                    blackDots.transform.eulerAngles = new Vector3(0, 0, degree + 90);
























                    ////******** これで一応空間にLineは追加されている。
                    ////まず、Game Objectを追加する
                    //GameObject lineObj = Instantiate(linePrefab);
                    //Renderer lineObjRenderer = lineObj.GetComponent<Renderer>();
                    //lineObjRenderer.enabled = true;
                    //lineObj.transform.parent = parentObj.transform;
                    //LineRenderer line = lineObj.GetComponent<LineRenderer>();
                    //line.SetPosition(0, beforePos);
                    //line.SetPosition(1, Input.mousePosition);
                    //line.startWidth = 50.0f;
                    //line.endWidth = 50.0f;
                    //line.sortingLayerName = "Default";
                    //line.sortingOrder = 1;
















                    //SpriteTexture spriteTexture = new SpriteTexture(8, 8, new Vector2(0, 1));
                    //VectorLine.SetLine(Color.white, new Vector2(10, 50), new Vector2(50, 120));


                    ////**** 色替え
                    ////Color lineColor = new Color(93.0f / 255.0f, 93.0f / 255.0f, 93.0f / 255.0f, 120.0f / 255.0f);
                    //Color lineColor = new Color(1.0f, 0.0f, 0.0f, 1.0f);

                    //// 元の画像の赤色のデータのみで表示される。
                    //blockPrefab.GetComponent<Image>().color = lineColor;

                    ////**** その場所にオブジェクトを置く
                    //GameObject blackDots = Instantiate(blockPrefab, placePosition, Quaternion.identity);
                    //GameObject blackDots = Instantiate(blockPrefab, placePosition, Quaternion.identity);
                    //blackDots.transform.parent = parentObj.transform;


                    //Renderer[] rendererComponents = parentObj.GetComponentsInChildren<Renderer>();
                    //Collider[] colliderComponents = parentObj.GetComponentsInChildren<Collider>();

                    //// Enable rendering:
                    //foreach (Renderer component in rendererComponents)
                    //{
                    //    component.enabled = true;
                    //}

                    //// Enable colliders:
                    //foreach (Collider component in colliderComponents)
                    //{
                    //    component.enabled = true;
                    //}


                    //**** ポジション情報を更新
                    beforePos = Input.mousePosition;
                }





            }


        } else {
            beforePos = new Vector3(0, 0, 0);
        }
    }




    public float GetAim(Vector2 p1, Vector2 p2)
    {
        //float dx = p2.x - p1.x;
        //float dy = p2.y - p1.y;
        //float rad = Mathf.Atan2(dy, dx);
        //return rad * Mathf.Rad2Deg;

    
        Vector2 dif = p1 - p2;
        float radian = Mathf.Atan2(dif.y, dif.x);
        float degree = radian * Mathf.Rad2Deg;
        return degree;
    }
}


