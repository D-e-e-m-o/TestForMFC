
// bigtest2_2Dlg.h : 头文件
//

#pragma once

#include<mmsystem.h>

// Cbigtest2_2Dlg 对话框
class Cbigtest2_2Dlg : public CDialog
{
// 构造
public:
	Cbigtest2_2Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BIGTEST2_2_DIALOG };
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
	CScrollBar m_SpeedRed;
	CScrollBar m_SpeedGreen;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int m_PosRed;
	int m_PosGreen;
	//小球移动方向，向右为+1，向左为-1
	short m_DirectRed;
	short m_DirectGreen;
};
