#include "UIlib.h"

#define RESOURCE_PATH	_T("res")
#define ROOT_BUTTON_XML _T("Button.xml")
#define ROOT_BUTTON_ID	_T("1QAZ-2WSX-3EDC-4RFV")

class DuiFrame : public DuiLib::WindowImplBase {
public:
	virtual DuiLib::CDuiString GetSkinFolder() { return RESOURCE_PATH; }
	virtual DuiLib::CDuiString GetSkinFile() { return ROOT_BUTTON_XML; }
	virtual LPCTSTR GetWindowClassName(void) const { return ROOT_BUTTON_ID; }
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