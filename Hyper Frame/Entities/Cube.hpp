#ifndef Cube_hpp
#define Cube_hpp

#include "../Krengine/Entity.hpp"
#include "../Krengine/Texture.hpp"

using namespace Krengine;

class Cube : public Entity
{
	public:
		Cube(Texture* texture);
		void Init();

	private:
		Texture* texture;
};

#endif
