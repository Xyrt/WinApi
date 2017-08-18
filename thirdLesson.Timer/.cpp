#include <windows.h>
#include <tchar.h>
#include <cstdlib>
#include <ctime>
#include "resource.h"

#define MY_VALUE 412

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wnd;
	
	memset(&wnd, 0, sizeof(wnd));

	wnd.cbSize = sizeof(wnd);

	wnd.lpfnWndProc = WndProc;
	wnd.hInstance = hInstance;
	wnd.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wnd.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(103));
	wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wnd.lpszMenuName = NULL;
	wnd.lpszClassName = _TEXT("Window");
	wnd.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	if (!RegisterClassEx(&wnd)) {
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}

	hWnd = CreateWindowEx(WS_EX_WINDOWEDGE, _TEXT("Window"), _TEXT("Hello"), WS_OVERLAPPEDWINDOW ^ (WS_MAXIMIZEBOX | WS_MINIMIZEBOX),
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		HWND_DESKTOP, NULL, hInstance, NULL);

	if (!hWnd) {
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}

	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.lParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	srand(time(NULL));
	int x;
	int y;

	switch (uMessage)
	{
	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		MoveWindow(hWnd, x, y, 300, 300, true);
		SendMessage(hWnd, WM_CLOSE, 0, 0);
		break;
	case WM_CREATE:
		SetTimer(hWnd, MY_VALUE, 1000, NULL);
		break;
	case WM_TIMER:
		SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256)));
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_CLOSE:
		if (MessageBox(hWnd, _TEXT("Вы действительно хотите завершить работу приложения?"), _TEXT("Информация"), MB_YESNO) == IDYES) {
			DestroyWindow(hWnd);
			break;
		}
	case WM_DESTROY:
		KillTimer(hWnd, MY_VALUE);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}
