#pragma once


// ScreenDisPlayFuntion

class ScreenDisPlayFuntion : public CWnd
{
	DECLARE_DYNAMIC(ScreenDisPlayFuntion)

public:
	ScreenDisPlayFuntion();
	virtual ~ScreenDisPlayFuntion();


	void ScreenSplitDisPlay(int nChanel);
	void ImageSplit(int nChanel, CWnd* pWnd);
	void Split(int nChanel);
	void SetRect(CRect* rect, int size);

protected:
	DECLARE_MESSAGE_MAP()
};


