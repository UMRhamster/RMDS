#pragma once


// MainInterface �Ի���

class MainInterface : public CDialogEx
{
	DECLARE_DYNAMIC(MainInterface)

public:
	MainInterface(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MainInterface();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
