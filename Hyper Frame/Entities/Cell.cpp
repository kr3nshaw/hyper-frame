#include "Cell.hpp"
#include "../Krengine/Entity.hpp"
#include "../Krengine/Maths.hpp"
#include "../Krengine/Texture.hpp"

using namespace Krengine;

Cell::Cell(Vector3 face, int size, int dimension, Vector2 gridPosition, Texture* texture)
{
	const float start = -(size / 2.0f);
	const float cellSize = (float)size / (float)dimension;
	const float cubeSize = size / 2.0f;
	
	float* v = new float[20];

	if (face.x == 1.0f)
	{
		float y1 = start + (gridPosition.x * cellSize);
		float z1 = start + (gridPosition.y * cellSize);
		float y2 = start + (gridPosition.x * cellSize) + cellSize;
		float z2 = start + (gridPosition.y * cellSize) + cellSize;

		v[0] = cubeSize;	v[1] = y1;	v[2] = z1;	v[3] = 0.0f;	v[4] = 0.0f;
		v[5] = cubeSize;	v[6] = y2;	v[7] = z1;	v[8] = 1.0f;	v[9] = 0.0f;
		v[10] = cubeSize;	v[11] = y1;	v[12] = z2;	v[13] = 0.0f;	v[14] = 1.0f;
		v[15] = cubeSize;	v[16] = y2;	v[17] = z2;	v[18] = 1.0f;	v[19] = 1.0f;
	}
	else if (face.y == 1.0f)
	{
		float x1 = start + (gridPosition.x * cellSize);
		float z1 = start + (gridPosition.y * cellSize);
		float x2 = start + (gridPosition.x * cellSize) + cellSize;
		float z2 = start + (gridPosition.y * cellSize) + cellSize;

		v[0] = x1;	v[1] = cubeSize;	v[2] = z1;	v[3] = 0.0f;	v[4] = 0.0f;
		v[5] = x2;	v[6] = cubeSize;	v[7] = z1;	v[8] = 1.0f;	v[9] = 0.0f;
		v[10] = x1;	v[11] = cubeSize;	v[12] = z2;	v[13] = 0.0f;	v[14] = 1.0f;
		v[15] = x2;	v[16] = cubeSize;	v[17] = z2;	v[18] = 1.0f;	v[19] = 1.0f;
	}
	else if (face.z == 1.0f)
	{
		float x1 = start + (gridPosition.x * cellSize);
		float y1 = start + (gridPosition.y * cellSize);
		float x2 = start + (gridPosition.x * cellSize) + cellSize;
		float y2 = start + (gridPosition.y * cellSize) + cellSize;

		v[0] = x1;	v[1] = y1;	v[2] = cubeSize;	v[3] = 0.0f;	v[4] = 0.0f;
		v[5] = x2;	v[6] = y1;	v[7] = cubeSize;	v[8] = 1.0f;	v[9] = 0.0f;
		v[10] = x1;	v[11] = y2;	v[12] = cubeSize;	v[13] = 0.0f;	v[14] = 1.0f;
		v[15] = x2;	v[16] = y2;	v[17] = cubeSize;	v[18] = 1.0f;	v[19] = 1.0f;
	}

	int* e = new int[6];

	e[0] = 0;
	e[1] = 1;
	e[2] = 2;
	e[3] = 2;
	e[4] = 3;
	e[5] = 1;

	Entity::Init(20, v, 6, e, texture, Vector3(1.0f, 1.0f, 1.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f));
}

void Cell::Init()
{
	//
}
