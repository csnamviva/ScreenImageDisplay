
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
}

BEGIN_MESSAGE_MAP(CScreenImageDisPlayFuntionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_MYBTN_PRESS, &CScreenImageDisPlayFuntionDlg::OnButtonPress)
	ON_WM_DESTROY()

	ON_WM_MENUSELECT()
END_MESSAGE_MAP()


LRESULT CScreenImageDisPlayFuntionDlg::OnButtonPress(WPARAM wParam, LPARAM lParam)
{
	TRACE("OnButtonPress  w= %ld   l= %ld \n", wParam, lParam);

	return 0;
}

// CScreenImageDisPlayFuntionDlg 메시지 처리기

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

	CString caption = _T("");
	for (int i = 0; i < MAX_BTN; i++)
	{
		m_BtnControl[i] = new BtnControl();

		caption.Format(_T("%d SplitButton"), (i + 1) * (i + 1));
		m_BtnControl[i]->Create(caption, WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TILED, CRect(10, 10 + (50 * i), BTN_WIDTH, 50 + (50 * i)), this, BTN_ID_1 + i);
		m_BtnControl[i]->init((i + 1) * (i + 1), this);
	}
	
	//Default Value
	int nIniWidth = 800;
	int nIniHeight = 600;
	this->m_ScreenSplit = new ScreenSplit();
	m_ScreenSplit->init(this);
	m_ScreenSplit->Setting(nIniWidth, nIniHeight, nBtnSize);

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
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

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
		CDialogEx::OnPaint();
	}
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
	delete m_ScreenSplit;
}

int CScreenImageDisPlayFuntionDlg::ButtonPress(int nSplit)
{
	//Setting ScreenSplit 1/4/9/16 button
	int nChanelData = 0;
	switch (nSplit)
	{
	case 1:
		nChanelData = 1;
		m_ScreenSplit->SetScreen(nChanelData);
		break;
	case 4:
		nChanelData = 2;
		m_ScreenSplit->SetScreen(nChanelData);
		break;
	case 9:
		nChanelData = 3;
		m_ScreenSplit->SetScreen(nChanelData);
		break;
	case 16:
		nChanelData = 4;
		m_ScreenSplit->SetScreen(nChanelData);
		break;
	}
	return 0;
}

void CScreenImageDisPlayFuntionDlg::OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu)
{
	CDialogEx::OnMenuSelect(nItemID, nFlags, hSysMenu);

	//MenuBar Click 
	if (!m_bMenuFlag)
	{
		GetFilePath(nItemID);
	}
	m_bMenuFlag = !m_bMenuFlag;
}


void CScreenImageDisPlayFuntionDlg::GetFilePath(int nItemID)
{
	//GetScreen Width/Height Size
	CString strPathIni = "D:\\test.ini";
	TCHAR strReadIni1[20] = { 0 };
	TCHAR strReadIni2[20] = { 0 };
	int nWidth = 0;
	int nHeight = 0;
	int nBtnSize = BTN_WIDTH;
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

	m_ScreenSplit->Setting(nWidth, nHeight, nBtnSize);
	SetWindowPos(NULL, 0, 0, nWidth + 185, nHeight + 100, SWP_NOMOVE);
}