#pragma once

#include<afxwin.h>
#include<iostream>
using namespace std;

class CTestWnd :public CFrameWnd
{
	DECLARE_MESSAGE_MAP()
public:
	LRESULT OnPaint(WPARAM wParam, LPARAM lParam);
	LRESULT OnKeyDown(WPARAM wParam, LPARAM lParam);
	LRESULT OnMouseMove(WPARAM wParam, LPARAM lParam);
	CRect Rect[4];
	CTestWnd();
};

class CTestApp :public CWinApp
{
public:
	BOOL InitInstance();
};

CTestApp theApp;
