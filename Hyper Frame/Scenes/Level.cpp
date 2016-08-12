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
#include "../Krengine/Window.hpp"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace Krengine;
using namespace std;

void Level::Init()
{
	cubeSize = Window::GetHeight() / 3.0f;
	cameraDistance = cubeSize * 2.0f;

	Program* program = new Program(new Shader(true, Vertex, "./Shaders/vertex.vert"), new Shader(true, Fragment, "./Shaders/fragment.frag"));

	cellTextures.push_back({ new Texture("./Graphics/Cells/Blank.png"),
							 new Texture("./Graphics/Cells/Blocked.png") });
	cellTextures.push_back({ new Texture("./Graphics/Cells/Red/Marker.png"),
							 new Texture("./Graphics/Cells/Red/CurrentMarker.png"),
							 new Texture("./Graphics/Cells/Red/LinkedMarker.png"),
							 new Texture("./Graphics/Cells/Red/Link.png") });
	cellTextures.push_back({ new Texture("./Graphics/Cells/Orange/Marker.png"),
							 new Texture("./Graphics/Cells/Orange/CurrentMarker.png"),
							 new Texture("./Graphics/Cells/Orange/LinkedMarker.png"),
							 new Texture("./Graphics/Cells/Orange/Link.png") });
	cellTextures.push_back({ new Texture("./Graphics/Cells/Yellow/Marker.png"),
							 new Texture("./Graphics/Cells/Yellow/CurrentMarker.png"),
							 new Texture("./Graphics/Cells/Yellow/LinkedMarker.png"),
							 new Texture("./Graphics/Cells/Yellow/Link.png") });
	cellTextures.push_back({ new Texture("./Graphics/Cells/Green/Marker.png"),
							 new Texture("./Graphics/Cells/Green/CurrentMarker.png"),
							 new Texture("./Graphics/Cells/Green/LinkedMarker.png"),
							 new Texture("./Graphics/Cells/Green/Link.png") });
	cellTextures.push_back({ new Texture("./Graphics/Cells/Blue/Marker.png"),
							 new Texture("./Graphics/Cells/Blue/CurrentMarker.png"),
							 new Texture("./Graphics/Cells/Blue/LinkedMarker.png"),
							 new Texture("./Graphics/Cells/Blue/Link.png") });
	cellTextures.push_back({ new Texture("./Graphics/Cells/Blue/Marker.png"),
							 new Texture("./Graphics/Cells/Blue/CurrentMarker.png"),
							 new Texture("./Graphics/Cells/Blue/LinkedMarker.png"),
							 new Texture("./Graphics/Cells/Blue/Link.png") });
	cellTextures.push_back({ new Texture("./Graphics/Cells/Purple/Marker.png"),
							 new Texture("./Graphics/Cells/Purple/CurrentMarker.png"),
							 new Texture("./Graphics/Cells/Purple/LinkedMarker.png"),
							 new Texture("./Graphics/Cells/Purple/Link.png") });

	for (vector<Texture*> vector : cellTextures)
	{
		for (Texture* texture : vector)
		{
			texture->Init();
		}
	}

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

					entities.push_back(new Cell(Vector3(1.0f, 0.0f, 0.0f),
												cubeSize,
												dimension,
												Vector2(x, y),
												static_cast<CellColour>((0xF0 & cell) >> 4),
												static_cast<CellType>(0x0F & cell),
												&cellTextures));
				}
			}

			for (int y = 0; y < dimension; ++y)
			{
				for (int x = 0; x < dimension; ++x)
				{
					fread(&cell, 1, 1, file);

					entities.push_back(new Cell(Vector3(0.0f, 1.0f, 0.0f),
												cubeSize,
												dimension,
												Vector2(x, y),
												static_cast<CellColour>((0xF0 & cell) >> 4),
												static_cast<CellType>(0x0F & cell),
												&cellTextures));
				}
			}

			for (int y = 0; y < dimension; ++y)
			{
				for (int x = 0; x < dimension; ++x)
				{
					fread(&cell, 1, 1, file);

					entities.push_back(new Cell(Vector3(0.0f, 0.0f, 1.0f),
												cubeSize,
												dimension,
												Vector2(x, y),
												static_cast<CellColour>((0xF0 & cell) >> 4),
												static_cast<CellType>(0x0F & cell),
												&cellTextures));
				}
			}
		}

		fclose(file);
	}

	Scene::Init(program, Camera(Vector3(0.0f, 0.0f, cameraDistance),
								Vector3(0.0f, 0.0f, 0.0f),
								Vector3(0.0f, 1.0f, 0.0f),
								74.0f,
								(float)Window::GetWidth() / (float)Window::GetHeight(),
								1.0f,
								1000.0f));
}

void Level::Update()
{
	if (Input::GetMouse1())
	{
		Entity* entity = GetEntityUnderMouse();

		if (entity != nullptr)
		{
			Cell* cell = reinterpret_cast<Cell*>(GetEntityUnderMouse());

			if (!drawing && (cell->GetColour() != Special) && (cell->GetType() != Link))
			{
				currentColour = cell->GetColour();
			}

			if (currentColour != Special)
			{
				if (((cell->GetColour() == Special) && (cell->GetType() == Blank)) || (cell->GetType() == Link))
				{
					cell->SetCell(currentColour, Link);
				}
			}

			drawing = true;
		}
	}
	else
	{
		drawing = false;
	}

	float x = (min(max(Window::GetHeight() / 3.0f, (float)Input::GetMouseY()), (2.0f / 3.0f) * Window::GetHeight()) - (Window::GetHeight() / 3.0f)) / (Window::GetHeight() / 3.0f);
	float y = (min(max(Window::GetWidth() / 3.0f, (float)Input::GetMouseX()), (2.0f / 3.0f) * Window::GetWidth()) - (Window::GetWidth() / 3.0f)) / (Window::GetWidth() / 3.0f);

	x = (x * (M_PI / 2.0f)) + ((3.0f / 2.0f) * M_PI);
	y *= M_PI / 2.0f;

	camera.Position.x = cos(x) * sin(y) * cameraDistance;
	camera.Position.y = -sin(x) * cameraDistance;
	camera.Position.z = cos(x) * cos(y) * cameraDistance;

	Scene::Update();
}

void Level::Draw()
{
	Scene::Draw();
}
