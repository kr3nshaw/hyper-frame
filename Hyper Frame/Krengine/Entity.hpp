#ifndef Entity_hpp
#define Entity_hpp

#include "Texture.hpp"
#include "Maths.hpp"
#include <GL/glew.h>

namespace Krengine
{
	class Entity
	{
		public:
			Vector3 scale;
			Vector3 rotation;
			Vector3 position;
			GLuint vertexArray;
			GLuint vertexBuffer;
			GLuint elementBuffer;

			virtual ~Entity();
			virtual void Init() = 0;

			int GetVerticesCount();
			const float* GetVertices();
			int GetElementsCount();
			const int* GetElements();
			Texture* GetTexture();

		protected:
			void Init(int verticesCount,
					  float* vertices,
					  int elementsCount,
					  int* elements,
					  Texture* texture,
					  Vector3 scale,
					  Vector3 rotation,
					  Vector3 position);

		private:
			bool created = false;

			int verticesCount;
			float* vertices = nullptr;
			int elementsCount;
			int* elements = nullptr;
			Texture* texture = nullptr;
	};
}

#endif
