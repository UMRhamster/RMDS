
// RMDSDlg.h : ͷ�ļ�
//

#pragma once
#include <iostream>
#include <string>

// CRMDSDlg �Ի���
class CRMDSDlg : public CDialogEx
{
// ����
public:
	CRMDSDlg(CWnd* pParent = NULL);	// ��׼���캯��
	//�ؼ�����-�����޸����ִ�С����ɫ
	CFont LOGIN_ACCOUNT_FONT;   //
	CFont LOGIN_PASSWORD_FONT;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RMDS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
//�Զ��庯��
private:
	BOOL CheckAccountInfo(std::string str);
	BOOL CheckPassWordInfo(std::string str);
	std::string CStrToStr(CString cString);

};
