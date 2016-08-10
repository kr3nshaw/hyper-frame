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
			virtual ~Entity();
			virtual void Init() = 0;

			int GetVerticesCount();
			const float* GetVertices();
			int GetElementsCount();
			const int* GetElements();
			Texture* GetTexture();

			Vector3 scale;
			Vector3 rotation;
			Vector3 position;
			GLuint vertexArray;
			GLuint vertexBuffer;
			GLuint elementBuffer;

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
			int verticesCount;
			float* vertices = nullptr;
			int elementsCount;
			int* elements = nullptr;
			Texture* texture = nullptr;

			bool created = false;
	};
}

#endif
