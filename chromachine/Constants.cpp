#include <SDL.h>
#include "Constants.h"

const char*    Constants::WindowTitle  = "Chromachine";
const uint32_t Constants::WindowWidth  = 1280;
const uint32_t Constants::WindowHeight = 720;
const uint32_t Constants::WindowFlags  = SDL_WINDOW_OPENGL;
const uint32_t Constants::RenderFlags  = SDL_RENDERER_ACCELERATED;
const uint32_t Constants::TargetFPS    = 60;
const uint32_t Constants::TargetTicks  = 1000 / Constants::TargetFPS;
