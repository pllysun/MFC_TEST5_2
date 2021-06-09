
// MFCApplication4Dlg.h: 头文件
//

#pragma once


// CMFCApplication4Dlg 对话框
class CMFCApplication4Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication4Dlg(CWnd* pParent = nullptr);	// 标准构造函数
//	CMFCApplication4Dlg::CMFCApplication4Dlg(CWnd* pParent): CDialogEx(IDD_MFCAPPLICATION4_DIALOG, pParent), m_nRValue(0)
//{
//		m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
//		m_bOK = FALSE;
//}

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChangeEditX();
	afx_msg void OnNMCustomdrawSliderB(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMThemeChangedScrollbarG(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpinR(NMHDR* pNMHDR, LRESULT* pResult);
//	CComboBox m_cbHatch;
	UINT m_nRValue;
	CSpinButtonCtrl m_spinRValue;
	CScrollBar m_sbGValue;
	CSliderCtrl m_sdBValue;
	CComboBox m_cbHatch;
	UINT m_nGValue;
	UINT m_nBValue;
	UINT m_nHatch;
	void DrawHatch();
	afx_msg void OnSelchangeComboHatch();
	BOOL m_bOK;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
