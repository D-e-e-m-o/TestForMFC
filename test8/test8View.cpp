
// test8View.cpp : Ctest8View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// Ctest8View ����/����

Ctest8View::Ctest8View()
{
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

//��ͼ����ѡ��

void Ctest8View::OnDrawType(UINT nID)
{
	m_nDrawType = nID - ID_DRAW_LINE;
}

// Ctest8View ����

void Ctest8View::OnDraw(CDC* pDC/*pDC*/)
{
	Ctest8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


// Ctest8View ���

#ifdef _DEBUG
void Ctest8View::AssertValid() const
{
	CView::AssertValid();
}

void Ctest8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest8Doc* Ctest8View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest8Doc)));
	return (Ctest8Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctest8View ��Ϣ�������

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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nFlags & MK_LBUTTON)
	{
		m_DrawNow->x1 = point.x;
		m_DrawNow->y1 = point.y;
		InvalidateRect(NULL);
	}
	CView::OnMouseMove(nFlags, point);
}
