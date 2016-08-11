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
		delete picking;
	}

	void Scene::Init(Program* program, Camera camera)
	{
		picking = new Program(new Shader(true, Vertex, "./Shaders/picking.vert"), new Shader(true, Fragment, "./Shaders/picking.frag"));
		picking->Init();

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
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(program->GetProgram());

		projection = glGetUniformLocation(program->GetProgram(), "Projection");
		glUniformMatrix4fv(projection, 1, GL_FALSE, value_ptr(camera.Projection));

		view = glGetUniformLocation(program->GetProgram(), "View");
		glUniformMatrix4fv(view, 1, GL_FALSE, value_ptr(camera.View));

		for (Entity* entity : entities)
		{
			glBindVertexArray(entity->VertexArray);
			glBindBuffer(GL_ARRAY_BUFFER, entity->VertexBuffer);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, entity->ElementBuffer);

			position = glGetAttribLocation(program->GetProgram(), "Pos");
			glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
			glEnableVertexAttribArray(position);

			texture = glGetAttribLocation(this->program->GetProgram(), "tex");
			glVertexAttribPointer(texture, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(GL_FLOAT)));
			glEnableVertexAttribArray(texture);

			Model = translate(Matrix4(), entity->Position);
			Model *= rotate(Model, entity->Rotation.z, Vector3(0.0f, 0.0f, 1.0f));
			Model *= rotate(Model, entity->Rotation.y, Vector3(0.0f, 1.0f, 0.0f));
			Model *= rotate(Model, entity->Rotation.x, Vector3(1.0f, 0.0f, 0.0f));
			Model *= scale(Model, entity->Scale);
			model = glGetUniformLocation(program->GetProgram(), "Model");
			glUniformMatrix4fv(model, 1, GL_FALSE, value_ptr(Model));

			glBindTexture(GL_TEXTURE_2D, entity->GetTexture()->GetTexture());

			glDrawElements(GL_TRIANGLES, entity->GetElementsCount(), GL_UNSIGNED_INT, 0);
		}
	}

	Entity* Scene::GetEntityUnderMouse()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(picking->GetProgram());

		projection = glGetUniformLocation(picking->GetProgram(), "Projection");
		glUniformMatrix4fv(projection, 1, GL_FALSE, value_ptr(camera.Projection));

		view = glGetUniformLocation(picking->GetProgram(), "View");
		glUniformMatrix4fv(view, 1, GL_FALSE, value_ptr(camera.View));

		for (int i = 0; i < entities.size(); ++i)
		{
			glBindVertexArray(entities[i]->VertexArray);
			glBindBuffer(GL_ARRAY_BUFFER, entities[i]->VertexBuffer);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, entities[i]->ElementBuffer);

			position = glGetAttribLocation(picking->GetProgram(), "Pos");
			glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
			glEnableVertexAttribArray(position);

			Model = translate(Matrix4(), entities[i]->Position);
			Model *= rotate(Model, entities[i]->Rotation.z, Vector3(0.0f, 0.0f, 1.0f));
			Model *= rotate(Model, entities[i]->Rotation.y, Vector3(0.0f, 1.0f, 0.0f));
			Model *= rotate(Model, entities[i]->Rotation.x, Vector3(1.0f, 0.0f, 0.0f));
			Model *= scale(Model, entities[i]->Scale);
			model = glGetUniformLocation(picking->GetProgram(), "Model");
			glUniformMatrix4fv(model, 1, GL_FALSE, value_ptr(Model));

			glProgramUniform1i(picking->GetProgram(), glGetUniformLocation(picking->GetProgram(), "Code"), i + 1);

			glDrawElements(GL_TRIANGLES, entities[i]->GetElementsCount(), GL_UNSIGNED_INT, 0);
		}

		unsigned char id[4];
		GLint viewport[4];

		glGetIntegerv(GL_VIEWPORT, viewport);
		glReadPixels(Input::GetMouseX(), viewport[3] - Input::GetMouseY(), 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &id);

		if (id[0] > 0)
		{
			return entities[id[0] - 1];
		}

		return nullptr;
	}

	Scene* Scene::GetNextScene()
	{
		return nextScene;
	}
}
