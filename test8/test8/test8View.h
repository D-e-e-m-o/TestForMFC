
// test8View.h : Ctest8View 类的接口
//

#pragma once

typedef class Cnode
{
public:
	short m_nDrawType;
	unsigned int x0, y0, x1, y1;
	Cnode *next;
}node;

class Ctest8View : public CView
{
protected: // 仅从序列化创建
	Ctest8View();
	DECLARE_DYNCREATE(Ctest8View)

// 特性
public:
	Ctest8Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctest8View();
	afx_msg void OnDrawType(UINT nID);
	afx_msg void OnUpdateDrawType(CCmdUI *pCmdUI);
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	short m_nDrawType;
	node* m_DrawNow;
	node* m_DrawHead;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	unsigned int m_nDrawNum;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // test8View.cpp 中的调试版本
inline Ctest8Doc* Ctest8View::GetDocument() const
   { return reinterpret_cast<Ctest8Doc*>(m_pDocument); }
#endif

