
// License ManagerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "License Manager.h"
#include "License ManagerDlg.h"
#include "Expire.h"
#include "DlgProxy.h"
#include "afxdialogex.h"
#include <Windows.h>
#include <rpc.h>
#include <rpcdce.h>
#include<stdio.h>
#include <iostream> 
#include <string>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#pragma comment(lib, "rpcrt4.lib")

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLicenseManagerDlg dialog

//Global variables
CString servcode;


IMPLEMENT_DYNAMIC(CLicenseManagerDlg, CDialog);

CLicenseManagerDlg::CLicenseManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLicenseManagerDlg::IDD, pParent)
{
	GetMACaddress();
	servercode = servcode;
	company = _T("");
	Cname = _T("");
	emailid = _T("");
	phoneno = _T("");
	address = _T("");
	city = _T("");
	state = _T("");
	zipcode = _T("");
	country = _T("");
	nouser = _T("");
	Product = _T("");
	licPath = _T("");
	
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	VERIFY(m_bmpEarth.LoadBitmap(IDB_BITMAP1));
	m_pAutoProxy = NULL;
}

CLicenseManagerDlg::~CLicenseManagerDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CLicenseManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SCode, servercode);
	DDX_Text(pDX, IDC_Servcode, servercode);
	DDX_Text(pDX, IDC_ComName, company); 
	DDX_Text(pDX, IDC_Pname, Product);
	DDX_Text(pDX, IDC_Cperson, Cname);
	DDX_Text(pDX, IDC_Email, emailid);
	DDX_Text(pDX, IDC_Phno, phoneno);
	DDX_Text(pDX, IDC_Address, address);
	DDX_Text(pDX, IDC_City, city);
	DDX_Text(pDX, IDC_State, state);
	DDX_Text(pDX, IDC_Zip, zipcode);
	DDX_Text(pDX, IDC_Country, country);
	DDX_Text(pDX, IDC_NoUser, nouser);
	DDX_Text(pDX, IDC_LicPath, licPath);
}

BEGIN_MESSAGE_MAP(CLicenseManagerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_ERASEBKGND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ReLicButton, &CLicenseManagerDlg::OnBnClickedRelicbutton)
	ON_BN_CLICKED(IDC_Browse, &CLicenseManagerDlg::OnBnClickedBrowse)
	ON_BN_CLICKED(IDC_RegButton, &CLicenseManagerDlg::OnBnClickedRegbutton)
END_MESSAGE_MAP()


// CLicenseManagerDlg message handlers

BOOL CLicenseManagerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLicenseManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

BOOL CLicenseManagerDlg::OnEraseBkgnd(CDC* pDC)
{
    CRect rect;
    GetClientRect(&rect);
    CBrush myBrush(RGB(255, 255, 255));    // dialog background color
    CBrush *pOld = pDC->SelectObject(&myBrush);
    BOOL bRes  = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
    pDC->SelectObject(pOld);    // restore old brush
    return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}
// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

/*void CLicenseManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}
*/
void CLicenseManagerDlg::OnPaint()
{
   CPaintDC dc(this); // device context for painting

   CDC dcMem;
   // create memory DC
   dcMem.CreateCompatibleDC(&dc);
   // select the source bitmao into the memory DC
   CBitmap* pOldBitmap = (CBitmap*)dcMem.SelectObject(&m_bmpEarth);
   // get the bitmap data
   BITMAP bmp = {0};
   m_bmpEarth.GetBitmap(&bmp);
   // transfer the bitmap into paint DC using a transparent color  
   dc.TransparentBlt(
      10, 10, bmp.bmWidth, bmp.bmHeight, // destination coordinates and sizes
      &dcMem,                            // source DC
      0, 0, bmp.bmWidth, bmp.bmHeight,   // source coordinates and sizes
      RGB(255, 0, 0));                   // transparent color
   // restore DC / free GDI objects 
   dcMem.SelectObject(pOldBitmap);
}
// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLicenseManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CLicenseManagerDlg::OnClose()
{
	if (CanExit())
		CDialog::OnClose();
}

void CLicenseManagerDlg::OnOK()
{
	if (CanExit())
		CDialog::OnOK();
}

void CLicenseManagerDlg::OnCancel()
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CLicenseManagerDlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}



