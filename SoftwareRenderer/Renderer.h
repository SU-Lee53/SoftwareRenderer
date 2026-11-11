#pragma once
#include <Windows.h>
#include <array>

class Renderer {
public:
	Renderer(HDC hDC, LONG nBackBufferWidth, LONG nBackBufferHeight);

	Renderer(const Renderer&) = delete;
	Renderer(Renderer&&) = delete;

	Renderer operator=(const Renderer&) = delete;
	Renderer operator=(Renderer&&) = delete;

	~Renderer();

	void Render();
	void Present(HDC windowDC);

private:
	void ClearBackBuffer();

private:
	HDC m_hDC = NULL;
	std::array<HBITMAP, 2> m_hBitmaps;
	HGDIOBJ m_hOldBitmap = NULL;
	HBRUSH m_hBackgroundBrush = NULL;
	COLORREF m_BackgroundColor = RGB(255, 255, 255);
	RECT m_ScreenRect{};
	int m_nNextBitmapIndex = 0;

	LONG m_nBackBufferWidth = 0;
	LONG m_nBackBufferHeight = 0;
};

