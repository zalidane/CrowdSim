#pragma once

struct SDL_Renderer;
class Window;

class Renderer
{
public:
	Renderer();
	~Renderer();

	bool Create(Window& window);

	void BeginFrame();
	void EndFrame();

	void DrawRectangle(
		float x,
		float y,
		float width,
		float height);

private:
	SDL_Renderer* m_renderer;
};
