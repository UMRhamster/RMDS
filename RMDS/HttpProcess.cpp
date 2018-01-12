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
	 //��Ҫpost������
	 std::string userInfo = "account="+utils.CStrToStr(LoginAccount)  
		 +"&password="+ utils.CStrToStr(LoginPassword);  //Utils::CStrToStr ��CStringװ����string
	 //ת����char*����
	 const char *sendData = userInfo.c_str();
	 BOOL result = cHttpFile->SendRequest(
		 strHeaders,strHeaders.GetLength(),
		 (LPVOID)(LPCTSTR)sendData, strlen(sendData));
	 CString strResult,strTemp;
	 BOOL retFlag;

	 DWORD dwRet;
	 cHttpFile->QueryInfoStatusCode(dwRet);
	 //���������ʾ�������
	 if (dwRet != HTTP_STATUS_OK)
	 {
		 CString errText;
		 errText.Format(L"POST���������룺%d", dwRet);
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