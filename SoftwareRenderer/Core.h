#pragma once
#include <memory>
#include <Windows.h>

class Renderer;

class Core {
public:
	Core(HWND hWnd, LONG nWidth, LONG nHeight);
	~Core();
	
	void Update();
	void Render();
	void Present();

private:
	HWND m_hWnd;
	std::unique_ptr<Renderer> m_pRenderer;

};

