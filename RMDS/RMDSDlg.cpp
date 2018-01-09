
// RMDSDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CRMDSDlg 对话框



CRMDSDlg::CRMDSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RMDS_DIALOG, pParent)
	, mLoginAccount(_T(""))
	, mLoginPassWord(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRMDSDlg::DoDataExchange(CDataExchange* pDX)
{
	//字体修改
	LOGIN_ACCOUNT_FONT.CreatePointFont(100, L"宋体");
	GetDlgItem(LOGIN_ACCOUNT)->SetFont(&LOGIN_ACCOUNT_FONT);
	//不合法提示
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


// CRMDSDlg 消息处理程序

BOOL CRMDSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRMDSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRMDSDlg::OnQueryDragIcon()
{return static_cast<HCURSOR>(m_hIcon);
}

	


void CRMDSDlg::OnStnClickedAccount()
{
	// TODO: 在此添加控件通知处理程序代码
}

//登录处理
void CRMDSDlg::OnBnClickedButton()
{
	GetDlgItem(LOGIN_ACCOUNT_EDIT)->GetWindowTextW(mLoginAccount); //获取输入账号
	GetDlgItem(LOGIN_PASSWORD_EDIT)->GetWindowTextW(mLoginPassWord); //获取输入密码
	if (CheckAccountInfo(CStrToStr(mLoginAccount)) && CheckPassWordInfo(CStrToStr(mLoginPassWord)))
	{
		MainInterface *mainInterface = new MainInterface; //创建主界面
		mainInterface->Create(IDD_DIALOG_MAIN, NULL);      //创建主界面
		mainInterface->ShowWindow(SW_SHOW);               //显示主界面
		ShowWindow(SW_HIDE);                              //隐藏当前界面（登录界面）
	}
}

/*
*正则表达式进行账号合法判断
*
*输入：string类型
*
*输出：BOOL类型
*/
BOOL CRMDSDlg::CheckAccountInfo(std::string str) 
{
	std::regex regPattern("[0-9a-zA-Z]{6,16}");   //正则规则:只能为数字、大小写英文字母 6~16位
	return std::regex_match(str, regPattern);  //返回判断 
}
/*
*正则表达式进行密码合法判断
*
*输入：string类型
*
*输出：BOOL类型
*/
BOOL CRMDSDlg::CheckPassWordInfo(std::string str)
{
	std::regex regPattern("[0-9a-zA-Z]{6,20}");   //正则规则:只能为数字、大小写英文字母 6~20位
	return std::regex_match(str, regPattern);  //返回判断 
}
/*
 *CString to string
 *
 *输入：CString类型
 *
 *输出：string类型
 */
std::string CRMDSDlg::CStrToStr(CString cString)
{
	CT2CA tempPassWord(cString);
	std::string strPassWord(tempPassWord);    //转换成string类型
	return strPassWord;
}
