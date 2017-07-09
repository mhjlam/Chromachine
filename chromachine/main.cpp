#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include <SDL.h>
#include "System.h"
#include "Constants.h"

int main(int argc, char* argv[])
{
	try
	{
		System system;
		system.Run();

		// Call destructor explicitly to detect memory leaks early
#ifdef _DEBUG
		system.~System();
		_CrtDumpMemoryLeaks();
#endif
	}
	catch (std::exception& e)
	{
		fprintf(stderr, "Exception: %s\n", e.what());
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, Constants::WindowTitle, e.what(), nullptr);
	}

	return 0;
}
