#include "Camera.hpp"
#include "Maths.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <cfloat>

using namespace glm;

namespace Krengine
{
	Camera::Camera() : Position(Vector3(0.0f, 0.0f, 1.0f)),
					   Target(Vector3(0.0f, 0.0f, 0.0f)),
					   Up(Vector3(0.0f, 1.0f, 0.0f)),
					   FovY(74.0f),
					   Aspect(16.0f / 9.0f),
					   ZNear(FLT_MIN),
					   ZFar(FLT_MAX)
	{
		//
	}

	Camera::Camera(Vector3 position,
				   Vector3 target,
				   Vector3 up,
				   float fovY,
				   float aspect,
				   float zNear,
				   float zFar) : Position(position), Target(target), Up(up), FovY(fovY), Aspect(aspect), ZNear(zNear), ZFar(zFar)
	{
		//
	}

	void Camera::Update()
	{
		View = lookAt(Position, Target, Up);
		Projection = perspective(radians(FovY), Aspect, ZNear, ZFar);
	}
}
