
// bigtest2_2Dlg.h : ͷ�ļ�
//

#pragma once

#include<mmsystem.h>

// Cbigtest2_2Dlg �Ի���
class Cbigtest2_2Dlg : public CDialog
{
// ����
public:
	Cbigtest2_2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BIGTEST2_2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CScrollBar m_SpeedRed;
	CScrollBar m_SpeedGreen;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int m_PosRed;
	int m_PosGreen;
	//С���ƶ���������Ϊ+1������Ϊ-1
	short m_DirectRed;
	short m_DirectGreen;
};
