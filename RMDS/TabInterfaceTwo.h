#pragma once
#include<tlhelp32.h>
#include<conio.h>
#include<iostream>
#include "afxcmn.h"

// TabInterfaceTwo 对话框

class TabInterfaceTwo : public CDialogEx
{
	DECLARE_DYNAMIC(TabInterfaceTwo)

public:
	TabInterfaceTwo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TabInterfaceTwo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = TAB_TWO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString mProcessInfo;
	afx_msg void OnBnClickedButton1();
	CListCtrl mProcessList;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void RefreshDataInList();   //刷新list中的数据
	BOOL stopTimer;
	afx_msg void OnBnClickedButton2();
};
