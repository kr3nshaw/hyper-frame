#ifndef Scene_hpp
#define Scene_hpp

#include "Camera.hpp"
#include "Entity.hpp"
#include "Maths.hpp"
#include "Program.hpp"
#include <GL/glew.h>
#include <vector>

namespace Krengine
{
	class Scene
	{
		public:
			virtual ~Scene();
			virtual void Init() = 0;
			virtual void Update();
			virtual void Draw();

			Entity* GetEntityUnderMouse();
			Scene* GetNextScene();

		protected:
			std::vector<Entity*> entities;
			Camera camera;

			void Init(Program* program, Camera camera);

		private:
			Program* program = nullptr;
			Program* picking = nullptr;
			GLint position;
			GLint texture;
			GLint projection;
			GLint view;
			GLint model;
			Matrix4 Model;

			Scene* nextScene = nullptr;
	};
}

#endif
