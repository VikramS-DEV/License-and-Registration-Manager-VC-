
// Password GeneratorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Password Generator.h"
#include "Password GeneratorDlg.h"
#include "afxdialogex.h"
#include "Validation.h"
#include<afxwin.h>
#include<afx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CPasswordGeneratorDlg dialog




CPasswordGeneratorDlg::CPasswordGeneratorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPasswordGeneratorDlg::IDD, pParent)
{
	licPath = _T("");
	Pcode = _T("");
	Pver= _T("");
	valid = _T("");
	Runs = FALSE;

	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	VERIFY(m_bmpEarth.LoadBitmap(IDB_BITMAP1));
}

void CPasswordGeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ProdVer, Pver);
	DDX_Text(pDX,IDC_ProdCode, Pcode);
	//DDX_Text(pDX,IDC_DATETIMEPICKER1, valid);
	DDX_Text(pDX,IDC_Vday, valid);
}

BEGIN_MESSAGE_MAP(CPasswordGeneratorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Browse, &CPasswordGeneratorDlg::OnBnClickedBrowse)
	ON_BN_CLICKED(IDC_Generate, &CPasswordGeneratorDlg::OnBnClickedGenerate)
	ON_BN_CLICKED(IDC_RADIO1, &CPasswordGeneratorDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CPasswordGeneratorDlg::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CPasswordGeneratorDlg message handlers

BOOL CPasswordGeneratorDlg::OnInitDialog()
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

void CPasswordGeneratorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

/*void CPasswordGeneratorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
	    dc.SetBkColor(RGB(255,255,255));
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
}*/
BOOL CPasswordGeneratorDlg::OnEraseBkgnd(CDC* pDC)
{
    CRect rect;
    GetClientRect(&rect);
    CBrush myBrush(RGB(255, 255, 255));    // dialog background color
    CBrush *pOld = pDC->SelectObject(&myBrush);
    BOOL bRes  = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
    pDC->SelectObject(pOld);    // restore old brush
    return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}


void CPasswordGeneratorDlg::OnPaint()
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
HCURSOR CPasswordGeneratorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPasswordGeneratorDlg::OnBnClickedBrowse()
{
	// TODO: Add your control notification handler code here
	TCHAR szFilter[] = _T("Key Files (*.key)|*.key||KEY Files (*.key)|*.key|Text Files (*.txt)|*.txt|");


	CString cstrPath;
 
	CFileDialog FileBrw(TRUE,_T("All Files"), (LPCTSTR)(cstrPath), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter, this );	

	if(FileBrw.DoModal()==IDOK)
	{
		licPath = FileBrw.GetPathName();
		SetDlgItemText(IDC_LicPath,licPath);
		
	}
}


void CPasswordGeneratorDlg::OnBnClickedGenerate()
{
	UpdateData(TRUE);
	Validation dlg;
	//CTime t = CTime::GetCurrentTime();
	//CString p = t.Format("%d-%m-%Y");
	if(licPath!="" && Pver!="" && Pcode!="" && valid!="" && valid.SpanIncluding(_T("0123456789")) == valid )	{
	 	
		if(Runs==FALSE && Days == FALSE)
		MessageBox(_T("Please select Days or Runs"));
		else
		dlg.DoModal();
	}
	else
		MessageBox(_T("Please fill all the details OR check the validity date"));
if(dlg.valid==1)
{

	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	FILE *fptr;
	CT2A ascii(licPath);
	char str[500],servcode[500],prcode[50],temp[200],pname[50];

	fptr = fopen(ascii.m_psz, "r");

	while(!feof(fptr))
	{
	  fgets(str,200,fptr);

	  if(strstr(str,"Server Code:")!=NULL)
	  {
	    sscanf(str,"Server Code: %s",servcode);
	  }

	  if(strstr(str,"Product:")!=NULL)
	  {
	    sscanf(str,"Product: %s",pname);
	  }
	}
	fclose(fptr);

/*
Codes for Product Codes

AMSDNC01     T178754
AMSDNC02	 T343874	
AMSDNC03	 T579103
AMSDNC08	 T974325
AMSDNC16	 T821047
AMSDNC24	 T103268	
AMSDNC30	 T232556
AMSDNC50	 T437713
AMSCADL10	 T686451
*/

	if(Pcode == "AMSDNC01")
	strcpy(prcode,"T178754");
	else if(Pcode == "AMSDNC02")
	strcpy(prcode,"T343874");
	else if(Pcode == "AMSDNC03")
	strcpy(prcode,"T579103");
	else if(Pcode == "AMSDNC08")
	strcpy(prcode,"T974325");
	else if(Pcode == "AMSDNC16")
	strcpy(prcode,"T821047");
	else if(Pcode == "AMSDNC24")
	strcpy(prcode,"T103268");
	else if(Pcode == "AMSDNC30")
	strcpy(prcode,"T232556");
	else if(Pcode == "AMSDNC50")
	strcpy(prcode,"T437713");
	else if(Pcode == "AMSCADL10")
	strcpy(prcode,"T686451");
	else
		strcpy(prcode,"UD");

	//Get  License generation date
	
   // CString time = t.Format("%d%m%Y");

// Generation date encryption
	//CT2A ascitime(time);

	//int tdate = atoi(ascitime.m_psz);

	//tdate = tdate*6;

	/*
	//Remove '-' from valid date
	CString sz = valid;
	CString szToDelete = _T("-");
	int ipos;
	CString sz2;
	while ((ipos = sz.FindOneOf(szToDelete)) >= 0)
	{
	sz2 = sz.Left(ipos);
	sz2 += sz.Mid(ipos + 1);
	sz = sz2;
	}

	//valid = sz;
	*/
//Valid date encryption
	//CT2A ascivalid(sz);

	CT2A ascivalid(valid);


	int validdate = atoi(ascivalid.m_psz);

	validdate = validdate*232;
	
//Current Date Encryption
CTime t = CTime::GetCurrentTime();
CString p = t.Format("%d%H%M%S");

CT2A ascipt(p);

int curtime = atoi(ascipt.m_psz);


//Server Code Encryption

strcpy(temp,servcode);
int blink = 1;

for(int i = 0;i< strlen(temp);i++)
{
 if(blink == 1)
 {
	 temp[i] = temp[i]+23;
	 blink=0;
 }
 else
 {
	temp[i] = temp[i]+22;
	blink=1;
 }

}




//Concatination of the License code
strcpy(servcode,"A4YJ827K8IP7217V1M87N24D2F17036-");
strcat(servcode,temp);
//itoa(validdate,temp,10);
//strcat(servcode,temp);
strcat(servcode,"-");
strcat(servcode,prcode);
strcat(servcode,"-");
itoa(validdate,temp,10);
strcat(servcode,temp);
strcat(servcode,"-");
itoa(curtime,temp,10);
strcat(servcode,temp);
//Create License file
CFolderPickerDialog dlgFolder;
CString foldpath;


if ( dlgFolder.DoModal() == IDOK )
foldpath = dlgFolder.GetFolderPath();

//foldpath = foldpath+"\AntechLicense.lic";
CT2A ascifp(foldpath+"\\AntechLicense.lic");
CT2A ascivd(valid);

	fptr = fopen(ascifp.m_psz,"w");
	if(fptr!=NULL)
	{
	  fprintf(fptr,"Antech Systems License Code\n------------------------------------------------------------------------------------\n");
	  
	  if(Days == TRUE)
	  fprintf(fptr,"Valid Days: %s\n",ascivd.m_psz);
	  else
		fprintf(fptr,"Valid Runs: %s\n",ascivd.m_psz);

	  fprintf(fptr,"Product: %s\n",pname);
	  fprintf(fptr,servcode);
 	  fclose(fptr);
	  MessageBox(_T("License File Succesfully Created!"));
	}
	else
		MessageBox(_T("No path selected!"));

}

}





void CPasswordGeneratorDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	Runs = TRUE;
	Days = FALSE;
}


void CPasswordGeneratorDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	Runs = FALSE;
	Days = TRUE;
}
