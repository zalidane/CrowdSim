#include "Window.h"

#include <SDL3/SDL.h>

Window::Window() :m_window(nullptr)
{
}

Window::~Window()
{
	if (m_window)
	{
		SDL_DestroyWindow(m_window);
	}
}

bool Window::Create(
	const char* title, 
	int width, 
	int height)
{
	m_window = SDL_CreateWindow(
		title, 
		width, 
		height, 
		0);

	return m_window != nullptr;
}
