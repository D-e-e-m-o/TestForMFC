
// test7Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// Ctest7Dlg 对话框
class Ctest7Dlg : public CDialog
{
// 构造
public:
	Ctest7Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST7_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
