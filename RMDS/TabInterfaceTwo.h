#pragma once


// TabInterfaceTwo �Ի���

class TabInterfaceTwo : public CDialogEx
{
	DECLARE_DYNAMIC(TabInterfaceTwo)

public:
	TabInterfaceTwo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TabInterfaceTwo();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = TAB_TWO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
