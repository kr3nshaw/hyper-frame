#include "Scene.hpp"
#include "Program.hpp"
#include "Entity.hpp"
#include "Texture.hpp"
#include "Camera.hpp"
#include "Maths.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <GL/glew.h>

namespace Krengine
{
	Scene::Scene(int width, int height) : width(width), height(height)
	{
		//
	}

	Scene::~Scene()
	{
		glUseProgram(0);

		for (Entity* entity : entities)
		{
			glDisableVertexAttribArray(position);

			glDeleteBuffers(1, &entity->elementBuffer);
			glDeleteBuffers(1, &entity->vertexBuffer);
			glDeleteVertexArrays(1, &entity->vertexArray);

			delete entity;
		}

		delete program;
	}

	void Scene::Init(Program* program, Camera camera)
	{
		this->program = program;
		this->camera = camera;

		this->program->Init();

		for (Entity* entity : entities)
		{
			entity->Init();

			glGenVertexArrays(1, &entity->vertexArray);
			glBindVertexArray(entity->vertexArray);

			glGenBuffers(1, &entity->vertexBuffer);
			glBindBuffer(GL_ARRAY_BUFFER, entity->vertexBuffer);
			glBufferData(GL_ARRAY_BUFFER, entity->GetVerticesCount() * sizeof(float), entity->GetVertices(), GL_STATIC_DRAW);

			glGenBuffers(1, &entity->elementBuffer);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, entity->elementBuffer);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, entity->GetElementsCount() * sizeof(int), entity->GetElements(), GL_STATIC_DRAW);

			position = glGetAttribLocation(this->program->GetProgram(), "Pos");
			glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
			glEnableVertexAttribArray(position);

			texture = glGetAttribLocation(this->program->GetProgram(), "tex");
			glVertexAttribPointer(texture, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(GL_FLOAT)));
			glEnableVertexAttribArray(texture);

			entity->GetTexture()->Init();
		}
	}

	void Scene::Update()
	{
		camera.Update();
	}

	void Scene::Draw()
	{
		glUseProgram(this->program->GetProgram());

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		projection = glGetUniformLocation(this->program->GetProgram(), "Projection");
		glUniformMatrix4fv(projection, 1, GL_FALSE, value_ptr(camera.Projection));

		view = glGetUniformLocation(this->program->GetProgram(), "View");
		glUniformMatrix4fv(view, 1, GL_FALSE, value_ptr(camera.View));

		for (Entity* entity : entities)
		{
			Matrix4 Model;
			Model = glm::translate(Model, entity->position);
			Model *= glm::rotate(Model, entity->rotation.x, Vector3(1.0f, 0.0f, 0.0f));
			Model *= glm::rotate(Model, entity->rotation.y, Vector3(0.0f, 1.0f, 0.0f));
			Model *= glm::rotate(Model, entity->rotation.z, Vector3(0.0f, 0.0f, 1.0f));
			Model *= glm::scale(Model, entity->scale);
			model = glGetUniformLocation(this->program->GetProgram(), "Model");
			glUniformMatrix4fv(model, 1, GL_FALSE, value_ptr(Model));

			glBindVertexArray(entity->vertexArray);
			glBindTexture(GL_TEXTURE_2D, entity->GetTexture()->GetTexture());
			glDrawElements(GL_TRIANGLES, entity->GetElementsCount(), GL_UNSIGNED_INT, 0);
		}
	}

	int Scene::GetWidth()
	{
		return width;
	}

	int Scene::GetHeight()
	{
		return height;
	}

	Scene* Scene::GetNextScene()
	{
		return nextScene;
	}
}
