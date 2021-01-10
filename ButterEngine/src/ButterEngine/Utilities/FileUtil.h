#pragma once


#include <fstream>

namespace Butter
{
	class BUTTER_API FileUtil
	{
	public:
		std::fstream fileStream;


		bool OpenFile(std::string* filePath, std::string* fileText);

		bool OpenFile(std::string* filePath, std::vector<std::string>* fileLines);
	};

}


