
// Ch3_6_Assignment.h : Ch3_6_Assignment ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CCh3_6_AssignmentApp:
// �� Ŭ������ ������ ���ؼ��� Ch3_6_Assignment.cpp�� �����Ͻʽÿ�.
//

class CCh3_6_AssignmentApp : public CWinAppEx
{
public:
	CCh3_6_AssignmentApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCh3_6_AssignmentApp theApp;
