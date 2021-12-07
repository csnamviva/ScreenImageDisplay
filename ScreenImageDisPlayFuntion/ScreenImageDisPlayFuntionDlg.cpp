
// ScreenImageDisPlayFuntionDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ScreenImageDisPlayFuntion.h"
#include "ScreenImageDisPlayFuntionDlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CScreenImageDisPlayFuntionDlg 대화 상자



CScreenImageDisPlayFuntionDlg::CScreenImageDisPlayFuntionDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCREENIMAGEDISPLAYFUNTION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScreenImageDisPlayFuntionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN, m_imgBg);
}

BEGIN_MESSAGE_MAP(CScreenImageDisPlayFuntionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_MYBTN_PRESS, &CScreenImageDisPlayFuntionDlg::OnButtonPress)
	ON_WM_DESTROY()

	ON_WM_MENUSELECT()
	ON_BN_CLICKED(IDC_BTN, &CScreenImageDisPlayFuntionDlg::OnBnClickedBtn)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
//	ON_WM_ERASEBKGND()
ON_BN_CLICKED(IDC_BUTTON1, &CScreenImageDisPlayFuntionDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


LRESULT CScreenImageDisPlayFuntionDlg::OnButtonPress(WPARAM wParam, LPARAM lParam)
{
	//TRACE("OnButtonPress  w= %ld   l= %ld \n", wParam, lParam);

	return 0;
}

// CScreenImageDisPlayFuntionDlg 메시지 처리기


void CScreenImageDisPlayFuntionDlg::ShowPicture()
{

//<<<<<<< HEAD
//	m_BtnControl[0]->SetWindowPos(NULL, 100, 100, 200, 200, SWP_NOSIZE);
//=======
	//m_BtnControl[0]->SetWindowPos(NULL, 100, 100, 200, 200, SWP_SHOWWINDOW);

	//m_BtnControl[0]->MoveWindow(100, 100, 200, 200);
}

BOOL CScreenImageDisPlayFuntionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	int nBtnSize = BTN_WIDTH;

	//HBITMAP hBit = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1));
	//m_imgBg.SetBitmap(hBit);
	//CRect rt;

	//hbitBase = (HBITMAP)LoadImage(NULL, _T("res\\split1_off.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);


	CString caption = _T("");
	for (int i = 0; i < MAX_BTN; i++)
	{
		m_BtnControl[i] = new BtnControl();

		caption.Format(_T("%d SplitButton"), (i + 1) * (i + 1));
		m_BtnControl[i]->Create(caption, WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TILED, CRect(10, 10 + (50 * i), BTN_WIDTH, 50 + (50 * i)), this, BTN_ID_1 + i);
		m_BtnControl[i]->init((i + 1), this);
	
		//GetClientRect(&rt);
		//m_imgBg.SetWindowPos(NULL, 10, 10 + (50 * i), BTN_WIDTH, 50 + (50 * i), SWP_SHOWWINDOW);
		//m_BtnControl[i]->SetBitmap(hbitBase);
	}

	this->m_pCalendar = new CMonthCalControl();
	m_pCalendar->Create(WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(10,240,205,435), this, ID_MONTHCONTROL);

	this->m_pListBox = new ListBox();
	m_pListBox->Create(WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(10, 450, 205, 550), this, ID_LISTBOX);

	font.CreateFont(16, 9, 0, 0, FW_LIGHT, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, 
		OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "Arial");
	m_pListBox->SetFont(&font);

	//Default Value
	int nIniWidth = 800;
	int nIniHeight = 600;
	this->m_ScreenSplit = new ScreenSplit();
	m_ScreenSplit->init(this);
	m_ScreenSplit->Setting(nIniWidth, nIniHeight, nBtnSize);

	//BackGround Bitmap LoadPart
	hbitBase = LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
	GetObject(hbitBase, sizeof(BITMAP), &m_bitmap);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CScreenImageDisPlayFuntionDlg::OnSysCommand(UINT nID, LPARAM lParam)
{

	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CScreenImageDisPlayFuntionDlg::OnPaint()
{
	CPaintDC dc(this);
	if (IsIconic())
	{
		 // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		if (m_bGridUseUnUse) {
#ifdef DCGRIDVERSION
			CDC* pDC;
			pDC = GetDC();
			int WidthSize = 24;
			int HeightSize = 16;
			int nGridTotalHeight = 150;
			int nGridLeft = BTN_WIDTH;
			int nGridWidth = nWidth / WidthSize + 10;
			int	nGridHeight = nGridTotalHeight / HeightSize;
			
			CRect pRect(210, 500, 1250, 968);

			m_nGridRectWidth = nGridWidth;
			m_nGridRectHeight = nGridHeight;

			for (int j = 0; j < HeightSize; j++) {
				for (int i = 0; i < WidthSize; i++) {
					pDC->Rectangle(nGridLeft + (nGridWidth * i), (nHeight + 30) + (nGridHeight * j), nGridLeft + (nGridWidth * (i + 1)), (nHeight + 30) + (nGridHeight * (j + 1)));
				}
			}
			SaveGridRect.left = nGridLeft;
			SaveGridRect.top = (nHeight + 30);
			SaveGridRect.right = nGridLeft + (nGridWidth * (24));
			SaveGridRect.bottom = (nHeight + 30) + (nGridHeight * (16));
			
			//InvalidateRect(pRect, FALSE);
			//////////////////////////////////////////////////
		//BackGround Image Change 
			CRect rect;
			GetWindowRect(&rect);
			
			
			CDC* pMemDC = new CDC();
			BOOL bSuccess= pMemDC->CreateCompatibleDC(pDC);
			if (bSuccess)
			{

				pMemDC->SetStretchBltMode(HALFTONE);

				pMemDC->SelectObject(hbitBase);

				pDC->StretchBlt(210, 0, nWidth + 200, nHeight, pMemDC, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
					//::StretchBlt(pDC->GetSafeHdc(), 210, 0, nWidth + 200, nHeight, hMemDC, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);

				pMemDC->DeleteDC();
			}
			
			/*
			* 
			* HDC hMemDC = CreateCompatibleDC(pDC->GetSafeHdc());
			SelectObject(hMemDC,hbitBase);
			StretchBlt(pDC->GetSafeHdc(), 210, 0, nWidth + 200, nHeight, hMemDC, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
			
			*/
			
			 
			//CRect Rect(210, 0, 1500, 968);
			//InvalidateRect(Rect, FALSE);

			TRACE("CScreenImageDisPlayFuntionDlg::OnPaint() \n");

			


			//////////////////////////////////////////////////
			delete pMemDC;
			
			ReleaseDC(pDC);
#endif
		}
	}

	

	/*CRect* pGridRectData;
	int WidthSize = 24;
	int HeightSize = 16;
	int nGridRight, nGridBottom;
	int nGridTotalHeight = 150;
	int nGridLeft = BTN_WIDTH;
	int nGridTop = 0;
	int nGridWidth = nWidth / WidthSize;
	int	nGridHeight = nGridTotalHeight / HeightSize;
	CRect GridRect[384];

	for (int j = 0; j < HeightSize; j++) {
		for (int i = 0; i < WidthSize; i++) {
			nGridLeft = i * nGridWidth + BTN_WIDTH;
			nGridRight = nGridLeft + nGridWidth;
			nGridTop = (nHeight + 20) + nGridHeight * j;
			nGridBottom = nGridTop + nGridHeight;

			GridRect[(WidthSize * j) + i].left = nGridLeft;
			GridRect[(WidthSize * j) + i].right = nGridRight;
			GridRect[(WidthSize * j) + i].top = nGridTop;
			GridRect[(WidthSize * j) + i].bottom = nGridBottom;
		}
	}
	pGridRectData = GridRect;*/

	//ScreenToClient(pGridRectData);

	//for (int i = 0; i < 384; i++) {
	//	int GridWidth = pGridRectData->right - pGridRectData->left;
	//	int Gridheight = pGridRectData->bottom - pGridRectData->top;
	//	MoveWindow(pGridRectData->left, pGridRectData->top, GridWidth, Gridheight);
	//	ShowWindow(SW_SHOW);
	//
	//	pGridRectData++;
	//}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CScreenImageDisPlayFuntionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CScreenImageDisPlayFuntionDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	for (int i = 0; i < MAX_BTN; i++)
	{
		delete m_BtnControl[i];
	}
	delete m_pCalendar;
	delete m_pListBox;
	delete m_ScreenSplit;
}

int CScreenImageDisPlayFuntionDlg::ButtonPress(int nSplit)
{
	//Setting ScreenSplit 1/4/9/16 button
	//Invalidate(FALSE);
	m_ScreenSplit->SetScreen(nSplit, 0);
	return 0;
}

void CScreenImageDisPlayFuntionDlg::OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu)
{
	CDialogEx::OnMenuSelect(nItemID, nFlags, hSysMenu);

	//MenuBar Prohibit Twice Click 
	if (!m_bMenuFlag)
	{
		GetFilePath(nItemID);
	}
	m_bMenuFlag = !m_bMenuFlag;
}


void CScreenImageDisPlayFuntionDlg::GetFilePath(int nItemID)
{
	//GetScreen Width/Height Size
	TCHAR szCurr[255];
	CString strPathIni = "D:\\test.ini";
	TCHAR strReadIni1[20] = { 0 };
	TCHAR strReadIni2[20] = { 0 };
	//RECT rect = { 0, 0, 0, 0 };

	GetCurrentDirectory(255, szCurr);
	strPathIni.Format("%s\\%s", szCurr, _T("test.ini"));
	
	int nBtnSize = BTN_WIDTH;

	if (nItemID != 0) {
		m_bGridUseUnUse = true;
		switch (nItemID)
		{
		case ID_DISPLAY_1:

			::GetPrivateProfileString("ScreenSizeType1", "Width", "640", strReadIni1, 20, strPathIni);
			::GetPrivateProfileString("ScreenSizeType1", "Height", "480", strReadIni2, 20, strPathIni);
			break;

		case ID_DISPLAY_2:
			::GetPrivateProfileString("ScreenSizeType2", "Width", "768", strReadIni1, 20, strPathIni);
			::GetPrivateProfileString("ScreenSizeType2", "Height", "576", strReadIni2, 20, strPathIni);
			break;

		case ID_DISPLAY_3:
			::GetPrivateProfileString("ScreenSizeType3", "Width", "800", strReadIni1, 20, strPathIni);
			::GetPrivateProfileString("ScreenSizeType3", "Height", "600", strReadIni2, 20, strPathIni);
			break;

		case ID_DISPLAY_4:
			::GetPrivateProfileString("ScreenSizeType4", "Width", "1024", strReadIni1, 20, strPathIni);
			::GetPrivateProfileString("ScreenSizeType4", "Height", "768", strReadIni2, 20, strPathIni);
			break;
		}
		nWidth = atoi(strReadIni1);
		nHeight = atoi(strReadIni2);
		//m_Rect = rect;
	}
	//Setting Screen Size Default Value 
	else
	{
		nWidth = 640;
		nHeight = 480;
	}

	m_ScreenSplit->Setting(nWidth, nHeight, nBtnSize);
	SetWindowPos(NULL, 0, 0, nWidth + 500, nHeight + 700, SWP_NOMOVE);
}

void CScreenImageDisPlayFuntionDlg::OnBnClickedBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CTime currentTime;
	CString strMsg;

	//LIstBox Colum limit
	if (m_nListCount > 4) {
		m_pListBox->ResetContent();
		m_nListCount = 0;
	}
	//////////////////////////////////////////////////

	CMonthCalCtrl* pCalendar = (CMonthCalCtrl*)GetDlgItem(ID_MONTHCONTROL);
	pCalendar->GetCurSel(currentTime);
	strMsg.Format("%d년 %d월 %d일\n", currentTime.GetYear(), currentTime.GetMonth(), currentTime.GetDay());

	m_pListBox->AddString(strMsg);
	m_nListCount++;
}


void CScreenImageDisPlayFuntionDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CScreenImageDisPlayFuntionDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	HBRUSH NewBrush = (HBRUSH)CreateSolidBrush(RGB(255,0,0));
	HBRUSH OldBrush = (HBRUSH)SelectObject(dc, NewBrush);
	int GridRectPoint = 0;
	

	GridRectPoint = m_nGridRectHeight / 2;
	//ScreenToClient(SaveGridRect);
	//TEST
	if (PtInRect(&SaveGridRect, point))
	{
		//switch (m_nDisplayNumber)
		//{
		//	case ID_DISPLAY_1:
		//		//600*480
		//		point.x = ((point.x) / m_nGridRectWidth) * m_nGridRectWidth;
		//		point.y = ((point.y + GridRectPoint) / m_nGridRectHeight) * m_nGridRectHeight - m_nGridRectHeight;
		//		Rectangle(dc, point.x+2, point.y + GridRectPoint + 2, point.x + m_nGridRectWidth + 2, point.y + m_nGridRectHeight + GridRectPoint + 1);
		//		pRect = { point.x, point.y + m_nGridRectHeight + GridRectPoint, point.x + m_nGridRectWidth, point.y + m_nGridRectHeight };
		//		InvalidateRect(&pRect, FALSE);
		//	break;

		//	case ID_DISPLAY_2:
		//		//768*576
		//		point.x = ((point.x - 12) / m_nGridRectWidth) * m_nGridRectWidth + 12;
		//		point.y = ((point.y) / m_nGridRectHeight) * m_nGridRectHeight;
		//		Rectangle(dc, point.x + 6, point.y + 3, point.x + 6 + m_nGridRectWidth, point.y + 3 + m_nGridRectHeight);
		//		pRect = { point.x, point.y + m_nGridRectHeight + GridRectPoint, point.x + m_nGridRectWidth, point.y + m_nGridRectHeight };
		//		InvalidateRect(&pRect, FALSE);
		//		break;

		//	case ID_DISPLAY_3:
		//		//800*600
		//		point.x = ((point.x - 12) / m_nGridRectWidth) * m_nGridRectWidth + 12;
		//		point.y = ((point.y + GridRectPoint) / m_nGridRectHeight) * m_nGridRectHeight;
		//		Rectangle(dc, point.x, point.y, point.x + m_nGridRectWidth, point.y + m_nGridRectHeight);
		//		pRect = { point.x, point.y + m_nGridRectHeight + GridRectPoint, point.x + m_nGridRectWidth, point.y + m_nGridRectHeight };
		//		InvalidateRect(&pRect, FALSE);
		//		break;

		//	case ID_DISPLAY_4:
		//		//1024 * 768A
		//		point.x = ((point.x) / m_nGridRectWidth) * m_nGridRectWidth;
		//		point.y = ((point.y + GridRectPoint) / m_nGridRectHeight) * m_nGridRectHeight - m_nGridRectHeight;
		//		Rectangle(dc, point.x, point.y + GridRectPoint + 1, point.x + m_nGridRectWidth, point.y + m_nGridRectHeight + GridRectPoint + 1);
		//		TRACE("%d %d  ============================= \n", point.x, point.y);
		//		pRect = { point.x, point.y + m_nGridRectHeight + GridRectPoint, point.x + m_nGridRectWidth, point.y + m_nGridRectHeight };
		//		InvalidateRect(&pRect, FALSE);
		//		break;
		//}

		point.x = ((point.x) / m_nGridRectWidth) * m_nGridRectWidth;
		point.y = ((point.y + GridRectPoint) / m_nGridRectHeight) * m_nGridRectHeight - m_nGridRectHeight;
		Rectangle(dc, point.x, point.y + GridRectPoint + 2 , point.x + m_nGridRectWidth, point.y + m_nGridRectHeight + GridRectPoint + 2);
		TRACE("%d %d  ============================= \n", point.x, point.y);
		//pRect = { point.x, point.y + m_nGridRectHeight + GridRectPoint, point.x + m_nGridRectWidth, point.y + m_nGridRectHeight };

		//CRect Rect(210, 500, 1500, 968);
		//InvalidateRect(&Rect, FALSE);


		m_bGridUseUnUse = false;
	}
	else {
		TRACE("%d %d   \n", point.x, point.y);
	}

	SelectObject(dc, OldBrush);

	DeleteObject(NewBrush);
	CDialogEx::OnLButtonUp(nFlags, point);
}




void CScreenImageDisPlayFuntionDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ShowPicture();
}
