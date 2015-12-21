#include"test6.h"

BEGIN_MESSAGE_MAP(CTestWnd, CFrameWnd)
	ON_MESSAGE(WM_PAINT, OnPaint)
	ON_MESSAGE(WM_LBUTTONDOWN,OnLButtonDown)
	ON_MESSAGE(WM_RBUTTONDOWN, OnRButtonDown)
	ON_MESSAGE(WM_TIMER,OnTimer)
END_MESSAGE_MAP()

CTestWnd::CTestWnd()
{
	m_Time = 0;
}

BOOL CTestApp::InitInstance()
{
	CTestWnd *pMainWnd = new CTestWnd();
	pMainWnd->Create(NULL, _T("Program for Test5"));
	pMainWnd->ShowWindow(m_nCmdShow);
	pMainWnd->UpdateWindow();
	m_pMainWnd = pMainWnd;

	return TRUE;
}

LRESULT CTestWnd::OnTimer(WPARAM wParam, LPARAM lParam)
{
	m_Time++;
	InvalidateRect(NULL);
	if (m_Time >= 1200) m_Time = 0;

	return TRUE;
}

LRESULT CTestWnd::OnLButtonDown(WPARAM wParam, LPARAM lParam)
{
	SetTimer(1,1000,NULL);
	return TRUE;
}

LRESULT CTestWnd::OnRButtonDown(WPARAM wParam, LPARAM lParam)
{
	KillTimer(1);
	return TRUE;
}

LRESULT CTestWnd::OnPaint(WPARAM wParam, LPARAM lParam)
{
	CPaintDC dc(this);
	CBrush Brush, *pOldBrush;
	CPen Pen, *pOldPen;

	Pen.CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	pOldPen = dc.SelectObject(&Pen);

	switch ( m_Time % 3 )
	{
	case 1:
		Brush.CreateHatchBrush(HS_FDIAGONAL, RGB(0, 0, 255));
		pOldBrush = dc.SelectObject(&Brush);
		break;
	case 2:
		Brush.CreateHatchBrush(HS_BDIAGONAL, RGB(0, 0, 255));
		pOldBrush = dc.SelectObject(&Brush);
		break;
	default:
		Brush.CreateSolidBrush(RGB(0, 0, 255));
		pOldBrush = dc.SelectObject(&Brush);
		break;
	}
	dc.Rectangle(100, 100, 500, 400);

	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);

	return TRUE;
}