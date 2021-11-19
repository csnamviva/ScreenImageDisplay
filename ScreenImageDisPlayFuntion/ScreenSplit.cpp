// ScreenSplit.cpp: 구현 파일
//

#include "pch.h"
#include "ScreenImageDisPlayFuntion.h"
#include "ScreenSplit.h"


// ScreenSplit

IMPLEMENT_DYNAMIC(ScreenSplit, CWnd)

ScreenSplit::ScreenSplit()
{

}

ScreenSplit::~ScreenSplit()
{
	if (m_PicBox != NULL) {
		for (int i = 0; i < 16; i++) {
			m_PicBox[i]->DestroyWindow();
			delete m_PicBox[i];
			m_PicBox[i] = NULL;
		}
	}
}

void ScreenSplit::Setting(int nWith, int nHeight, int nBtnSize)
{
	m_nWidth = nWith;
	m_nHeight = nHeight;
	m_nBtnSize = nBtnSize;
}

void ScreenSplit::init(CWnd* pWnd)
{
	m_pParentWnd = pWnd;

	DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TILED;
	char szName[100];
	RECT rect = { 0,0,0,0 };
	for (int i = 0; i < 16; i++) {

		m_PicBox[i] = new CPicBox();

		sprintf_s(szName, 100, "name_%d", i);
		m_PicBox[i]->Create(NULL, "1", dwStyle, rect, m_pParentWnd, 1001 + i);
		m_PicBox[i]->ShowWindow(SW_HIDE);
	}

	//ImageFile Setting
	TCHAR strReadIni1[20] = { 0 };
	TCHAR strReadIni2[20] = { 0 };
	TCHAR strReadIni3[20] = { 0 };
	TCHAR strReadIni4[20] = { 0 };

	CString strPathIni = "D:\\test.ini";
	::GetPrivateProfileString("1ScreenImageType", "ImageType", "1", strReadIni1, 20, strPathIni);
	::GetPrivateProfileString("4ScreenImageType", "ImageType", "2", strReadIni2, 20, strPathIni);
	::GetPrivateProfileString("9ScreenImageType", "ImageType", "3", strReadIni3, 20, strPathIni);
	::GetPrivateProfileString("16ScreenImageType", "ImageType", "4", strReadIni4, 20, strPathIni);

	m_n1ScreenBmData = atoi(strReadIni1);
	m_n4ScreenBmData = atoi(strReadIni2);
	m_n9ScreenBmData = atoi(strReadIni3);
	m_n16ScreenBmData = atoi(strReadIni4);
}


