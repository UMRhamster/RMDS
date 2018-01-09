
// RMDSDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RMDS.h"
#include "RMDSDlg.h"
#include "afxdialogex.h"
#include "Resource.h"
#include "MainInterface.h"
#include <regex>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRMDSDlg �Ի���



CRMDSDlg::CRMDSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RMDS_DIALOG, pParent)
	, mLoginAccount(_T(""))
	, mLoginPassWord(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRMDSDlg::DoDataExchange(CDataExchange* pDX)
{
	//�����޸�
	LOGIN_ACCOUNT_FONT.CreatePointFont(100, L"����");
	GetDlgItem(LOGIN_ACCOUNT)->SetFont(&LOGIN_ACCOUNT_FONT);
	//���Ϸ���ʾ
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, LOGIN_ACCOUNT_EDIT, mLoginAccount);
	DDV_MaxChars(pDX, mLoginAccount, 16);
	DDX_Text(pDX, LOGIN_PASSWORD_EDIT, mLoginPassWord);
	DDV_MaxChars(pDX, mLoginPassWord, 20);
}

BEGIN_MESSAGE_MAP(CRMDSDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(LOGIN_ACCOUNT, &CRMDSDlg::OnStnClickedAccount)
	ON_BN_CLICKED(LOGIN_BUTTON, &CRMDSDlg::OnBnClickedButton)
END_MESSAGE_MAP()


// CRMDSDlg ��Ϣ�������

BOOL CRMDSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CRMDSDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRMDSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRMDSDlg::OnQueryDragIcon()
{return static_cast<HCURSOR>(m_hIcon);
}

	


void CRMDSDlg::OnStnClickedAccount()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

//��¼����
void CRMDSDlg::OnBnClickedButton()
{
	GetDlgItem(LOGIN_ACCOUNT_EDIT)->GetWindowTextW(mLoginAccount); //��ȡ�����˺�
	GetDlgItem(LOGIN_PASSWORD_EDIT)->GetWindowTextW(mLoginPassWord); //��ȡ��������
	if (CheckAccountInfo(CStrToStr(mLoginAccount)) && CheckPassWordInfo(CStrToStr(mLoginPassWord)))
	{
		MainInterface *mainInterface = new MainInterface; //����������
		mainInterface->Create(IDD_DIALOG_MAIN, NULL);      //����������
		mainInterface->ShowWindow(SW_SHOW);               //��ʾ������
		ShowWindow(SW_HIDE);                              //���ص�ǰ���棨��¼���棩
	}
}

/*
*������ʽ�����˺źϷ��ж�
*
*���룺string����
*
*�����BOOL����
*/
BOOL CRMDSDlg::CheckAccountInfo(std::string str) 
{
	std::regex regPattern("[0-9a-zA-Z]{6,16}");   //�������:ֻ��Ϊ���֡���СдӢ����ĸ 6~16λ
	return std::regex_match(str, regPattern);  //�����ж� 
}
/*
*������ʽ��������Ϸ��ж�
*
*���룺string����
*
*�����BOOL����
*/
BOOL CRMDSDlg::CheckPassWordInfo(std::string str)
{
	std::regex regPattern("[0-9a-zA-Z]{6,20}");   //�������:ֻ��Ϊ���֡���СдӢ����ĸ 6~20λ
	return std::regex_match(str, regPattern);  //�����ж� 
}
/*
 *CString to string
 *
 *���룺CString����
 *
 *�����string����
 */
std::string CRMDSDlg::CStrToStr(CString cString)
{
	CT2CA tempPassWord(cString);
	std::string strPassWord(tempPassWord);    //ת����string����
	return strPassWord;
}
