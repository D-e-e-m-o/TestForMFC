
// test7Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// Ctest7Dlg �Ի���
class Ctest7Dlg : public CDialog
{
// ����
public:
	Ctest7Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST7_DIALOG };
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
	afx_msg void OnBnClickedCancel();
	int m_nStyle;
	CRect rt;
	afx_msg void OnClickedDraw();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CScrollBar m_Red;
	CScrollBar m_Green;
	CScrollBar m_Blue;
	CEdit m_strRGB;
	afx_msg void OnClickedDisplay();
};
