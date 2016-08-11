#ifndef Level_hpp
#define Level_hpp

#include "../Krengine/Scene.hpp"

using namespace Krengine;

class Level : public Scene
{
	public:
		void Init();
		void Update();
		void Draw();

	private:
		int cubeSize;
		float cameraDistance;
};

#endif
