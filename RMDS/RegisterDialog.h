#pragma once


// RegisterDialog 对话框

class RegisterDialog : public CDialogEx
{
	DECLARE_DYNAMIC(RegisterDialog)

public:
	RegisterDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~RegisterDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString mRegisterAccount;
	CString mRegisterPassWordF;
	CString mRegisterPassWordS;
};
