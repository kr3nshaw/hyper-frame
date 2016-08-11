#include "Camera.hpp"
#include "Entity.hpp"
#include "Input.hpp"
#include "Maths.hpp"
#include "Program.hpp"
#include "Scene.hpp"
#include "Texture.hpp"
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>

using namespace glm;

namespace Krengine
{
	Scene::~Scene()
	{
		glUseProgram(0);

		for (Entity* entity : entities)
		{
			glDisableVertexAttribArray(position);

			glDeleteBuffers(1, &entity->ElementBuffer);
			glDeleteBuffers(1, &entity->VertexBuffer);
			glDeleteVertexArrays(1, &entity->VertexArray);

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

			glGenVertexArrays(1, &entity->VertexArray);
			glBindVertexArray(entity->VertexArray);

			glGenBuffers(1, &entity->VertexBuffer);
			glBindBuffer(GL_ARRAY_BUFFER, entity->VertexBuffer);
			glBufferData(GL_ARRAY_BUFFER, entity->GetVerticesCount() * sizeof(float), entity->GetVertices(), GL_STATIC_DRAW);

			glGenBuffers(1, &entity->ElementBuffer);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, entity->ElementBuffer);
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
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		projection = glGetUniformLocation(this->program->GetProgram(), "Projection");
		glUniformMatrix4fv(projection, 1, GL_FALSE, value_ptr(camera.Projection));

		view = glGetUniformLocation(this->program->GetProgram(), "View");
		glUniformMatrix4fv(view, 1, GL_FALSE, value_ptr(camera.View));

		for (Entity* entity : entities)
		{
			Model = translate(Matrix4(), entity->Position);
			Model *= rotate(Model, entity->Rotation.z, Vector3(0.0f, 0.0f, 1.0f));
			Model *= rotate(Model, entity->Rotation.y, Vector3(0.0f, 1.0f, 0.0f));
			Model *= rotate(Model, entity->Rotation.x, Vector3(1.0f, 0.0f, 0.0f));
			Model *= scale(Model, entity->Scale);
			model = glGetUniformLocation(this->program->GetProgram(), "Model");
			glUniformMatrix4fv(model, 1, GL_FALSE, value_ptr(Model));

			glBindVertexArray(entity->VertexArray);
			glBindTexture(GL_TEXTURE_2D, entity->GetTexture()->GetTexture());
			glDrawElements(GL_TRIANGLES, entity->GetElementsCount(), GL_UNSIGNED_INT, 0);
		}
	}

	Entity* Scene::GetEntityUnderMouse()
	{
		return nullptr;
	}

	Scene* Scene::GetNextScene()
	{
		return nextScene;
	}
}
