
// test7Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test7.h"
#include "test7Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest7Dlg 对话框



Ctest7Dlg::Ctest7Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_TEST7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_SOLID, m_nStyle);
	//DDX_Control(pDX, IDC_RED, m_nRed);
	//DDX_Control(pDX, IDC_BLUE, m_nBlue);
	//DDX_Control(pDX, IDC_GREEN, m_nGreen);
	DDX_Control(pDX, IDC_RED, m_Red);
	DDX_Control(pDX, IDC_GREEN, m_Green);
	DDX_Control(pDX, IDC_BLUE, m_Blue);
	DDX_Control(pDX, IDC_EDIT1, m_strRGB);
}

BEGIN_MESSAGE_MAP(Ctest7Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &Ctest7Dlg::OnBnClickedCancel)
	//ON_BN_CLICKED(IDC_RADIO2, &Ctest7Dlg::OnBnClickedRadio2)
	ON_EN_CHANGE(IDC_EDIT1, &Ctest7Dlg::OnEnChangeEdit1)
	//ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR2, &Ctest7Dlg::OnNMThemeChangedScrollbar2)
	ON_BN_CLICKED(IDC_DRAW, &Ctest7Dlg::OnClickedDraw)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_DISPLAY, &Ctest7Dlg::OnClickedDisplay)
END_MESSAGE_MAP()


// Ctest7Dlg 消息处理程序

BOOL Ctest7Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	((CButton*)GetDlgItem(IDC_DISPLAY))->SetCheck(1);

	GetDlgItem(IDC_WHEREDRAW)->GetWindowRect(&rt);
	ScreenToClient(rt);
	rt.DeflateRect(10, 15);
	rt.OffsetRect(0, 5);
	m_Red.SetScrollRange(0, 255);
	m_Green.SetScrollRange(0, 255);
	m_Blue.SetScrollRange(0, 255);
	m_Red.SetScrollPos(0);
	m_Green.SetScrollPos(0);
	m_Blue.SetScrollPos(0);
	m_strRGB.SetWindowTextW(_T("RGB(  0,  0,  0)"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ctest7Dlg::OnPaint()
{
	CPaintDC dc(this);
	CPen Pen, *pOldPen;
	CBrush Brush, *pOldBrush;
	UpdateData(TRUE);
	if (((CButton*)GetDlgItem(IDC_DISPLAY))->GetCheck())
	{
		switch (m_nStyle)
		{
		case 0:
			Pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
			break;
		case 1:
			Pen.CreatePen(PS_DASH, 1, RGB(255, 0, 0));
			break;
		case 2:
			Pen.CreatePen(PS_DASHDOT, 1, RGB(255, 0, 0));
			break;
		case 3:
			Pen.CreatePen(PS_DASHDOTDOT, 1, RGB(255, 0, 0));
			break;
		}
		pOldPen = dc.SelectObject(&Pen);
		Brush.CreateSolidBrush(RGB(m_Red.GetScrollPos(),
			m_Green.GetScrollPos(),
			m_Blue.GetScrollPos()));
		pOldBrush = dc.SelectObject(&Brush);
		dc.Rectangle(rt);
		dc.SelectObject(pOldPen);
	}
	else
	{
		Pen.CreateStockObject(NULL_PEN);
		Brush.CreateStockObject(NULL_BRUSH);
		dc.Rectangle(rt);
	}
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
		CDialog::OnPaint();
	}
	
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ctest7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Ctest7Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}


void Ctest7Dlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Ctest7Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Ctest7Dlg::OnClickedDraw()
{
	InvalidateRect(rt);
	// TODO: 在此添加控件通知处理程序代码
}


void Ctest7Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
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

	int r, g, b;
	r = m_Red.GetScrollPos();
	g = m_Green.GetScrollPos();
	b = m_Blue.GetScrollPos();
	CString rgb;
	rgb.Format(_T("RGB(%3d,%3d,%3d)"), r, g, b);
	m_strRGB.SetWindowTextW(rgb);
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


void Ctest7Dlg::OnClickedDisplay()
{
	// TODO: 在此添加控件通知处理程序代码
	if (((CButton*)GetDlgItem(IDC_DISPLAY))->GetCheck())
	{
		InvalidateRect(rt);
	}
	else
	{
		CClientDC dc(this);
		CPen Pen;
		CBrush Brush;
		Pen.CreateStockObject(NULL_PEN);
		Brush.CreateStockObject(NULL_BRUSH);
		dc.Rectangle(rt);
	}
}
