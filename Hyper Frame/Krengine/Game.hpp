#ifndef Game_hpp
#define Game_hpp

#include "Scene.hpp"
#include <SDL2/SDL.h>

namespace Krengine
{
	class Game
	{
		public:
			Game(const char* const title, Scene* scene);
			~Game();
			static void Log(const char* const entry);

		private:
			SDL_Window* window = nullptr;
			SDL_GLContext context;
			Scene* scene = nullptr;
	};
}

#endif
