#pragma once

#include <vector>

#include "../Rendering/Window.h"
#include "../../Game/Agent.h"
#include "../Rendering/Renderer.h"

class Application
{
public:
	bool Initialize();
	void Update(float dt);
	void Render();

	void Run();

	void Shutdown();

private:
	Window m_window;
	Renderer m_renderer;

	std::vector<Agent> m_agents;
};
