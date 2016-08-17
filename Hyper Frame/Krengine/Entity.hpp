#ifndef Entity_hpp
#define Entity_hpp

#include "Maths.hpp"
#include "Texture.hpp"
#include <GL/glew.h>

namespace Krengine
{
	/// <summary>Represents an entity in the world.</summary>
	class Entity
	{
		public:
			/// <summary>The scale of the <see cref="Entity" />.</summary>
			Vector3 Scale;

			/// <summary>The rotation of the <see cref="Entity" /> in radians.</summary>
			Vector3 Rotation;

			/// <summary>The position of the <see cref="Entity" />.</summary>
			Vector3 Position;

			/// <summary>Frees the memory allocated for the vertex array and the element array.</summary>
			virtual ~Entity();

			/// <summary>Contains any instructions that can not be called in the constructor.</summary>
			virtual void Init() = 0;

			/// <summary>Gets the total number of vertices.</summary>
			int GetVerticesCount();

			/// <summary>Gets the vertex array.</summary>
			const float* GetVertices();

			/// <summary>Gets the total number of elements.</summary>
			int GetElementsCount();

			/// <summary>Gets the element array.</summary>
			const int* GetElements();

			/// <summary>Gets the texture of the entity.</summary>
			Texture* GetTexture();

		protected:
			/// <summary>Initialises the <see cref="Entity" /> and must be called at the end of the overriden <see cref="Init" /> method.</summary>
			void Init(int verticesCount,
					  float* vertices,
					  int elementsCount,
					  int* elements,
					  Texture* texture,
					  Vector3 scale,
					  Vector3 rotation,
					  Vector3 position);

			/// <summary>Sets the <see cref="texture" /> of the <see cref="Entity" />.</summary>
			void SetTexture(Texture* texture);

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
