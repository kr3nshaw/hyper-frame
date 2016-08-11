#include "Game.hpp"
#include "Program.hpp"
#include "Shader.hpp"
#include <GL/glew.h>
#include <cstdlib>

namespace Krengine
{
	Program::Program(Shader* vertexShader, Shader* fragmentShader) : vertexShader(vertexShader), fragmentShader(fragmentShader)
	{
		//
	}

	Program::~Program()
	{
		if (created)
		{
			glDetachShader(program, fragmentShader->GetShader());
			glDetachShader(program, vertexShader->GetShader());

			glDeleteProgram(program);
		}

		delete fragmentShader;
		delete vertexShader;
	}

	void Program::Init()
	{
		if (!created)
		{
			program = glCreateProgram();

			vertexShader->Init();
			fragmentShader->Init();

			glAttachShader(program, vertexShader->GetShader());
			glAttachShader(program, fragmentShader->GetShader());

			glLinkProgram(program);

			int logLength;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);

			if (logLength > 0)
			{
				char* log = (char*)malloc(logLength);
				glGetProgramInfoLog(program, logLength, &logLength, log);

				Game::Log(log);

				free(log);
			}

			created = true;
		}
	}

	GLuint Program::GetProgram()
	{
		return program;
	}
}
