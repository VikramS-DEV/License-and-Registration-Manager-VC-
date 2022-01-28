
// DlgProxy.h: header file
//

#pragma once

class CLicenseManagerDlg;


// CLicenseManagerDlgAutoProxy command target

class CLicenseManagerDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CLicenseManagerDlgAutoProxy)

	CLicenseManagerDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CLicenseManagerDlg* m_pDialog;

// Operations
public:

// Overrides
	public:
	virtual void OnFinalRelease();

// Implementation
protected:
	virtual ~CLicenseManagerDlgAutoProxy();

	// Generated message map functions

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CLicenseManagerDlgAutoProxy)

	// Generated OLE dispatch map functions

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

