// MainInterface.cpp : 实现文件
//

#include "stdafx.h"
#include "RMDS.h"
#include "MainInterface.h"
#include "afxdialogex.h"
#include "TabInterfaceOne.h"
#include "TabInterfaceTwo.h"


// MainInterface 对话框

IMPLEMENT_DYNAMIC(MainInterface, CDialogEx)

MainInterface::MainInterface(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_MAIN, pParent)
{

}

MainInterface::~MainInterface()
{
}

void MainInterface::DoDataExchange(CDataExchange* pDX)
{
	//.....................
	DDX_Control(pDX, MAIN_TABBAR, mTabBar);
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MainInterface, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, MAIN_TABBAR, &MainInterface::OnTcnSelchangeTabbar)
END_MESSAGE_MAP()


// MainInterface 消息处理程序


BOOL MainInterface::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//为TAB增加两个选项卡
	mTabBar.InsertItem(0, _T("测试1"));
	mTabBar.InsertItem(1, _T("测试2"));
	//创建对话框
	tabInterfaceOne.Create(TAB_ONE, &mTabBar);
	tabInterfaceTwo.Create(TAB_TWO, &mTabBar);
	//设定在Tab内显示的范围  
	CRect rc;
	mTabBar.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	tabInterfaceOne.MoveWindow(&rc);
	tabInterfaceTwo.MoveWindow(&rc);
	//把对话框对象指针保存起来
	dialog[0] = &tabInterfaceOne;
	dialog[1] = &tabInterfaceTwo;
	//初始化界面显示
	dialog[0]->ShowWindow(SW_SHOW);
	dialog[1]->ShowWindow(SW_HIDE);
	//保存当前显示状态
	mCurrentTab = 0;
	mTabBar.SetCurSel(mCurrentTab);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void MainInterface::OnTcnSelchangeTabbar(NMHDR *pNMHDR, LRESULT *pResult)
{
	//隐藏当前界面
	dialog[mCurrentTab]->ShowWindow(SW_HIDE);
	//获取新界面的索引
	mCurrentTab = mTabBar.GetCurSel();
	//显示新界面
	dialog[mCurrentTab]->ShowWindow(SW_SHOW);
	
	*pResult = 0;
}
