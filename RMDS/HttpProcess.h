#pragma once
#include "stdafx.h"
#include "Utils.h"
#include <iostream>
#include <afxinet.h>

class HttpProcess
{
private:
	//std::string CStrToStr(CString cString);
public:
	BOOL Login(CString LoginAccount, CString LoginPassword);
	CInternetSession cInternetSession;
	Utils utils;
};