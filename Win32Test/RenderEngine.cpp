#include "RenderEngine.h"

extern void DrawMain();

RenderEngine::RenderEngine()
	:g_hWnd(NULL), g_hdc(NULL), m_hDisplayDc(NULL),m_bindImage(NULL),
	m_hImageBuf(NULL), m_hImage(NULL),
	width(0), height(0),
	bk_brush(CreateSolidBrush(RGB(0, 0, 0)))
{
	memset(&g_clientRect, 0, sizeof(g_clientRect));
}

RenderEngine::~RenderEngine()
{
	SAFE_DELETE_OBJ(m_hDisplayDc);
	SAFE_DELETE_OBJ(m_hImageBuf);
	SAFE_DELETE_OBJ(m_bindImage);
	SAFE_DELETE_OBJ(m_hImage);
	if (g_hdc != NULL)
		ReleaseDC(g_hWnd, g_hdc);
}

void RenderEngine::init(HWND hWnd)
{
	g_hWnd = hWnd;
	GetClientRect(hWnd, &g_clientRect);
	g_hdc = GetDC(hWnd);
	m_hDisplayDc = CreateCompatibleDC(g_hdc);
	m_hImageBuf = CreateCompatibleDC(g_hdc);
	m_bindImage = CreateCompatibleBitmap(m_hDisplayDc, 0, 0);
	SelectObject(m_hDisplayDc, m_bindImage);
	width = g_clientRect.right - g_clientRect.left;
	height = g_clientRect.bottom - g_clientRect.top;
}

void RenderEngine::render() const
{
	clear();
	drawAll();
	BitBlt(g_hdc, 0, 0, width, height, m_hDisplayDc, 0, 0, SRCCOPY);
}

void RenderEngine::drawAll() const
{
	DrawMain();
}

void RenderEngine::clear() const
{
	FillRect(m_hDisplayDc, &g_clientRect, bk_brush);
}
