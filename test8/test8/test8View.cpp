
// test8View.cpp : Ctest8View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "test8.h"
#endif

#include "test8Doc.h"
#include "test8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest8View

IMPLEMENT_DYNCREATE(Ctest8View, CView)

BEGIN_MESSAGE_MAP(Ctest8View, CView)
	ON_COMMAND_RANGE(ID_DRAW_LINE, ID_DRAW_RECT, OnDrawType)
	ON_UPDATE_COMMAND_UI_RANGE(ID_DRAW_LINE,ID_DRAW_RECT,OnUpdateDrawType)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Ctest8View 构造/析构

Ctest8View::Ctest8View()
{
	// TODO: 在此处添加构造代码
	m_DrawNow = new node();
	m_DrawHead = new node();
	m_DrawNow->next = nullptr;
	m_DrawHead->next = nullptr;
	m_nDrawType = 0;
	m_nDrawNum = 0;
	
}

Ctest8View::~Ctest8View()
{
}

BOOL Ctest8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

//绘图类型选择

void Ctest8View::OnDrawType(UINT nID)
{
	m_nDrawType = nID - ID_DRAW_LINE;
}

// Ctest8View 绘制

void Ctest8View::OnDraw(CDC* pDC/*pDC*/)
{
	Ctest8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	node* pic = m_DrawHead;
	if (m_nDrawNum)
	{
		do
		{
			switch (pic->m_nDrawType)
			{
			case 0:
				pDC->MoveTo(pic->x0, pic->y0);
				pDC->LineTo(pic->x1, pic->y1);
				break;
			case 1:
				pDC->Ellipse(pic->x0, pic->y0, pic->x1, pic->y1);
				break;
			case 2:
				pDC->Rectangle(pic->x0, pic->y0, pic->x1, pic->y1);
				break;
			}
		} while( (pic->next != nullptr)&&(pic = pic->next) );
	}
}


// Ctest8View 诊断

#ifdef _DEBUG
void Ctest8View::AssertValid() const
{
	CView::AssertValid();
}

void Ctest8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest8Doc* Ctest8View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest8Doc)));
	return (Ctest8Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctest8View 消息处理程序

void Ctest8View::OnUpdateDrawType(CCmdUI *pCmdUI)
{
	if (m_nDrawType == (pCmdUI->m_nID - ID_DRAW_LINE))
	{
		pCmdUI->SetRadio(TRUE);
	}
	else
	{
		pCmdUI->SetRadio(FALSE);
	}
}


void Ctest8View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	node* pic = new node();
	if (m_nDrawNum == 0)
	{
		m_DrawHead->next = pic;
		m_nDrawNum = 1;
	}
	//m_nDrawNum++;
	pic->x0 = point.x;
	pic->x1 = point.x;
	pic->y0 = point.y;
	pic->y1 = point.y;
	pic->m_nDrawType = m_nDrawType;
	pic->next = nullptr;
	m_DrawNow->next = pic;
	m_DrawNow = pic;
	CView::OnLButtonDown(nFlags, point);
}


void Ctest8View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nFlags & MK_LBUTTON)
	{
		m_DrawNow->x1 = point.x;
		m_DrawNow->y1 = point.y;
		InvalidateRect(NULL);
	}
	CView::OnMouseMove(nFlags, point);
}
