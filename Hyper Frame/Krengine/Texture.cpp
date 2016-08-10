#include "Texture.hpp"
#include <GL/glew.h>
#include <SDL2_image/SDL_image.h>

namespace Krengine
{
	Texture::Texture(const char* data)
	{
		surface = IMG_Load(data);
		SDL_Surface* newSurface = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA8888, 0);
		SDL_FreeSurface(surface);
		surface = newSurface;
	}

	Texture::~Texture()
	{
		if (created)
		{
			glDeleteTextures(1, &texture);
		}

		SDL_FreeSurface(surface);
	}

	void Texture::Init()
	{
		if (!created)
		{
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, surface->pixels);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glGenerateMipmap(GL_TEXTURE_2D);

			created = true;
		}
	}

	GLuint Texture::GetTexture()
	{
		return texture;
	}
}
