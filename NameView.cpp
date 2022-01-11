
// NameView.cpp : CNameView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
		ON_WM_SIZE()
END_MESSAGE_MAP()

// CNameView 생성/소멸

CNameView::CNameView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CNameView::~CNameView()
{
}

BOOL CNameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CNameView 그리기

void CNameView::OnDraw(CDC* pDC)
{
	CNameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	pDC->SetTextAlign(TA_CENTER);
	pDC->TextOutW(m_szSize.cx * 0.5, m_szSize.cy /4, _T("주소 : 의왕시 안양 판교로100"));
	pDC->TextOutW(m_szSize.cx * 0.5, m_szSize.cy / 4 * 2, _T("전화번호 : 010 - 2084 - 0358"));
	pDC->TextOutW(m_szSize.cx * 0.5, m_szSize.cy / 3 * 2, _T("이름 : 박종현"));
}


// CNameView 인쇄

BOOL CNameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CNameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CNameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CNameView 진단

#ifdef _DEBUG
void CNameView::AssertValid() const
{
	CView::AssertValid();
}

void CNameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNameDoc* CNameView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNameDoc)));
	return (CNameDoc*)m_pDocument;
}
#endif //_DEBUG


// CNameView 메시지 처리기


void CNameView::OnSize(UINT nType, int cx, int cy)
{
		CView::OnSize(nType, cx, cy);

		// TODO: 여기에 메시지 처리기 코드를 추가합니다.
		CString str;
		str.Format(_T("윈도우 크기 : (%d, %d)"), cx, cy);
		MessageBox(str);
		
		m_szSize.cx = cx;
		m_szSize.cy = cy;
}
