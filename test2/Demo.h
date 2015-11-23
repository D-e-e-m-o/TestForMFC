#pragma once

#include <afxwin.h>

class CDemoWnd :public CFrameWnd
{
public:
	CDemoWnd();
	~CDemoWnd();
};

class CDemoApp :public CWinApp
{
public:
	BOOL InitInstance();
};

CDemoApp theApp;