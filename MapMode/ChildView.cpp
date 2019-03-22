
// ChildView.cpp: CChildView 类的实现
//

#include "stdafx.h"
#include "MapMode.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView 消息处理程序

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

/*
SetWindowOrg(x, y) 是把设备坐标的原点(视口)映射到逻辑坐标的(X, Y)处
SetViewportOrg(x, y) 是把逻辑坐标的原点(窗口)映射到设备坐标的(X, Y)处

坐标方向的确定方法:
X轴 --- 如果逻辑窗范围和视口范围符号相同，则逻辑坐标的方向和视口的方向相同，即X轴向右为正，否则向左为正。
Y轴 --- 如果逻辑窗范围和视口范围符号相同，则逻辑坐标的方向和视口的方向相同，即Y轴向下为正，否则向上为正。
*/

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 用于绘制的设备上下文

	CRect rc;
	GetClientRect(&rc);

	//dc.SetMapMode(MM_LOMETRIC);
	//dc.SetWindowOrg(100, 100);
	//dc.Rectangle(0, 0, 200, 200);
	//dc.MoveTo(0, 200);
	//dc.LineTo(200, 0);
	//dc.MoveTo(100, 0);
	//dc.LineTo(200, 100);

	//dc.SetViewportOrg(200, 200);
	//dc.SelectStockObject(GRAY_BRUSH);
	//dc.Rectangle(0, 0, 200, 200);

	dc.SetMapMode(MM_ANISOTROPIC);
	dc.SetViewportOrg(rc.Width() / 2, rc.Height() / 2);
	dc.SetViewportExt(-rc.Width(), -rc.Height());

	dc.SetWindowExt(1000, 1000);

	dc.MoveTo(0, 0);
	dc.LineTo(1000, 1000);
}