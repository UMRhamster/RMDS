#include "stdafx.h"
#include "HttpProcess.h"
#include <afxpriv.h>



BOOL HttpProcess::Login(CString LoginAccount, CString LoginPassword)
{

	 CHttpConnection *cHttpConnection = cInternetSession
		.GetHttpConnection(TEXT("dyc1996.w3.luyouxia.net"));
	 CHttpFile *cHttpFile = cHttpConnection->OpenRequest(
		CHttpConnection::HTTP_VERB_POST,
		L"/test");
	 CString strHeaders = L"Content-Type: application/x-www-form-urlencoded;charset=UTF-8";
	 //需要post的数据
	 std::string userInfo = "account="+utils.CStrToStr(LoginAccount)  
		 +"&password="+ utils.CStrToStr(LoginPassword);  //Utils::CStrToStr 将CString装换成string
	 //转换成char*类型
	 const char *sendData = userInfo.c_str();
	 BOOL result = cHttpFile->SendRequest(
		 strHeaders,strHeaders.GetLength(),
		 (LPVOID)(LPCTSTR)sendData, strlen(sendData));
	 CString strResult,strTemp;
	 BOOL retFlag;

	 DWORD dwRet;
	 cHttpFile->QueryInfoStatusCode(dwRet);
	 //如果报错，提示错误代码
	 if (dwRet != HTTP_STATUS_OK)
	 {
		 CString errText;
		 errText.Format(L"POST出错，错误码：%d", dwRet);
		 AfxMessageBox(errText);
	 }

	 do
	 {
		 cHttpFile->SetReadBufferSize(10 * 1024);
		 retFlag = cHttpFile->ReadString(strTemp);
		 strResult += strTemp + L"/n";
	 } while (retFlag != FALSE);
	 return true;
}