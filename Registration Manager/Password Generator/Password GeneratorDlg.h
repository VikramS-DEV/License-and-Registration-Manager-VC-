
// Password GeneratorDlg.h : header file
//

#pragma once


// CPasswordGeneratorDlg dialog
class CPasswordGeneratorDlg : public CDialog
{
// Construction
public:
	CPasswordGeneratorDlg(CWnd* pParent = NULL);	// standard constructor
	private:
   CBitmap m_bmpEarth;
// Dialog Data
	enum { IDD = IDD_PASSWORDGENERATOR_DIALOG };
	CString licPath,Pcode,Pver,valid;
	BOOL Runs,Days;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBrowse();
	afx_msg void OnBnClickedGenerate();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
};
