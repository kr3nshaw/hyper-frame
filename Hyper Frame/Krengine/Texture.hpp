#ifndef Texture_hpp
#define Texture_hpp

#include <GL/glew.h>
#include <SDL2/SDL.h>

namespace Krengine
{
	/// <summary>Represents a texture.</summary>
	class Texture
	{
		public:
			/// <summary>Initialises a new instance of the <see cref="Texture" /> class.</summary>
			/// <param name="data">A C-style string that contains the path to the texture file.</param>
			Texture(const char* data);

			/// <summary>Frees the memory allocated for the <see cref="Texture" /> data, and calls OpenGL cleanup functions.</summary>
			~Texture();

			/// <summary>Contains any instructions that can not be called in the constructor.</summary>
			void Init();

			/// <summary>Gets the internal identifier of the texture as provided by OpenGL.</summary>
			GLuint GetTexture();

		private:
			SDL_Surface* surface = nullptr;
			bool created = false;

			GLuint texture;
	};
}

#endif
