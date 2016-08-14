#ifndef Cell_hpp
#define Cell_hpp

#include "../Krengine/Entity.hpp"
#include "../Krengine/Maths.hpp"
#include "../Krengine/Texture.hpp"
#include <vector>

using namespace Krengine;
using namespace std;

enum CellColour
{
	Special,
	Red,
	Orange,
	Yellow,
	Green,
	LightBlue,
	DarkBlue,
	Purple,
};

enum CellType
{
	Marker,
	CurrentMarker,
	LinkedMarker,
	Link
};

const CellType Blank = Marker;
const CellType Blocked = CurrentMarker;

class Cell : public Entity
{
	public:
		Cell(Vector3 face, Vector2 gridPosition, CellColour colour, CellType type, vector<vector<Texture*>>* cellTextures, int size, int dimension);
		void Init();

		Vector3 GetFace();
		Vector2 GetGridPosition();
		CellColour GetColour();
		CellType GetType();
		void SetCell(CellColour colour, CellType type);

	private:
		Vector3 face;
		Vector2 gridPosition;
		CellColour colour;
		CellType type;
		vector<vector<Texture*>>* cellTextures;

};

#endif
