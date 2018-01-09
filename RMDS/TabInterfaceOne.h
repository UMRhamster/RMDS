#pragma once


// TabInterfaceOne 对话框

class TabInterfaceOne : public CDialogEx
{
	DECLARE_DYNAMIC(TabInterfaceOne)

public:
	TabInterfaceOne(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TabInterfaceOne();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = TAB_ONE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
