#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM LParam)
{

	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, iMsg, wParam, LParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	LPWSTR szClassName = L"MyindowClass";
	LPWSTR szTitleName = L"My first window";

	WNDCLASSEX magicWindow;

	memset(&magicWindow, 0, sizeof(magicWindow));

	magicWindow.cbSize = sizeof(magicWindow);
	magicWindow.lpszClassName = _TEXT("MyindowClass");
	magicWindow.style = CS_HREDRAW | CS_VREDRAW;
	magicWindow.lpfnWndProc = WndProc;
	magicWindow.hInstance = hInstance;
	magicWindow.hCursor = LoadCursor(NULL, IDC_SIZEALL);
	magicWindow.hIconSm = LoadIcon(NULL, IDI_QUESTION);
	magicWindow.hIcon = LoadIcon(NULL, IDI_QUESTION);

	magicWindow.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

	if (!RegisterClassEx(&magicWindow))
	{
		return 1;
	}

	HWND hWnd = CreateWindowEx(WS_EX_TOPMOST, L"MyindowClass", L"Hello Darling", WS_OVERLAPPEDWINDOW, 100, 40, 200, 300, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return false;

	}

	MessageBox(NULL, L"YVEREN?", L"HOCHESH VNYTR?", MB_YESNOCANCEL);

	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		//TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return msg.wParam;
}
