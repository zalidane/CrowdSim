#include "Window.h"

#include <SDL3/SDL.h>

bool Window::Create()
{
	m_window = SDL_CreateWindow(
		"CrowdSim",
		1280,
		720,
		0);

	return m_window != nullptr;
}

void Window::Destroy()
{
	SDL_DestroyWindow(m_window);
	m_window = nullptr;
}
