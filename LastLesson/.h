#include <windows.h>
#include <windowsx.h>

class MyWindow
{
public:
	MyWindow();
	~MyWindow() = default;
	
	static BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
	void Cls_OnClose(HWND hWnd);
	BOOL Cls_OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify);
private:
	static MyWindow* ptr;
	HWND hDialog;
	HWND hButOK;
	HWND hButCancel;
};
