#include "pch.h"
#include "BtnControl.h"

#include "ScreenImageDisPlayFuntionDlg.h"
BEGIN_MESSAGE_MAP(BtnControl, CButton)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

class CScreenImageDisPlayFuntionDlg;


void BtnControl::init(int nID, int nWidth, int nHeight, CWnd* pWnd)
{


	m_nID = nID;
	m_pParentWnd = (CScreenImageDisPlayFuntionDlg*)pWnd;
	//m_pParentWnd = pWnd;

}

void BtnControl::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	((CScreenImageDisPlayFuntionDlg*)m_pParentWnd)->ButtonPress(m_nID);
	CButton::OnLButtonDown(nFlags, point);
}

