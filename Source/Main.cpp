#include "Engine/Core/Application.h"
#include <SDL3/SDL.h>

int main()
{
	Application app;

	if (!app.Initialize())
	{
		return -1;
	}

	app.Run();
	app.Shutdown();

	return 0;
}