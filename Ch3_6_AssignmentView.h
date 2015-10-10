
// Ch3_6_AssignmentView.h : CCh3_6_AssignmentView Ŭ������ �������̽�
//

#pragma once


class CCh3_6_AssignmentView : public CView
{
protected: // serialization������ ��������ϴ�.
	CCh3_6_AssignmentView();
	DECLARE_DYNCREATE(CCh3_6_AssignmentView)

// Ư���Դϴ�.
public:
	CCh3_6_AssignmentDoc* GetDocument() const;

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
	virtual ~CCh3_6_AssignmentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
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
	int xCell=100, yCell=50; //�� ���� ����
	int m_Low = 5, m_Col = 4; // �� ���� ����
};

#ifndef _DEBUG  // Ch3_6_AssignmentView.cpp�� ����� ����
inline CCh3_6_AssignmentDoc* CCh3_6_AssignmentView::GetDocument() const
   { return reinterpret_cast<CCh3_6_AssignmentDoc*>(m_pDocument); }
#endif

