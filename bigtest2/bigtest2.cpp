#include"bigtest2.h"

BEGIN_MESSAGE_MAP(CTestWnd, CFrameWnd)
	ON_MESSAGE(WM_PAINT, OnPaint)
	ON_MESSAGE(WM_KEYDOWN,OnKeyDown)
END_MESSAGE_MAP()

CTestWnd::CTestWnd()
{
	x0 = 500;
	y0 = 200;
	x1 = 700;
	y1 = 400;
}

BOOL CTestApp::InitInstance()
{
	CTestWnd *pMainWnd = new CTestWnd();
	pMainWnd->Create(NULL, _T("Program for BigTest2.1"));
	pMainWnd->ShowWindow(m_nCmdShow);
	pMainWnd->UpdateWindow();
	m_pMainWnd = pMainWnd;
	return TRUE;
}

LRESULT CTestWnd::OnPaint(WPARAM wParam, LPARAM lParam)
{
	CPaintDC dc(this);
	dc.Rectangle(x0, y0, x1, y1);
	return TRUE;
}

LRESULT CTestWnd::OnKeyDown(WPARAM wParam, LPARAM lParam)
{
	switch (wParam&0xff)
	{
	case VK_LEFT:
		x0 -= 10;
		x1 -= 10;
		break;
	case VK_RIGHT:
		x0 += 10;
		x1 += 10;
		break;
	case VK_UP:
		y0 -= 10;
		y1 -= 10;
		break;
	case VK_DOWN:
		y0 += 10;
		y1 += 10;
		break;
	default:
		break;
	}
	CRect rt;
	GetWindowRect(&rt);
	if (x1 > rt.Width() -30) { x0 = rt.Width() -230; x1 = rt.Width() -30; }
	if (y1 > rt.Height() -50) { y0 = rt.Height() - 250; y1 = rt.Height() - 50; }
	if (x0 < 10) { x0 = 10; x1 = 210; }
	if (y0 < 10) { y0 = 10; y1 = 210; }
	InvalidateRect(NULL);
	return TRUE;
}