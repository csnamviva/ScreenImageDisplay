#pragma once
#include "CPicBox.h"
#include "CDrawGridPicBox.h"

//Use PicBox Class GridRectangle
//#define GRIDVERSION

// ScreenSplit

class ScreenSplit : public CWnd
{
	DECLARE_DYNAMIC(ScreenSplit)

public:
	ScreenSplit();
	virtual ~ScreenSplit();


	int m_nWidth;
	int m_nHeight;
	int m_n1ScreenBmData;
	int m_n4ScreenBmData;
	int m_n9ScreenBmData;
	int m_n16ScreenBmData;
	int m_nBtnSize;
	
	bool bFlag;
	//ImageData Num
	int m_nImageTypeData = 0;



	CPicBox* m_PicBox[40];
	CRect GridRect[400];

	CDrawGridPicBox* m_SetPicBox[400];
	CWnd* m_pParentWnd;
	CWnd* m_pGridWnd;

	CRect rect[20];


	void SetScreen(int nChanel, int nSetScreenNum);
	void init(CWnd* pWnd);
	void ImageSplit(int cHanel);
	void ScreenShow(CRect* pRect, int nChanel, int nScreenNum);
	void Setting(int nWith, int nHeight, int nBtnSize);
	void GetScreenImageData(int nImageData, int nChanel, int nScreenData);


protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};


