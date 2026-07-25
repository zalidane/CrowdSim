#include "Application.h"

#include <SDL3/SDL.h>
#include <random>
#include <chrono>

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

	if (!m_renderer.Create(m_window))
	{
		return false;
	}

	Agent agent;

	agent.x = 100.0f;
	agent.y = 100.0f;

	agent.vx = 50.0f;
	agent.vy = 250.0f;

	m_agents.push_back(agent);

	return true;
}

void Application::Update(float dt)
{
	constexpr float WindowWidth = 1280.0f;
	constexpr float WindowHeight = 720.0f;
	constexpr float AgentSize = 50.0f;

	for (Agent& agent : m_agents)
	{
		agent.x += agent.vx * dt;
		agent.y += agent.vy * dt;

		if (agent.x < 0)
		{
			agent.x = 0;
			agent.vx *= -1;
		}

		if (agent.x > WindowWidth - AgentSize)
		{
			agent.x = WindowWidth - AgentSize;
			agent.vx *= -1;
		}

		if (agent.y < 0)
		{
			agent.y = 0;
			agent.vy *= -1;
		}

		if (agent.y > WindowHeight - AgentSize)
		{
			agent.y = WindowHeight - AgentSize;
			agent.vy *= -1;
		}
	}
}

void Application::Render()
{
	m_renderer.BeginFrame();

	for (const Agent& agent : m_agents)
	{
		m_renderer.DrawRectangle(agent.x, agent.y, 50.0f, 50.0f);
	}

	m_renderer.EndFrame();
}

void Application::Run()
{
	bool running = true;

	auto previousTime = std::chrono::steady_clock::now();

	while (running)
	{
		auto currentTime = std::chrono::steady_clock::now();

		std::chrono::duration<float> delta = currentTime - previousTime;

		previousTime = currentTime;

		float dt = delta.count();

		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
			{
				running = false;
			}
		}

		Update(dt);
		Render();
	}
}

void Application::Shutdown()
{
	SDL_Quit();
}