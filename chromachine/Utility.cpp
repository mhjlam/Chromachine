#include <SDL.h>
#include "Utility.h"

void Utility::DestroyWindow(SDL_Window* window)
{
	SDL_DestroyWindow(window);
}

void Utility::DestroyRenderer(SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
}

void Utility::FreeSurface(SDL_Surface* surface)
{
	SDL_FreeSurface(surface);
}
