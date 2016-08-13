#ifndef Level_hpp
#define Level_hpp

#include "Cell.hpp"
#include "../Krengine/Scene.hpp"
#include <unordered_map>
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
		static int cube;
		int cubeSize;
		float cameraDistance;
		vector<vector<Texture*>> cellTextures;
		int dimension;
		vector<vector<vector<Cell*>>> cells;
		vector<Cell*> markers;
		unordered_map<Cell*, vector<Cell*>> neighbours;
		bool drawing = false;
		CellColour currentColour = Special;
		unordered_map<Cell*, bool> searched;

		bool MarkersLinked(Cell* cell);
		bool markersLinked(Cell* cell);
};

#endif
