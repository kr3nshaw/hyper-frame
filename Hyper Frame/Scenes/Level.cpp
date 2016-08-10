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
#include <algorithm>
#include <cmath>
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

	// Texture* blank = new Texture("./Graphics/Cells/Blank.png");
	// Texture* blocked = new Texture("./Graphics/Cells/Blocked.png");

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
			entities.push_back(new Cell(Vector3(1.0f, 0.0f, 0.0f), cubeSize, dimension, Vector2(i, j), cells[2][0]));
			entities.push_back(new Cell(Vector3(0.0f, 1.0f, 0.0f), cubeSize, dimension, Vector2(i, j), cells[1][0]));
			entities.push_back(new Cell(Vector3(0.0f, 0.0f, 1.0f), cubeSize, dimension, Vector2(i, j), cells[0][0]));
		}
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
	float z = 0.0f;

	x = (x * (M_PI / 2.0f)) - (M_PI / 2.0f);
	y *= (M_PI / 2.0f);

	Vector3 v;
	v.x = ((cos(y) * cos(z)) * 0.0f) +
		  (((cos(z) * sin(x) * sin(y)) - (cos(x) * (sin(z)))) * 0.0f) +
		  (((cos(x) * cos(z) * sin(y)) + (sin(x) * sin(z))) * cameraDistance);
	v.y = ((cos(y) * sin(z)) * 0.0f) +
		  (((cos(x) * cos(z)) + (sin(x) * sin(y) * sin(z))) * 0.0f) +
		  (((cos(x) * sin(y) * sin(z)) - (cos(z) * sin(x))) * cameraDistance);
	v.z = (-sin(y) * 0.0f) + ((cos(y) * sin(x)) * 0.0f) + ((cos(x) * (cos(y))) * cameraDistance);

	camera.Position = v;

	Scene::Update();
}

void Level::Draw()
{
	Scene::Draw();
}
