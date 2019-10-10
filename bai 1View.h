
// bai 1View.h : interface of the Cbai1View class
//

#pragma once
#include"hcn.h"
#include"htron.h"
#include"xe.h"

class Cbai1View : public CView
{
protected: // create from serialization only
	Cbai1View();
	DECLARE_DYNCREATE(Cbai1View)

// Attributes
public:
	Cbai1Doc* GetDocument() const;

// Operations
public:
	xe xe1;
	int check_key;

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Cbai1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in bai 1View.cpp
inline Cbai1Doc* Cbai1View::GetDocument() const
   { return reinterpret_cast<Cbai1Doc*>(m_pDocument); }
#endif

