#pragma once


// RegisterDialog �Ի���

class RegisterDialog : public CDialogEx
{
	DECLARE_DYNAMIC(RegisterDialog)

public:
	RegisterDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~RegisterDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString mRegisterAccount;
	CString mRegisterPassWordF;
	CString mRegisterPassWordS;
};
