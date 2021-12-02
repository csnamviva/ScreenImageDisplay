#pragma once


// CDrawGridPicBox

class CDrawGridPicBox : public CWnd
{
	DECLARE_DYNAMIC(CDrawGridPicBox)

public:
	CDrawGridPicBox();
	virtual ~CDrawGridPicBox();

	void init(CWnd* pWnd, CRect* pRect);

	CWnd* m_pParentWnd;
	CRect* m_pParentRect;


protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


