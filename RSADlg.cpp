// RSADlg.cpp : implementation file
//

#include "stdafx.h"
#include "RSA.h"
#include "RSADlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRSADlg dialog

CRSADlg::CRSADlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRSADlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRSADlg)
	m_C = _T("");
	m_D = _T("");
	m_E = _T("");
	m_M = _T("");
	m_MM = _T("");
	m_N = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRSADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRSADlg)
	DDX_Text(pDX, IDC_C, m_C);
	DDX_Text(pDX, IDC_D, m_D);
	DDX_Text(pDX, IDC_E, m_E);
	DDX_Text(pDX, IDC_M, m_M);
	DDX_Text(pDX, IDC_MM, m_MM);
	DDX_Text(pDX, IDC_N, m_N);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRSADlg, CDialog)
	//{{AFX_MSG_MAP(CRSADlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GENKEY, OnGenkey)
	ON_BN_CLICKED(IDC_ENCRYPT, OnEncrypt)
	ON_BN_CLICKED(IDC_DECRYPT, OnDecrypt)
	ON_BN_CLICKED(IDC_OUTE, OnOute)
	ON_BN_CLICKED(IDC_INE, OnIne)
	ON_BN_CLICKED(IDC_OUTM, OnOutm)
	ON_BN_CLICKED(IDC_INM, OnInm)
	ON_BN_CLICKED(IDC_OUTC, OnOutc)
	ON_BN_CLICKED(IDC_IND, OnInd)
	ON_BN_CLICKED(IDC_OUTD, OnOutd)
	ON_BN_CLICKED(IDC_INN, OnInn)
	ON_BN_CLICKED(IDC_OUTN, OnOutn)
	ON_BN_CLICKED(IDC_OUTMM, OnOutmm)
	ON_BN_CLICKED(IDC_INC, OnInc)
	ON_BN_CLICKED(IDC_SIGNATURE, OnSignature)
	ON_BN_CLICKED(IDC_VERIFY, OnVerify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRSADlg message handlers

BOOL CRSADlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRSADlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRSADlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRSADlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//生成公钥E、私钥D及模数N
void CRSADlg::OnGenkey() 
{
	// TODO: Add your control notification handler code here
	P.GetPrime(16);
	Q.GetPrime(16);
	N.Mov(P.Mul(Q));
	N.Put(m_N);
	P.m_ulValue[0]--;
	Q.m_ulValue[0]--;
	P.Mov(P.Mul(Q));
	D.Mov(P.Coprime(4));
	D.Put(m_D);
	E.Mov(D.Euc(P));
	E.Put(m_E);
	UpdateData(FALSE);
	MessageBox("成功生成RSA密钥!");	
}

//对明文加密,每100个字节一组,生成256个字符(即128个字节的大数)的密文
void CRSADlg::OnEncrypt() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	unsigned long len=m_M.GetLength();
	unsigned long group=len/100;
	unsigned i,j;
	CString temp;
	m_C="";
	for(i=0;i<group;i++)
	{
		temp=m_M.Mid(i*100,100);
		P.StrToBig(temp);
		Q.Mov(P.RsaTrans(E,N));
		Q.Put(temp);
		for(j=temp.GetLength();j<256;j++) temp.Insert(0,'0');
		m_C+=temp;
	}
	if(len%100!=0){
		temp=m_M.Mid(group*100);
		P.StrToBig(temp);
		Q.Mov(P.RsaTrans(E,N));
		Q.Put(temp);
		for(j=temp.GetLength();j<256;j++) temp.Insert(0,'0');
		m_C+=temp;
	}
	UpdateData(FALSE);
	MessageBox("已完成加密!");
}

//对密文进行解密(每256个字符一组)
void CRSADlg::OnDecrypt() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	unsigned long len=m_C.GetLength();
	unsigned long group=len/256;
	unsigned i;
	CString temp;
	m_MM="";
	for(i=0;i<group;i++)
	{
		temp=m_C.Mid(i*256,256);
		P.Get(temp);
		Q.Mov(P.RsaTrans(D,N));
		Q.BigToStr(temp);
		m_MM+=temp;
	}
	UpdateData(FALSE);
	MessageBox("已完成解密!");
}

