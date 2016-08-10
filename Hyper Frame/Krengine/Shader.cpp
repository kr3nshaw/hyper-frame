#include "Shader.hpp"
#include "Game.hpp"
#include <GL/glew.h>
#include <cstdio>
#include <cstdlib>

namespace Krengine
{
	Shader::Shader(bool fromFile, ShaderType type, const char* data) : type(type)
	{
		if (!fromFile)
		{
			this->data = const_cast<char*>(data);
		}
		else
		{
			FILE* file = fopen(data, "r");

			fseek(file, 0, SEEK_END);
			long fileSize = ftell(file);
			rewind(file);

			this->data = (char*)malloc((fileSize + 1) * sizeof(char));

			fread(this->data, sizeof(char), fileSize, file);
			this->data[fileSize] = '\0';

			fclose(file);
		}
	}

	Shader::~Shader()
	{
		if (created)
		{
			glDeleteShader(shader);
		}

		if (fromFile)
		{
			free(data);
		}
	}

	void Shader::Init()
	{
		if (!created)
		{
			switch (type)
			{
				case Vertex:
					shader = glCreateShader(GL_VERTEX_SHADER);

					break;

				case Fragment:
					shader = glCreateShader(GL_FRAGMENT_SHADER);

					break;
			}

			glShaderSource(shader, 1, &data, nullptr);
			glCompileShader(shader);

			int logLength;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);

			if (logLength > 0)
			{
				char* log = (char*)malloc(logLength);
				glGetShaderInfoLog(shader, logLength, &logLength, log);

				Game::Log(log);
				
				free(log);
			}
			
			created = true;
		}
	}

	GLuint Shader::GetShader()
	{
		return shader;
	}
}
