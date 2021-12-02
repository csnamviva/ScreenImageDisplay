// CDrawGridPicBox.cpp: 구현 파일
//

#include "pch.h"
#include "ScreenImageDisPlayFuntion.h"
#include "CDrawGridPicBox.h"


// CDrawGridPicBox

IMPLEMENT_DYNAMIC(CDrawGridPicBox, CWnd)

CDrawGridPicBox::CDrawGridPicBox()
{

}

CDrawGridPicBox::~CDrawGridPicBox()
{
}


BEGIN_MESSAGE_MAP(CDrawGridPicBox, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CDrawGridPicBox 메시지 처리기



void CDrawGridPicBox::init(CWnd* pWnd, CRect* pRect)
{
	m_pParentWnd = pWnd;
	m_pParentRect = pRect;
}



void CDrawGridPicBox::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CWnd::OnPaint()을(를) 호출하지 마십시오.
	//Pen.CreatePen(PS_SOLID, 10, RGB(255,0,0));
	//Brush.CreateStockObject(NULL_BRUSH);
}


void CDrawGridPicBox::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CWnd::OnLButtonDown(nFlags, point);

	TRACE("%d, %d\n", point.x, point.y);
}
