#include "MyWindow.h"

MyWindow* MyWindow::ptr = NULL;

MyWindow::MyWindow()
{
	ptr = this;
}

BOOL CALLBACK  MyWindow::DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		HANDLE_MSG(hWnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, ptr->Cls_OnCommand);
		HANDLE_MSG(hWnd, WM_CLOSE, ptr->Cls_OnClose);
	}
	return false;
}

void MyWindow::Cls_OnClose(HWND hWnd)
{
	DestroyWindow(hWnd);
	PostQuitMessage(0);
}

BOOL MyWindow::Cls_OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam)
{
	hDialog = hWnd;
	hButOK = GetDlgItem(hWnd, IDOK);
	hButCancel = GetDlgItem(hWnd, IDCANCEL);
	return true;
}

void MyWindow::Cls_OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch (id)
	{
	case IDOK:
		{
			MessageBox(hWnd, L"OK", L"WM_COMMAD", MB_OK);
			break;
		}

	case IDCANCEL:
		{
			MessageBox(hWnd, L"CANCEL", L"WM_COMMAD", MB_OK);
			break;
		}
	default:
		break;
	}
}
