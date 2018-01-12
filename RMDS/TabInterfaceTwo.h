#pragma once
#include<tlhelp32.h>
#include<conio.h>
#include<iostream>
#include "afxcmn.h"

// TabInterfaceTwo �Ի���

class TabInterfaceTwo : public CDialogEx
{
	DECLARE_DYNAMIC(TabInterfaceTwo)

public:
	TabInterfaceTwo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TabInterfaceTwo();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = TAB_TWO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString mProcessInfo;
	afx_msg void OnBnClickedButton1();
	CListCtrl mProcessList;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void RefreshDataInList();   //ˢ��list�е�����
	BOOL stopTimer;
	afx_msg void OnBnClickedButton2();
};
