
// Ch3_6_AssignmentView.h : CCh3_6_AssignmentView 클래스의 인터페이스
//

#pragma once


class CCh3_6_AssignmentView : public CView
{
protected: // serialization에서만 만들어집니다.
	CCh3_6_AssignmentView();
	DECLARE_DYNCREATE(CCh3_6_AssignmentView)

// 특성입니다.
public:
	CCh3_6_AssignmentDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CCh3_6_AssignmentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBlockSize();

	CSize cView;
	CPoint pt;
	bool click[4][5];
	int xCell=100, yCell=50; //블럭 상하 높이
	int m_Low = 5, m_Col = 4; // 블럭 상하 개수
};

#ifndef _DEBUG  // Ch3_6_AssignmentView.cpp의 디버그 버전
inline CCh3_6_AssignmentDoc* CCh3_6_AssignmentView::GetDocument() const
   { return reinterpret_cast<CCh3_6_AssignmentDoc*>(m_pDocument); }
#endif

