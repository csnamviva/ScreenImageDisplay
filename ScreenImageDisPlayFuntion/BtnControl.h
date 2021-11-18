#pragma once
#include <afxwin.h>
#include "ScreenSplit.h"

class BtnControl :    public CButton
{
public:
	void init(int nID, int nWidth, int nHeight, CWnd* pWnd);
	int m_nID;

	CWnd* m_pParentWnd;

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

