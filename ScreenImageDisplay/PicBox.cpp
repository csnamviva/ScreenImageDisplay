// PicBox.cpp: 구현 파일
//

#include "pch.h"
#include "ScreenImageDisplay.h"
#include "PicBox.h"


// PicBox

IMPLEMENT_DYNAMIC(PicBox, CWnd)

PicBox::PicBox()
{

}

PicBox::~PicBox()
{
}


BEGIN_MESSAGE_MAP(PicBox, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// PicBox 메시지 처리기




void PicBox::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CWnd::OnPaint()을(를) 호출하지 마십시오.
	//dc.TextOut(0,0,"");
	//test2
	//test3222
	//test3
}
