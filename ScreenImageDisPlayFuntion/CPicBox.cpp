// CPicBox.cpp: 구현 파일
//

#include "pch.h"
#include "ScreenImageDisPlayFuntion.h"
#include "CPicBox.h"


// CPicBox

IMPLEMENT_DYNAMIC(CPicBox, CWnd)

CPicBox::CPicBox()
{

}

CPicBox::~CPicBox()
{
}


BEGIN_MESSAGE_MAP(CPicBox, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CPicBox 메시지 처리기




void CPicBox::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CWnd::OnPaint()을(를) 호출하지 마십시오.
	dc.TextOut(0, 0, "");
}
