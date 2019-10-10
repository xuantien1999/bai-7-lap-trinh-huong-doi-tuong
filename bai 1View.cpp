
// bai 1View.cpp : implementation of the Cbai1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "bai 1.h"
#endif

#include "bai 1Doc.h"
#include "bai 1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cbai1View

IMPLEMENT_DYNCREATE(Cbai1View, CView)

BEGIN_MESSAGE_MAP(Cbai1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cbai1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// Cbai1View construction/destruction

Cbai1View::Cbai1View()
{
	// TODO: add construction code here
	xe1.thietlap(100, 140, 250, 180);
}

Cbai1View::~Cbai1View()
{
}

BOOL Cbai1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cbai1View drawing

void Cbai1View::OnDraw(CDC* /*pDC*/)
{
	Cbai1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC pDC(this);
	xe1.vexe(&pDC);
	// TODO: add draw code for native data here
}


// Cbai1View printing


void Cbai1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cbai1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cbai1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cbai1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Cbai1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cbai1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cbai1View diagnostics

#ifdef _DEBUG
void Cbai1View::AssertValid() const
{
	CView::AssertValid();
}

void Cbai1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cbai1Doc* Cbai1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cbai1Doc)));
	return (Cbai1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cbai1View message handlers


void Cbai1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	check_key = nChar;
	if (check_key == 37)
	{
		
		CClientDC pDC(this);
		CPen *pen;
		pen = new CPen(PS_SOLID, 1, RGB(255, 255, 255));
		CPen *oldpen;
		oldpen = pDC.SelectObject(pen);
		xe1.vexe(&pDC);
		CPen *pen1;
		pen1 = new CPen(PS_SOLID, 1, RGB(0, 0, 0));
		CPen *oldpen1;
		oldpen1 = pDC.SelectObject(pen1);
		xe1.di_chuyen_xe_trai(&pDC);
		xe1.vexenguoc(&pDC);
	}
	if (check_key == 39)
	{
		CClientDC pDC(this);
		CPen *pen;
		pen = new CPen(PS_SOLID, 1, RGB(255, 255, 255));
		CPen *oldpen;
		oldpen = pDC.SelectObject(pen);
		xe1.vexenguoc(&pDC);

		CPen *pen1;
		pen1 = new CPen(PS_SOLID, 1, RGB(0, 0, 0));
		CPen *oldpen1;
		oldpen1 = pDC.SelectObject(pen1);
		xe1.di_chuyen_xe_phai(&pDC);
		xe1.vexe(&pDC);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
