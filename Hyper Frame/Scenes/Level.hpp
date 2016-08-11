#ifndef Level_hpp
#define Level_hpp

#include "../Krengine/Scene.hpp"
#include <vector>

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
		std::vector<std::vector<Texture*>> cellTextures;
};

#endif
