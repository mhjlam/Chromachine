#include <SDL.h>
#include <string>
#include "System.h"
#include "Constants.h"
#include "Utility.h"


System::System() : window(nullptr, SDL_DestroyWindow), renderer(nullptr, SDL_DestroyRenderer) // must provide deleter at object initialization (before constructor)
{
	// Initialize SDL system
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::string msg = "Initialization error: " + std::string(SDL_GetError());
		throw std::exception(msg.c_str());
	}

	// Initialize SDL window
	window = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>(SDL_CreateWindow(
		Constants::WindowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Constants::WindowWidth, Constants::WindowHeight, Constants::WindowFlags), SDL_DestroyWindow);
	//std::shared_ptr<SDL_Window> w = std::make_shared<SDL_Window>(SDL_CreateWindow(
	//	Constants::WindowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Constants::WindowWidth, Constants::WindowHeight, Constants::WindowFlags), [](SDL_Window* w) { SDL_DestroyWindow(w); });

	if (!window)
	{
		std::string errmsg = "Initialization error: " + std::string(SDL_GetError());
		throw std::exception(errmsg.c_str());
	}

	// Initialize SDL renderer
	renderer = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>(SDL_CreateRenderer(window.get(), -1, Constants::RenderFlags), SDL_DestroyRenderer);
	//std::shared_ptr<SDL_Renderer> r = std::make_shared<SDL_Renderer>(SDL_CreateRenderer(window.get(), 0, Constants::RenderFlags), [](SDL_Renderer* r) { SDL_DestroyRenderer(r); });

	if (!renderer)
	{
		std::string errmsg = "Initialization error: " + std::string(SDL_GetError());
		throw std::exception(errmsg.c_str());
	}

	// Load scenes
	

	if (scenes.size() > 0)
	{
		activeScene = scenes.front();
	}
}


System::~System()
{
	renderer.reset();
	window.reset();
	SDL_Quit();
}


void System::Run()
{
	int i = 0;
	bool running = true;
	double time = SDL_GetTicks() / 1000.0;

	while (running)
	{
		while (SDL_PollEvent(&lastEvent))
		{
			switch (lastEvent.type)
			{
				case SDL_QUIT:
				{
					running = false;
					break;
				}

				case SDL_KEYDOWN:
				{
					switch (lastEvent.key.keysym.sym)
					{
						case SDLK_ESCAPE:
						{
							running = false;
							break;
						}
					}

					break;
				}
			}
		}

		double delta = (SDL_GetTicks() / 1000.0) - time;
		double time = SDL_GetTicks() / 1000.0;

		Update(delta);
		Render(delta);
	}
}


void System::Update(double delta)
{
	int i = static_cast<int>(delta) * 100;

	uint8_t r = static_cast<uint8_t>(sin(0.01 * i + 0) * 127 + 128);
	uint8_t g = static_cast<uint8_t>(sin(0.01 * i + 2) * 127 + 128);
	uint8_t b = static_cast<uint8_t>(sin(0.01 * i + 4) * 127 + 128);

	SDL_SetRenderDrawColor(renderer.get(), r, g, b, 255);
}


void System::Render(double delta)
{
	SDL_RenderClear(renderer.get());
	SDL_RenderPresent(renderer.get());
}
