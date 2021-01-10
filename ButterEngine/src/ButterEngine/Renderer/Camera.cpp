#include "btrpch.h"
#include "Camera.h"


namespace Butter
{
	// Default constructor
	Camera::Camera()
	{
		Position = glm::vec3(0.0f, 0.0f, 0.0f);
		//LookAtPoint = glm::vec3(0.0f, 0.0f, 10.0f);
		LookAtVector = glm::vec3(0.0f, 0.0f, 10.0f);
		UpVector = glm::vec3(0.0f, 1.0f, 0.0f);
		RightVector = glm::vec3(1.0f, 0.0f, 0.0f);
		ResolutionX = 512;
		ResolutionY = 512;

		/*
		LookAtPoint = glm::vec3(0.0f, 0.0f, 0.0f);
		Position = glm::vec3(0.0f, 0.0f, -10.0f);
		LookAtVector = glm::normalize(LookAtPoint - Position);
		UpVector = glm::vec3(0.0f, 1.0f, 0.0f);
		*/
	}

	// Constructor with parameters
	Camera::Camera(glm::vec3 position, glm::vec3 lookAtVector, glm::vec3 upVector, unsigned int resolutionX, unsigned int resolutionY)
		: Position(position), LookAtVector(lookAtVector), UpVector(upVector), ResolutionX(resolutionX), ResolutionY(resolutionY)
	{
	}

	/*
	Camera::Camera(glm::vec3 position, glm::vec3 lookAtPoint, glm::vec3 upVector, unsigned int resolutionX, unsigned int resolutionY)
		: Position(position), LookAtPoint(lookAtPoint), UpVector(upVector), ResolutionX(resolutionX), ResolutionY(resolutionY)
	{
	}
	*/

	// Called every frame to update camera and receive input
	void Camera::Update()
	{
		CalculateViewPlane();
		//CalculateView();
	}

	void Camera::CalculateView()
	{
		RightVector = glm::cross(normalize(UpVector), normalize(LookAtVector));
		UpVector = glm::cross(normalize(LookAtVector), normalize(RightVector));
	}

	void Camera::CalculateViewPlane()
	{
		//LookAtVector = LookAtPoint - Position;

		LookAtPoint = Position + LookAtVector;
		LookAtVector = glm::normalize(LookAtVector);

		//RightVector = glm::cross(LookAtVector, UpVector);
		
		//RightVector = glm::normalize(RightVector);


		AspectRatio = ResolutionY / ResolutionX;
		ViewPlaneHalfWidth = tan(FOV / 2);
		ViewPlaneHalfHeight = AspectRatio * ViewPlaneHalfWidth;

		ViewPlaneOrigin = LookAtPoint - (UpVector * ViewPlaneHalfHeight) - (RightVector * ViewPlaneHalfWidth);


		/*
		float Width = 1024;
		float Height = 768;
		float hWidth = Width / 2;
		float hHeight = Height / 2;

		// Project the LookAtVector from the Camera's Position, by the ViewDistance, to find the Center of the view plane
		Vector3 Center = Transform.GetPosition() + (LookAtVector * ViewDistance);

		// Calculate the extents of the view plane by using the Field of View and Aspect Ratio

		ViewPlane.TL.SetX(Center.GetX() - hWidth);
		ViewPlane.TL.SetY(Center.GetY() - hHeight);

		ViewPlane.TR.SetX(Center.GetX() + hWidth);
		ViewPlane.TR.SetY(Center.GetY() - hHeight);

		ViewPlane.BL.SetX(Center.GetX() - hWidth);
		ViewPlane.BL.SetY(Center.GetY() + hHeight);
		
		ViewPlane.BR.SetX(Center.GetX() + hWidth);
		ViewPlane.BR.SetY(Center.GetY() + hHeight);
		*/
	}
}