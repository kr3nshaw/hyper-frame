#include "Cell.hpp"
#include "../Krengine/Entity.hpp"
#include "../Krengine/Maths.hpp"
#include "../Krengine/Texture.hpp"
#include <vector>

using namespace Krengine;
using namespace std;

Cell::Cell(Vector3 face,
		   Vector2 gridPosition,
		   CellColour colour,
		   CellType type,
		   vector<vector<Texture*>>* cellTextures,
		   int size,
		   int dimension) : face(face), gridPosition(gridPosition), colour(colour), type(type), cellTextures(cellTextures)
{
	const float start = -(size / 2.0f);
	const float cellSize = (float)size / (float)dimension;
	const float cubeSize = size / 2.0f;
	
	float* v = new float[20];

	if (face.x == 1.0f)
	{
		float y1 = -(start + (gridPosition.y * cellSize));
		float z1 = -(start + (gridPosition.x * cellSize));
		float y2 = -(start + (gridPosition.y * cellSize) + cellSize);
		float z2 = -(start + (gridPosition.x * cellSize) + cellSize);

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
		float y1 = -(start + (gridPosition.y * cellSize));
		float x2 = start + (gridPosition.x * cellSize) + cellSize;
		float y2 = -(start + (gridPosition.y * cellSize) + cellSize);

		v[0] = x1;	v[1] = y1;	v[2] = cubeSize;	v[3] = 0.0f;	v[4] = 0.0f;
		v[5] = x2;	v[6] = y1;	v[7] = cubeSize;	v[8] = 1.0f;	v[9] = 0.0f;
		v[10] = x1;	v[11] = y2;	v[12] = cubeSize;	v[13] = 0.0f;	v[14] = 1.0f;
		v[15] = x2;	v[16] = y2;	v[17] = cubeSize;	v[18] = 1.0f;	v[19] = 1.0f;
	}

	int* e = new int[6];

	e[0] = 0;	e[1] = 1;	e[2] = 2;
	e[3] = 2;	e[4] = 3;	e[5] = 1;

	Entity::Init(20, v, 6, e, (*cellTextures)[this->colour][this->type], Vector3(1.0f, 1.0f, 1.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f));
}

void Cell::Init()
{
	//
}

Vector3 Cell::GetFace()
{
	return face;
}

Vector2 Cell::GetGridPosition()
{
	return gridPosition;
}

CellColour Cell::GetColour()
{
	return colour;
}

CellType Cell::GetType()
{
	return type;
}

void Cell::SetCell(CellColour colour, CellType type)
{
	this->colour = colour;
	this->type = type;
	SetTexture((*cellTextures)[this->colour][this->type]);
}
