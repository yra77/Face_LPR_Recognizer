

#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>


using namespace std;


class File_Create
{

public:

	static void CreateFolders(string desctopPath)
	{

		if (!std::filesystem::exists(desctopPath + "Foto Base Recognize"))
		{
			std::filesystem::create_directories(desctopPath + "Foto Base Recognize/Recognize Base");
			std::filesystem::create_directories(desctopPath + "Foto Base Recognize/Foto Base");
			std::filesystem::create_directories(desctopPath + "Foto Base Recognize/Human Base");
			std::filesystem::create_directories(desctopPath + "Foto Base Recognize/Data_Base_Text");

			ofstream ofStream(desctopPath + "Foto Base Recognize/Data_Base_Text/Base.txt");
			ofStream.close();
		}

		if (!std::filesystem::exists(desctopPath + "Auto Base"))
		{
			std::filesystem::create_directories(desctopPath + "Auto Base");
		}
	}

};

