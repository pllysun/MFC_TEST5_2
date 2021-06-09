
// MFCApplication4Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication4.h"
#include "MFCApplication4Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication4Dlg 对话框



CMFCApplication4Dlg::CMFCApplication4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION4_DIALOG, pParent)
	, m_nRValue(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bOK = FALSE;
}

void CMFCApplication4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_COMBO_HATCH, m_cbHatch);
	DDX_Text(pDX, IDC_EDIT_X, m_nRValue);
	DDV_MinMaxUInt(pDX, m_nRValue, 0, 255);
	DDX_Control(pDX, IDC_SPIN2_X, m_spinRValue);
	DDX_Control(pDX, IDC_SCROLLBAR_G, m_sbGValue);
	DDX_Control(pDX, IDC_SLIDER_B, m_sdBValue);
	DDX_Control(pDX, IDC_COMBO_HATCH, m_cbHatch);
}

BEGIN_MESSAGE_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_X, &CMFCApplication4Dlg::OnChangeEditX)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_B, &CMFCApplication4Dlg::OnNMCustomdrawSliderB)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR_G, &CMFCApplication4Dlg::OnNMThemeChangedScrollbarG)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2_X, &CMFCApplication4Dlg::OnDeltaposSpinR)
	ON_CBN_SELCHANGE(IDC_COMBO_HATCH, &CMFCApplication4Dlg::OnSelchangeComboHatch)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CMFCApplication4Dlg 消息处理程序

BOOL CMFCApplication4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 填充并设定图案组合框选项
	int nIndex;
	nIndex = m_cbHatch.AddString(L"向上45度斜线");
	m_cbHatch.SetItemData(nIndex, HS_BDIAGONAL);
	nIndex = m_cbHatch.AddString(L"交叉十字线");
	m_cbHatch.SetItemData(nIndex, HS_CROSS);
	nIndex = m_cbHatch.AddString(L"斜十字交叉线");
	m_cbHatch.SetItemData(nIndex, HS_DIAGCROSS);
	nIndex = m_cbHatch.AddString(L"向下45度斜线");
	m_cbHatch.SetItemData(nIndex, HS_FDIAGONAL);
	nIndex = m_cbHatch.AddString(L"水平线");
	m_cbHatch.SetItemData(nIndex, HS_HORIZONTAL);
	nIndex = m_cbHatch.AddString(L"垂直线");
	m_cbHatch.SetItemData(nIndex, HS_VERTICAL);
	m_cbHatch.SetCurSel(0);
	m_nHatch = m_cbHatch.GetItemData(0);
	// 设置上下转换按钮范围和当前值
	m_spinRValue.SetRange(0, 255);
	m_nRValue = 0;
	m_spinRValue.SetPos(m_nRValue);
	// 设置滚动条范围和当前值
	m_sbGValue.SetScrollRange(0, 255);
	m_nGValue = 0;
	m_sbGValue.SetScrollPos(m_nGValue);
	// 设置滑动条范围和当前值
	m_sdBValue.SetRange(0, 255);
	m_nBValue = 0;
	m_sdBValue.SetPos(m_nBValue);
	return TRUE; // return TRUE unless you set the focus to a control
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_bOK = TRUE;
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
		DrawHatch();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication4Dlg::OnChangeEditX()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if (m_bOK)
	{
		UpdateData();
		DrawHatch();
	}
}


void CMFCApplication4Dlg::OnNMCustomdrawSliderB(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMFCApplication4Dlg::OnNMThemeChangedScrollbarG(NMHDR* pNMHDR, LRESULT* pResult)
{
	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMFCApplication4Dlg::OnDeltaposSpinR(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMFCApplication4Dlg::DrawHatch()
{
	// TODO: 在此处添加实现代码.
	CWnd* pWnd = GetDlgItem(IDC_STATIC_DRAW);
	pWnd->UpdateWindow();
	CDC* pDC = pWnd->GetDC(); // 获得窗口当前的设备环境指针
	CBrush drawBrush; // 定义画刷变量
	drawBrush.CreateHatchBrush(m_nHatch, RGB(m_nRValue, m_nGValue, m_nBValue));
	// 创建一个图案画刷。RGB是一个颜色宏，用来将指定的红、绿、蓝三种
	// 颜色分量转换成一个32位的RGB颜色值
	CBrush* pOldBrush = pDC->SelectObject(&drawBrush);
	CRect rcClient;
	pWnd->GetClientRect(rcClient); // 获取当前控件的客房区大小
	pDC->Rectangle(rcClient); // 用当前画刷填充指定的矩形框
	pDC->SelectObject(pOldBrush); // 恢复原来的画刷
}


void CMFCApplication4Dlg::OnSelchangeComboHatch()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = m_cbHatch.GetCurSel();
	if (nIndex != CB_ERR)
	{
		m_nHatch = m_cbHatch.GetItemData(nIndex);
		DrawHatch();
	}
}


void CMFCApplication4Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int nID = pScrollBar->GetDlgCtrlID();
	if (nID == IDC_SLIDER_B)
	{ // 若是滑动条产生水平滚动消息
		m_nBValue = m_sdBValue.GetPos(); // 则获得滑动条当前的位置
		DrawHatch();
	}
	if (nID == IDC_SCROLLBAR_G) { // 若是滚动条条产生水平滚动消息
		switch (nSBCode)
		{
		case SB_LINELEFT: m_nGValue--; // 单击滚动条左边箭头
			break;
		case SB_LINERIGHT: m_nGValue++; // 单击滚动条右边箭头
			break;
		case SB_PAGELEFT: m_nGValue -= 10;
			break;
		case SB_PAGERIGHT: m_nGValue += 10;
			break;
		case SB_THUMBTRACK: m_nGValue = nPos;
			break;
		}
		if (m_nGValue < 0) m_nGValue = 0;
		if (m_nGValue > 255) m_nGValue = 255;
		m_sbGValue.SetScrollPos(m_nGValue);
		DrawHatch();
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
