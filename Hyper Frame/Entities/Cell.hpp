#ifndef Cell_hpp
#define Cell_hpp

#include "../Krengine/Entity.hpp"
#include "../Krengine/Texture.hpp"
#include "../Krengine/Maths.hpp"

using namespace Krengine;

class Cell : public Entity
{
	public:
		Cell(Vector3 face, int size, int dimension, Vector2 gridPosition, Texture* texture);
		void Init();
};

#endif
