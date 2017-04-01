#include <SDL.h>
#include <cmath>
#include <cstdio>

#define TARGET_FPS 60
#define TARGET_TICKS 1000 / TARGET_FPS


int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Event e;
	bool quit = false;

	SDL_Window* window = SDL_CreateWindow("Chromachine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

	int i = 0;
	int r = 0;
	int g = 0;
	int b = 0;

	while (!quit)
	{
		Uint32 ticks_start = SDL_GetTicks();

		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT:
				quit = true;
				break;

			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					quit = true;
					break;
				}
				break;
			}
		}

		r = sin(0.01*i + 0) * 127 + 128;
		g = sin(0.01*i + 2) * 127 + 128;
		b = sin(0.01*i + 4) * 127 + 128;

		SDL_SetRenderDrawColor(renderer, r, g, b, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);

		Uint32 ticks_delta = SDL_GetTicks() - ticks_start;

		if (ticks_delta < TARGET_TICKS)
		{
			SDL_Delay(TARGET_TICKS - ticks_delta);
		}

		i++ % 32;
	}

	SDL_Quit();

	return 0;
}