// Fetches the MAC address and prints it
void CLicenseManagerDlg::GetMACaddress(void)
{
	unsigned char MACData[6];
	char temp[50];

	UUID uuid;
    UuidCreateSequential( &uuid );				// Ask OS to create UUID

    for (int i=2; i<8; i++)						// Bytes 2 through 7 inclusive are MAC address
		MACData[i - 2] = uuid.Data4[i];

		printf("MAC Address: %02X-%02X-%02X-%02X-%02X-%02X\n", 
	MACData[0], MACData[1], MACData[2], MACData[3], MACData[4], MACData[5]);

	char printstr[13] = {00};

for(int x = 0; x < 6; x++)
    sprintf(printstr+(x*2), "%02x", MACData[x]);
printstr[12] = '\0';

	DWORD VolumeSerialNumber=0; 
GetVolumeInformation(L"c:\\", NULL, NULL, &VolumeSerialNumber, NULL, NULL, NULL, NULL);

char volno [500];
itoa (VolumeSerialNumber ,volno,16);

servcode = CString(printstr)+CString(volno);\


CT2A ascii(servcode);

strcpy(temp,ascii.m_psz);

for(int i = 0;i< strlen(temp);i++)
{
 if(temp[i]!='7' && temp[i]!='8' && temp[i]!='9' && temp[i]!='x' && temp[i]!='y' && temp[i]!='z')		
 temp[i] = temp[i]+3;
 
}
servcode = temp;
servcode.MakeUpper();
}


void CLicenseManagerDlg::OnBnClickedRelicbutton()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(company=="" || company.GetLength()<1)
	MessageBox(_T("Please enter valid Company Name"));
	else if(Cname=="" || Cname.GetLength()<=1)
	MessageBox(_T("Please enter valid Contact Name"));
	else if(emailid=="" || emailid.Find(_T("@"))==-1 || emailid.Find(_T(".com"))==-1 )
	MessageBox(_T("Please enter valid Email ID"));
	else if (phoneno=="" && ((phoneno.GetLength())==10 && phoneno.SpanIncluding(_T("0123456789")) == phoneno))
	MessageBox(_T("Please enter valid Phone Number"));
	else if(address=="" || address.GetLength()<=1)
	MessageBox(_T("Please enter valid Addresss"));
	else if(city=="" || city.GetLength()<=1)
	MessageBox(_T("Please enter valid City"));
	else if(state=="" || state.GetLength()<=1)
	MessageBox(_T("Please enter valid State"));
	else if(zipcode==""  || zipcode.GetLength()<=1)
	MessageBox(_T("Please enter valid Zip Code"));
	else if(country=="" || country.GetLength()<=1)
	MessageBox(_T("Please enter valid Country"));
	else if(nouser=="" || nouser.SpanIncluding(_T("0123456789"))!= nouser)
	MessageBox(_T("Please enter valid Number of Users"));
	else if(Product=="" || Product.GetLength()<=1)
	MessageBox(_T("Please enter Product Name"));
	else
	{
	char deskpath[500];

	SHGetSpecialFolderPathA(HWND_DESKTOP, deskpath, CSIDL_DESKTOP, FALSE);
	CString path = CString(deskpath);	

	CTime t = CTime::GetCurrentTime();
    CString time = t.Format("%d/%m/%Y");	

	FILE *fptr;

	   fptr = fopen(path+"\\Registration.key", "w");
	   
    // exiting program 
    if (fptr == NULL) {
        MessageBox(_T("File System Error!"));
        exit(1);
    } 

	fprintf(fptr,"Antech Systems License Request Information\n------------------------------------------------------------------------------------\n");
	CT2A ascii(time);
	fprintf(fptr,"Date: %s\n",ascii.m_psz);
	CT2A ascii1(servercode);
	fprintf(fptr,"Server Code: %s\n",ascii1.m_psz);
	CT2A ascii2(company);
	fprintf(fptr,"Company: %s\n",ascii2.m_psz);
	CT2A ascii3(Cname);
	fprintf(fptr,"Contact Person: %s\n",ascii3.m_psz);
	CT2A ascii4(emailid);
	fprintf(fptr,"Email Id: %s\n",ascii4.m_psz);
	CT2A ascii5(phoneno);
	fprintf(fptr,"Phone Number: %s\n",ascii5.m_psz);
	CT2A ascii6(address);
	fprintf(fptr,"Address: %s\n",ascii6.m_psz);
	CT2A ascii7(city);
	fprintf(fptr,"City: %s\n",ascii7.m_psz);
	CT2A ascii8(state);
	fprintf(fptr,"State: %s\n",ascii8.m_psz);
	CT2A ascii9(zipcode);
	fprintf(fptr,"Zip Code: %s\n",ascii9.m_psz);
	CT2A ascii10(country);
	fprintf(fptr,"Country: %s\n",ascii10.m_psz);
	CT2A ascii11(nouser);
	fprintf(fptr,"Number of Users: %s\n",ascii11.m_psz);
	CT2A ascii12(Product);
	fprintf(fptr,"Product: %s\n",ascii12.m_psz);

	
	fclose(fptr);
   
	MessageBox(_T("Your Registration key file is succesfully created on your Dekstop!\nPlease email us this file to rnd@antechmicro.com for license"));
	
	}

}


void CLicenseManagerDlg::OnBnClickedBrowse()
{
	// TODO: Add your control notification handler code here
		TCHAR szFilter[] = _T("License Files (*.lic)|*.lic||KEY Files (*.lic)|*.key|Text Files (*.txt)|*.txt|");


	CString cstrPath;
 
	CFileDialog FileBrw(TRUE,_T("All Files"), (LPCTSTR)(cstrPath), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter, this );	 
	
	if(FileBrw.DoModal()==IDOK)
	{
		licPath=FileBrw.GetPathName();
		SetDlgItemText(IDC_LicPath,licPath);
	}
}


