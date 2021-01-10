#include "btrpch.h"
#include "ButterEngine/Core/Transform.h"

namespace Butter
{
	Transform::Transform()
	{
		Position	= Vector3(0.0, 0.0, 0.0);
		Rotation	= Vector3(0.0, 0.0, 0.0);
		Scale		= Vector3(1.0, 1.0, 1.0);
	}

	Vector3 Transform::GetPosition()
	{
		return Position;
	}

	Vector3 Transform::GetRotation()
	{
		return Rotation;
	}

	Vector3 Transform::GetScale()
	{
		return Scale;
	}
}

