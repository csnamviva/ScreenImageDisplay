#pragma once

// CPicBox

class CPicBox : public CWnd
{
	DECLARE_DYNAMIC(CPicBox)

public:
	CPicBox();
	virtual ~CPicBox();

	int m_nImageType;
	int m_nScreenNum;
	int m_nChanel;
	int m_nSaveScreenNum;
	int m_nWidth;
	int m_nHeight;
	//1, 2, ,3, 4
	int m_nChanelData;


	bool m_bScreenNumUseFlag;

	CString Str;
	CWnd* m_pParentWnd;


	TCHAR  m_szFile[255];

	//ScreenSplit m_ScreenSplit;
	void SetPicBox(int nScreenNum, CWnd* pWnd, int nChanel, bool bScreenNumUse);
	void Setting(int Chanel);

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


