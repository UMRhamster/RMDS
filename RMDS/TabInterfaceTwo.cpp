// TabInterfaceTwo.cpp : 实现文件
//

#include "stdafx.h"
#include "RMDS.h"
#include "TabInterfaceTwo.h"
#include "afxdialogex.h"


// TabInterfaceTwo 对话框

IMPLEMENT_DYNAMIC(TabInterfaceTwo, CDialogEx)

TabInterfaceTwo::TabInterfaceTwo(CWnd* pParent /*=NULL*/)
	: CDialogEx(TAB_TWO, pParent)
{

}

TabInterfaceTwo::~TabInterfaceTwo()
{
}

void TabInterfaceTwo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TabInterfaceTwo, CDialogEx)
END_MESSAGE_MAP()


// TabInterfaceTwo 消息处理程序
