#include "Cube.hpp"
#include "../Entities/Cell.hpp"
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
#include <unordered_map>
#include <vector>

using namespace Krengine;
using namespace std;

int Cube::cube = 0;

void Cube::Init()
{
	if (++cube > 40)
	{
		cube = 1;
	}

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

	char filename[FILENAME_MAX];
	sprintf(filename, "./Cubes/%i.hfc", cube);

	FILE* file = fopen(filename, "rb");

	if (file != nullptr)
	{
		int header;
		int id;
		int version;

		fread(&header, 4, 1, file);

		id = 0x0000FFFF & header;
		version = (0x00FF0000 & header) >> 16;
		dimension = (0xFF000000 & header) >> 24;

		if ((id == 0x4648) && (version == 0))
		{
			unsigned char cell;

			cells.push_back(vector<vector<Cell*>>());

			for (int y = 0; y < dimension; ++y)
			{
				cells[0].push_back(vector<Cell*>());

				for (int x = 0; x < dimension; ++x)
				{
					fread(&cell, 1, 1, file);

					cells[0][y].push_back(new Cell(Vector3(1.0f, 0.0f, 0.0f),
												   Vector2(x, y),
												   static_cast<CellColour>((0xF0 & cell) >> 4),
												   static_cast<CellType>(0x0F & cell),
												   &cellTextures,
												   cubeSize,
												   dimension));
					entities.push_back(cells[0][y][x]);

					if ((cells[0][y][x]->GetColour() != Special) && (cells[0][y][x]->GetType() != Link))
					{
						markers.push_back(cells[0][y][x]);
					}
				}
			}

			cells.push_back(vector<vector<Cell*>>());

			for (int y = 0; y < dimension; ++y)
			{
				cells[1].push_back(vector<Cell*>());

				for (int x = 0; x < dimension; ++x)
				{
					fread(&cell, 1, 1, file);

					cells[1][y].push_back(new Cell(Vector3(0.0f, 1.0f, 0.0f),
												   Vector2(x, y),
												   static_cast<CellColour>((0xF0 & cell) >> 4),
												   static_cast<CellType>(0x0F & cell),
												   &cellTextures,
												   cubeSize,
												   dimension));
					entities.push_back(cells[1][y][x]);

					if ((cells[1][y][x]->GetColour() != Special) && (cells[1][y][x]->GetType() != Link))
					{
						markers.push_back(cells[1][y][x]);
					}
				}
			}

			cells.push_back(vector<vector<Cell*>>());

			for (int y = 0; y < dimension; ++y)
			{
				cells[2].push_back(vector<Cell*>());

				for (int x = 0; x < dimension; ++x)
				{
					fread(&cell, 1, 1, file);

					cells[2][y].push_back(new Cell(Vector3(0.0f, 0.0f, 1.0f),
												   Vector2(x, y),
												   static_cast<CellColour>((0xF0 & cell) >> 4),
												   static_cast<CellType>(0x0F & cell),
												   &cellTextures,
												   cubeSize,
												   dimension));
					entities.push_back(cells[2][y][x]);

					if ((cells[2][y][x]->GetColour() != Special) && (cells[2][y][x]->GetType() != Link))
					{
						markers.push_back(cells[2][y][x]);
					}
				}
			}
		}

		fclose(file);
	}

	for (vector<vector<Cell*>> face : cells)
	{
		for (vector<Cell*> row : face)
		{
			for (Cell* cell : row)
			{
				int face;
				int x = cell->GetGridPosition().x;
				int y = cell->GetGridPosition().y;
				vector<Cell*> n;

				if (cell->GetFace() == Vector3(1.0f, 0.0f, 0.0f))
				{
					face = 0;
				}
				else if (cell->GetFace() == Vector3(0.0f, 1.0f, 0.0f))
				{
					face = 1;
				}
				else if (cell->GetFace()== Vector3(0.0f, 0.0f, 1.0f))
				{
					face = 2;
				}
				else
				{
					face = 3;
				}

				if ((x > 0) && (x != (dimension - 1)) && (y > 0) && (y != (dimension - 1)))
				{
					n.push_back(cells[face][y - 1][x]);
					n.push_back(cells[face][y][x + 1]);
					n.push_back(cells[face][y + 1][x]);
					n.push_back(cells[face][y][x - 1]);
				}
				else if (face == 0)
				{
					if (y == 0)
					{
						n.push_back(cells[1][dimension - (x + 1)][dimension - 1]);
					}
					else
					{
						n.push_back(cells[0][y - 1][x]);
					}

					if (x != (dimension - 1))
					{
						n.push_back(cells[0][y][x + 1]);
					}

					if (y != (dimension - 1))
					{
						n.push_back(cells[0][y + 1][x]);
					}

					if (x == 0)
					{
						n.push_back(cells[2][y][dimension - 1]);
					}
					else
					{
						n.push_back(cells[0][y][x - 1]);
					}
				}
				else if (face == 1)
				{
					if (y != 0)
					{
						n.push_back(cells[1][y - 1][x]);
					}

					if (x == (dimension - 1))
					{
						n.push_back(cells[0][0][dimension - (y + 1)]);
					}
					else
					{
						n.push_back(cells[1][y][x + 1]);
					}

					if (y == (dimension - 1))
					{
						n.push_back(cells[2][0][x]);
					}
					else
					{
						n.push_back(cells[1][y + 1][x]);
					}

					if (x != 0)
					{
						n.push_back(cells[1][y][x - 1]);
					}
				}
				else if (face == 2)
				{
					if (y == 0)
					{
						n.push_back(cells[1][dimension - 1][x]);
					}
					else
					{
						n.push_back(cells[2][y - 1][x]);
					}

					if (x == (dimension - 1))
					{
						n.push_back(cells[0][y][0]);
					}
					else
					{
						n.push_back(cells[2][y][x + 1]);
					}

					if (y != (dimension - 1))
					{
						n.push_back(cells[2][y + 1][x]);
					}

					if (x != 0)
					{
						n.push_back(cells[2][y][x - 1]);
					}
				}

				neighbours.insert(make_pair(cell, n));
			}
		}
	}

	Scene::Init(program, Camera(Vector3(0.0f, 0.0f, cameraDistance),
								Vector3(0.0f, 0.0f, 0.0f),
								Vector3(0.0f, 1.0f, 0.0f),
								74.0f,
								(float)Window::GetWidth() / (float)Window::GetHeight(),
								1.0f,
								1000.0f));
}