void CLicenseManagerDlg::OnBnClickedRegbutton()
{
	// TODO: Add your control notification handler code here

	FILE *fp;
	char fline,scode[100],prcode[100],vtime[100],str[500],cutime[500],fullcode[500],oldcode[500];
	int count = 0,lcount = 0,i=0,j=0,k=0,l=0,days=0,ct=0;
	BOOL first = TRUE;



	CT2A ascii(licPath);

	fp = fopen(ascii.m_psz,"r");
 if(fp!=NULL)
{
  while(!feof(fp))
 {
	if(lcount<4)
	{
		fgets(str,200,fp);

		if(lcount==2)
		{
		
			if(strstr(str,"Valid Days:")!=NULL)
			days=1;
			
			if(strstr(str,"Valid Runs:")!=NULL)
			days=0;
		}
		lcount++;
	}
	else
	{
		if(first==TRUE)
		{
			fline = fgetc(fp);
			first=FALSE;
		}
		if(fline == '-')
		{
			count++;
			fline = fgetc(fp);
		}
		if(count == 1)
		{
		  scode[i] = fline;
		  i++;
		}

		if(count == 2)
		{
			prcode[j] = fline;
			j++;
		}
		if(count == 3)
		{
			vtime[k] = fline;
			k++;
		}
		if(count == 4)
		{
			cutime[l] = fline;
			l++;
		}
		fline = fgetc(fp);
	}

 }
  fclose(fp);
}
  scode[i]='\0';
  prcode[j]='\0';
  vtime[k]='\0';
  cutime[l]='\0';
//  MessageBox(CString(scode));
// MessageBox(CString(prcode));
// MessageBox(CString(vtime));

  //Getting the full code
  fp = fopen(ascii.m_psz,"r");

 if(fp!=NULL)
{
  while(!feof(fp))
  {
	  fgets(str,200,fp);
	  ct++;

	  if(ct == 5)
	strcpy(fullcode,str);		

  }
}
 fclose(fp);


  //Decryption of the servercode

  int blink = 1;
  char temp[200];
for(int i = 0;i< 20;i++)
{
 if(blink == 1)
 {
	 temp[i] = scode[i]-23;
	 blink=0;
 }
 else
 {
	temp[i] = scode[i]-22;
	blink=1;
 }

}

temp[20] = '\0';


//-------------------------------------------
// To check if the license file matches the previous file
	FILE *file;
			TCHAR szPath[_MAX_PATH]; 
    VERIFY(::GetModuleFileName(AfxGetApp()->m_hInstance, szPath, _MAX_PATH));
    CString fsPath(szPath);

    int nIndex  = fsPath.ReverseFind(_T('\\')); 
	 if (nIndex > 0)
	{
    fsPath = fsPath.Left(nIndex);
    }

   if (file = fopen(fsPath +"\\Log_Files\\IunCl87.dll", "r")) {
	   fgets(str,200,fp);
      fclose(file);

	  if(strcmp(str,fullcode)==0)
	  {
		  MessageBox(_T("License file is already used!"));
		  return;
	  }

   }

// To Make dll with code
CT2A ascii1(servercode);


if(strcmp(temp,ascii1.m_psz)==0)
{
		TCHAR szPath[_MAX_PATH]; 
    VERIFY(::GetModuleFileName(AfxGetApp()->m_hInstance, szPath, _MAX_PATH));
    CString csPath(szPath);

    int nIndex  = csPath.ReverseFind(_T('\\')); 
	 if (nIndex > 0)
	{
    csPath = csPath.Left(nIndex);
    }

	 CT2A aspath(csPath +"\\Log_Files\\rlet9.dll");
    

	 fp = fopen(csPath +"\\Log_Files\\IunCl87.dll","w");  //DLL where the full code will be stored
	 fprintf(fp,"%s",fullcode);
	 fclose(fp);

	 fp = fopen(aspath.m_psz,"w");

	if (fp == NULL) {
        MessageBox(_T("Log File System Error!"));
        exit(1);
    }
	else
	{
	 fprintf(fp,"%s\n",vtime);
	 fprintf(fp,"%s\n",prcode);
	 if(days==1)
	 fprintf(fp,"D\n");
	 else
	 fprintf(fp,"R\n");
	 fprintf(fp,"%s\n",cutime);
	 fclose(fp);

	 MessageBox(_T("Registration Succesfull!"));
	}

	if(PathFileExists(csPath +"\\Log_Files\\HiRes.dll"))
		DeleteFile(csPath +"\\Log_Files\\HiRes.dll");

}
else
{
	MessageBox(_T("Registration File Invalid!\nContact Antech for more inforamtion"));
}



}
