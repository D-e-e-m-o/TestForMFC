
// bigtest2_2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cbigtest2_2App: 
// �йش����ʵ�֣������ bigtest2_2.cpp
//

class Cbigtest2_2App : public CWinApp
{
public:
	Cbigtest2_2App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cbigtest2_2App theApp;