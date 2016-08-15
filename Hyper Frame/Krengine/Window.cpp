#include "Window.hpp"

namespace Krengine
{
	SDL_Window* Window::window = nullptr;

	int Window::GetWidth()
	{
		int width;
		SDL_GetWindowSize(window, &width, nullptr);

		return width;
	}

	int Window::GetHeight()
	{
		int height;
		SDL_GetWindowSize(window, nullptr, &height);

		return height;
	}
}
