#include "Core.h"
#include "Renderer.h"

#include <memory>

Core::Core(HWND hWnd, LONG nWidth, LONG nHeight)
	: m_hWnd{ hWnd }
{
	HDC hDC = ::GetDC(hWnd);
	m_pRenderer = std::make_unique<Renderer>(hDC, nWidth, nHeight);
}

Core::~Core()
{
}

void Core::Update()
{

}

void Core::Render()
{
	m_pRenderer->Render();
}

void Core::Present()
{
	HDC windowDC = GetDC(m_hWnd);
	m_pRenderer->Present(windowDC);
	ReleaseDC(m_hWnd, windowDC);
}