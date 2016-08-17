#ifndef Program_hpp
#define Program_hpp

#include "Shader.hpp"
#include <GL/glew.h>

namespace Krengine
{
	/// <summary>Represents a shader program.</summary>
	class Program
	{
		public:
			/// <summary>Initialises a new instance of the <see cref="Program" /> class.</summary>
			/// <param name="vertexShader">A pointer to the vertex shader.</param>
			/// <param name="fragmentShader">A pointer to the fragment shader.</param>
			Program(Shader* vertexShader, Shader* fragmentShader);

			/// <summary>Frees the memory allocated for the vertex <see cref="Shader" /> and the fragment <see cref="Shader" />, and calls OpenGL cleanup functions.</summary>
			~Program();

			/// <summary>Contains any instructions that can not be called in the constructor.</summary>
			void Init();

			/// <summary>Gets the internal identifier of the shader program as provided by OpenGL.</summary>
			GLuint GetProgram();

		private:
			Shader* vertexShader = nullptr;
			Shader* fragmentShader = nullptr;
			bool created = false;

			GLuint program;
	};
}

#endif
