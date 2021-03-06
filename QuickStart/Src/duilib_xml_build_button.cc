#include "UIlib.h"

#define ROOT_BUTTON _T("1QAZ-2WSX-3EDC-4RFV")

class DuiFrameWnd : public DuiLib::CWindowWnd, 
					public DuiLib::INotifyUI {
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DuiFrameWnd"); }

	virtual void Notify(DuiLib::TNotifyUI& msg) {
		if (msg.sType == DUI_MSGTYPE_CLICK) {
			if (msg.pSender->GetName() == ROOT_BUTTON) {
				::MessageBox(NULL, _T("click"), _T("button"), NULL);
			}
		}
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE) {
			paintMgr_.Init(m_hWnd);
			paintMgr_.AddNotifier(this);

			DuiLib::CDialogBuilder builder;
			DuiLib::CControlUI *root = builder.Create(_T("Button.xml"), 
													  (UINT)0, NULL, &paintMgr_);
			ASSERT(root != NULL);
			paintMgr_.AttachDialog(root);

			return lRes;
		} else if (uMsg == WM_NCACTIVATE) {
			if (!::IsIconic(m_hWnd))
				return (wParam == 0) ? TRUE : FALSE;
		} else if (uMsg == WM_NCCALCSIZE) {
			return 0;
		} else if (uMsg == WM_NCPAINT) {
			return 0;
		}

		if (paintMgr_.MessageHandler(uMsg, wParam, lParam, lRes))
			return lRes;

		return __super::HandleMessage(uMsg, wParam, lParam);
	}
protected:
	DuiLib::CPaintManagerUI paintMgr_;
};

int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR lpCmdLine,
					   int nCmdShow) {
	DuiLib::CPaintManagerUI::SetInstance(hInstance);
	DuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DuiWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.ShowModal();

	return 0;
}