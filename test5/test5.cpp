#include"test5.h"

BEGIN_MESSAGE_MAP(CTestWnd, CFrameWnd)
	ON_MESSAGE(WM_PAINT, OnPaint)
	ON_MESSAGE(WM_KEYDOWN, OnKeyDown)
	ON_MESSAGE(WM_MOUSEMOVE, OnMouseMove)
END_MESSAGE_MAP()

CTestWnd::CTestWnd()
{
	Rect[0].SetRect(100, 100, 450, 350);
	Rect[1].SetRect(450, 100, 800, 350);
	Rect[2].SetRect(100, 350, 450, 600);
	Rect[3].SetRect(450, 350, 800, 600);
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

LRESULT CTestWnd::OnKeyDown(WPARAM wParam, LPARAM lParam)
{
	if ( (wParam&0xff) == VK_CONTROL ) {
		AfxMessageBox(_T("你按下了Ctrl"));
		//return TRUE;
	}

	if ( (wParam&0xff) == VK_SHIFT ) {
		AfxMessageBox(_T("你按下了Shift"));
		//return TRUE;
	}
	return TRUE;
}

LRESULT CTestWnd::OnPaint(WPARAM wParam, LPARAM lParam)
{
	CPaintDC dc(this);
	CPen Pen, *pOldPen;

	Pen.CreatePen(PS_SOLID, 5, RGB(165, 7, 146));
	pOldPen = dc.SelectObject(&Pen);

	dc.Rectangle(100, 100, 800, 600);
	dc.MoveTo(100, 350);
	dc.LineTo(800-3, 350);
	dc.MoveTo(450, 100);
	dc.LineTo(450, 600-3);

	dc.SelectObject(pOldPen);

	return TRUE;

}

LRESULT CTestWnd::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	HCURSOR hCursor;
	CPoint pt;
	CClientDC dc(this);
	char str[12];

	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	sprintf_s(str, 12, "(%4d,%4d)", pt.x, pt.y);

	dc.SelectStockObject(ANSI_FIXED_FONT);
	dc.SetTextColor(RGB(255, 0, 0));
	dc.TextOutW(1, 1, str);

	if (Rect[0].PtInRect(pt))
	{
		hCursor = theApp.LoadStandardCursor(IDC_CROSS);
		SetCursor(hCursor);

	}
	else if (Rect[1].PtInRect(pt))
	{
		hCursor = theApp.LoadStandardCursor(IDC_SIZEALL);
		SetCursor(hCursor);
	}
	else if (Rect[2].PtInRect(pt))
	{
		hCursor = theApp.LoadStandardCursor(IDC_IBEAM);
		SetCursor(hCursor);
	}
	else if (Rect[3].PtInRect(pt))
	{
		hCursor = theApp.LoadStandardCursor(IDC_WAIT);
		SetCursor(hCursor);
	}

	return TRUE;
}