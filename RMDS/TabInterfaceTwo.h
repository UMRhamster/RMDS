#pragma once


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
};
