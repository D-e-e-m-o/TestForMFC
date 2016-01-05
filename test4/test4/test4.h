#pragma once

#include<afxwin.h>

#define YELLOW 0
#define PURPLE 1
#define RED 2
#define GREEN 3
#define BLUE 4

class CTestWnd :public CFrameWnd
{
	DECLARE_MESSAGE_MAP()
public:
	LOGPEN lopn[5];
	LRESULT OnPaint(WPARAM wParam, LPARAM lParam);
	CTestWnd();
};

class CTestApp :public CWinApp
{
public:
	BOOL InitInstance();
};

CTestApp theApp;
