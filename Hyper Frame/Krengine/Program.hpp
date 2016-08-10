#ifndef Program_hpp
#define Program_hpp

#include "Shader.hpp"
#include <GL/glew.h>

namespace Krengine
{
	class Program
	{
		public:
			Program(Shader* vertexShader, Shader* fragmentShader);
			~Program();
			void Init();

			GLuint GetProgram();

		private:
			Shader* vertexShader = nullptr;
			Shader* fragmentShader = nullptr;
			bool created = false;

			GLuint program;
	};
}

#endif
