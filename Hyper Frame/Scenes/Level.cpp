#include "Level.hpp"
#include "Cell.hpp"
#include "../Krengine/Scene.hpp"
#include "../Krengine/Program.hpp"
#include "../Krengine/Shader.hpp"
#include "../Krengine/Entity.hpp"
#include "../Krengine/Texture.hpp"
#include "../Krengine/Camera.hpp"
#include "../Krengine/Maths.hpp"
#include "../Krengine/Input.hpp"
#include <vector>

using namespace Krengine;
using namespace std;

Level::Level(int width, int height) : Scene(width, height)
{
	//
}

void Level::Init()
{
	Program* program = new Program(new Shader(true, Vertex, "./Shaders/vertex.vert"), new Shader(true, Fragment, "./Shaders/fragment.frag"));

	Texture* blank = new Texture("./Graphics/Cells/Blank.png");
	Texture* blocked = new Texture("./Graphics/Cells/Blocked.png");

	vector<vector<Texture*>> cells;

	cells.push_back({ new Texture("./Graphics/Cells/Blue/CurrentMarker.png"),
					  new Texture("./Graphics/Cells/Blue/Link.png"),
					  new Texture("./Graphics/Cells/Blue/LinkedMarker.png"),
					  new Texture("./Graphics/Cells/Blue/Marker.png") });
	cells.push_back({ new Texture("./Graphics/Cells/Green/CurrentMarker.png"),
					  new Texture("./Graphics/Cells/Green/Link.png"),
					  new Texture("./Graphics/Cells/Green/LinkedMarker.png"),
					  new Texture("./Graphics/Cells/Green/Marker.png") });
	cells.push_back({ new Texture("./Graphics/Cells/Orange/CurrentMarker.png"),
					  new Texture("./Graphics/Cells/Orange/Link.png"),
					  new Texture("./Graphics/Cells/Orange/LinkedMarker.png"),
					  new Texture("./Graphics/Cells/Orange/Marker.png") });
	cells.push_back({ new Texture("./Graphics/Cells/Purple/CurrentMarker.png"),
					  new Texture("./Graphics/Cells/Purple/Link.png"),
					  new Texture("./Graphics/Cells/Purple/LinkedMarker.png"),
					  new Texture("./Graphics/Cells/Purple/Marker.png") });
	cells.push_back({ new Texture("./Graphics/Cells/Red/CurrentMarker.png"),
					  new Texture("./Graphics/Cells/Red/Link.png"),
					  new Texture("./Graphics/Cells/Red/LinkedMarker.png"),
					  new Texture("./Graphics/Cells/Red/Marker.png") });
	cells.push_back({ new Texture("./Graphics/Cells/Yellow/CurrentMarker.png"),
					  new Texture("./Graphics/Cells/Yellow/Link.png"),
					  new Texture("./Graphics/Cells/Yellow/LinkedMarker.png"),
					  new Texture("./Graphics/Cells/Yellow/Marker.png") });

	const int dimension = 4;

	for (int i = 0; i < dimension; ++i)
	{
		for (int j = 0; j < dimension; ++j)
		{
			entities.push_back(new Cell(Vector3(1.0f, 0.0f, 0.0f), cubeSize, dimension, Vector2(i, j), cells[i][j]));
			entities.push_back(new Cell(Vector3(0.0f, 1.0f, 0.0f), cubeSize, dimension, Vector2(i, j), cells[i][j]));
			entities.push_back(new Cell(Vector3(0.0f, 0.0f, 1.0f), cubeSize, dimension, Vector2(i, j), cells[i][j]));
		}
	}

	Scene::Init(program, Camera(Vector3(cubeSize, cubeSize, cubeSize),
								Vector3(cubeSize / 2.0f, cubeSize / 2.0f, cubeSize / 2.0f),
								Vector3(0.0f, 1.0f, 0.0f),
								74.0f,
								(float)GetWidth() / (float)GetHeight(),
								0.001f,
								1000.0f));
}

void Level::Update()
{
	if (Input::GetVK_LEFT())
	{
		--camera.Position.x;
	}
	else if (Input::GetVK_RIGHT())
	{
		++camera.Position.x;
	}
	else if (Input::GetVK_UP())
	{
		--camera.Position.y;
	}
	else if (Input::GetVK_DOWN())
	{
		++camera.Position.y;
	}

	Scene::Update();
}

void Level::Draw()
{
	Scene::Draw();
}
