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
END_MESSAGE_MAP()


// TabInterfaceOne 消息处理程序
