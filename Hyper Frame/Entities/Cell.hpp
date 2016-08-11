#ifndef Cell_hpp
#define Cell_hpp

#include "../Krengine/Entity.hpp"
#include "../Krengine/Maths.hpp"
#include "../Krengine/Texture.hpp"

using namespace Krengine;

class Cell : public Entity
{
	public:
		Cell(Vector3 face, int size, int dimension, Vector2 gridPosition, Texture* texture);
		void Init();

		Vector3 GetFace();
		Vector2 GetGridPosition();
		void SetTexture(Texture* texture);

	private:
		Vector3 face;
		Vector2 gridPosition;
};

#endif
