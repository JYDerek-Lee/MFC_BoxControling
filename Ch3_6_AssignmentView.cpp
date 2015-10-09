
// Ch3_6_AssignmentView.cpp : CCh3_6_AssignmentView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
//	ON_WM_CHAR()
ON_WM_SIZE()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CCh3_6_AssignmentView ����/�Ҹ�
#define XUP  fx+=xCell
#define YUP  fy+=yCell

CCh3_6_AssignmentView::CCh3_6_AssignmentView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CCh3_6_AssignmentView::~CCh3_6_AssignmentView()
{
}

BOOL CCh3_6_AssignmentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CCh3_6_AssignmentView �׸���

void CCh3_6_AssignmentView::OnDraw(CDC *pDC)
{
	CCh3_6_AssignmentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CBrush m_brSkyBlue;
	CBrush oldBrush;
	
	int fx = 100, fy = 100; //�ʱ� ��ġ
	int i = 0, k = 0;
	//���� ����
	for (i = 0; i < 4; i++) {
		fx = 100;
		pDC->Rectangle(fx, fy, fx + xCell, fy + yCell);
		for (k = 0; k < 5; k++) {
			pDC->Rectangle(fx, fy, fx + xCell, fy + yCell);
			XUP;
		}
		YUP;
	}

	//�귯��
	oldBrush.CreateStockObject(WHITE_BRUSH); //������ġ
	m_brSkyBlue.CreateSolidBrush(RGB(166, 202, 240)); //������ġ
	pDC->SelectObject(&m_brSkyBlue);
	//����
	//Ŭ�� ��ġ Ȯ�� �� ��ĥ
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
	pDC->SelectObject(oldBrush); //���󺹱�
	m_brSkyBlue.DeleteObject();
}


// CCh3_6_AssignmentView �μ�

BOOL CCh3_6_AssignmentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CCh3_6_AssignmentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CCh3_6_AssignmentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CCh3_6_AssignmentView ����

#ifdef _DEBUG
void CCh3_6_AssignmentView::AssertValid() const
{
	CView::AssertValid();
}

void CCh3_6_AssignmentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCh3_6_AssignmentDoc* CCh3_6_AssignmentView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCh3_6_AssignmentDoc)));
	return (CCh3_6_AssignmentDoc*)m_pDocument;
}
#endif //_DEBUG


// CCh3_6_AssignmentView �޽��� ó����
void CCh3_6_AssignmentView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	//Ű���� ��ġ �̵�
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
	pt = CPoint(100, 100); //������ġ ����
}

void CCh3_6_AssignmentView::OnLButtonDown(UINT nFlags, CPoint point) { 
	int fx = 100, fy = 100; //�ʱ� ��ġ
	int i = 0, k = 0;

	//���� ���� Ŭ�� �Ǻ�
	if (point.x >=100 && point.x <= 600 && point.y >= 50 && point.y <= 300) {
		//���� ��ġ �ľ� �� �迭�� ����
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
