#ifndef Camera_hpp
#define Camera_hpp

#include "Maths.hpp"

namespace Krengine
{
	struct Camera
	{
		public:
			Vector3 Position;
			Vector3 Target;
			Vector3 Up;

			float FovY;
			float Aspect;
			float ZNear;
			float ZFar;

			Matrix4 View;
			Matrix4 Projection;

			Camera();
			Camera(Vector3 position, Vector3 target, Vector3 up, float fovY, float aspect, float zNear, float zFar);
			void Update();
	};
}

#endif
