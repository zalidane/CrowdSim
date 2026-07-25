#include "Application.h"

#include <SDL3/SDL.h>
#include <iostream>

bool Application::Initialize()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		return false;
	}

	if (!m_window.Create(
		"CrowdSim",
		1280,
		720))
	{
		return false;
	}

	std::cout << "Application initialized.\n";
	
	return true;
}

void Application::Run()
{
	bool running = true;

	while (running)
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
			{
				running = false;
			}
		}
	}
}

void Application::Shutdown()
{
	SDL_Quit();
}