
// RMDS.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRMDSApp: 
// �йش����ʵ�֣������ RMDS.cpp
//

class CRMDSApp : public CWinApp
{
public:
	CRMDSApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CRMDSApp theApp;
