#pragma once


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
};
