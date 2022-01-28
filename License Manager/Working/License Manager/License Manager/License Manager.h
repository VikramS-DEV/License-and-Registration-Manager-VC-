
// License Manager.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLicenseManagerApp:
// See License Manager.cpp for the implementation of this class
//

class CLicenseManagerApp : public CWinApp
{
public:
	CLicenseManagerApp();

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLicenseManagerApp theApp;