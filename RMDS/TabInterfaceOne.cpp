// TabInterfaceOne.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RMDS.h"
#include "TabInterfaceOne.h"
#include "afxdialogex.h"


// TabInterfaceOne �Ի���

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


// TabInterfaceOne ��Ϣ�������


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
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void TabInterfaceOne::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
}
