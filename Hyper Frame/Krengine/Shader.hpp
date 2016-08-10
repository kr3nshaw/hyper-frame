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

	class Shader
	{
		public:
			Shader(bool fromfile, ShaderType type, const char* data);
			~Shader();
			void Init();

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
