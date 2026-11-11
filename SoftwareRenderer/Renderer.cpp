#include "Renderer.h"

Renderer::Renderer(HDC hDC, LONG nBackBufferWidth, LONG nBackBufferHeight)
	: m_nBackBufferWidth{ nBackBufferWidth }, m_nBackBufferHeight{ nBackBufferHeight }
{
	m_hDC = ::CreateCompatibleDC(hDC);
	for (auto& hBitmap : m_hBitmaps) {
		hBitmap = ::CreateCompatibleBitmap(hDC, m_nBackBufferWidth, m_nBackBufferHeight);
	}

	m_hBackgroundBrush = ::CreateSolidBrush(m_BackgroundColor);
	m_ScreenRect = RECT{
		.left = 0,
		.top = 0,
		.right = m_nBackBufferWidth,
		.bottom = m_nBackBufferHeight
	};
}

Renderer::~Renderer()
{
	::SelectObject(m_hDC, m_hOldBitmap);

	for (auto& hBitmap : m_hBitmaps) {
		::DeleteObject(hBitmap);
	}
}

void Renderer::Render()
{
	ClearBackBuffer();
}

void Renderer::Present(HDC windowDC)
{
	::BitBlt(
		windowDC,
		0,
		0,
		m_nBackBufferWidth,
		m_nBackBufferHeight,
		m_hDC,
		0,
		0,
		SRCCOPY
	);

	m_nNextBitmapIndex = (m_nNextBitmapIndex + 1) % 2;
}

void Renderer::ClearBackBuffer()
{
	HGDIOBJ hOldBitmap = ::SelectObject(m_hDC, m_hBitmaps[m_nNextBitmapIndex]);
	::FillRect(m_hDC, &m_ScreenRect, m_hBackgroundBrush);
}