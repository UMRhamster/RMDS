#pragma once


// TabInterfaceOne �Ի���

class TabInterfaceOne : public CDialogEx
{
	DECLARE_DYNAMIC(TabInterfaceOne)

public:
	TabInterfaceOne(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TabInterfaceOne();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = TAB_ONE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
