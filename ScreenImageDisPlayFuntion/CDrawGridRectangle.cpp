// CDrawGridRectangle.cpp: 구현 파일
//

#include "pch.h"
#include "ScreenImageDisPlayFuntion.h"
#include "CDrawGridRectangle.h"
#include "ScreenImageDisPlayFuntionDlg.h"

class CScreenImageDisPlayFuntionDlg;

// CDrawGridRectangle

IMPLEMENT_DYNAMIC(CDrawGridRectangle, CWnd)

CDrawGridRectangle::CDrawGridRectangle()
{

}

CDrawGridRectangle::~CDrawGridRectangle()
{
}


BEGIN_MESSAGE_MAP(CDrawGridRectangle, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CDrawGridRectangle 메시지 처리기



void CDrawGridRectangle::init(CWnd* pWnd)
{
	m_pParentWnd = pWnd;
}


void CDrawGridRectangle::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CWnd::OnPaint()을(를) 호출하지 마십시오.
	CDC* pDC;
	pDC = GetDC();
	int WidthSize = 24;
	int HeightSize = 16;
	int nGridTotalHeight = 150;
	int nGridLeft = BTN_WIDTH;
	int nGridWidth = ((CScreenImageDisPlayFuntionDlg*)m_pParentWnd)->nWidth / WidthSize + 10;
	int	nGridHeight = nGridTotalHeight / HeightSize;

	

	((CScreenImageDisPlayFuntionDlg*)m_pParentWnd)->m_nGridRectWidth = nGridWidth;
	((CScreenImageDisPlayFuntionDlg*)m_pParentWnd)->m_nGridRectHeight = nGridHeight;

	for (int j = 0; j < HeightSize; j++) {
		for (int i = 0; i < WidthSize; i++) {
			pDC->Rectangle(nGridLeft + (nGridWidth * i), (((CScreenImageDisPlayFuntionDlg*)m_pParentWnd)->nHeight + 30) + (nGridHeight * j),
				nGridLeft + (nGridWidth * (i + 1)), (((CScreenImageDisPlayFuntionDlg*)m_pParentWnd)->nHeight + 30) + (nGridHeight * (j + 1)));
		}
	}
	((CScreenImageDisPlayFuntionDlg*)m_pParentWnd)->SaveGridRect.left = nGridLeft;
	((CScreenImageDisPlayFuntionDlg*)m_pParentWnd)->SaveGridRect.top = (((CScreenImageDisPlayFuntionDlg*)m_pParentWnd)->nHeight + 30);
	((CScreenImageDisPlayFuntionDlg*)m_pParentWnd)->SaveGridRect.right = nGridLeft + (nGridWidth * (24));
	((CScreenImageDisPlayFuntionDlg*)m_pParentWnd)->SaveGridRect.bottom = (((CScreenImageDisPlayFuntionDlg*)m_pParentWnd)->nHeight + 30) + (nGridHeight * (16));
	ReleaseDC(pDC);
	CRect Rect(210, 500, 1250, 968);
	InvalidateRect(Rect, FALSE);

}
