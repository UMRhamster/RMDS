// MainInterface.cpp : 实现文件
//

#include "stdafx.h"
#include "RMDS.h"
#include "MainInterface.h"
#include "afxdialogex.h"


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
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MainInterface, CDialogEx)
END_MESSAGE_MAP()


// MainInterface 消息处理程序
