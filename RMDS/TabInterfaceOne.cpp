// TabInterfaceOne.cpp : 实现文件
//

#include "stdafx.h"
#include "RMDS.h"
#include "TabInterfaceOne.h"
#include "afxdialogex.h"


// TabInterfaceOne 对话框

IMPLEMENT_DYNAMIC(TabInterfaceOne, CDialogEx)

TabInterfaceOne::TabInterfaceOne(CWnd* pParent /*=NULL*/)
	: CDialogEx(TAB_ONE, pParent)
{

}

TabInterfaceOne::~TabInterfaceOne()
{
}

void TabInterfaceOne::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TabInterfaceOne, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// TabInterfaceOne 消息处理程序


BOOL TabInterfaceOne::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	/*
	int cx, cy;
	cx = GetSystemMetrics(SM_CXSCREEN);
	cy = GetSystemMetrics(SM_CYSCREEN);
	
	CRect rcTemp;
	rcTemp.BottomRight() = CPoint(500, 500);
	rcTemp.TopLeft() = CPoint(0, 0);
	MoveWindow(&rcTemp);
	*/
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void TabInterfaceOne::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}
