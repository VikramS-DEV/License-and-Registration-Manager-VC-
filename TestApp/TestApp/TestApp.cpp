
// TestApp.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "TestApp.h"
#include "TestAppDlg.h"
#include "Expire.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestAppApp

BEGIN_MESSAGE_MAP(CTestAppApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CTestAppApp construction

CTestAppApp::CTestAppApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CTestAppApp object

CTestAppApp theApp;


// CTestAppApp initialization

BOOL CTestAppApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	//**************Code for Expiration********************************************

			TCHAR szPath[_MAX_PATH]; 
    VERIFY(::GetModuleFileName(AfxGetApp()->m_hInstance, szPath, _MAX_PATH));
    CString csPath(szPath);

    int nIndex  = csPath.ReverseFind(_T('\\')); 
	 if (nIndex > 0)
	{
    csPath = csPath.Left(nIndex);
    }

    char str[200],vtime[200],prcode[200],type[10],cutime[500];
	int cnt=0,validtime;
	UINT vt;

	CString path = csPath +"\\Log_Files\\rlet9.dll";

	FILE *fp;
	
	fp = fopen(path,"r");

	if(fp!=NULL)
	{
		while(!feof(fp))
		{

		  fgets(str,200,fp);

		  if(cnt==0)
		  strcpy(vtime,str);

		  if(cnt==1)
		  strcpy(prcode,str);

		  if(cnt==2)
		  strcpy(type,str);

		  if(cnt==3)
		  strcpy(cutime,str);
		  cnt++;

		}
		fclose(fp);
	}
	else
	{
		 if(AfxMessageBox("License is required to run the software.\n\nPlease register to generate license",MB_OKCANCEL)==IDOK)	
		 {

		  ::WinExec("LicenseManager.exe", SW_SHOWNORMAL || SW_SHOWNA);
		 return FALSE;
		}
		 else
		   return FALSE;
	}
	validtime = atoi(vtime);
	validtime = validtime/232;


	if(type[0]=='R')
		vt=TYPERUNS;
	else
		vt=TYPEDAYS;

	//Mixprcode and cur time
	strcat(prcode,cutime);

   CExpire expire("System CDNA",prcode,validtime,vt);

     if(expire.HasExpired())
    {

		fp = fopen(csPath +"\\Log_Files\\HiRes.dll","w");  //File created if the software expires
		fclose(fp);
    }

	FILE *file;

   if (file = fopen(csPath +"\\Log_Files\\HiRes.dll", "r")) {
      fclose(file);

	   if(AfxMessageBox("This software is expired\nDou you want to renew it?",MB_YESNO)==IDYES) //if the HiRes file exists the software is expired
	   ::WinExec("LicenseManager.exe", SW_SHOWNORMAL || SW_SHOWNA);
        return FALSE;
   } 


    char s[128];
	int no;
	if(type[0]=='R')
    {
		sprintf(s,"You have %d runs left)",expire.GetRunsLeft());
		DaysRemain= no = expire.GetRunsLeft();
		Stype = 1;
	}
	else
    {
		sprintf(s,"You have %d days left)",expire.GetDaysLeft());
		DaysRemain= no = expire.GetDaysLeft();
		Stype = 2;
	}

    AfxMessageBox(s);

	//CPDncApp *hpt;
//hpt->m_pMainWnd->SetWindowText(s);

	


//**********************************************************
	

	if(no!=0){
	CTestAppDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	}
	// Delete the shell manager created above.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

