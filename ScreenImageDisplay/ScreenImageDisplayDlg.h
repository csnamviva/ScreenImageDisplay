﻿
// ScreenImageDisplayDlg.h: 헤더 파일
//
#include "MyButton.h"

#pragma once
#define MAX_BTN 4
#define BTN_ID_1 10001
#define BTN_ID_2 10002
#define BTN_ID_3 10003
#define BTN_ID_4 10004
#define BTN_ID_5 10005

// CScreenImageDisplayDlg 대화 상자
class CScreenImageDisplayDlg : public CDialogEx
{
// 생성입니다.
public:
	CScreenImageDisplayDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCREENIMAGEDISPLAY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


////////////////////////////////
	MyButton* m_MyButton[16];
	ScreenSplit* m_ScreenSplit;
	//ScreenSplit m_ScreenSplit;


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnButtonPress(WPARAM wParam, LPARAM lParam); 
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	int ButtonPress(int nSplit);
};
