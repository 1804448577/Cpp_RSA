// RSADlg.h : header file
//
#include "BigInt.h"

#if !defined(AFX_RSADLG_H__ACCE22F8_CED3_4D59_BA67_D85CDF6DA131__INCLUDED_)
#define AFX_RSADLG_H__ACCE22F8_CED3_4D59_BA67_D85CDF6DA131__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRSADlg dialog

class CRSADlg : public CDialog
{
// Construction
public:
	CRSADlg(CWnd* pParent = NULL);	// standard constructor

	CBigInt P;
	CBigInt Q;
	CBigInt N;
	CBigInt E;
	CBigInt D;

// Dialog Data
	//{{AFX_DATA(CRSADlg)
	enum { IDD = IDD_RSA_DIALOG };
	CString	m_C;
	CString	m_D;
	CString	m_E;
	CString	m_M;
	CString	m_MM;
	CString	m_N;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRSADlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void InFromFile(CString& str);
	void OutToFile(CString& str);
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRSADlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGenkey();
	afx_msg void OnEncrypt();
	afx_msg void OnDecrypt();
	afx_msg void OnOute();
	afx_msg void OnIne();
	afx_msg void OnOutm();
	afx_msg void OnInm();
	afx_msg void OnOutc();
	afx_msg void OnInd();
	afx_msg void OnOutd();
	afx_msg void OnInn();
	afx_msg void OnOutn();
	afx_msg void OnOutmm();
	afx_msg void OnInc();
	afx_msg void OnSignature();
	afx_msg void OnVerify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSADLG_H__ACCE22F8_CED3_4D59_BA67_D85CDF6DA131__INCLUDED_)
