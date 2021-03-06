#include "UIlib.h"

class DuiFrameWnd : public DuiLib::CWindowWnd, 
					public DuiLib::INotifyUI {
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DuiFrameWnd"); }

	virtual void Notify(DuiLib::TNotifyUI& msg) { }

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE) {
			DuiLib::CControlUI *pWnd = new DuiLib::CButtonUI;
			pWnd->SetName(_T("1QAZ-2WSX-3EDC-4RFV"));
			pWnd->SetText(_T("Hello World"));
			pWnd->SetBkColor(0xF3F3F3F3);

			paintMgr_.Init(m_hWnd);
			paintMgr_.AttachDialog(pWnd);

			return lRes;
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