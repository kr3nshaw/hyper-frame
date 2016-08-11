#include "Cell.hpp"
#include "Level.hpp"
#include "../Krengine/Camera.hpp"
#include "../Krengine/Entity.hpp"
#include "../Krengine/Input.hpp"
#include "../Krengine/Maths.hpp"
#include "../Krengine/Program.hpp"
#include "../Krengine/Scene.hpp"
#include "../Krengine/Shader.hpp"
#include "../Krengine/Texture.hpp"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace Krengine;
using namespace std;

Level::Level(int width, int height) : Scene(width, height)
{
	cubeSize = height / 3.0f;
	cameraDistance = cubeSize * 2.0f;
}

void Level::Init()
{
	Program* program = new Program(new Shader(true, Vertex, "./Shaders/vertex.vert"), new Shader(true, Fragment, "./Shaders/fragment.frag"));

	vector<vector<Texture*>> cells;

	cells.push_back({ new Texture("./Graphics/Cells/Blank.png"),
					  new Texture("./Graphics/Cells/Blocked.png") });
	cells.push_back({ new Texture("./Graphics/Cells/Red/Marker.png"),
					  new Texture("./Graphics/Cells/Red/CurrentMarker.png"),
					  new Texture("./Graphics/Cells/Red/LinkedMarker.png"),
					  new Texture("./Graphics/Cells/Red/Link.png") });
	cells.push_back({ new Texture("./Graphics/Cells/Orange/Marker.png"),
					  new Texture("./Graphics/Cells/Orange/CurrentMarker.png"),
					  new Texture("./Graphics/Cells/Orange/LinkedMarker.png"),
					  new Texture("./Graphics/Cells/Orange/Link.png") });
	cells.push_back({ new Texture("./Graphics/Cells/Yellow/Marker.png"),
					  new Texture("./Graphics/Cells/Yellow/CurrentMarker.png"),
					  new Texture("./Graphics/Cells/Yellow/LinkedMarker.png"),
					  new Texture("./Graphics/Cells/Yellow/Link.png") });
	cells.push_back({ new Texture("./Graphics/Cells/Green/Marker.png"),
					  new Texture("./Graphics/Cells/Green/CurrentMarker.png"),
					  new Texture("./Graphics/Cells/Green/LinkedMarker.png"),
					  new Texture("./Graphics/Cells/Green/Link.png") });
	cells.push_back({ new Texture("./Graphics/Cells/Blue/Marker.png"),
					  new Texture("./Graphics/Cells/Blue/CurrentMarker.png"),
					  new Texture("./Graphics/Cells/Blue/LinkedMarker.png"),
					  new Texture("./Graphics/Cells/Blue/Link.png") });
	cells.push_back({ new Texture("./Graphics/Cells/Blue/Marker.png"),
					  new Texture("./Graphics/Cells/Blue/CurrentMarker.png"),
					  new Texture("./Graphics/Cells/Blue/LinkedMarker.png"),
					  new Texture("./Graphics/Cells/Blue/Link.png") });
	cells.push_back({ new Texture("./Graphics/Cells/Purple/Marker.png"),
					  new Texture("./Graphics/Cells/Purple/CurrentMarker.png"),
					  new Texture("./Graphics/Cells/Purple/LinkedMarker.png"),
					  new Texture("./Graphics/Cells/Purple/Link.png") });


	FILE* file = fopen("./Cubes/1.hfc", "rb");

	if (file != nullptr)
	{
		int header;
		int id;
		int version;
		int dimension;

		fread(&header, 4, 1, file);

		id = 0x0000FFFF & header;
		version = (0x00FF0000 & header) >> 16;
		dimension = (0xFF000000 & header) >> 24;

		if ((id == 0x4648) && (version == 0))
		{
			unsigned char cell;

			for (int y = 0; y < dimension; ++y)
			{
				for (int x = 0; x < dimension; ++x)
				{
					fread(&cell, 1, 1, file);

					entities.push_back(new Cell(Vector3(1.0f, 0.0f, 0.0f), cubeSize, dimension, Vector2(x, y), cells[(0xF0 & cell) >> 4][0x0F & cell]));
				}
			}

			for (int y = 0; y < dimension; ++y)
			{
				for (int x = 0; x < dimension; ++x)
				{
					fread(&cell, 1, 1, file);

					entities.push_back(new Cell(Vector3(0.0f, 1.0f, 0.0f), cubeSize, dimension, Vector2(x, y), cells[(0xF0 & cell) >> 4][0x0F & cell]));
				}
			}

			for (int y = 0; y < dimension; ++y)
			{
				for (int x = 0; x < dimension; ++x)
				{
					fread(&cell, 1, 1, file);

					entities.push_back(new Cell(Vector3(0.0f, 0.0f, 1.0f), cubeSize, dimension, Vector2(x, y), cells[(0xF0 & cell) >> 4][0x0F & cell]));
				}
			}
		}

		fclose(file);
	}

	Scene::Init(program, Camera(Vector3(0.0f, 0.0f, cameraDistance),
								Vector3(0.0f, 0.0f, 0.0f),
								Vector3(0.0f, 1.0f, 0.0f),
								74.0f,
								(float)GetWidth() / (float)GetHeight(),
								0.001f,
								1000.0f));
}

void Level::Update()
{
	float x = (min(max(GetHeight() / 3.0f, (float)Input::GetMouseY()), (2.0f / 3.0f) * GetHeight()) - (GetHeight() / 3.0f)) / (GetHeight() / 3.0f);
	float y = (min(max(GetWidth() / 3.0f, (float)Input::GetMouseX()), (2.0f / 3.0f) * GetWidth()) - (GetWidth() / 3.0f)) / (GetWidth() / 3.0f);

	x = (x * (M_PI / 2.0f)) - (M_PI / 2.0f);
	y *= (M_PI / 2.0f);

	camera.Position.x = cos(x) * sin(y) * cameraDistance;
	camera.Position.y = -sin(x) * cameraDistance;
	camera.Position.z = cos(x) * cos(y) * cameraDistance;

	Scene::Update();
}

void Level::Draw()
{
	Scene::Draw();
}