void ScreenSplit::Set1Screen()
{
	m_nChanel = 1;
	for (int i = 0; i < m_nChanel; i++)
	{
		rect[i].left = m_nBtnSize;
		rect[i].right = m_nWidth + m_nBtnSize;
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
			rect[i].left = m_nBtnSize + m_nWidth / 2;
			rect[i].right = m_nWidth + m_nBtnSize;
		}
		if (i % 2 == 0)
		{
			rect[i].left = m_nBtnSize;
			rect[i].right = m_nWidth / 2 + m_nBtnSize;
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
	ScreenShow(rect, m_nChanel);
}

void ScreenSplit::Set9Screen()
{
	m_nChanel = 9;

	for (int i = 0; i < m_nChanel; i++) {
		if (i % 3 == 1) {
			rect[i].left = m_nWidth / 3 + m_nBtnSize;
			rect[i].right = (m_nWidth / 3) * 2 + m_nBtnSize;
		}
		if (i % 3 == 2) {
			rect[i].left = (m_nWidth / 3) * 2 + m_nBtnSize;
			rect[i].right = m_nWidth + m_nBtnSize;
		}
		if (i % 3 == 0) {
			rect[i].left = 0 + m_nBtnSize;
			rect[i].right = m_nWidth / 3 + m_nBtnSize;
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
	ScreenShow(rect, m_nChanel);
}

void ScreenSplit::Set16Screen()
{
	m_nChanel = 16;
	for (int i = 0; i < m_nChanel; i++) {
		if (i % 4 == 1) {
			rect[i].left = m_nWidth / 4 + m_nBtnSize;
			rect[i].right = (m_nWidth / 4) * 2 + m_nBtnSize;
		}
		if (i % 4 == 2) {
			rect[i].left = (m_nWidth / 4) * 2 + m_nBtnSize;
			rect[i].right = (m_nWidth / 4) * 3 + m_nBtnSize;
		}
		if (i % 4 == 3) {
			rect[i].left = (m_nWidth / 4) * 3 + m_nBtnSize;
			rect[i].right = m_nWidth + m_nBtnSize;
		}
		if (i % 4 == 0) {
			rect[i].left = 0 + m_nBtnSize;
			rect[i].right = m_nWidth / 4 + m_nBtnSize;
		}
		if (i < 4) {
			rect[i].top = 0;
			rect[i].bottom = m_nHeight / 4;
		}
		if ((3 < i) && (i < 8)) {
			rect[i].top = m_nHeight / 4;
			rect[i].bottom = m_nHeight / 2;
		}
		if ((7 < i) && (i < 12)) {
			rect[i].top = m_nHeight / 2;
			rect[i].bottom = (m_nHeight / 4) * 3;
		}
		if ((11 < i) && (i < 16)) {
			rect[i].top = (m_nHeight / 4) * 3;
			rect[i].bottom = m_nHeight;
		}
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
	int nChanelData = nChanel;
	int nScreenData = 0;
	int nImageTypeData = 0;

	if (nChanel == 1) {
		nScreenData = nChanelData / 1;
		nImageTypeData = m_n1ScreenBmData;
	}
	else if (nChanel == 4)
	{
		nScreenData = nChanelData / 2;
		nImageTypeData = m_n4ScreenBmData;
	}
	else if (nChanel == 9)
	{
		nScreenData = nChanelData / 3;
		nImageTypeData = m_n9ScreenBmData;
	}
	else if (nChanel == 16)
	{
		nScreenData = nChanelData / 4;
		nImageTypeData = m_n16ScreenBmData;
	}

	GetScreenImageData(nImageTypeData, nChanelData, nScreenData);
}

void ScreenSplit::GetScreenImageData(int nImageData, int nChanel, int nScreenData)
{
	CDC memDC;
	CDC* pDC = m_pParentWnd->GetDC();
	CBitmap bmp, * pOldBmp;
	BITMAP bm;

	int nImageType = nImageData;
	int nChanelData = nChanel;
	int nScreenTypeData = nScreenData;

	switch (nImageType)
	{
	case 1:
		bmp.m_hObject = (HBITMAP)LoadImage(NULL,
			_T("d:\\temp\\face.bmp"),
			IMAGE_BITMAP,
			0, 0,
			LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);

		if (bmp.m_hObject == NULL) return;
		break;
	case 2:
		bmp.m_hObject = (HBITMAP)LoadImage(NULL,
			_T("d:\\temp\\2.bmp"),
			IMAGE_BITMAP,
			0, 0,
			LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);

		if (bmp.m_hObject == NULL) return;
		break;
	case 3:
		bmp.m_hObject = (HBITMAP)LoadImage(NULL,
			_T("d:\\temp\\3.bmp"),
			IMAGE_BITMAP,
			0, 0,
			LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);

		if (bmp.m_hObject == NULL) return;
		break;
	case 4:
		bmp.m_hObject = (HBITMAP)LoadImage(NULL,
			_T("d:\\temp\\1.bmp"),
			IMAGE_BITMAP,
			0, 0,
			LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);

		if (bmp.m_hObject == NULL) return;
		break;
	}
	bmp.GetBitmap(&bm);
	memDC.CreateCompatibleDC(pDC);
	pOldBmp = memDC.SelectObject(&bmp);
	for (int i = 0; i < nChanelData; i++) {
		int nX = rect[i].left;
		int nY = rect[i].top;
		pDC->StretchBlt(nX, nY, m_nWidth / nScreenTypeData, m_nHeight / nScreenTypeData
			, &memDC,
			0, 0, bm.bmWidth, bm.bmHeight,
			SRCCOPY);
	}
	memDC.SelectObject(pOldBmp);
	m_pParentWnd->ReleaseDC(pDC);
}


BEGIN_MESSAGE_MAP(ScreenSplit, CWnd)
END_MESSAGE_MAP()



// ScreenSplit 메시지 처리기


