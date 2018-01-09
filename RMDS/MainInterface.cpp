// MainInterface.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RMDS.h"
#include "MainInterface.h"
#include "afxdialogex.h"
#include "TabInterfaceOne.h"
#include "TabInterfaceTwo.h"


// MainInterface �Ի���

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


// MainInterface ��Ϣ�������


BOOL MainInterface::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//ΪTAB��������ѡ�
	mTabBar.InsertItem(0, _T("����1"));
	mTabBar.InsertItem(1, _T("����2"));
	//�����Ի���
	tabInterfaceOne.Create(TAB_ONE, &mTabBar);
	tabInterfaceTwo.Create(TAB_TWO, &mTabBar);
	//�趨��Tab����ʾ�ķ�Χ  
	CRect rc;
	mTabBar.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	tabInterfaceOne.MoveWindow(&rc);
	tabInterfaceTwo.MoveWindow(&rc);
	//�ѶԻ������ָ�뱣������
	dialog[0] = &tabInterfaceOne;
	dialog[1] = &tabInterfaceTwo;
	//��ʼ��������ʾ
	dialog[0]->ShowWindow(SW_SHOW);
	dialog[1]->ShowWindow(SW_HIDE);
	//���浱ǰ��ʾ״̬
	mCurrentTab = 0;
	mTabBar.SetCurSel(mCurrentTab);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void MainInterface::OnTcnSelchangeTabbar(NMHDR *pNMHDR, LRESULT *pResult)
{
	//���ص�ǰ����
	dialog[mCurrentTab]->ShowWindow(SW_HIDE);
	//��ȡ�½��������
	mCurrentTab = mTabBar.GetCurSel();
	//��ʾ�½���
	dialog[mCurrentTab]->ShowWindow(SW_SHOW);
	
	*pResult = 0;
}
