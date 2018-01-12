
#include "stdafx.h"
#include "Utils.h"
#include <iostream>
/*
*CString to string
*
*���룺CString����
*
*�����string����
*/
std::string Utils::CStrToStr(CString cString)
{
	CT2CA tempPassWord(cString);
	std::string strPassWord(tempPassWord);    //ת����string����
	return strPassWord;
}
void Utils::sendProcessInfo()
{
	
	//���� CSocket ����
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
	//ת����Ҫ���ӵĶ˿���������
	int nPort = atoi(Utils::CStrToStr(strPort).c_str());
	//����ָ���ĵ�ַ�Ͷ˿�
	if (cSocket.Connect(strIP, nPort))
	{
		char szRecValue[1024] = { 0 };

		//�������ݸ�������
		cSocket.Send(strText, strText.GetLength());

		//���շ��������ͻ���������(�÷���������, �ڴ˵ȴ������ݽ��յ��ż�������ִ��)
		cSocket.Receive((void *)szRecValue, 1024);

		CString receive(szRecValue); //ת����CString
		AfxMessageBox(receive);
	}
	else
	{
		CString szMsg;

		szMsg.Format(L"create faild: %d", cSocket.GetLastError());

		AfxMessageBox(szMsg);
	}
}
