#ifndef Scene_hpp
#define Scene_hpp

#include "Program.hpp"
#include "Entity.hpp"
#include "Camera.hpp"
#include <GL/glew.h>
#include <vector>

namespace Krengine
{
	class Scene
	{
		public:
			Scene(int width, int height);
			virtual ~Scene();
			virtual void Init() = 0;
			virtual void Update();
			virtual void Draw();

			int GetWidth();
			int GetHeight();
			Scene* GetNextScene();

		protected:
			void Init(Program* program, Camera camera);

			std::vector<Entity*> entities;
			Camera camera;

		private:
			Program* program = nullptr;
			GLint position;
			GLint texture;
			GLint model;
			GLint view;
			GLint projection;

			int width;
			int height;
			Scene* nextScene = nullptr;
	};
}

#endif
