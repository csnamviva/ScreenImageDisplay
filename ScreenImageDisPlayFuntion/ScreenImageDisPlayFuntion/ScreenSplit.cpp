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

void ScreenSplit::SetScreen(int nChanelData)
{
	//nData = 1/2/3/4 -> for roof Num
	int nData = nChanelData;

	//nChanel = 1/4/9/16 -> ScreenRect Num
	int nChanel = nChanelData * nChanelData;

	int nRectRight, nnRectBottom;
	int nRectLeft = 0;
	int nRectTop = 0;
	int nWidth = m_nWidth / nData;
	int nHeight= m_nHeight / nData;
	
	for (int n = 0; n < nData; n++)
	{
		for (int m = 0; m < nData; m++)
		{
			nRectLeft = m * nWidth + m_nBtnSize;
			nRectRight = nRectLeft + nWidth;
			nRectTop = nHeight * n;
			nnRectBottom = nRectTop + nHeight;

			rect[m + (n * nData)].left = nRectLeft;
			rect[m + (n * nData)].right = nRectRight;
			rect[m + (n * nData)].top = nRectTop;
			rect[m + (n * nData)].bottom = nnRectBottom;
		}
	}
	ScreenShow(rect, nChanel);
}


void ScreenSplit::ScreenShow(CRect* pRect, int nChanel)
{
	//Set Screen Show
	CRect* pRectData = pRect;
	int m_nChanel = nChanel;

	for (int i = 0; i < 16; i++) {
		m_PicBox[i]->ShowWindow(SW_HIDE);
	}

	for (int i = 0; i < m_nChanel; i++)
	{
		int Width = pRectData->right - pRectData->left;
		int height = pRectData->bottom - pRectData->top;
		m_PicBox[i]->MoveWindow(pRectData->left, pRectData->top, Width, height);
		m_PicBox[i]->ShowWindow(SW_SHOW);
		m_PicBox[i]->SetPicBox(i+1);
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


