#pragma once
#ifndef OCTREE_H
#define OCTREE_H

#include "ButterEngine/Core/Core.h"
#include "ButterEngine/ECS/ECS.h"
#include "ButterEngine/Components/BoundingBox.h"
#include <glm/glm.hpp>
#include "btrpch.h"

#include <queue>
#include <stack>

#include "ButterEngine/Utilities/List.hpp"

#define NUM_CHILDREN 8

namespace Butter
{
	namespace Octree
	{
		enum class Octant : unsigned char
		{
			O1 = 0x01,
			O2 = 0x02,
			O3 = 0x04,
			O4 = 0x08,
			O5 = 0x10,
			O6 = 0x20,
			O7 = 0x40,
			O8 = 0x80
		};

		// Calculate bounds of specified quadrant in bounding box

		void CalculateBounds(BoundingBox* out, Octant octant, BoundingBox parentBounds)
		{

		}

		class BUTTER_API Node
		{

		public:

			//Node(int depth, Vector3 position, float size);
			//~Node();

			Node* Parent;
			Node* Children[NUM_CHILDREN];

			unsigned char ActiveOctants;

			bool HasChildren = false;

			bool TreeReady = false;
			bool TreeBuilt = false;

			std::vector<BoundingBox> Objects;
			std::queue<BoundingBox> Queue;

			BoundingBox Bounds;

			//int Depth;
			//Vector3 Position;
			//float Size;

			Node();
			Node(BoundingBox bounds);
			Node(BoundingBox bounds, std::vector<BoundingBox> objectList);

			void Build();
			bool Insert(BoundingBox obj);

			void Destroy();


		};
	}
}


#endif