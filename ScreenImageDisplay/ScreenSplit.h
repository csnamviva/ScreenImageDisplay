#pragma once
#include "PicBox.h"

// ScreenSplit

class ScreenSplit : public CWnd
{
	DECLARE_DYNAMIC(ScreenSplit)

public:
	ScreenSplit();
	virtual ~ScreenSplit();
////////////////////////////////////////
	int m_nChanel;
	int m_nWidth;
	int m_nHeight;

	PicBox* m_PicBox[16];
	CWnd* m_pParentWnd;

	CRect rect[20];


///////////////////////////////////////////
	void Set1Screen();
	void Set4Screen();
	void Set9Screen();
	void Set16Screen();
	void init(int nWith, int nHeight, CWnd* pWnd);
	void ImageSplit(int cHanel);
	void ScreenShow(CRect *pRect, int nChanel);

protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnDestroy();
};


