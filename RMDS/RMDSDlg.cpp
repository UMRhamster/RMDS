
// RMDSDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RMDS.h"
#include "RMDSDlg.h"
#include "afxdialogex.h"
#include "Resource.h"
#include "MainInterface.h"
#include "RegisterDialog.h"
#include "HttpProcess.h"
#include "Utils.h"
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
	//���Ϸ���ʾ�������С�޸�,��ɫ�޸���OnCtlColor
	ACCOUNT_TEXT.CreatePointFont(80, L"����");
	GetDlgItem(LOGIN_ACCOUNT_TEXT)->SetFont(&ACCOUNT_TEXT);
	PASSWORD_TEXT.CreatePointFont(80, L"����");
	GetDlgItem(LOGIN_PASSWORD_TEXT)->SetFont(&PASSWORD_TEXT);

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
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(REGISTER_BUTTON, &CRMDSDlg::OnClickedRegisterButton)
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

	//���˺ű༭���Ȼ�ý���
	GetDlgItem(LOGIN_ACCOUNT_EDIT)->SetFocus();

	//S
	return FALSE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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
		//��ȡ����dc
		CPaintDC dc(this);
		//��ȡ���ڵĴ�С
		CRect windowRect;
		GetWindowRect(&windowRect);
		//ͼƬ��Դ·��
		CImage cImage;
		cImage.Load(_T("res\\main_bg.jpg"));
		//˫�����ͼ
		CDC memDC;   //�ڴ�dc
		CBitmap cBitmap;   //�����Ϊ����
		cBitmap.CreateCompatibleBitmap(&dc, windowRect.Width(), windowRect.Height());
		memDC.CreateCompatibleDC(&dc);
		CBitmap* hOldMap = (CBitmap*)memDC.SelectObject(&cBitmap);
		//��ͼƬ�����ڴ�dc��
		//cImage.Draw(GetDC()->GetSafeHdc(), CRect(0, 0, windowRect.Width(), windowRect.Height()));
		cImage.BitBlt(memDC, 0, 0, windowRect.Width(), windowRect.Height(), 0, 0, SRCCOPY);
		//�ٽ��ڴ�dc�ϵ����ݻ�������dc��
		dc.BitBlt(0, 0, windowRect.Width(), windowRect.Height(), &memDC, 0, 0, SRCCOPY);

		memDC.SelectObject(cImage);  //ѡ��ԭ��ϵͳ�ṩ�����ǵ�λͼ����
		cBitmap.DeleteObject();
		memDC.DeleteDC();

		CDialogEx::OnPaint();
		//CRect crect;
		//GetWindowRect(&crect);
		//CImage cImage;
		//if (cImage.Load(_T("main_bg.bmp")) == S_OK) {
		//	cImage.Draw(GetDC()->GetSafeHdc(), CRect(0, 0, crect.Width(), crect.Height()));
		//}
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
	if (CheckAccountInfo(utils.CStrToStr(mLoginAccount)) && CheckPassWordInfo(utils.CStrToStr(mLoginPassWord)))
	{
		//HttpProcess httpProcess;
	//	httpProcess.Login(mLoginAccount,mLoginPassWord);
		
		MainInterface *mainInterface = new MainInterface; //����������
		mainInterface->Create(IDD_DIALOG_MAIN, NULL);      //����������
		mainInterface->ShowWindow(SW_SHOW);               //��ʾ������
		ShowWindow(SW_HIDE);                              //���ص�ǰ���棨��¼���棩
		
	}
}

void CRMDSDlg::OnClickedRegisterButton()
{
	RegisterDialog registerDialog;
	registerDialog.DoModal();
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
BOOL CRMDSDlg::LoginFromFile() 
{
	//�Դ�����ʽ���ļ��������нضϣ�ֻ������
	CFile file(_T("file\\login.txt"), CFile::modeCreate
		                            | CFile::modeRead
		                            | CFile::modeNoTruncate);
	while (true)
	{
		//�ļ�ָ��
		static int position = 0;
		//�ƶ��ļ�ָ��
		file.Seek(0, CFile::begin);
		//��ȡ�ļ�
		char *buf;
		int ret = file.Read(buf, 100);
		//�Ѵﵽ�ļ�ĩβ����ֹѭ��
		if (ret < 100)
		{
			break;
		}
		//�ر��ļ�
		file.Close();
	}
	return true;
}*/
//����������ɫ��ʾ
HBRUSH CRMDSDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	int id = pWnd->GetDlgCtrlID();
	if (LOGIN_ACCOUNT_TEXT == id || LOGIN_PASSWORD_TEXT == id)
	{
		pDC->SetTextColor(RGB(255, 0, 0));  //������ɫΪ��ɫ
		pDC->SetBkMode(TRANSPARENT);//�����ı�����ģʽΪ͸��
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	
	if (LOGIN_ACCOUNT == id || LOGIN_PASSWORD == id)
	{
		pDC->SetTextColor(RGB(255, 255, 255));  //������ɫΪ��ɫ
		pDC->SetBkMode(TRANSPARENT);//�����ı�����ģʽΪ͸��
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	return hbr;
}

//���������¼�,���Ʋ��Ϸ���ʾ
BOOL CRMDSDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYUP)    //WM_KEYUP ���¼����ɿ���
	{
		GetDlgItem(LOGIN_ACCOUNT_EDIT)->GetWindowTextW(mLoginAccount);
		if (CheckAccountInfo(utils.CStrToStr(mLoginAccount))) 
		{
			GetDlgItem(LOGIN_ACCOUNT_TEXT)->ShowWindow(SW_HIDE);
		}
		else
		{
			GetDlgItem(LOGIN_ACCOUNT_TEXT)->ShowWindow(SW_SHOW);
		}
		GetDlgItem(LOGIN_PASSWORD_EDIT)->GetWindowTextW(mLoginPassWord);
		if (CheckPassWordInfo(utils.CStrToStr(mLoginPassWord)))
		{
			GetDlgItem(LOGIN_PASSWORD_TEXT)->ShowWindow(SW_HIDE);
		}
		else
		{
			GetDlgItem(LOGIN_PASSWORD_TEXT)->ShowWindow(SW_SHOW);
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
