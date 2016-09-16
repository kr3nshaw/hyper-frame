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
	/// <summary>Represents a scene in the game.</summary>
	class Scene
	{
		public:
			/// <summary>Frees the memory allocated for the <see cref="Entity">entities</see>, the <see cref="Program">shader programs</see>, and calls OpenGL cleanup functions.</summary>
			virtual ~Scene();

			/// <summary>Contains any instructions that can not be called in the constructor.</summary>
			virtual void Init() = 0;

			/// <summary>Updates the <see cref="Scene" /> and must be called at the end of the overriden Update method.</summary>
			virtual void Update();

			/// <summary>Draws the <see cref="Scene" /> and must be called at the end of the overriden Draw method.</summary>
			virtual void Draw();

			/// <summary>Determines which <see cref="Entity" /> the mouse is currently hovering over.</summary>
			/// <returns>The <see cref="Scene" /> that the mouse is currently hovering over.</returns>
			Entity* GetEntityUnderMouse();

			/// <summary>Gets the <see cref="nextScene" />.</summary>
			Scene* GetNextScene();

		protected:
			/// <summary>A vector that contains all of the <see cref="Entity">entities</see> in the <see cref="Scene" />.</summary>
			std::vector<Entity*> entities;

			/// <summary>The <see cref="Camera" /> that is viewing the <see cref="Scene" />.</summary>
			Camera camera;

			/// <summary>The next <see cref="Scene" /> in the <see cref="Game" /> if there is one, or nullptr if there isn't.</summary>
			Scene* nextScene = nullptr;

			/// <summary>Initialises the <see cref="Scene" /> and must be called at the end of the overriden <see cref="Init" /> method.</summary>
			void Init(Program* program, Camera camera);

		private:
			Program* program = nullptr;
			Program* picking = nullptr;
			GLuint vertexArray;
			GLuint vertexBuffer;
			GLuint elementBuffer;
			GLint position;
			GLint texture;
			GLint projection;
			GLint view;
			GLint model;
			Matrix4 Model;

			void SetProgram(Program* program);
	};
}

#endif
