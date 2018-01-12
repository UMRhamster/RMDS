#pragma once
#include "afxcmn.h"
#include "TabInterfaceOne.h"
#include "TabInterfaceTwo.h"


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
public:
	CTabCtrl mTabBar;
	TabInterfaceOne tabInterfaceOne;
	TabInterfaceTwo tabInterfaceTwo;
	CDialog* dialog[2];
	//�˵�
	CMenu cMenu;
	virtual BOOL OnInitDialog();
	//��ǰѡ���ѡ�����
	int mCurrentTab;
	afx_msg void OnTcnSelchangeTabbar(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
