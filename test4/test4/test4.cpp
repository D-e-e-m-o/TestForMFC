#include"test4.h"

BEGIN_MESSAGE_MAP(CTestWnd, CFrameWnd)
	ON_MESSAGE(WM_PAINT, OnPaint)
END_MESSAGE_MAP()

CTestWnd::CTestWnd()
{
	for (int i = 0; i < 5; i++)
	{
		lopn[i].lopnStyle = PS_SOLID;
		lopn[i].lopnWidth.x = 10;
	}
	lopn[YELLOW].lopnColor = RGB(230, 240, 10);
	lopn[PURPLE].lopnColor = RGB(165, 7, 146);
	lopn[RED].lopnColor = RGB(255, 0, 0);
	lopn[GREEN].lopnColor = RGB(0, 255, 70);
	lopn[BLUE].lopnColor = RGB(18, 0, 250);
}

BOOL CTestApp::InitInstance()
{
	CTestWnd *pMainWnd = new CTestWnd();
	pMainWnd->Create(NULL, _T("Program for Test4"));
	pMainWnd->ShowWindow(m_nCmdShow);
	pMainWnd->UpdateWindow();
	m_pMainWnd = pMainWnd;
	return TRUE;
}

LRESULT CTestWnd::OnPaint(WPARAM wParam, LPARAM lParam)
{
	CPaintDC dc(this);
	CPen Pen, *pOldPen;
	CBrush Brush, *pOldBrush;
	
	Brush.CreateHatchBrush(HS_DIAGCROSS, RGB(165, 7, 146));
	pOldBrush = dc.SelectObject(&Brush);

	Pen.CreatePenIndirect(&lopn[YELLOW]);
	pOldPen = dc.SelectObject(&Pen);
	dc.MoveTo(100, 100);
	dc.LineTo(200, 100);
	Pen.DeleteObject();

	CPoint point[6];
	Pen.CreatePenIndirect(&lopn[PURPLE]);
	dc.SelectObject(&Pen);
	point[0] = CPoint(100, 200);
	point[1] = CPoint(200, 200);
	point[2] = CPoint(250, 150);
	dc.Polyline(point, 3);
	Pen.DeleteObject();

	Pen.CreatePenIndirect(&lopn[RED]);
	dc.SelectObject(&Pen);
	dc.Rectangle(100, 300, 200, 400);
	Pen.DeleteObject();

	Pen.CreatePenIndirect(&lopn[GREEN]);
	dc.SelectObject(&Pen);
	dc.Ellipse(300, 100, 400, 200);
	Pen.DeleteObject();

	Pen.CreatePenIndirect(&lopn[BLUE]);
	dc.SelectObject(&Pen);
	point[0] = CPoint(400, 300);
	point[1] = CPoint(500, 300-173);
	point[2] = CPoint(700, 300-173);
	point[3] = CPoint(800, 300);
	point[4] = CPoint(700, 300+173);
	point[5] = CPoint(500, 300+173);
	dc.Polygon(point, 6);
	Pen.DeleteObject();

	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);

	return TRUE;
}