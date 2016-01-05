
// bigtest2_2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bigtest2_2.h"
#include "bigtest2_2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cbigtest2_2Dlg 对话框



Cbigtest2_2Dlg::Cbigtest2_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_BIGTEST2_2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_PosRed = 10;
	m_PosGreen = 10;
	m_DirectRed = 1;
	m_DirectGreen = 1;
}

void Cbigtest2_2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RED, m_SpeedRed);
	DDX_Control(pDX, IDC_GREEN, m_SpeedGreen);
}

BEGIN_MESSAGE_MAP(Cbigtest2_2Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// Cbigtest2_2Dlg 消息处理程序

BOOL Cbigtest2_2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_SpeedRed.SetScrollRange(0, 99);
	m_SpeedGreen.SetScrollRange(0, 99);
	m_SpeedRed.SetScrollPos(0);
	m_SpeedGreen.SetScrollPos(0);
	SetTimer(1, 100, NULL);
	SetTimer(2, 100, NULL);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cbigtest2_2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		CBrush Brush, *pOldBrush;
		Brush.CreateSolidBrush(RGB(255, 0, 0));
		pOldBrush = dc.SelectObject(&Brush);
		dc.Ellipse(m_PosRed, 10, m_PosRed + 100, 110);
		Brush.DeleteObject();
		Brush.CreateSolidBrush(RGB(0, 255, 0));
		dc.SelectObject(&Brush);
		dc.Ellipse(m_PosGreen, 120, m_PosGreen +100, 220);
		dc.SelectObject(pOldBrush);
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cbigtest2_2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cbigtest2_2Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UINT nCurPos;

	switch (nSBCode)
	{
	case SB_THUMBTRACK:
		pScrollBar->SetScrollPos(nPos);
		break;

	case SB_LINELEFT:
		nCurPos = pScrollBar->GetScrollPos();
		pScrollBar->SetScrollPos(nCurPos - 1);
		break;

	case SB_LINERIGHT:
		nCurPos = pScrollBar->GetScrollPos();
		pScrollBar->SetScrollPos(nCurPos + 1);
		break;

	case SB_PAGELEFT:
		nCurPos = pScrollBar->GetScrollPos();
		pScrollBar->SetScrollPos(nCurPos - 5);
		break;

	case SB_PAGERIGHT:
		nCurPos = pScrollBar->GetScrollPos();
		pScrollBar->SetScrollPos(nCurPos + 5);
		break;
	}
	if (pScrollBar == &m_SpeedRed)
	{
		KillTimer(1);
		SetTimer(1, 100 - m_SpeedRed.GetScrollPos(), NULL);
	}
	else
	{
		KillTimer(2);
		SetTimer(2, 100 - m_SpeedGreen.GetScrollPos(), NULL);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void Cbigtest2_2Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case 1:
		if ((m_PosRed + m_DirectRed > 450) ||
			(m_PosRed + m_DirectRed < 10))
		{
			m_DirectRed = -m_DirectRed;
		}
		m_PosRed += m_DirectRed;
		break;
	case 2:
		if ((m_PosGreen + m_DirectGreen > 450) ||
			(m_PosGreen + m_DirectGreen < 10))
		{
			m_DirectGreen = -m_DirectGreen;
		}
		m_PosGreen += m_DirectGreen;
		break;
	default:
		break;
	}
	CRect rt(10, 10, 550, 220);
	InvalidateRect(rt);
	CDialog::OnTimer(nIDEvent);
}
