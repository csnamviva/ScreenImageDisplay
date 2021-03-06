
// SearchCopyDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "SearchCopy.h"
#include "SearchCopyDlg.h"
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


// CSearchCopyDlg 대화 상자



CSearchCopyDlg::CSearchCopyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEARCHCOPY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSearchCopyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSearchCopyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CSearchCopyDlg 메시지 처리기

BOOL CSearchCopyDlg::OnInitDialog()
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
	char		szConfigMain[MAX_PATH];
	TCHAR		chPath[MAX_PATH + 1];
	memset(chPath, 0, sizeof(chPath));
	CFile file;
	CString strTmp = _T("");

	//int k = file.GetLength();
	//file.Read(chPath, file.GetLength());
	//file.Close();
	//m_strSysPathUpper.Format("%s\\work\\Test\\SearchCopy\\Image", chPath);
	::GetCurrentDirectory(MAX_PATH, chPath);
	strTmp = chPath;


	m_strImageFolder = strTmp;
	m_strImageFolder += "\\Image";

	m_SearchImage.m_strFileName = m_strImageFolder;
	m_SearchImage.m_strFileName += "\\search.txt";

	m_LogoImage.m_strFileName = m_strImageFolder;
	m_LogoImage.m_strFileName += "\\logo.txt";

	//m_strImageFolder += "\\search.txt";
	//m_SearchImage.m_strFileName = m_strImageFolder;
	m_pDc = GetDC();
	OnMainSkinLoad();

	//파일경로 확인해야함 경로가 다름
	OnMainLogoLoad();
	//InitSearch();


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CSearchCopyDlg::OnMainSkinLoad()
{
	stPICTURE_FILE	MainImageInfo;
	MainImageInfo = m_ImageFunc.GetPictureInfo(m_strImageFolder, m_SearchImage.IniFileReadStringEx("Search Main", "Main Skin", _T("")), FALSE);

	m_wGUIWidth = MainImageInfo.iWidth;
	m_wGUIHeight = MainImageInfo.iHeight;

	MoveWindow(MainImageInfo.iLeft, MainImageInfo.iTop, m_wGUIWidth, m_wGUIHeight);
	m_hMainBitmap = NULL;
	m_hMainBitmap = m_ImageFunc.GetBitmap(m_pDc, MainImageInfo.strFileName);
}

void CSearchCopyDlg::OnMainLogoLoad()
{
	stPICTURE_FILE MainLogoInfo;
	MainLogoInfo = theApp.m_ImageFunc.GetPictureInfo(m_strImageFolder,
		m_SearchImage.IniFileReadStringEx("Search Main", "Logo", _T("")));
	m_hMainLogoBitmap = NULL;
	m_hMainLogoBitmap = m_ImageFunc.GetBitmap(m_pDc, MainLogoInfo.strFileName);
}
void CSearchCopyDlg::InitSearch()
{
	//for (int i = 0; i < MAX_VIEW; i++)
	//{
	//	CRect	rc(0, 0, 0, 0);
	//	m_Win[i]->MoveWindow(&rc);
	//	m_Win[i]->SetArea(&rc); //t
	//}
}

void CSearchCopyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSearchCopyDlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	if (IsIconic())
	{
		

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
		RECT rect;
		rect.top = 0;
		rect.left = 0;
		rect.right = m_wGUIWidth;
		rect.bottom = m_wGUIHeight;
		theApp.m_ImageFunc.MoveSkinButton(&dc, m_hMainBitmap, &rect);

	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CSearchCopyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

