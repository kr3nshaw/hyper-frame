#ifndef Window_hpp
#define Window_hpp

#include <SDL2/SDL.h>

namespace Krengine
{
	/// <summary>Represents the <see cref="Game" /> window.</summary>
	class Window
	{
		public:
			/// <summary>A pointer to the SDL window.</summary>
			static SDL_Window* window;

			/// <summary>Gets the width of the window.</summary>
			static int GetWidth();

			/// <summary>Gets the height of the window.</summary>
			static int GetHeight();
	};
}

#endif
