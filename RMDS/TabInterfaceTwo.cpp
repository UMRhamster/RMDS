// TabInterfaceTwo.cpp : 实现文件
//

#include "stdafx.h"
#include "RMDS.h"
#include "TabInterfaceTwo.h"
#include "afxdialogex.h"
#include <afxsock.h>

// TabInterfaceTwo 对话框

IMPLEMENT_DYNAMIC(TabInterfaceTwo, CDialogEx)

TabInterfaceTwo::TabInterfaceTwo(CWnd* pParent /*=NULL*/)
	: CDialogEx(TAB_TWO, pParent)
	, mProcessInfo(_T(""))
{

}

TabInterfaceTwo::~TabInterfaceTwo()
{
}

void TabInterfaceTwo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, LIST_PROCESS, mProcessList);
}


BEGIN_MESSAGE_MAP(TabInterfaceTwo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TabInterfaceTwo::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, &TabInterfaceTwo::OnBnClickedButton2)
END_MESSAGE_MAP()


// TabInterfaceTwo 消息处理程序


BOOL TabInterfaceTwo::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	LVCOLUMN lvColumn;
	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //设置左对齐模式
	lvColumn.cx = 120;             //设置标题的宽度为120个元素
	lvColumn.pszText = _T("szExeFile");//设置标题
	mProcessList.InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //设置左对齐模式
	lvColumn.cx = 120;             //设置标题的宽度为120个元素
	lvColumn.pszText = _T("th32ProcessID");//设置标题
	mProcessList.InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //设置左对齐模式
	lvColumn.cx = 120;             //设置标题的宽度为120个元素
	lvColumn.pszText = _T("cntUsage");//设置标题
	mProcessList.InsertColumn(2, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //设置左对齐模式
	lvColumn.cx = 120;             //设置标题的宽度为120个元素
	lvColumn.pszText = _T("th32ModuleID");//设置标题
	mProcessList.InsertColumn(3, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //设置左对齐模式
	lvColumn.cx = 120;             //设置标题的宽度为120个元素
	lvColumn.pszText = _T("cntThreads");//设置标题
	mProcessList.InsertColumn(4, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //设置左对齐模式
	lvColumn.cx = 120;             //设置标题的宽度为120个元素
	lvColumn.pszText = _T("dwFlags");//设置标题
	mProcessList.InsertColumn(5, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //设置左对齐模式
	lvColumn.cx = 120;             //设置标题的宽度为120个元素
	lvColumn.pszText = _T("th32ParentProcessID");//设置标题
	mProcessList.InsertColumn(6, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //设置左对齐模式
	lvColumn.cx = 120;             //设置标题的宽度为120个元素
	lvColumn.pszText = _T("dwSize");//设置标题
	mProcessList.InsertColumn(7, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //设置左对齐模式
	lvColumn.cx = 120;             //设置标题的宽度为120个元素
	lvColumn.pszText = _T("pcPriClassBase");//设置标题
	mProcessList.InsertColumn(8, &lvColumn);

	//初始化stopTimer
	stopTimer = false;

	/*
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 procList;
	procList.dwSize = sizeof(PROCESSENTRY32);
	BOOL bRet = Process32First(hSnapshot, &procList);
	int m_ProcessCount; //进程数
		CString id, threads;
		*/
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void TabInterfaceTwo::OnBnClickedButton1()
{
	if (!stopTimer)
	{
		SetTimer(1, 1000, NULL);
		stopTimer = true;
	}
	else
	{
		KillTimer(1);
		stopTimer = false;
	}

}

void TabInterfaceTwo::RefreshDataInList()
{
	//	清空list中数据（刷新）
	mProcessList.DeleteAllItems();

	HANDLE hSnapshot;//定义一个句柄

	hSnapshot = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);// 创建系统快照

	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(pe);
	Process32First(hSnapshot, &pe);

	LVITEM lvItem;
	int nItem;

	CString str;
	int i = 0;
	do
	{
		lvItem.mask = LVIF_TEXT;
		lvItem.iItem = i;    //行号
		lvItem.iSubItem = 0;  //列号
		str.Format(L"%s", pe.szExeFile);
		lvItem.pszText = (LPWSTR)(LPCTSTR)str; //内容
		nItem = mProcessList.InsertItem(&lvItem);	 //插入一行，返回索引号
		str.Format(L"%d", pe.th32ProcessID);
		mProcessList.SetItemText(nItem, 1, (LPWSTR)(LPCTSTR)str);//设置行号和列号的值
		str.Format(L"%u", pe.cntUsage);
		mProcessList.SetItemText(nItem, 2, (LPWSTR)(LPCTSTR)str);
		str.Format(L"%u", pe.th32ModuleID);
		mProcessList.SetItemText(nItem, 3, (LPWSTR)(LPCTSTR)str);
		str.Format(L"%u", pe.cntThreads);
		mProcessList.SetItemText(nItem, 4, (LPWSTR)(LPCTSTR)str);
		str.Format(L"%u", pe.dwFlags);
		mProcessList.SetItemText(nItem, 5, (LPWSTR)(LPCTSTR)str);
		str.Format(L"%u", pe.th32ParentProcessID);
		mProcessList.SetItemText(nItem, 6, (LPWSTR)(LPCTSTR)str);
		str.Format(L"%u", pe.dwSize);
		mProcessList.SetItemText(nItem, 7, (LPWSTR)(LPCTSTR)str);
		str.Format(L"%ld", pe.pcPriClassBase);
		mProcessList.SetItemText(nItem, 8, (LPWSTR)(LPCTSTR)str);
		i++;
	} while (Process32Next(hSnapshot, &pe));
	CloseHandle(hSnapshot);//关闭
}
void TabInterfaceTwo::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case 1:
		RefreshDataInList();
		break;
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void TabInterfaceTwo::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int value = MessageBox(L"确定关闭计算机？",L"提示",MB_OKCANCEL| MB_ICONEXCLAMATION);
	if (value == 1)
	{
		system("shutdown -r");
	}
	else
	{
		system("shutdown -a");
	}
}
