#include "Scenes/Level.hpp"
#include "Krengine/Game.hpp"

using namespace Krengine;

int main(int argc, char* argv[])
{
	Game game("Hyper Frame", new Level());

	return 0;
}
