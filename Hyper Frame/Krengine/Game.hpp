#ifndef Game_hpp
#define Game_hpp

#include "Scene.hpp"
#include <SDL2/SDL.h>

namespace Krengine
{
	/// <summary>Represents the game.</summary>
	class Game
	{
		public:
			/// <summary>Initialises a new instance of the <see cref="Game" /> class.</summary>
			/// <param name="title">The title of the window.</param>
			/// <param name="scene">The first <see cref="Scene" /> that the <see cref="Game" /> will run.</param>
			Game(const char* const title, Scene* scene);

			/// <summary>Frees the memory allocated for the current <see cref="Scene" /> and calls SDL cleanup functions.</summary>
			~Game();

			/// <summary>Prints a message to the console.</summary>
			static void Log(const char* const entry);

		private:
			SDL_GLContext context;
			Scene* scene = nullptr;
	};
}

#endif
