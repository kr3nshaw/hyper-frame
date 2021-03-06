#include "Game.hpp"
#include "Input.hpp"
#include "Scene.hpp"
#include "Window.hpp"
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <cstdio>

namespace Krengine
{
	Game::Game(const char* const title, Scene* scene) : scene(scene)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			Log(SDL_GetError());
		}

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		SDL_DisplayMode displayMode;
		SDL_GetDisplayMode(0, 0, &displayMode);

		Window::window = SDL_CreateWindow(title,
								  SDL_WINDOWPOS_CENTERED,
								  SDL_WINDOWPOS_CENTERED,
								  displayMode.w,
								  displayMode.h,
								  SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL);

		if (Window::window == nullptr)
		{
			Log(SDL_GetError());
		}

		context = SDL_GL_CreateContext(Window::window);

		if (context == nullptr)
		{
			Log(SDL_GetError());
		}

		glEnable(GL_DEPTH_TEST);

		SDL_GL_SetSwapInterval(1);

		glewExperimental = GL_TRUE;
		glewInit();

		this->scene->Init();

		while (Input::Update())
		{
			if (this->scene->GetNextScene() != nullptr)
			{
				Scene* oldScene = this->scene;

				this->scene = oldScene->GetNextScene();

				delete oldScene;

				this->scene->Init();
			}

			this->scene->Update();

			this->scene->Draw();

			SDL_GL_SwapWindow(Window::window);
		}
	}

	Game::~Game()
	{
		delete scene;

		SDL_GL_DeleteContext(context);

		SDL_DestroyWindow(Window::window);

		SDL_Quit();
	}

	void Game::Log(const char* const entry)
	{
		printf("%s\n", entry);
	}
}
