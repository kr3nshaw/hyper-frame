#include "Cube.hpp"
#include "../Krengine/Entity.hpp"
#include "../Krengine/Texture.hpp"

using namespace Krengine;

Cube::Cube(Texture* texture) : texture(texture)
{
	//
}

void Cube::Init()
{
	float* v = new float[20];

	v[0] = -1.0f;	v[1] = -0.5f;	v[2] = 0.0f;	v[3] = 0.0f;	v[4] = 0.0f;
	v[5] = 0.0f;	v[6] = -0.5f;	v[7] = 0.0f;	v[8] = 1.0f;	v[9] = 0.0f;
	v[10] = -1.0f;	v[11] = 0.5f;	v[12] = 0.0f;	v[13] = 0.0f;	v[14] = 1.0f;
	v[15] = 0.0f;	v[16] = 0.5f;	v[17] = 0.0f;	v[18] = 1.0f;	v[19] = 1.0f;

	int* e = new int[6];

	e[0] = 0;
	e[1] = 1;
	e[2] = 2;
	e[3] = 2;
	e[4] = 1;
	e[5] = 3;

	Entity::Init(20, v, 6, e, texture, Vector3(1.0f, 1.0f, 1.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f));
}
