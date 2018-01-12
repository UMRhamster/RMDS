// RegisterDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "RMDS.h"
#include "RegisterDialog.h"
#include "afxdialogex.h"


// RegisterDialog 对话框

IMPLEMENT_DYNAMIC(RegisterDialog, CDialogEx)

RegisterDialog::RegisterDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_REGISTER, pParent)
	, mRegisterAccount(_T(""))
	, mRegisterPassWordF(_T(""))
	, mRegisterPassWordS(_T(""))
{

}

RegisterDialog::~RegisterDialog()
{
}

void RegisterDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, REGISTER_ACCOUNT_EDIT, mRegisterAccount);
	DDV_MaxChars(pDX, mRegisterAccount, 16);
	DDX_Text(pDX, REGISTER_PASSWORDF_EDIT, mRegisterPassWordF);
	DDV_MaxChars(pDX, mRegisterPassWordF, 20);
	DDX_Text(pDX, REGISTER_PASSWORDS_EDIT, mRegisterPassWordS);
	DDV_MaxChars(pDX, mRegisterPassWordS, 20);
}


BEGIN_MESSAGE_MAP(RegisterDialog, CDialogEx)
END_MESSAGE_MAP()


// RegisterDialog 消息处理程序
