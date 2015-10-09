
// Ch3_6_AssignmentView.cpp : CCh3_6_AssignmentView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Ch3_6_Assignment.h"
#endif

#include "Ch3_6_AssignmentDoc.h"
#include "Ch3_6_AssignmentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCh3_6_AssignmentView

IMPLEMENT_DYNCREATE(CCh3_6_AssignmentView, CView)

BEGIN_MESSAGE_MAP(CCh3_6_AssignmentView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
//	ON_WM_CHAR()
ON_WM_SIZE()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CCh3_6_AssignmentView 생성/소멸
#define XUP  fx+=xCell
#define YUP  fy+=yCell

CCh3_6_AssignmentView::CCh3_6_AssignmentView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CCh3_6_AssignmentView::~CCh3_6_AssignmentView()
{
}

BOOL CCh3_6_AssignmentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CCh3_6_AssignmentView 그리기

void CCh3_6_AssignmentView::OnDraw(CDC *pDC)
{
	CCh3_6_AssignmentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CBrush m_brSkyBlue;
	CBrush oldBrush;
	
	int fx = 100, fy = 100; //초기 위치
	int i = 0, k = 0;
	//격자 생성
	for (i = 0; i < 4; i++) {
		fx = 100;
		pDC->Rectangle(fx, fy, fx + xCell, fy + yCell);
		for (k = 0; k < 5; k++) {
			pDC->Rectangle(fx, fy, fx + xCell, fy + yCell);
			XUP;
		}
		YUP;
	}

	//브러쉬
	oldBrush.CreateStockObject(WHITE_BRUSH); //이전위치
	m_brSkyBlue.CreateSolidBrush(RGB(166, 202, 240)); //현재위치
	pDC->SelectObject(&m_brSkyBlue);
	//씨발
	//클릭 위치 확인 후 색칠
	for (i = 0; i < 4; i++) {
		for (k = 0; k < 5; k++) {
			if (click[i][k] == TRUE) {
				pDC->Rectangle(xCell*(k+1), yCell*(i+2), xCell*(k+2), yCell*(i+3));
				pt.x = xCell*(k + 1);
				pt.y = yCell*(i + 2);
				click[i][k] = FALSE;
			}
		}
	}

	pDC->Rectangle(pt.x, pt.y, pt.x + 100, pt.y + 50);
	pDC->SelectObject(oldBrush); //원상복귀
	m_brSkyBlue.DeleteObject();
}


// CCh3_6_AssignmentView 인쇄

BOOL CCh3_6_AssignmentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CCh3_6_AssignmentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CCh3_6_AssignmentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CCh3_6_AssignmentView 진단

#ifdef _DEBUG
void CCh3_6_AssignmentView::AssertValid() const
{
	CView::AssertValid();
}

void CCh3_6_AssignmentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCh3_6_AssignmentDoc* CCh3_6_AssignmentView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCh3_6_AssignmentDoc)));
	return (CCh3_6_AssignmentDoc*)m_pDocument;
}
#endif //_DEBUG


// CCh3_6_AssignmentView 메시지 처리기
void CCh3_6_AssignmentView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	//키보드 위치 이동
	switch (nChar) {
		case VK_UP: 
			pt.y -= 50;
			if (pt.y < 100)
				pt.y = 250;
			break;
		
		case VK_DOWN:
			pt.y += 50;
			if (pt.y>=300)
				pt.y = 100; 
			break;
		
		case VK_LEFT: 
			pt.x -= 100;
			if (pt.x<100) 
				pt.x = 500;
			break;
		
		case VK_RIGHT: 
			pt.x += 100;
			if (pt.x>=600)
				pt.x = 100;
			break;
		}
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CCh3_6_AssignmentView::OnSize(UINT nType, int cx, int cy) {
	CView::OnSize(nType, cx, cy);
	cView = CSize(cx, cy);
	//cView = CSize(100, 50);
	pt = CPoint(100, 100); //시작위치 지정
}

void CCh3_6_AssignmentView::OnLButtonDown(UINT nFlags, CPoint point) { 
	int fx = 100, fy = 100; //초기 위치
	int i = 0, k = 0;

	//격자 내부 클릭 판별
	if (point.x >=100 && point.x <= 600 && point.y >= 50 && point.y <= 300) {
		//세부 위치 파악 후 배열에 저장
		for (i = 0; i < 4; i++) {
			fx = 100;
			for (k = 0; k < 5; k++) {
				click[i][k] = (point.x > fx && point.x < fx + xCell && point.y > fy\
					&& point.y < fy + yCell) ? (TRUE) : (FALSE);
				XUP;
			}
			YUP;
		}
	}
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
