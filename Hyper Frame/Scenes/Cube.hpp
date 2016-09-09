#ifndef Cube_hpp
#define Cube_hpp

#include "../Entities/Cell.hpp"
#include "../Krengine/Scene.hpp"
#include <unordered_map>
#include <vector>

using namespace Krengine;
using namespace std;

class Cube : public Scene
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
		unordered_map<Cell*, bool> blankSearched;
		Entity* entity = nullptr;
		bool drawing = false;
		CellColour currentColour = Special;

		bool MarkersLinked(Cell* cell);
};

#endif
