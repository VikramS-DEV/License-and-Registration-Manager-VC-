
// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "License Manager.h"
#include "DlgProxy.h"
#include "License ManagerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLicenseManagerDlgAutoProxy

IMPLEMENT_DYNCREATE(CLicenseManagerDlgAutoProxy, CCmdTarget)

CLicenseManagerDlgAutoProxy::CLicenseManagerDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CLicenseManagerDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CLicenseManagerDlg)))
		{
			m_pDialog = reinterpret_cast<CLicenseManagerDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CLicenseManagerDlgAutoProxy::~CLicenseManagerDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CLicenseManagerDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CLicenseManagerDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CLicenseManagerDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// Note: we add support for IID_ILicenseManager to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .IDL file.

// {43A21C41-3300-4795-B00C-9EBCC206996A}
static const IID IID_ILicenseManager =
{ 0x43A21C41, 0x3300, 0x4795, { 0xB0, 0xC, 0x9E, 0xBC, 0xC2, 0x6, 0x99, 0x6A } };

BEGIN_INTERFACE_MAP(CLicenseManagerDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CLicenseManagerDlgAutoProxy, IID_ILicenseManager, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {FEC12A09-80FB-4DE8-8826-59A1D7A26DDC}
IMPLEMENT_OLECREATE2(CLicenseManagerDlgAutoProxy, "LicenseManager.Application", 0xfec12a09, 0x80fb, 0x4de8, 0x88, 0x26, 0x59, 0xa1, 0xd7, 0xa2, 0x6d, 0xdc)


// CLicenseManagerDlgAutoProxy message handlers
