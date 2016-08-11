#ifndef Window_hpp
#define Window_hpp

#include <SDL2/sdl.h>

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
