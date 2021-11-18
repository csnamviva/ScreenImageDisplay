// ScreenSplit.cpp: 구현 파일
//

#include "pch.h"
#include "ScreenImageDisplay.h"
#include "ScreenSplit.h"


// ScreenSplit

IMPLEMENT_DYNAMIC(ScreenSplit, CWnd)

ScreenSplit::ScreenSplit()
{

}

ScreenSplit::~ScreenSplit()
{
	for (int i = 0; i < 16; i++) {
		delete m_PicBox[i];
	}
}

void ScreenSplit::init(int nWidth, int nHeight, CWnd* pWnd)
{
	m_nWidth = nWidth;
	m_nHeight = nHeight;

	m_pParentWnd = pWnd;

	DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TILED;
	char szName[100];
	RECT rect = { 0,0,0,0 };
	for (int i = 0; i < 16; i++) {

		m_PicBox[i] = new  PicBox();

		sprintf_s(szName, 100, "name_%d", i);
		m_PicBox[i]->Create(NULL, "1", dwStyle, rect, m_pParentWnd, 1001 + i);
		m_PicBox[i]->ShowWindow(SW_HIDE);
	}
}


void ScreenSplit::Set1Screen()
{
	m_nChanel = 1;
	for (int i = 0; i < m_nChanel; i++)
	{
		rect[i].left = 0;
		rect[i].right = m_nWidth;
		rect[i].top = 0;
		rect[i].bottom = m_nHeight;
	}
	ScreenShow(rect, m_nChanel);
}

void ScreenSplit::Set4Screen()
{
	m_nChanel = 4;
	for (int i = 0; i < m_nChanel; i++) {
		if (i % 2 == 1)
		{
			rect[i].left = m_nWidth / 2;
			rect[i].right = m_nWidth;
		}
		if (i % 2 == 0)
		{
			rect[i].left = 0;
			rect[i].right = m_nWidth / 2;
		}
		if (i < 2) {
			rect[i].top = 0;
			rect[i].bottom = m_nHeight / 2;
		}
		else if (1 < i) {
			rect[i].top = m_nHeight / 2;
			rect[i].bottom = m_nHeight;
		}
	}

	//
	//for (int i = 0; i < m_nChanel; i++)
	//{
	//	rect[i].left = 0;
	//	rect[i].right = m_nWidth;
	//	rect[i].top = 0;
	//	rect[i].bottom = m_nHeight;
	//}
	ScreenShow(rect, m_nChanel);
}

void ScreenSplit::Set9Screen()
{
	m_nChanel = 9;

	for (int i = 0; i < m_nChanel; i++) {
		if (i % 3 == 1) {
			rect[i].left = m_nWidth / 3;
			rect[i].right = (m_nWidth / 3) * 2;
		}
		if (i % 3 == 2) {
			rect[i].left = (m_nWidth / 3) * 2;
			rect[i].right = m_nWidth;
		}
		if (i % 3 == 0) {
			rect[i].left = 0;
			rect[i].right = m_nWidth / 3;
		}
		if (i < 3) {
			rect[i].top = 0;
			rect[i].bottom = m_nHeight / 3;
		}
		if ((2 < i) && (i < 6)) {
			rect[i].top = m_nHeight / 3;
			rect[i].bottom = (m_nHeight / 3) * 2;
		}
		if ((5 < i) && (i < 9)) {
			rect[i].top = (m_nHeight / 3) * 2;
			rect[i].bottom = m_nHeight;
		}
	}

	//for (int i = 0; i < m_nChanel; i++)
	//{
	//	rect[i].left = 0;
	//	rect[i].right = m_nWidth;
	//	rect[i].top = 0;
	//	rect[i].bottom = m_nHeight;
	//}
	ScreenShow(rect, m_nChanel);
}

void ScreenSplit::Set16Screen()
{
	m_nChanel = 16;
	for (int i = 0; i < m_nChanel; i++)
	{
		rect[i].left = 0;
		rect[i].right = m_nWidth;
		rect[i].top = 0;
		rect[i].bottom = m_nHeight;
	}
	ScreenShow(rect, m_nChanel);
}

