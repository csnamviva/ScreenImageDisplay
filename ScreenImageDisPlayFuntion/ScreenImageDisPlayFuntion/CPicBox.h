#pragma once


// CPicBox

class CPicBox : public CWnd
{
	DECLARE_DYNAMIC(CPicBox)

public:
	CPicBox();
	virtual ~CPicBox();

	int m_nScreenNum;
	CString Str;

	void SetPicBox(int nScreenNum);

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


