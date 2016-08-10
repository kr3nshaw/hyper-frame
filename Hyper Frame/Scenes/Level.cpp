#include "Level.hpp"
#include "Cube.hpp"
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

Level::Level(int width, int height) : Scene(width, height)
{
	//
}

void Level::Init()
{
	Program* program = new Program(new Shader(true, Vertex, "./Shaders/vertex.vert"), new Shader(true, Fragment, "./Shaders/fragment.frag"));

	Texture* blank = new Texture("./Graphics/Cells/Blank.png");
	Texture* blocked = new Texture("./Graphics/Cells/Blocked.png");
	Texture* blue_currentMarker = new Texture("./Graphics/Cells/Blue/CurrentMarker.png");
	Texture* blue_link = new Texture("./Graphics/Cells/Blue/Link.png");
	Texture* blue_linkedMarker = new Texture("./Graphics/Cells/Blue/LinkedMarker.png");
	Texture* blue_marker = new Texture("./Graphics/Cells/Blue/Marker.png");
	Texture* green_currentMarker = new Texture("./Graphics/Cells/Green/CurrentMarker.png");
	Texture* green_link = new Texture("./Graphics/Cells/Green/Link.png");
	Texture* green_linkedMarker = new Texture("./Graphics/Cells/Green/LinkedMarker.png");
	Texture* green_marker = new Texture("./Graphics/Cells/Green/Marker.png");
	Texture* orange_currentMarker = new Texture("./Graphics/Cells/Orange/CurrentMarker.png");
	Texture* orange_link = new Texture("./Graphics/Cells/Orange/Link.png");
	Texture* orange_linkedMarker = new Texture("./Graphics/Cells/Orange/LinkedMarker.png");
	Texture* orange_marker = new Texture("./Graphics/Cells/Orange/Marker.png");
	Texture* purple_currentMarker = new Texture("./Graphics/Cells/Purple/CurrentMarker.png");
	Texture* purple_link = new Texture("./Graphics/Cells/Purple/Link.png");
	Texture* purple_linkedMarker = new Texture("./Graphics/Cells/Purple/LinkedMarker.png");
	Texture* purple_marker = new Texture("./Graphics/Cells/Purple/Marker.png");
	Texture* red_currentMarker = new Texture("./Graphics/Cells/Red/CurrentMarker.png");
	Texture* red_link = new Texture("./Graphics/Cells/Red/Link.png");
	Texture* red_linkedMarker = new Texture("./Graphics/Cells/Red/LinkedMarker.png");
	Texture* red_marker = new Texture("./Graphics/Cells/Red/Marker.png");
	Texture* yellow_currentMarker = new Texture("./Graphics/Cells/Yellow/CurrentMarker.png");
	Texture* yellow_link = new Texture("./Graphics/Cells/Yellow/Link.png");
	Texture* yellow_linkedMarker = new Texture("./Graphics/Cells/Yellow/LinkedMarker.png");
	Texture* yellow_marker = new Texture("./Graphics/Cells/Yellow/Marker.png");

	entities.push_back(new Cube(blank));

	Scene::Init(program, Camera(Vector3(0.0f, 0.0f, 10.0f),
								Vector3(0.0f, 0.0f, 0.0f),
								Vector3(0.0f, 1.0f, 0.0f),
								74.0f,
								(float)GetWidth() / (float)GetHeight(),
								1.0f,
								100.0f));
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
