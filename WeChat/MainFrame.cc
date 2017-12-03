#include "MainFrame.h"

DuiLib::CDuiString MainFrame::GetSkinFolder() {
	return PATH_RESOURCE;
}

DuiLib::CDuiString MainFrame::GetSkinFile() {
	return XML_MAIN_FRAME;
}

LPCTSTR MainFrame::GetWindowClassName(void) const {
	return _T("WeChat");
}

LRESULT MainFrame::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
	bSendHot_ = false;
	bWndTop_ = false;
	return __super::OnCreate(uMsg, wParam, lParam, bHandled);
}

void MainFrame::OnClick(DuiLib::TNotifyUI& msg) {
	if (msg.pSender->GetName() == BUTTON_CLOSE) {
		Close();
	}
	if (msg.pSender->GetName() == BUTTON_MIN) {
		SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
	}
	if (msg.pSender->GetName() == BUTTON_MAX) {
		SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);
		m_PaintManager.FindControl(BUTTON_MAX)->SetVisible(false);
		m_PaintManager.FindControl(BUTTON_RESTORE)->SetVisible(true);
	}
	if (msg.pSender->GetName() == BUTTON_RESTORE) {
		SendMessage(WM_SYSCOMMAND, SC_RESTORE, 0);
		m_PaintManager.FindControl(BUTTON_RESTORE)->SetVisible(false);
		m_PaintManager.FindControl(BUTTON_MAX)->SetVisible(true);
	}
	if (msg.pSender->GetName() == BUTTON_DING) {
		if (!bWndTop_) {
			bWndTop_ = true;
			SetWindowPos(this->m_hWnd, HWND_TOPMOST, 
						 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		} else {
			bWndTop_ = false;
			SetWindowPos(this->m_hWnd, HWND_NOTOPMOST, 
						 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}			
	}
}

LRESULT MainFrame::OnMouseMove(UINT uMsg, WPARAM wParam, 
							   LPARAM lParam, BOOL& bHandled) {
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