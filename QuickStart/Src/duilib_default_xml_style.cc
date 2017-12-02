#include "UIlib.h"

// Resource define
#define RESOURCE_PATH	_T("res")
#define ROOT_BUTTON_XML _T("Button.xml")
#define TITLEBAR_XML	_T("TitleBar.xml")
#define BUTTON_STYLE_XML _T("DefaultButtonStyle.xml")

// ID define
#define ROOT_BUTTON_ID		_T("1QAZ-2WSX-3EDC-4BON")
#define TITLEBAR_MIN_ID		_T("1QAZ-2WSX-3EDC-4MIN")
#define TITLEBAR_MAX_ID		_T("1QAZ-2WSX-3EDC-4MAX")
#define TITLEBAR_RESTORE_ID	_T("1QAZ-2WSX-3EDC-4RST")
#define TITLEBAR_CLOSE_ID	_T("1QAZ-2WSX-3EDC-4CLO")
#define STYLE_BUTTON_0001	_T("1QAZ-2WSX-3EDC-4BTN-0001")
#define STYLE_BUTTON_0002	_T("1QAZ-2WSX-3EDC-4BTN-0002")
#define STYLE_BUTTON_0003	_T("1QAZ-2WSX-3EDC-4BTN-0003")

class DuiFrame : public DuiLib::WindowImplBase {
public:
	virtual DuiLib::CDuiString GetSkinFolder() { return RESOURCE_PATH; }
	virtual DuiLib::CDuiString GetSkinFile() { return BUTTON_STYLE_XML; }
	virtual LPCTSTR GetWindowClassName(void) const { return ROOT_BUTTON_ID; }

	virtual void OnClick(DuiLib::TNotifyUI& msg) {
		if (msg.pSender->GetName() == ROOT_BUTTON_ID) {
			::MessageBox(NULL, _T("click"), _T("button"), NULL);
		}
		if (msg.pSender->GetName() == TITLEBAR_MIN_ID) {
			
		}
		if (msg.pSender->GetName() == TITLEBAR_MAX_ID) {
			m_PaintManager.FindControl(TITLEBAR_MAX_ID)->SetVisible(false);
			m_PaintManager.FindControl(TITLEBAR_RESTORE_ID)->SetVisible(true);
		}
		if (msg.pSender->GetName() == TITLEBAR_RESTORE_ID) {
			m_PaintManager.FindControl(TITLEBAR_RESTORE_ID)->SetVisible(false);
			m_PaintManager.FindControl(TITLEBAR_MAX_ID)->SetVisible(true);
		}
		if (msg.pSender->GetName() == TITLEBAR_CLOSE_ID) {
			Close();
		}
	}
};

int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR lpCmdLine,
					   int nCmdShow) {
	DuiLib::CPaintManagerUI::SetInstance(hInstance);
	DuiLib::CPaintManagerUI::SetResourcePath(RESOURCE_PATH);

	DuiFrame duiFrame;
	duiFrame.Create(NULL, _T("DuiWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();
	duiFrame.ShowModal();

	return 0;
}