#include "btrpch.h"
#include "BoundingBox.h"

namespace Butter
{
	BoundingBox::BoundingBox(Vector3 center, Vector3 dimensions) : Center(center), Dimensions(dimensions)
	{
		Min = Vector3(center.x - dimensions.x / 2, center.y - dimensions.y / 2, center.z - dimensions.z / 2);
		Max = Vector3(center.x + dimensions.x / 2, center.y + dimensions.y / 2, center.z + dimensions.z / 2);
		Radius = Vector3(Dimensions.x / 2, Dimensions.y / 2, Dimensions.z / 2);
	};

	/*
	BoundingBox::BoundingBox(Vector3 min, Vector3 max) : Min(min), Max(max)
	{

		Dimensions = Vector3(Max.x - Min.x, Max.y - Min.y, Max.z - Min.z);
		Center = Vector3(Min.x + Dimensions.x/2, Min.y + Dimensions.y/2, Min.z + Dimensions.z/2);
		Radius = Vector3(Dimensions.x / 2, Dimensions.y / 2, Dimensions.z / 2);
	};
	*/

	bool BoundingBox::operator==(BoundingBox bounds)
	{
		return Min == bounds.Min && Max == bounds.Max;
	}

	bool BoundingBox::ContainsPoint(Vector3 point)
	{
		return (point.x >= Min.x) && (point.x <= Max.x)
			&& (point.y >= Min.y) && (point.y <= Max.y)
			&& (point.z >= Min.z) && (point.z <= Max.z);
	}

	bool BoundingBox::ContainsBounds(BoundingBox bounds)
	{
		return ContainsPoint(bounds.Min) && ContainsPoint(bounds.Max);
	}

	bool BoundingBox::IntersectsBounds(BoundingBox bounds)
	{
		Vector3 dist;
		dist.x = std::abs(Center.x - bounds.Center.x);
		dist.y = std::abs(Center.y - bounds.Center.y);
		dist.z = std::abs(Center.z - bounds.Center.z);

		// Each axis
		for (int i = 0; i < 3; i++)
		{
			if (dist[i] > Radius[i] + bounds.Radius[i])
			{
				return false;
			}
		}

		return true;
	}
}