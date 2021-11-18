#pragma once
#include <afxwin.h>
#include "ScreenSplit.h"

class MyButton :   public CButton
{

public:
	void init(int nID, int nWidth, int nHeight, CWnd* pWnd);
	int m_nID;

	//CScreenImageDisplayDlg* m_pParentWnd;
	CWnd*   m_pParentWnd;
	bool m_bPress;
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

/////////////////////////////////


//	afx_msg void OnDestroy();
};

