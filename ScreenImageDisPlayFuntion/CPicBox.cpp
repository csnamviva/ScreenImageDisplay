// CPicBox.cpp: 구현 파일
//

#include "pch.h"
#include "ScreenImageDisPlayFuntion.h"
#include "CPicBox.h"
#include "ScreenSplit.h"


// CPicBox
class ScreenSplit;


IMPLEMENT_DYNAMIC(CPicBox, CWnd)

CPicBox::CPicBox()
{

}

CPicBox::~CPicBox()
{
}


BEGIN_MESSAGE_MAP(CPicBox, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CPicBox 메시지 처리기




void CPicBox::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CWnd::OnPaint()을(를) 호출하지 마십시오.

	CDC memDC;
	CDC* pDC = this->GetDC();

	CBitmap bmp, * pOldBmp;
	BITMAP bm;


	
	if (m_bScreenNumUseFlag) {
		CString str;
		str.Format("%d", m_nScreenNum);
		dc.TextOut(0, 0, str);
	
		bmp.m_hObject = (HBITMAP)LoadImage(NULL,        //이미지도 같은 디렉토리에서 읽어오도록 수정
			m_szFile,
			IMAGE_BITMAP,
			0, 0,
			LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);

		if (bmp.m_hObject == NULL) return;

		bmp.GetBitmap(&bm);
		memDC.CreateCompatibleDC(&dc);
		pOldBmp = memDC.SelectObject(&bmp);
		//dc.StretchBlt(0, 0, m_nWidht, m_nHeight , &memDC, 0, 0, bm.bmWidth, bm.bmHeight,	SRCCOPY);
		dc.StretchBlt(0, 0, 320,240, &memDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
		
		memDC.SelectObject(pOldBmp);
		
		ReleaseDC(pDC);

	}
}

void CPicBox::Setting(int nChanel)
{
	m_nChanel = nChanel;
}


//void CPicBox::SetPicBox(int nScreenNum, CWnd* pWnd, int nChanel, bool bScreenNumUse,int nImageType)
void CPicBox::SetPicBox(int nScreenNum, CWnd* pWnd, int nChanel, bool bScreenNumUse)
{
	int nImageType = 1;
	m_nScreenNum = nScreenNum;
	m_pParentWnd = pWnd;
	m_bScreenNumUseFlag = bScreenNumUse;


	//TCHAR szFile[255];
	TCHAR szDir[255];
	GetCurrentDirectory(255, szDir);

	switch (nImageType)
	{
	case 1:
		sprintf_s(m_szFile, 255, "%s\\image\\%s", szDir, _T("face.bmp"));
		break;
	case 2:
		sprintf_s(m_szFile, 255, "%s\\image\\%s", szDir, _T("3.bmp"));
		break;
	case 3:
		sprintf_s(m_szFile, 255, "%s\\image\\%s", szDir, _T("3.bmp"));
		break;
	case 4:
		sprintf_s(m_szFile, 255, "%s\\image\\%s", szDir, _T("1.bmp"));
		break;
	}


	
}


void CPicBox::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CWnd::OnLButtonDblClk(nFlags, point);

	if (((ScreenSplit*)m_pParentWnd)->bFlag) {
		m_nSaveScreenNum = m_nScreenNum;
		((ScreenSplit*)m_pParentWnd)->bFlag = FALSE;
	}
	else
	{
		((ScreenSplit*)m_pParentWnd)->bFlag = TRUE;
		m_nSaveScreenNum = 0;
	}
	((ScreenSplit*)m_pParentWnd)->SetScreen(m_nChanel, m_nSaveScreenNum);
}


void CPicBox::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//CWnd::OnLButtonDown(nFlags, point);

}
