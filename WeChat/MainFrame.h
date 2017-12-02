#ifndef WECHAT_MAIN_FRAME_H_
#define WECHAT_MAIN_FRAME_H_

#include "UIlib.h"
#include "resdef.h"

class MainFrame : public DuiLib::WindowImplBase {
public:
	virtual DuiLib::CDuiString GetSkinFolder() { return PATH_RESOURCE; }
	virtual DuiLib::CDuiString GetSkinFile() { return XML_MAIN_FRAME; }
	virtual LPCTSTR GetWindowClassName(void) const { return _T("WeChat"); }

	virtual LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
		bSendHot_ = false;

		return __super::OnCreate(uMsg, wParam, lParam, bHandled);
	}

	virtual void OnClick(DuiLib::TNotifyUI& msg) {
		if (msg.pSender->GetName() == BUTTON_CLOSE) {
			Close();
		}
		if (msg.pSender->GetName() == BUTTON_TOOL) {
			m_PaintManager.FindControl(TABEL_CHATER)->SetText("Hello World");
		}
	}

	LRESULT OnMouseMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
		POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
		DuiLib::CControlUI* pMove = m_PaintManager.FindControl(pt);
		if (pMove == NULL) return 0;
		if (pMove->GetName() == BUTTON_SEND) {
			pMove->SetBkColor(WECHAT_GREEN);
			((DuiLib::CButtonUI*)pMove)->SetTextColor(WECHAT_WHITE);
			bSendHot_ = true;
		} else if (bSendHot_) {
			DuiLib::CButtonUI *pSendBtn = (DuiLib::CButtonUI*)m_PaintManager.FindControl(BUTTON_SEND);
			pSendBtn->SetBkColor(WECHAT_WHITE);
			pSendBtn->SetTextColor(WECHAT_GRAY);
		}

		return __super::OnMouseMove(uMsg, wParam, lParam, bHandled);
	}
private:
	bool bSendHot_;
};

#endif //WECHAT_MAIN_FRAME_H_