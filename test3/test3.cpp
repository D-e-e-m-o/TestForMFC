#include"test3.h"

BEGIN_MESSAGE_MAP(CTestWnd,CFrameWnd)
	ON_MESSAGE(WM_LBUTTONDOWN,OnLButtonDown)
	ON_MESSAGE(WM_LBUTTONUP, OnLButtonUp)
	ON_MESSAGE(WM_PAINT, OnPaint)
	ON_MESSAGE(WM_MOUSEMOVE, OnMouseMove)
	ON_MESSAGE(WM_KEYUP,OnKeyUp)
END_MESSAGE_MAP()

CTestWnd::CTestWnd()
{
	Draw_Rectangle = false;
	Draw_Ellipse = false;
	Draw_Mode = false;
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
}

BOOL CTestApp::InitInstance()
{
	CTestWnd *pMainWnd = new CTestWnd();
	pMainWnd->Create(NULL, _T("Program for Test3"));
	//SetCursor(this->LoadCursor(IDC_WAIT));
	pMainWnd->ShowWindow(m_nCmdShow);
	pMainWnd->UpdateWindow();
	m_pMainWnd = pMainWnd;
	return TRUE;
}

LRESULT CTestWnd::OnLButtonDown(WPARAM wParam, LPARAM lParam)
{
	if (wParam & MK_CONTROL)
	{
		x1 = LOWORD(lParam);
		y1 = HIWORD(lParam);
		x2 = x1;
		y2 = y1;
		Draw_Rectangle = true;
		Draw_Ellipse = false;
		Draw_Mode = true;
		InvalidateRect(NULL);
	}
	if (wParam & MK_SHIFT)
	{
		x1 = LOWORD(lParam);
		y1 = HIWORD(lParam);
		x2 = x1;
		y2 = y1;
		Draw_Ellipse = true;
		Draw_Rectangle = false;
		Draw_Mode = true;
		InvalidateRect(NULL);
	}
	if (Draw_Mode)
	{
		//SetCursor(theApp.LoadCursorW(IDC_CROSS));
		HCURSOR hCursor = theApp.LoadStandardCursor(IDC_CROSS);
		SetCursor(hCursor);
	}
	return TRUE;
}

LRESULT CTestWnd::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	if( Draw_Mode )
	{
		HCURSOR hCursor = theApp.LoadStandardCursor(IDC_CROSS);
		SetCursor(hCursor);
		x2 = LOWORD(lParam);
		y2 = HIWORD(lParam);
		InvalidateRect(NULL);
	}
	return TRUE;
}

LRESULT CTestWnd::OnLButtonUp(WPARAM wParam, LPARAM lParam)
{
	Draw_Mode = false;
	return TRUE;
}

LRESULT CTestWnd::OnKeyUp(WPARAM wParam, LPARAM lParam)
{
	Draw_Mode = false;
	return TRUE;
}

LRESULT CTestWnd::OnPaint(WPARAM wParam, LPARAM lParam)
{
	CPaintDC dc(this);
	dc.SelectStockObject(GRAY_BRUSH);
	if( Draw_Rectangle ) dc.Rectangle(x1, y1, x2, y2);
	if( Draw_Ellipse ) dc.Ellipse(x1, y1, x2, y2);
	return TRUE;
}
