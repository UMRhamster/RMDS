#pragma once
#include "afxcmn.h"
#include "TabInterfaceOne.h"
#include "TabInterfaceTwo.h"


// MainInterface 对话框

class MainInterface : public CDialogEx
{
	DECLARE_DYNAMIC(MainInterface)

public:
	MainInterface(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MainInterface();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl mTabBar;
	TabInterfaceOne tabInterfaceOne;
	TabInterfaceTwo tabInterfaceTwo;
	CDialog* dialog[2];
	//菜单
	CMenu cMenu;
	virtual BOOL OnInitDialog();
	//当前选择的选项卡界面
	int mCurrentTab;
	afx_msg void OnTcnSelchangeTabbar(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
