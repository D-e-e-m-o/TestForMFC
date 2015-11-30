#pragma once

#include<afxwin.h>

class CTestWnd :public CFrameWnd
{
	DECLARE_MESSAGE_MAP()
public:
	LRESULT OnPaint(WPARAM wParam, LPARAM lParam);
	LRESULT OnLButtonDown(WPARAM wParam, LPARAM lParam);
	LRESULT OnMouseMove(WPARAM wParam, LPARAM lParam);
	LRESULT OnLButtonUp(WPARAM wParam, LPARAM lParam);
	int x1, y1, x2, y2;
	bool Draw_Rectangle,Draw_Ellipse,Draw_Mode;
	CTestWnd();
};

class CTestApp :public CWinApp
{
public:
	BOOL InitInstance();
};

CTestApp theApp;