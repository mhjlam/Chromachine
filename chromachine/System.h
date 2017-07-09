#pragma once

#include <memory>
#include <vector>

struct SDL_Window;
struct SDL_Renderer;
class Scene;

class System
{
private:
	SDL_Event lastEvent;

	std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
	std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer;

	std::shared_ptr<Scene> activeScene;
	std::vector<std::shared_ptr<Scene>> scenes;

public:
	System();
	~System();

	void Run();

private:
	void Update(double delta);
	void Render(double delta);
};
