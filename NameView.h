
// NameView.h : CNameView Ŭ������ �������̽�
//

#pragma once


class CNameView : public CView
{
protected: // serialization������ ��������ϴ�.
	CNameView();
	DECLARE_DYNCREATE(CNameView)

// Ư���Դϴ�.
public:
	CNameDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CNameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CSize			m_szSize;
};

#ifndef _DEBUG  // NameView.cpp�� ����� ����
inline CNameDoc* CNameView::GetDocument() const
   { return reinterpret_cast<CNameDoc*>(m_pDocument); }
#endif

