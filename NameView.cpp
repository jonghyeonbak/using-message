
// NameView.cpp : CNameView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Name.h"
#endif

#include "NameDoc.h"
#include "NameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNameView

IMPLEMENT_DYNCREATE(CNameView, CView)

BEGIN_MESSAGE_MAP(CNameView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
		ON_WM_SIZE()
END_MESSAGE_MAP()

// CNameView ����/�Ҹ�

CNameView::CNameView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CNameView::~CNameView()
{
}

BOOL CNameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CNameView �׸���

void CNameView::OnDraw(CDC* pDC)
{
	CNameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.

	pDC->SetTextAlign(TA_CENTER);
	pDC->TextOutW(m_szSize.cx * 0.5, m_szSize.cy /4, _T("�ּ� : �ǿս� �Ⱦ� �Ǳ���100"));
	pDC->TextOutW(m_szSize.cx * 0.5, m_szSize.cy / 4 * 2, _T("��ȭ��ȣ : 010 - 2084 - 0358"));
	pDC->TextOutW(m_szSize.cx * 0.5, m_szSize.cy / 3 * 2, _T("�̸� : ������"));
}


// CNameView �μ�

BOOL CNameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CNameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CNameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CNameView ����

#ifdef _DEBUG
void CNameView::AssertValid() const
{
	CView::AssertValid();
}

void CNameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNameDoc* CNameView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNameDoc)));
	return (CNameDoc*)m_pDocument;
}
#endif //_DEBUG


// CNameView �޽��� ó����


void CNameView::OnSize(UINT nType, int cx, int cy)
{
		CView::OnSize(nType, cx, cy);

		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
		CString str;
		str.Format(_T("������ ũ�� : (%d, %d)"), cx, cy);
		MessageBox(str);
		
		m_szSize.cx = cx;
		m_szSize.cy = cy;
}
