
// test8View.h : Ctest8View ��Ľӿ�
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
protected: // �������л�����
	Ctest8View();
	DECLARE_DYNCREATE(Ctest8View)

// ����
public:
	Ctest8Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Ctest8View();
	afx_msg void OnDrawType(UINT nID);
	afx_msg void OnUpdateDrawType(CCmdUI *pCmdUI);
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // test8View.cpp �еĵ��԰汾
inline Ctest8Doc* Ctest8View::GetDocument() const
   { return reinterpret_cast<Ctest8Doc*>(m_pDocument); }
#endif

