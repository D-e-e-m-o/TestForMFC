#include "Demo.h"

CDemoWnd::CDemoWnd()
{
}

CDemoWnd::~CDemoWnd()
{
}

BOOL CDemoApp::InitInstance()
{
	CDemoWnd* pMainWnd = new CDemoWnd();
	pMainWnd->Create(NULL, _T("Demonstrate for MFC Program"));
	pMainWnd->ShowWindow(m_nCmdShow);
	pMainWnd->UpdateWindow();
	m_pMainWnd = pMainWnd;
	return TRUE;
}