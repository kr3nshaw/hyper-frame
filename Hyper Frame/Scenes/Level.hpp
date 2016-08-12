#ifndef Level_hpp
#define Level_hpp

#include "Cell.hpp"
#include "../Krengine/Scene.hpp"
#include <vector>

using namespace Krengine;
using namespace std;

class Level : public Scene
{
	public:
		void Init();
		void Update();
		void Draw();

	private:
		int cubeSize;
		float cameraDistance;
		vector<vector<Texture*>> cellTextures;
		CellColour currentColour = Special;
		bool drawing = false;
};

#endif
