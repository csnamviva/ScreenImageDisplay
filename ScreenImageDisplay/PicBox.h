#pragma once


// PicBox

class PicBox : public CWnd
{
	DECLARE_DYNAMIC(PicBox)

public:
	PicBox();
	virtual ~PicBox();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


