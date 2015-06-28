#include "stdafx.h"
#include "GlobalTimer.h"
#include "RenderEngine.h"
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

	switch (message){
	case WM_PAINT_START:
		*(bool*)wParam = true;
		_globalTimer->resetTimerDT();
		break;
	case WM_PAINT_END:
		*(bool*)wParam = false;
		break;
	case WM_CREATE:
		_globalTimer;
		_renderEngine->init(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
};