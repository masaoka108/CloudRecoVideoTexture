using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class TutorialButtonScript : MonoBehaviour {

    private Canvas[] allGO;
    private Canvas TopCanvas;
    private Canvas Top2Canvas;
    private Canvas Pc1Canvas;
    private Canvas Sp1Canvas;
    private Canvas VolumeCanvas;
    private GameObject BtnBackPage;

    private Canvas PreviousCanvas;

	// Use this for initialization
	void Start () {
        TopCanvas = GameObject.Find("TopCanvas").GetComponent<Canvas>();
        Top2Canvas = GameObject.Find("Top2Canvas").GetComponent<Canvas>();
        Pc1Canvas = GameObject.Find("Pc1Canvas").GetComponent<Canvas>();
        Sp1Canvas = GameObject.Find("Sp1Canvas").GetComponent<Canvas>();
        VolumeCanvas = GameObject.Find("VolumeCanvas").GetComponent<Canvas>();

        allGO = new Canvas[] { TopCanvas, Top2Canvas, Pc1Canvas, Sp1Canvas, VolumeCanvas };

        allSetActiveFalse();
        TopCanvas.enabled = true;

        BtnBackPage = GameObject.Find("BtnBackPage");
        BtnBackPage.SetActive(false);
	}

    public void OnClickTopToNext()
    {
        allSetActiveFalse();
        Top2Canvas.enabled = true;

        BtnBackPage.SetActive(true);

        PreviousCanvas = TopCanvas;
    }


    public void OnClickPcSp()
    {
        allSetActiveFalse();
        Pc1Canvas.enabled = true;

        BtnBackPage.SetActive(true);

        PreviousCanvas = Top2Canvas;
    }

    public void OnClickSp()
    {
        allSetActiveFalse();
        Sp1Canvas.enabled = true;

        BtnBackPage.SetActive(true);

        PreviousCanvas = Top2Canvas;
    }

    public void OnClickVolume()
    {

        PreviousCanvas = getCurrentCanvas();
        allSetActiveFalse();
        VolumeCanvas.enabled = true;
    }


    public void OnClickBackApp()
    {
        SceneManager.LoadScene("Vuforia-3-CloudReco");
 
    }

    public void OnClickCopuyUrl()
    {
        UniClipboard.SetText("https://universear.hiliberate.biz/");
    }

    public void OnPageBack()
    {
        allSetActiveFalse();
        PreviousCanvas.enabled = true;

        if (PreviousCanvas == TopCanvas)
        {
            BtnBackPage.SetActive(false);
        }

        PreviousCanvas = getPreviousCanvas();
    }


    private void allSetActiveFalse() {
        foreach (Canvas c in allGO)
        {
            c.enabled = false;
        }
    }

    private Canvas getCurrentCanvas()
    {
        foreach (Canvas c in allGO)
        {
            if (c.enabled == true) {
                return c;
            }
        }

        return null;
    }

    private Canvas getPreviousCanvas() {
        foreach (Canvas c in allGO)
        {
            if (c.enabled == true)
            {
                if (c == TopCanvas) {
                    return null;
                }
                else if (c == Top2Canvas)
                {
                    return TopCanvas;
                } else if (c == Pc1Canvas) {
                    return Top2Canvas;
                } else if (c == Sp1Canvas) {
                    return Top2Canvas;
                }
                //else if (c == VolumeCanvas) {
                //    return TopCanvas;
                //}
            }
        }

        return null;
    }

}
