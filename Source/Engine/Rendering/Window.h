#pragma once

struct SDL_Window;

class Window
{
public:
	Window();
	~Window();

	bool Create(
		const char* title,
		int width,
		int height);

	SDL_Window* GetNativeWindow() const;

private:
	SDL_Window* m_window;
};

