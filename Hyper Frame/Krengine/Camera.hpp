#ifndef Camera_hpp
#define Camera_hpp

#include "Maths.hpp"

namespace Krengine
{
	/// <summary>Represents a camera in the world.</summary>
	struct Camera
	{
		public:
			/// <summary>The position of the <see cref="Camera" /> in the world.</summary>
			Vector3 Position;

			/// <summary>The point that the <see cref="Camera" /> will look at.</summary>
			Vector3 Target;

			/// <summary>A unit vector that determines which direction the <see cref="Camera" /> treats as 'up'.</summary>
			Vector3 Up;

			/// <summary>The field of view of the <see cref="Camera" />.</summary>
			float FovY;

			/// <summary>The aspect ratio of the <see cref="Camera" />.</summary>
			float Aspect;

			/// <summary>The near clipping plane of the <see cref="Camera" />.</summary>
			float ZNear;

			/// <summary>The far clipping plane of the <see cref="Camera" />.</summary>
			float ZFar;

			/// <summary>The calculated view matrix (<see cref="Update" /> must be called first).</summary>
			Matrix4 View;

			/// <summary>The calculated projection matrix (<see cref="Update" /> must be called first).</summary>
			Matrix4 Projection;

			/// <summary>Initialises a new instance of the <see cref="Camera" /> struct.</summary>
			Camera();

			/// <summary>Initialises a new instance of the <see cref="Camera" /> struct.</summary>
			/// <param name="position">The <see cref="Position" /> of the <see cref="Camera" /> in the world.</param>
			/// <param name="target">The <see cref="Target" /> of the <see cref="Camera" />.</param>
			/// <param name="up">The direction that the <see cref="Camera" /> treats as <see cref="Up" />.</param>
			/// <param name="fovY">The <see cref="FovY" /> of the <see cref="Camera" />.</param>
			/// <param name="aspect">The <see cref="Aspect" /> of the <see cref="Camera" />.</param>
			/// <param name="zNear">The <see cref="ZNear" /> of the <see cref="Camera" />.</param>
			/// <param name="zFar">The <see cref="ZFar" /> of the <see cref="Camera" />.</param>
			Camera(Vector3 position, Vector3 target, Vector3 up, float fovY, float aspect, float zNear, float zFar);

			/// <summary>Updates the <see cref="View" /> and <see cref="Projection" /> matrices.</summary>
			void Update();
	};
}

#endif
