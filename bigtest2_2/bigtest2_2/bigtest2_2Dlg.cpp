
// bigtest2_2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bigtest2_2.h"
#include "bigtest2_2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cbigtest2_2Dlg �Ի���



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


// Cbigtest2_2Dlg ��Ϣ�������

BOOL Cbigtest2_2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_SpeedRed.SetScrollRange(0, 99);
	m_SpeedGreen.SetScrollRange(0, 99);
	m_SpeedRed.SetScrollPos(0);
	m_SpeedGreen.SetScrollPos(0);
	SetTimer(1, 100, NULL);
	SetTimer(2, 100, NULL);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cbigtest2_2Dlg::OnPaint()
{
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

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cbigtest2_2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cbigtest2_2Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
