
// RMDSDlg.cpp : 实现文件
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
	//不合法提示的字体大小修改,颜色修改在OnCtlColor
	ACCOUNT_TEXT.CreatePointFont(80, L"宋体");
	GetDlgItem(LOGIN_ACCOUNT_TEXT)->SetFont(&ACCOUNT_TEXT);
	PASSWORD_TEXT.CreatePointFont(80, L"宋体");
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

	//让账号编辑框先获得焦点
	GetDlgItem(LOGIN_ACCOUNT_EDIT)->SetFocus();

	//S
	return FALSE;  // 除非将焦点设置到控件，否则返回 TRUE
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
		//获取窗口dc
		CPaintDC dc(this);
		//获取窗口的大小
		CRect windowRect;
		GetWindowRect(&windowRect);
		//图片资源路径
		CImage cImage;
		cImage.Load(_T("res\\main_bg.jpg"));
		//双缓冲绘图
		CDC memDC;   //内存dc
		CBitmap cBitmap;   //可理解为画布
		cBitmap.CreateCompatibleBitmap(&dc, windowRect.Width(), windowRect.Height());
		memDC.CreateCompatibleDC(&dc);
		CBitmap* hOldMap = (CBitmap*)memDC.SelectObject(&cBitmap);
		//将图片画在内存dc上
		//cImage.Draw(GetDC()->GetSafeHdc(), CRect(0, 0, windowRect.Width(), windowRect.Height()));
		cImage.BitBlt(memDC, 0, 0, windowRect.Width(), windowRect.Height(), 0, 0, SRCCOPY);
		//再将内存dc上的内容滑到窗口dc上
		dc.BitBlt(0, 0, windowRect.Width(), windowRect.Height(), &memDC, 0, 0, SRCCOPY);

		memDC.SelectObject(cImage);  //选择原来系统提供给我们的位图对象
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
	if (CheckAccountInfo(utils.CStrToStr(mLoginAccount)) && CheckPassWordInfo(utils.CStrToStr(mLoginPassWord)))
	{
		//HttpProcess httpProcess;
	//	httpProcess.Login(mLoginAccount,mLoginPassWord);
		
		MainInterface *mainInterface = new MainInterface; //创建主界面
		mainInterface->Create(IDD_DIALOG_MAIN, NULL);      //创建主界面
		mainInterface->ShowWindow(SW_SHOW);               //显示主界面
		ShowWindow(SW_HIDE);                              //隐藏当前界面（登录界面）
		
	}
}

void CRMDSDlg::OnClickedRegisterButton()
{
	RegisterDialog registerDialog;
	registerDialog.DoModal();
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
BOOL CRMDSDlg::LoginFromFile() 
{
	//以创建方式打开文件，不进行截断，只读操作
	CFile file(_T("file\\login.txt"), CFile::modeCreate
		                            | CFile::modeRead
		                            | CFile::modeNoTruncate);
	while (true)
	{
		//文件指针
		static int position = 0;
		//移动文件指针
		file.Seek(0, CFile::begin);
		//读取文件
		char *buf;
		int ret = file.Read(buf, 100);
		//已达到文件末尾，中止循环
		if (ret < 100)
		{
			break;
		}
		//关闭文件
		file.Close();
	}
	return true;
}*/
//控制文字颜色显示
HBRUSH CRMDSDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	int id = pWnd->GetDlgCtrlID();
	if (LOGIN_ACCOUNT_TEXT == id || LOGIN_PASSWORD_TEXT == id)
	{
		pDC->SetTextColor(RGB(255, 0, 0));  //设置颜色为红色
		pDC->SetBkMode(TRANSPARENT);//设置文本背景模式为透明
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	
	if (LOGIN_ACCOUNT == id || LOGIN_PASSWORD == id)
	{
		pDC->SetTextColor(RGB(255, 255, 255));  //设置颜色为白色
		pDC->SetBkMode(TRANSPARENT);//设置文本背景模式为透明
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	return hbr;
}

//监听键盘事件,控制不合法提示
BOOL CRMDSDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYUP)    //WM_KEYUP 按下键盘松开后
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
