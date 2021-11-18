#include "pch.h"
#include "MyButton.h"

#include "ScreenImageDisplayDlg.h"

class CScreenImageDisplayDlg;

BEGIN_MESSAGE_MAP(MyButton, CButton)
ON_WM_LBUTTONDOWN()
//ON_WM_LBUTTONUP()
//ON_WM_DESTROY()
END_MESSAGE_MAP()

//static int m_nPressID = 0;


void MyButton::init(int nID, int nWidth, int nHeight, CWnd* pWnd)
{

	
	m_nID = nID;
	m_pParentWnd = (CScreenImageDisplayDlg*)pWnd;
	//m_pParentWnd = pWnd;
	
}


void MyButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	TRACE("%d\n", m_nID);
	//m_nPressID = m_nID;
	m_bPress = true;

	((CScreenImageDisplayDlg*)m_pParentWnd)->ButtonPress(m_nID);
	CButton::OnLButtonDown(nFlags, point);
}


//void MyButton::OnLButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//	TRACE("%d", m_nID);
//
//
//		
//	CButton::OnLButtonUp(nFlags, point);
//}


//void MyButton::OnDestroy()
//{
//	CButton::OnDestroy();
//
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
//	
//	
//	
//}
