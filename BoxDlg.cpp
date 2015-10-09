// BoxDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Ch3_6_Assignment.h"
#include "BoxDlg.h"
#include "afxdialogex.h"


// CBoxDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CBoxDlg, CDialogEx)

CBoxDlg::CBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBoxDlg::IDD, pParent)
	, m_Low(0), m_Col(0) {

}

CBoxDlg::~CBoxDlg()
{
}

void CBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_LOW, m_Low);
	DDV_MinMaxInt(pDX, m_Low, 4, 20);
	DDX_Text(pDX, IDC_COL, m_Col);
	DDV_MinMaxInt(pDX, m_Col, 4, 20);
}


BEGIN_MESSAGE_MAP(CBoxDlg, CDialogEx)

END_MESSAGE_MAP()


// CBoxDlg 메시지 처리기입니다.

/*
void CBoxDlg::OnBlockSize() {
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
*/