#pragma once


// CDrawGridRectangle

class CDrawGridRectangle : public CWnd
{
	DECLARE_DYNAMIC(CDrawGridRectangle)

public:
	CDrawGridRectangle();
	virtual ~CDrawGridRectangle();

	void init(CWnd* pWnd);

	CWnd* m_pParentWnd;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


