#ifndef Texture_hpp
#define Texture_hpp

#include <GL/glew.h>
#include <SDL2/SDL.h>

namespace Krengine
{
	class Texture
	{
		public:
			Texture(const char* data);
			~Texture();
			void Init();

			GLuint GetTexture();

		private:
			SDL_Surface* surface = nullptr;
			bool created = false;

			GLuint texture;
	};
}

#endif
