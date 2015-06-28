#include "stdafx.h"
#include "GlobalTimer.h"
#include "RenderEngine.h"

extern LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void InitWnd(HINSTANCE hInstance, HWND* hWnd);

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, 
	_In_ int nShowCmd)
{
	HWND hWnd = NULL;
	InitWnd(hInstance, &hWnd);
	MSG msg = { 0 };
	bool shouldPaint = true;
	int frame_time = 1000 / 60;
	while (msg.message != WM_QUIT){
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else if(shouldPaint){
			_renderEngine->render();

			PostMessage(hWnd, WM_PAINT_END, (WPARAM)(&shouldPaint), NULL);
		}
		_globalTimer->refresh();
		if (_globalTimer->getTimerDT() > frame_time)
			PostMessage(hWnd, WM_PAINT_START, (WPARAM)(&shouldPaint), NULL);
	}
	return msg.wParam;
}

void InitWnd(HINSTANCE hInstance, HWND* hWnd){
	WNDCLASSEX wnd_class;
	wnd_class.cbClsExtra = NULL;
	wnd_class.cbWndExtra = NULL;
	wnd_class.cbSize = sizeof(wnd_class);
	wnd_class.hbrBackground = NULL;
	wnd_class.hCursor = NULL;
	wnd_class.hIcon = NULL;
	wnd_class.hIconSm = NULL;
	wnd_class.hInstance = hInstance;
	wnd_class.lpfnWndProc = WndProc;
	wnd_class.lpszClassName = _T("WndClass");
	wnd_class.lpszMenuName = NULL;
	wnd_class.style = CS_VREDRAW | CS_HREDRAW;
	RegisterClassEx(&wnd_class);
	*hWnd = CreateWindowEx(
		WS_EX_ACCEPTFILES,
		_T("WndClass"),
		_T("ÎÒµÄ²âÊÔ´°¿Ú"),
		WS_OVERLAPPEDWINDOW ^ WS_MAXIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 600,
		NULL,
		NULL,
		hInstance,
		NULL
		);
	ShowWindow(*hWnd, SW_SHOWNORMAL);
	UpdateWindow(*hWnd);
};
