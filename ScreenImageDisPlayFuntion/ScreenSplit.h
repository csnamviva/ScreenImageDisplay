#pragma once
#include "CPicBox.h"

// ScreenSplit

class ScreenSplit : public CWnd
{
	DECLARE_DYNAMIC(ScreenSplit)

public:
	ScreenSplit();
	virtual ~ScreenSplit();


	int m_nChanel;
	int m_nWidth;
	int m_nHeight;
	int m_n1ScreenBmData;
	int m_n4ScreenBmData;
	int m_n9ScreenBmData;
	int m_n16ScreenBmData;
	int m_nBtnSize;


	CPicBox* m_PicBox[16];
	CWnd* m_pParentWnd;

	CRect rect[20];


	void Set1Screen();
	void Set4Screen();
	void Set9Screen();
	void Set16Screen();
	void init(CWnd* pWnd);
	void ImageSplit(int cHanel);
	void ScreenShow(CRect* pRect, int nChanel);
	void Setting(int nWith, int nHeight, int nBtnSize);
	void GetScreenImageData(int nImageData, int nChanel, int nScreenData);


protected:
	DECLARE_MESSAGE_MAP()
};


