#include "Entity.hpp"
#include "Texture.hpp"
#include <GL/glew.h>

namespace Krengine
{
	Entity::~Entity()
	{
		if (created)
		{
			delete elements;
			delete vertices;
		}
	}

	void Entity::Init(int verticesCount,
					  float* vertices,
					  int elementsCount,
					  int* elements,
					  Texture* texture,
					  Vector3 scale,
					  Vector3 rotation,
					  Vector3 position)
	{
		if (!created)
		{
			this->verticesCount = verticesCount;
			this->vertices = vertices;
			this->elementsCount = elementsCount;
			this->elements = elements;
			this->texture = texture;
			this->scale = scale;
			this->rotation = rotation;
			this->position = position;

			created = true;
		}
	}

	int Entity::GetVerticesCount()
	{
		return verticesCount;
	}

	const float* Entity::GetVertices()
	{
		return vertices;
	}

	int Entity::GetElementsCount()
	{
		return elementsCount;
	}

	const int* Entity::GetElements()
	{
		return elements;
	}

	Texture* Entity::GetTexture()
	{
		return texture;
	}
}
