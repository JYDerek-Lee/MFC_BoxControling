#pragma once


// CBoxDlg ��ȭ �����Դϴ�.

class CBoxDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBoxDlg)

public:
	CBoxDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CBoxDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_OPTION_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBlockSize();
	int m_Row;
	int m_Col;
};