void ScreenSplit::ScreenShow(CRect* pRect, int nChanel)
{
	CRect* pRectData = pRect;
	m_nChanel = nChanel;

	for (int i = 0; i < 16; i++) {
		m_PicBox[i]->ShowWindow(SW_HIDE);
	}

	for (int i = 0; i < m_nChanel; i++)
	{
		int Width = pRectData->right - pRectData->left;
		int height = pRectData->bottom - pRectData->top;
		m_PicBox[i]->MoveWindow(pRectData->left, pRectData->top, Width, height);
		m_PicBox[i]->ShowWindow(SW_SHOW);
		pRectData++;
	}
	ImageSplit(m_nChanel);
}

void ScreenSplit::ImageSplit(int nChanel)
{
	CDC memDC;
	CDC* pDC = m_pParentWnd->GetDC();
	CBitmap bmp, * pOldBmp;
	BITMAP bm;

	//1.이미지 로딩하기  
	bmp.m_hObject = (HBITMAP)LoadImage(NULL,
		_T("d:\\temp\\face.bmp"),
		IMAGE_BITMAP,
		0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);

	if (bmp.m_hObject == NULL) return;

	//2.이미지 정보를 얻기 위해서 ,여기서는 이미지 크기를 구하기 위해서   
	bmp.GetBitmap(&bm);

	//3.화면DC가 화면에 뿌리기 전에 데이터를 임시로 저장해주는 역할  
	memDC.CreateCompatibleDC(pDC);

	//4.메모리DC가 로딩된 비트맵정보를 읽어들인다.  
	pOldBmp = memDC.SelectObject(&bmp);

	if (nChanel == 1) {
		//6.화면에 뿌린다.(메모리DC에서 화면DC로 고속복사로 뿌린다)  
		pDC->StretchBlt(0, 0, m_nWidth, m_nHeight
			, &memDC,
			0, 0, bm.bmWidth, bm.bmHeight,
			SRCCOPY);
	}
	if (nChanel == 4) {
		for (int i = 0; i < 4; i++) {
			//5.이미지를 뿌릴 최초의 시작점을 구한다.  
			//GetClientRect(&rect[i]);

			int nX = rect[i].left;
			int nY = rect[i].top;

			//6.화면에 뿌린다.(메모리DC에서 화면DC로 고속복사로 뿌린다)  
			pDC->BitBlt(nX, nY,
				bm.bmWidth, bm.bmHeight,
				&memDC,
				0, 0,
				SRCCOPY);
		}
	}
	if (nChanel == 9) {
		for (int i = 0; i < 9; i++) {
			//5.이미지를 뿌릴 최초의 시작점을 구한다.  
			//GetClientRect(&rect[i]);

			int nX = rect[i].left;
			int nY = rect[i].top;

			//6.화면에 뿌린다.(메모리DC에서 화면DC로 고속복사로 뿌린다)  
			pDC->StretchBlt(nX, nY, m_nWidth / 3, m_nHeight / 3
				, &memDC,
				0, 0, bm.bmWidth, bm.bmHeight,
				SRCCOPY);
		}
	}
	if (nChanel == 16) {
		for (int i = 0; i < 16; i++) {
			//5.이미지를 뿌릴 최초의 시작점을 구한다.  
			//GetClientRect(&rect[i]);

			int nX = rect[i].left;
			int nY = rect[i].top;

			//6.화면에 뿌린다.(메모리DC에서 화면DC로 고속복사로 뿌린다)  
			pDC->StretchBlt(nX, nY, m_nWidth / 4, m_nHeight / 4
				, &memDC,
				0, 0, bm.bmWidth, bm.bmHeight,
				SRCCOPY);
		}
	}
	//7.원래의 비트맵정보로 환원한다.  
	memDC.SelectObject(pOldBmp);
	m_pParentWnd->ReleaseDC(pDC);
}


BEGIN_MESSAGE_MAP(ScreenSplit, CWnd)
//	ON_WM_DESTROY()
END_MESSAGE_MAP()



// ScreenSplit 메시지 처리기



//void ScreenSplit::OnDestroy()
//{
//	CWnd::OnDestroy();
//
//	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//	for (int i = 0; i < 16; i++) {
//		delete m_PicBox[i];
//	}
//}
