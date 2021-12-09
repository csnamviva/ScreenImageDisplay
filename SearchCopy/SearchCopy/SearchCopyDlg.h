
// SearchCopyDlg.h: 헤더 파일
//

#include "CFileEx.h"
#define MAX_VIEW 64

#pragma once


// CSearchCopyDlg 대화 상자
class CSearchCopyDlg : public CDialogEx
{
// 생성입니다.
public:
	CSearchCopyDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.


	void OnMainSkinLoad();
	void InitSearch();
	void OnMainLogoLoad();

	WORD		m_wGUIWidth, m_wGUIHeight;
	CBitmap* m_hMainBitmap;
	CBitmap* m_hMainLogoBitmap;
	CDC* m_pDc;


	CFileEx		m_SearchImage;
	CFileEx		m_LogoImage;

	CString		m_strImageFolder;
	CString		m_strSysPathUpper;
	CImageEx	m_ImageFunc;


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCHCOPY_DIALOG };
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
};
