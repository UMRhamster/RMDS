
#include "stdafx.h"
#include "Utils.h"
#include <iostream>
/*
*CString to string
*
*输入：CString类型
*
*输出：string类型
*/
std::string Utils::CStrToStr(CString cString)
{
	CT2CA tempPassWord(cString);
	std::string strPassWord(tempPassWord);    //转换成string类型
	return strPassWord;
}
void Utils::sendProcessInfo()
{
	
	//创建 CSocket 对象
	CSocket cSocket;

	CString strIP = L"dyc1996.w3.luyouxia.net";
	CString strPort = L"/login";
	CString strText;

	if (!cSocket.Create())
	{
		CString message;
		message.Format(L"create faild: %d",cSocket.GetLastError());
		AfxMessageBox(message);
		return;
	}
	//转换需要连接的端口内容类型
	int nPort = atoi(Utils::CStrToStr(strPort).c_str());
	//连接指定的地址和端口
	if (cSocket.Connect(strIP, nPort))
	{
		char szRecValue[1024] = { 0 };

		//发送内容给服务器
		cSocket.Send(strText, strText.GetLength());

		//接收服务器发送回来的内容(该方法会阻塞, 在此等待有内容接收到才继续向下执行)
		cSocket.Receive((void *)szRecValue, 1024);

		CString receive(szRecValue); //转换成CString
		AfxMessageBox(receive);
	}
	else
	{
		CString szMsg;

		szMsg.Format(L"create faild: %d", cSocket.GetLastError());

		AfxMessageBox(szMsg);
	}
}
