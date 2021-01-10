#pragma once
#include "ButterEngine/Core/Core.h"
#include "ButterEngine/Core/DataTypes.h"
#include "ButterEngine/Utilities/FileUtil.h"
#include <fstream>
#include <ostream>

namespace Butter
{
	struct ObjData
	{

		std::vector<Vector3> vertices;
		std::vector<Vector2> uvs;
		std::vector<Vector3> normals;
		bool useSmoothShading;

	};

	class BUTTER_API ObjLoader
	{
	public:


		bool Load(std::string * filePath, ObjData * objData);

	};
}

