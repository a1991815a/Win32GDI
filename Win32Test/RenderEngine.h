#ifndef __RENDERENGINE__
#define __RENDERENGINE__
#include "stdafx.h"
#include "SingleInstance.h"

#define _renderEngine RenderEngine::getInstance()

class RenderEngine: public SingleInstance<RenderEngine>{
	friend class SingleInstance<RenderEngine>;
	RenderEngine();
	~RenderEngine();
public:
	void init(HWND hWnd);
	void render() const;
	void drawAll() const;
	void clear() const;

private:
	HWND g_hWnd;
	HDC g_hdc;
	HDC m_hDisplayDc;
	HDC m_hImageBuf;
	HBITMAP m_bindImage;
	HBITMAP m_hImage;
	RECT g_clientRect;
	int width, height;
	HBRUSH bk_brush;
};
#endif