//签名
void CRSADlg::OnSignature() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	unsigned long len=m_M.GetLength();
	unsigned long group=len/100;
	unsigned i,j;
	CString temp;
	m_C="";
	for(i=0;i<group;i++)
	{
		temp=m_M.Mid(i*100,100);
		P.StrToBig(temp);
		Q.Mov(P.RsaTrans(D,N));
		Q.Put(temp);
		for(j=temp.GetLength();j<256;j++) temp.Insert(0,'0');
		m_C+=temp;
	}
	if(len%100!=0){
		temp=m_M.Mid(group*100);
		P.StrToBig(temp);
		Q.Mov(P.RsaTrans(D,N));
		Q.Put(temp);
		for(j=temp.GetLength();j<256;j++) temp.Insert(0,'0');
		m_C+=temp;
	}
	UpdateData(FALSE);
	MessageBox("已完成签名!");
}

//验证
void CRSADlg::OnVerify() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	unsigned long len=m_C.GetLength();
	unsigned long group=len/256;
	unsigned i;
	CString temp;
	m_MM="";
	for(i=0;i<group;i++)
	{
		temp=m_C.Mid(i*256,256);
		P.Get(temp);
		Q.Mov(P.RsaTrans(E,N));
		Q.BigToStr(temp);
		m_MM+=temp;
	}
	UpdateData(FALSE);
	MessageBox("已完成验证!");
}

//将字符串导出至文件
void CRSADlg::OutToFile(CString& str)
{
    CFileDialog dlg(FALSE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT ,"All Files(*.*)|*.*||");
	if(dlg.DoModal()!=IDOK)	return;
	CString	filePath=dlg.GetPathName();
	CFile out;
	out.Open(filePath,CFile::modeWrite|CFile::modeCreate);
	out.Write(str,str.GetLength());	
	out.Close();
}

//从文件输入至字符串
void CRSADlg::InFromFile(CString& str)
{
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,"ALL Files(*.*)|*.*||");
	if(dlg.DoModal()!=IDOK) return;
	CString filePath=dlg.GetPathName();
	CFile in;
	if(!in.Open(filePath,CFile::modeRead))
	{
		MessageBox("指定文件不存在!");
		return;
	}
	DWORD dwFileLen=in.GetLength();
	char *buf=new char[dwFileLen+1];
	buf[dwFileLen]=0;
	in.Read(buf,dwFileLen);
	in.Close();
	str=buf;
	delete buf;
}

//导出公钥E到文件
void CRSADlg::OnOute() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	OutToFile(m_E);
}

//从文件导入公钥E
void CRSADlg::OnIne() 
{
	// TODO: Add your control notification handler code here
	InFromFile(m_E);
	E.Get(m_E);
	UpdateData(FALSE);
}

//导出明文到文件
void CRSADlg::OnOutm() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	OutToFile(m_M);
}

//从文件导入明文
void CRSADlg::OnInm() 
{
	// TODO: Add your control notification handler code here
	InFromFile(m_M);
	UpdateData(FALSE);
}

//导出密文到文件
void CRSADlg::OnOutc() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	OutToFile(m_C);
}

//从文件导入密文
void CRSADlg::OnInc() 
{
	// TODO: Add your control notification handler code here
	InFromFile(m_C);
	UpdateData(FALSE);
}

//从文件导入私钥
void CRSADlg::OnInd() 
{
	// TODO: Add your control notification handler code here
	InFromFile(m_D);
	D.Get(m_D);
	UpdateData(FALSE);
}

//导出私钥到文件
void CRSADlg::OnOutd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	OutToFile(m_D);
}

//从文件导入模数N
void CRSADlg::OnInn() 
{
	// TODO: Add your control notification handler code here
	InFromFile(m_N);
	N.Get(m_N);
	UpdateData(FALSE);
}

//导出模数N到文件
void CRSADlg::OnOutn() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	OutToFile(m_N);
}

//将解密后字符串导出到文件
void CRSADlg::OnOutmm() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	OutToFile(m_MM);
}
