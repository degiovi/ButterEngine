#pragma once
#include "ButterEngine/Core/Core.h"
#include "ButterEngine/Core/Transform.h"

namespace Butter
{
	class Camera
	{
	public:

		Camera();
		Camera(glm::vec3 position, glm::vec3 lookAtVector, glm::vec3 upVector, unsigned int resolutionX, unsigned int resolutionY);

		virtual ~Camera() = default;

		void CalculateViewPlane();

		void Update();
		void CalculateView();

		int ResolutionX = 512;
		int ResolutionY = 512;

		Plane ViewPlane;

		Transform Transform;

		glm::vec3 Position;

		glm::vec3 UpVector;
		glm::vec3 RightVector;
		glm::vec3 LookAtVector;

		glm::vec3 ViewPlaneOrigin;
		float ViewPlaneHalfWidth;
		float ViewPlaneHalfHeight;


		glm::vec3 LookAtPoint;

		float FOV = 100;
		float AspectRatio;
		float ViewDistance = 50.0f;

	};
}