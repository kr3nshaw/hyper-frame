#include "Scenes/Level.hpp"
#include "Krengine/Game.hpp"

using namespace Krengine;

int main(int argc, char* argv[])
{
	const int width = 640;
	const int height = 480;

	Game game("Hyper Frame", width, height, new Level(width, height));

	return 0;
}
