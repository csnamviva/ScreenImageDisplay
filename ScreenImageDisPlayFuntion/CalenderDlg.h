#pragma once


// CalenderDlg 대화 상자

class CalenderDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CalenderDlg)

public:
	CalenderDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CalenderDlg();
//	CMonthCalCtrl m_Calendar;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
