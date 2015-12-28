
// test7Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test7.h"
#include "test7Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest7Dlg �Ի���



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


// Ctest7Dlg ��Ϣ�������

BOOL Ctest7Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
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
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

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
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Ctest7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Ctest7Dlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnCancel();
}


void Ctest7Dlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Ctest7Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Ctest7Dlg::OnClickedDraw()
{
	InvalidateRect(rt);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Ctest7Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
