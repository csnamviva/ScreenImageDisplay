
// ScreenImageDisPlayFuntionDlg.h: 헤더 파일
//
#include "BtnControl.h"
#include "CalenderDlg.h"
#include "CMonthCalControl.h"
#include "ListBox.h"
#include "CDrawGridPicBox.h"


#pragma once

#define MAX_BTN 4
#define BTN_WIDTH 210
#define BTN_ID_1 10001
#define BTN_ID_2 10002
#define BTN_ID_3 10003
#define BTN_ID_4 10004
#define BTN_ID_5 10005

#define ID_MONTHCONTROL 1001
#define ID_LISTBOX 11001

#define ID_DISPLAY_1 32772
#define ID_DISPLAY_2 32773
#define ID_DISPLAY_3 32774
#define ID_DISPLAY_4 32775


//Use Main Dlg Dc
#define DCGRIDVERSION

// CScreenImageDisPlayFuntionDlg 대화 상자
class CScreenImageDisPlayFuntionDlg : public CDialogEx
{
// 생성입니다.
public:
	CScreenImageDisPlayFuntionDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCREENIMAGEDISPLAYFUNTION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	afx_msg LRESULT OnButtonPress(WPARAM wParam, LPARAM lParam);
//TEST
public:
	afx_msg void OnDestroy();
	int ButtonPress(int nSplit);
	bool m_bMenuFlag = 0;
	int nWidth;
	int nHeight;

	int m_nGridRectWidth;
	int m_nGridRectHeight;
	RECT m_Rect;



	bool m_bGridUseUnUse;

	void GetFilePath(int nItemID);

	//int m_nChanelNum;
	//int m_nImageData;
	int m_nListCount;

	CFont font;

	CRect SaveGridRect;

	BtnControl* m_BtnControl[16];
	CMonthCalControl* m_pCalendar;
	ListBox* m_pListBox;
	ScreenSplit* m_ScreenSplit;

	HBITMAP mh_dir_image, mh_my_image;



	afx_msg void OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu);
	//afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedBtn();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CButton m_imgBg;
};
