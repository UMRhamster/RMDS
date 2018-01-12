// TabInterfaceTwo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RMDS.h"
#include "TabInterfaceTwo.h"
#include "afxdialogex.h"
#include <afxsock.h>

// TabInterfaceTwo �Ի���

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


// TabInterfaceTwo ��Ϣ�������


BOOL TabInterfaceTwo::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	LVCOLUMN lvColumn;
	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //���������ģʽ
	lvColumn.cx = 120;             //���ñ���Ŀ��Ϊ120��Ԫ��
	lvColumn.pszText = _T("szExeFile");//���ñ���
	mProcessList.InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //���������ģʽ
	lvColumn.cx = 120;             //���ñ���Ŀ��Ϊ120��Ԫ��
	lvColumn.pszText = _T("th32ProcessID");//���ñ���
	mProcessList.InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //���������ģʽ
	lvColumn.cx = 120;             //���ñ���Ŀ��Ϊ120��Ԫ��
	lvColumn.pszText = _T("cntUsage");//���ñ���
	mProcessList.InsertColumn(2, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //���������ģʽ
	lvColumn.cx = 120;             //���ñ���Ŀ��Ϊ120��Ԫ��
	lvColumn.pszText = _T("th32ModuleID");//���ñ���
	mProcessList.InsertColumn(3, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //���������ģʽ
	lvColumn.cx = 120;             //���ñ���Ŀ��Ϊ120��Ԫ��
	lvColumn.pszText = _T("cntThreads");//���ñ���
	mProcessList.InsertColumn(4, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //���������ģʽ
	lvColumn.cx = 120;             //���ñ���Ŀ��Ϊ120��Ԫ��
	lvColumn.pszText = _T("dwFlags");//���ñ���
	mProcessList.InsertColumn(5, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //���������ģʽ
	lvColumn.cx = 120;             //���ñ���Ŀ��Ϊ120��Ԫ��
	lvColumn.pszText = _T("th32ParentProcessID");//���ñ���
	mProcessList.InsertColumn(6, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //���������ģʽ
	lvColumn.cx = 120;             //���ñ���Ŀ��Ϊ120��Ԫ��
	lvColumn.pszText = _T("dwSize");//���ñ���
	mProcessList.InsertColumn(7, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;   //���������ģʽ
	lvColumn.cx = 120;             //���ñ���Ŀ��Ϊ120��Ԫ��
	lvColumn.pszText = _T("pcPriClassBase");//���ñ���
	mProcessList.InsertColumn(8, &lvColumn);

	//��ʼ��stopTimer
	stopTimer = false;

	/*
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 procList;
	procList.dwSize = sizeof(PROCESSENTRY32);
	BOOL bRet = Process32First(hSnapshot, &procList);
	int m_ProcessCount; //������
		CString id, threads;
		*/
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
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
	//	���list�����ݣ�ˢ�£�
	mProcessList.DeleteAllItems();

	HANDLE hSnapshot;//����һ�����

	hSnapshot = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);// ����ϵͳ����

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
		lvItem.iItem = i;    //�к�
		lvItem.iSubItem = 0;  //�к�
		str.Format(L"%s", pe.szExeFile);
		lvItem.pszText = (LPWSTR)(LPCTSTR)str; //����
		nItem = mProcessList.InsertItem(&lvItem);	 //����һ�У�����������
		str.Format(L"%d", pe.th32ProcessID);
		mProcessList.SetItemText(nItem, 1, (LPWSTR)(LPCTSTR)str);//�����кź��кŵ�ֵ
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
	CloseHandle(hSnapshot);//�ر�
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int value = MessageBox(L"ȷ���رռ������",L"��ʾ",MB_OKCANCEL| MB_ICONEXCLAMATION);
	if (value == 1)
	{
		system("shutdown -r");
	}
	else
	{
		system("shutdown -a");
	}
}
