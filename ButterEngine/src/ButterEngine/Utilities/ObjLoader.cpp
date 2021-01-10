#include "btrpch.h"
#include "ObjLoader.h"

namespace Butter
{
	bool ObjLoader::Load(std::string * filePath, ObjData * objData)
	{
		FileUtil file;
		std::vector<std::string> lines;

		std::string comment = "#";
		std::string delimiter = " ";

		bool result = file.OpenFile(filePath, &lines);

		if (result == true)
		{
			for (int i = 0; i < lines.size(); i++)
			{
				
			}
		}

		/*
		FILE * file = fopen(filePath, "r");

		
		while (1)
		{
			char lineHeader[128];

			int result = std::fscanf(file, "%s", lineHeader);

			if (result = EOF)
				break;
			else
			{
				if (strcmp(lineHeader, "v") == 0)
				{
					Vector3 vertex;
					std::fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
					objData->vertices.push_back(vertex);
				}
			}
		}
		*/
	}
}