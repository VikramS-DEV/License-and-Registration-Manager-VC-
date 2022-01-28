
// License ManagerDlg.h : header file
//

#pragma once

class CLicenseManagerDlgAutoProxy;


// CLicenseManagerDlg dialog
class CLicenseManagerDlg : public CDialog
{
	DECLARE_DYNAMIC(CLicenseManagerDlg);
	friend class CLicenseManagerDlgAutoProxy;
// Construction
public:
	CLicenseManagerDlg(CWnd* pParent = NULL);	// standard constructor
	
	virtual ~CLicenseManagerDlg();

// Dialog Data
	CString servercode;
	CString company;
	CString Cname;
	CString emailid;
	CString phoneno;
	CString address;
	CString city;
	CString state;
	CString zipcode;
	CString country;
	CString nouser;
	CString Product;
	CString licPath;
	CString regpath;
	private:
   CBitmap m_bmpEarth;
	enum { IDD = IDD_LICENSEMANAGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	CLicenseManagerDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	void GetMACaddress(void);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRelicbutton();
	afx_msg void OnBnClickedBrowse();
	afx_msg void OnBnClickedRegbutton();
};
