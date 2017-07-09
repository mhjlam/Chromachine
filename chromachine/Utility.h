#pragma once

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;

namespace Utility
{
	void DestroyWindow(SDL_Window* window);
	void DestroyRenderer(SDL_Renderer* renderer);
	void FreeSurface(SDL_Surface* surface);
}
