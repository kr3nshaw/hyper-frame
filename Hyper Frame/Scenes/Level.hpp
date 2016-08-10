#ifndef Level_hpp
#define Level_hpp

#include "../Krengine/Scene.hpp"

using namespace Krengine;

class Level : public Scene
{
	public:
		Level(int width, int height);
		void Init();
		void Update();
		void Draw();
};

#endif