void Cube::Update()
{
	if (Input::GetMouse1())
	{
		Entity* entity = GetEntityUnderMouse();

		if (entity != nullptr)
		{
			Cell* cell = reinterpret_cast<Cell*>(GetEntityUnderMouse());

			if (!drawing && (cell->GetColour() != Special) && (cell->GetType() != Link))
			{
				for (Cell* c : markers)
				{
					if ((c->GetColour() == currentColour) && (c->GetType() != LinkedMarker))
					{
						c->SetCell(c->GetColour(), Marker);
					}
				}

				currentColour = cell->GetColour();

				for (Cell* c : markers)
				{
					if (c->GetColour() == currentColour)
					{
						c->SetCell(c->GetColour(), CurrentMarker);
					}
				}
			}

			if (currentColour != Special)
			{
				if (((cell->GetColour() == Special) && (cell->GetType() == Blank)) || (cell->GetType() == Link))
				{
					cell->SetCell(currentColour, Link);

					vector<Cell*> linkedMarkers = markers;

					for (int i = 0; i < linkedMarkers.size(); ++i)
					{
						if (MarkersLinked(linkedMarkers[i]))
						{
							linkedMarkers[i]->SetCell(linkedMarkers[i]->GetColour(), LinkedMarker);

							linkedMarkers.erase(linkedMarkers.begin() + i--);
						}
						else if (linkedMarkers[i]->GetType() != CurrentMarker)
						{
							linkedMarkers[i]->SetCell(linkedMarkers[i]->GetColour(), Marker);
						}
					}

					if (linkedMarkers.empty())
					{
						nextScene = new Cube();
					}
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

void Cube::Draw()
{
	Scene::Draw();
}


bool Cube::MarkersLinked(Cell* cell)
{
	bool linked = markersLinked(cell);

	searched.clear();

	return linked;
}

bool Cube::markersLinked(Cell* cell)
{
	searched.insert(make_pair(cell, true));

	for (Cell* neighbour : neighbours.find(cell)->second)
	{
		if (searched.find(neighbour) == searched.end())
		{
			if (neighbour->GetColour() != cell->GetColour())
			{
				searched.insert(make_pair(neighbour, true));
			}
			else if (neighbour->GetType() == Link)
			{
				return markersLinked(neighbour);
			}
			else
			{
				return true;
			}
		}
	}

	return false;
}
