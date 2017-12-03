#ifndef WECHAT_MAIN_FRAME_H_
#define WECHAT_MAIN_FRAME_H_

#include "UIlib.h"
#include "resdef.h"

class MainFrame : public DuiLib::WindowImplBase {
public:
	virtual DuiLib::CDuiString GetSkinFolder();
	virtual DuiLib::CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName(void) const;

	virtual LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual void OnClick(DuiLib::TNotifyUI& msg);
	virtual LRESULT OnMouseMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
private:
	bool bSendHot_;
	bool bWndTop_;
};

#endif //WECHAT_MAIN_FRAME_H_