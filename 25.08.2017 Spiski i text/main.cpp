#include <Windows.h>
#include "resource.h"

#define ID_EDIT 100

BOOL CALLBACK DlgProc(HWND hwnd, UINT iMsg, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	//return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
	HWND hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
	ShowWindow(hwnd, SW_NORMAL);
	UpdateWindow(hwnd);

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	static HWND hEdit;
	LONG style;
	static HWND hEdit1;
	static HWND hButtonDelLife;
	static HWND hDlg;
	static HWND hListBox;
	int index;

	switch (uMsg)
	{
	case WM_INITDIALOG:
		hDlg = hwnd;
	//	hDlg = GetDlgItem(hwnd, IDD_DIALOG1);
		hButtonDelLife = GetDlgItem(hwnd, IDOK);
		hEdit1 = GetDlgItem(hwnd, IDC_BUTTON1);
		hEdit = CreateWindowEx(NULL, L"EDIT", L"TYPA TEXT", WS_CHILD | WS_VISIBLE, 50, 50, 400, 20, hwnd, (HMENU)NULL, GetModuleHandle(NULL), NULL);

		hListBox = CreateWindowEx(NULL, L"LISTBOX", NULL, WS_CHILD | WS_VISIBLE | LBS_STANDARD, 20, 80, 130, 50, hwnd, (HMENU)NULL, GetModuleHandle(NULL), NULL);

		SendMessage(hListBox, LB_ADDSTRING, 0, LPARAM(L"YA TUT PERVIY"));
		SendMessage(hListBox, LB_ADDSTRING, 0, LPARAM(L"YA TUT VTOROY"));

		return true;
	case WM_COMMAND:
		//if (lParam == LPARAM(hButtonDelLife));
		if (LOWORD(wParam) == IDC_DELETE)
		{
			int len = SendMessage(hEdit, WM_GETTEXTLENGTH, 0, 0);
			SendMessage(hEdit, EM_SETSEL, 0, len + 1);
			SendMessage(hEdit, WM_CLEAR, 0, 0);
		}
		 if (LOWORD(wParam) == IDCANCEL)
		{
			SendMessage(hEdit, WM_CUT, 0, 0);
			SendMessage(hEdit1, WM_PASTE, 0, 0);
		}
		else if (LOWORD(wParam) == IDC_BUTTON3)
		{
			int len = SendMessage(hEdit, WM_GETTEXTLENGTH, 0, 0) + 1;
			wchar_t* buf = new wchar_t[len];
			//memset(buf, 0, sizeof(buf));
		//	GetWindowText(hEdit, buf, sizeof(buf));
			SendMessage(hEdit, EM_GETLINE, 0, LPARAM(buf));
			buf[len - 1] = L'\0';
			SetWindowText(hDlg, buf);
			SendMessage(hEdit1, WM_SETTEXT, 0, LPARAM(buf));
			delete[] buf;
		}
		else if (LOWORD(wParam) == IDC_BUTTON4)
		{
			wchar_t buf[30];

			GetWindowText(hEdit, buf, sizeof(buf));
			SendMessage(hListBox, LB_ADDSTRING, 0, LPARAM(buf));
			int count = SendMessage(hListBox, LB_GETCOUNT, 0, 0);
			wchar_t buf1[20];
			wsprintf(buf1, L"COUNT: %d", count);
			MessageBox(NULL, buf1, L"Size", MB_OK);
		}
		return true;
	case WM_RBUTTONDOWN:
			index = SendMessage(hListBox, LB_GETCURSEL, 0, 0);
			SendMessage(hListBox, LB_DELETESTRING, index, 0);
		return true;
	case WM_LBUTTONDOWN:
		style = GetWindowLong(hEdit, GWL_STYLE);
		//SetWindowLong(hEdit, GWL_STYLE, style | ES_NUMBER);
		return true;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		PostQuitMessage(0);
		return true;
	}
		return false;
}
