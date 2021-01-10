#include "btrpch.h"
#include "FileUtil.h"


namespace Butter
{
	bool FileUtil::OpenFile(std::string* filePath, std::string* fileText)
	{
		fileStream.open(*filePath);

		if (fileStream.is_open())
		{
			std::string line;

			for (int lines = 0; std::getline(fileStream, line); lines++)
			{
				*fileText += line;
				*fileText += "\n";
			}

			return true;

			//BTR_INFO(*fileText);
		}
		else
		{
			BTR_ERROR("File was not opened or does not exist.");
			return false;
		}

	}

	bool FileUtil::OpenFile(std::string* filePath, std::vector<std::string>* fileLines)
	{
		fileStream.open(*filePath);

		if (fileStream.is_open())
		{
			std::string line;

			for (int lines = 0; std::getline(fileStream, line); lines++)
			{
				fileLines->push_back(line); 
			}
			return true;
		}
		else
		{
			return false;
		}
	}

}



