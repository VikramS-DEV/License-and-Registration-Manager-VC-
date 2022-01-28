#pragma once


// Validation dialog

class Validation : public CDialog
{
	DECLARE_DYNAMIC(Validation)

public:
	Validation(CWnd* pParent = NULL);   // standard constructor
	virtual ~Validation();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

	CString Username,Password;
	int valid;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
