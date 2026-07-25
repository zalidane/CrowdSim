#include "Application.h"

#include <iostream>
#include <SDL3/SDL_events.h>

bool Application::Initialize()
{
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
	std::cout << "Application shutting down.\n";
}