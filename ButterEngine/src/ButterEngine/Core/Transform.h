#pragma once
#include "ButterEngine/Core/Core.h"
#include "ButterEngine/Core/DataTypes.h"

namespace Butter
{
	class Transform
	{
	public:
		Transform();
		virtual ~Transform() = default;

		Vector3 GetPosition();
		Vector3 GetRotation();
		Vector3 GetScale();

		//void SetPosition();
		//void SetRotation();
		//void SetScale();

	private:
		Vector3 Position = Vector3();
		Vector3 Rotation = Vector3();
		Vector3 Scale = Vector3();
	};
}