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
		glDisableVertexAttribArray(texture);
		glDisableVertexAttribArray(position);
		glDeleteBuffers(1, &elementBuffer);
		glDeleteBuffers(1, &vertexBuffer);
		glDeleteVertexArrays(1, &vertexArray);

		for (Entity* entity : entities)
		{
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

		glGenVertexArrays(1, &vertexArray);
		glBindVertexArray(vertexArray);

		glGenBuffers(1, &vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

		glGenBuffers(1, &elementBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);

		SetProgram(this->program);

		for (Entity* entity : entities)
		{
			entity->Init();
		}

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	void Scene::Update()
	{
		camera.Update();
	}

	void Scene::Draw()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUniformMatrix4fv(projection, 1, GL_FALSE, value_ptr(camera.Projection));
		glUniformMatrix4fv(view, 1, GL_FALSE, value_ptr(camera.View));

		for (Entity* entity : entities)
		{
			glBufferData(GL_ARRAY_BUFFER, entity->GetVerticesCount() * sizeof(float), entity->GetVertices(), GL_STATIC_DRAW);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, entity->GetElementsCount() * sizeof(int), entity->GetElements(), GL_STATIC_DRAW);

			Model = translate(Matrix4(), entity->Position);
			Model *= rotate(Model, entity->Rotation.z, Vector3(0.0f, 0.0f, 1.0f));
			Model *= rotate(Model, entity->Rotation.y, Vector3(0.0f, 1.0f, 0.0f));
			Model *= rotate(Model, entity->Rotation.x, Vector3(1.0f, 0.0f, 0.0f));
			Model *= scale(Model, entity->Scale);
			glUniformMatrix4fv(model, 1, GL_FALSE, value_ptr(Model));

			glBindTexture(GL_TEXTURE_2D, entity->GetTexture()->GetTexture());

			glDrawElements(GL_TRIANGLES, entity->GetElementsCount(), GL_UNSIGNED_INT, 0);
		}
	}

	Entity* Scene::GetEntityUnderMouse()
	{
		SetProgram(picking);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUniformMatrix4fv(projection, 1, GL_FALSE, value_ptr(camera.Projection));
		glUniformMatrix4fv(view, 1, GL_FALSE, value_ptr(camera.View));

		for (int i = 0; i < entities.size(); ++i)
		{
			glBufferData(GL_ARRAY_BUFFER, entities[i]->GetVerticesCount() * sizeof(float), entities[i]->GetVertices(), GL_STATIC_DRAW);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, entities[i]->GetElementsCount() * sizeof(int), entities[i]->GetElements(), GL_STATIC_DRAW);

			Model = translate(Matrix4(), entities[i]->Position);
			Model *= rotate(Model, entities[i]->Rotation.z, Vector3(0.0f, 0.0f, 1.0f));
			Model *= rotate(Model, entities[i]->Rotation.y, Vector3(0.0f, 1.0f, 0.0f));
			Model *= rotate(Model, entities[i]->Rotation.x, Vector3(1.0f, 0.0f, 0.0f));
			Model *= scale(Model, entities[i]->Scale);
			glUniformMatrix4fv(model, 1, GL_FALSE, value_ptr(Model));

			glProgramUniform1i(picking->GetProgram(), glGetUniformLocation(picking->GetProgram(), "in_code"), i + 1);

			glDrawElements(GL_TRIANGLES, entities[i]->GetElementsCount(), GL_UNSIGNED_INT, 0);
		}

		GLint viewport[4];
		glGetIntegerv(GL_VIEWPORT, viewport);

		unsigned char id[4];
		glReadPixels(Input::GetMouseX(), viewport[3] - Input::GetMouseY(), 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &id);

		SetProgram(program);

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

	void Scene::SetProgram(Program* program)
	{
		glUseProgram(program->GetProgram());

		position = glGetAttribLocation(program->GetProgram(), "in_position");
		glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
		glEnableVertexAttribArray(position);

		texture = glGetAttribLocation(program->GetProgram(), "in_texture");
		glVertexAttribPointer(texture, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(GL_FLOAT)));
		glEnableVertexAttribArray(texture);

		projection = glGetUniformLocation(program->GetProgram(), "in_projection");
		view = glGetUniformLocation(program->GetProgram(), "in_view");
		model = glGetUniformLocation(program->GetProgram(), "in_model");
	}
}
