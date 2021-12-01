// CalenderDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ScreenImageDisPlayFuntion.h"
#include "CalenderDlg.h"
#include "afxdialogex.h"


// CalenderDlg 대화 상자

IMPLEMENT_DYNAMIC(CalenderDlg, CDialogEx)

CalenderDlg::CalenderDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
//	m_Calendar.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TILED, CRect(200, 20, 200*175, 20*175), this, 1234);
}

CalenderDlg::~CalenderDlg()
{
}

void CalenderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CalenderDlg, CDialogEx)
END_MESSAGE_MAP()


// CalenderDlg 메시지 처리기
