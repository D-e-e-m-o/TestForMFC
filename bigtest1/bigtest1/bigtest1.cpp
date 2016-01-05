#include"bigtest1.h"

BEGIN_MESSAGE_MAP(CTestWnd, CFrameWnd)
	ON_MESSAGE(WM_PAINT, OnPaint)
	ON_MESSAGE(WM_LBUTTONDOWN, OnLButtonDown)
	ON_MESSAGE(WM_TIMER, OnTimer)
END_MESSAGE_MAP()

BOOL CTestApp::InitInstance()
{
	CTestWnd *pMainWnd = new CTestWnd();
	pMainWnd->Create(NULL, _T("Program for BigTest1"));
	pMainWnd->ShowWindow(m_nCmdShow);
	pMainWnd->UpdateWindow();
	m_pMainWnd = pMainWnd;
	return TRUE;
}

LRESULT CTestWnd::OnLButtonDown(WPARAM wParam, LPARAM lParam)
{
	m_shortTime = 0;
	SetTimer(1, 1, NULL);
	return TRUE;
}

LRESULT CTestWnd::OnTimer(WPARAM wParam, LPARAM lParam)
{
	m_shortTime++;
	InvalidateRect(NULL);
	return TRUE;
}

LRESULT CTestWnd::OnPaint(WPARAM wParam, LPARAM lParam)
{
	CPaintDC dc(this);
	CBrush Brush, *pOldBrush;

	Brush.CreateSolidBrush(RGB(255, 0, 0));
	pOldBrush = dc.SelectObject(&Brush);
	dc.Ellipse(m_shortTime + 100, 100, m_shortTime + 200, 200);

	dc.SelectObject(pOldBrush);
	if (m_shortTime > 900) KillTimer(1);

	return TRUE;
}