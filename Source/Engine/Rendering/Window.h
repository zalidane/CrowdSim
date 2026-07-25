#pragma once

struct SDL_Window;

class Window
{
public:
	bool Create();

	void Destroy();

private:
	SDL_Window* m_window = nullptr;
};

