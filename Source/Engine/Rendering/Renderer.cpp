#include "Renderer.h"
#include "Window.h"

#include <SDL3/SDL.h>

Renderer::Renderer() : m_renderer(nullptr)
{
}

Renderer::~Renderer()
{
	if (m_renderer)
	{
		SDL_DestroyRenderer(m_renderer);
	}
}

bool Renderer::Create(Window& window)
{
	m_renderer = SDL_CreateRenderer(window.GetNativeWindow(), nullptr);
	
	return m_renderer != nullptr;
}

void Renderer::BeginFrame()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	
	SDL_RenderClear(m_renderer);
}

void Renderer::EndFrame()
{
	SDL_RenderPresent(m_renderer);
}

void Renderer::DrawRectangle(
	float x,
	float y,
	float width,
	float height)
{
	// verified rectangle is drawing

	SDL_SetRenderDrawColor(
		m_renderer, 255, 255, 255, 255);

	SDL_FRect rect{
		x, y, width, height
	};

	SDL_RenderFillRect(m_renderer, &rect);
}