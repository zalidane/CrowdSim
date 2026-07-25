#pragma once

#include "../Rendering/Window.h"

class Application
{
public:
	bool Initialize();

	void Run();

	void Shutdown();

private:
	Window m_window;
};
