
// RMDSDlg.h : 头文件
//

#pragma once
#include <iostream>
#include <string>

// CRMDSDlg 对话框
class CRMDSDlg : public CDialogEx
{
// 构造
public:
	CRMDSDlg(CWnd* pParent = NULL);	// 标准构造函数
	//控件定义-用于修改文字大小及颜色
	CFont LOGIN_ACCOUNT_FONT;   //
	CFont LOGIN_PASSWORD_FONT;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RMDS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnStnClickedAccount();
	afx_msg void OnBnClickedButton();
	CString mLoginAccount;
	CString mLoginPassWord;
//自定义函数
private:
	BOOL CheckAccountInfo(std::string str);
	BOOL CheckPassWordInfo(std::string str);
	std::string CStrToStr(CString cString);

};
