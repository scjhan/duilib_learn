#include <windows.h>
#include <tchar.h>

#include "MainFrame.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, 
					   HINSTANCE prevInstance, 
					   LPTSTR lpCmdLine, 
					   int nCmdShow)
{
	DuiLib::CPaintManagerUI::SetInstance(hInstance);
	DuiLib::CPaintManagerUI::SetResourcePath(PATH_RESOURCE);

	MainFrame mainFrame;
	mainFrame.Create(NULL, _T("DuiWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	mainFrame.CenterWindow();
	mainFrame.ShowModal();

	return 0;
}