#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "ButterEngine/Core/Core.h"
#include "ButterEngine/Core/DataTypes.h"
#include "btrpch.h"


namespace Butter
{
	class BUTTER_API BoundingBox
	{


	public:

		BoundingBox(Vector3 center, Vector3 dimensions);
		//BoundingBox(Vector3 min, Vector3 max);

		Vector3 Center;
		Vector3 Dimensions;
		Vector3 Radius;

		Vector3 Min;
		Vector3 Max;

		bool ContainsPoint(Vector3 point);
		bool ContainsBounds(BoundingBox bounds);
		bool IntersectsBounds(BoundingBox bounds);

		bool operator==(BoundingBox bounds);

	private:


	};
}

#endif