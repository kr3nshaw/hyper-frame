#ifndef Shader_hpp
#define Shader_hpp

#include <GL/glew.h>

namespace Krengine
{
	enum ShaderType
	{
		Vertex,
		Fragment
	};

	/// <summary>Represents a shader.</summary>
	class Shader
	{
		public:
			/// <summary>Initialises a new instance of the <see cref="Shader" /> class.</summary>
			/// <param name="fromFile">Specifies whether the shader data exists in an external file or is hard-coded.</param>
			/// <param name="type">The type of shader.</param>
			/// <param name="data">A C-style string that contains the path to the file if the shader data exists in an external file, or the shader data if it is hard-coded.</param>
			Shader(bool fromfile, ShaderType type, const char* data);

			/// <summary>Frees the memory allocated for the <see cref="Shader" /> data, and calls OpenGL cleanup functions.</summary>
			~Shader();

			/// <summary>Contains any instructions that can not be called in the constructor.</summary>
			void Init();

			/// <summary>Gets the internal identifier of the shader as provided by OpenGL.</summary>
			GLuint GetShader();

		private:
			bool fromFile;
			ShaderType type;
			char* data = nullptr;
			bool created = false;

			GLuint shader;
	};
}

#endif
