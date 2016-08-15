#ifndef Window_hpp
#define Window_hpp

#ifdef __linux__
#include <SDL2/SDL.h>
#else
#include <SDL2/sdl.h>
#endif

namespace Krengine
{
	class Window
	{
		public:
			static SDL_Window* window;

			static int GetWidth();
			static int GetHeight();
	};
}

#endif
