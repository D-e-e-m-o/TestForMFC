#pragma once

#include<afxwin.h>

class CTestWnd :public CFrameWnd
{
	DECLARE_MESSAGE_MAP()
public:
	int x0, y0, x1, y1;
	LRESULT OnPaint(WPARAM wParam, LPARAM lParam);
	LRESULT OnKeyDown(WPARAM wParam, LPARAM lParam);
	CTestWnd();
};

class CTestApp :public CWinApp
{
public:
	BOOL InitInstance();
};

CTestApp theApp;