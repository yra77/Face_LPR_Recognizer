
#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;


class File_W
{

public:

	static void Auto_To_File(std::string& str, std::string desckTop_Path)
	{

		std::wofstream writeFile;

		time_t now = time(0);
		tm* timeNow = localtime(&now);

		std::string tm = std::to_string(timeNow->tm_mday) + "." + std::to_string(timeNow->tm_mon + 1) 
			              + " " + std::to_string(timeNow->tm_hour) + "." + std::to_string(timeNow->tm_min) 
			              + "." + std::to_string(timeNow->tm_sec);

		std::string fileName = desckTop_Path + "Auto Base/" + tm + ".csv";

		writeFile.open(fileName);

		if (writeFile.is_open())
		{
			writeFile << str.c_str();
			writeFile.close();

			MessageBox(0, L"File Write!", L"", MB_OK | MB_ICONINFORMATION | MB_APPLMODAL);
		}
		else
			MessageBox(0, L"File not write!", L"", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	}


	static bool Write_TXT(string path, string text)
	{
		std::wofstream fileWrite;
		fileWrite.open(path, std::ios_base::app);

		if (fileWrite.is_open())
		{
			string probel = " ";
			string n = "\n";
			string buf = text + n;

			fileWrite << buf.c_str();

			fileWrite.close();

			return true;
		}

		return false;
	}

	static void Write_PNG(string path, Mat img)
	{
		imwrite(path, img);
	}

};

