// Validation.cpp : implementation file
//

#include "stdafx.h"
#include "Password Generator.h"
#include "Validation.h"
#include "afxdialogex.h"


// Validation dialog

IMPLEMENT_DYNAMIC(Validation, CDialog)

Validation::Validation(CWnd* pParent /*=NULL*/)
	: CDialog(Validation::IDD, pParent)
{
	 Username = _T("");
	 Password =  _T("");
}

Validation::~Validation()
{
}

void Validation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USER, Username);
	DDX_Text(pDX,IDC_PSD, Password);
}


BEGIN_MESSAGE_MAP(Validation, CDialog)
	ON_BN_CLICKED(IDOK, &Validation::OnBnClickedOk)
END_MESSAGE_MAP()


// Validation message handlers


void Validation::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(Username == "admin" && Password == "123")
	{
	 valid = 1;
	 CDialog::OnOK();
	}
	else
	{	
		valid =0;
		MessageBox(_T("Incorrect Username or Password!\nPlease try again"));
	}
}
