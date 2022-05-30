
#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <minwindef.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <Commdlg.h>
#include <windows.h>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;


class File_R
{
public:

	static string Get_Desctop_Path()
	{
		string desctopPath;
		string userprofile = getenv("USERPROFILE");

		if (!userprofile.empty())
		{
			return desctopPath = userprofile + "/Desktop/";
		}

		return "";
	}


	static string Path_To_Folder()
	{
		char dir_Path[MAX_PATH];
		string path_EXE;
		string bad_Path;
		//»щем папку с ехе и обрезаем сам ехе
		GetModuleFileNameA(NULL, dir_Path, MAX_PATH);

		path_EXE = dir_Path;
		string::size_type iLastSlash = path_EXE.find_last_of("\\/");

		if (string::npos != iLastSlash)
		{
			path_EXE.erase(iLastSlash, numeric_limits<string::size_type>::max());
			path_EXE = path_EXE + "/";

			string copyFolder = path_EXE + "install_OpenCV/";

			if (!filesystem::exists("C:/install_OpenCV"))
				filesystem::copy(copyFolder, "C:/install_OpenCV/", filesystem::copy_options::overwrite_existing 
					                                               | filesystem::copy_options::recursive);

			return path_EXE;
		}

		return bad_Path;
	}


	static bool Read_TXT(string path, vector<string>& arrays, int &count)
	{
		ifstream fileRead;
		fileRead.open(path);

		if(!fileRead.is_open())
		{
		  return false;
		}

		while (!fileRead.eof())
		{
			arrays.resize(arrays.size() + 1);
			fileRead >> arrays[count];
			count++;
		}

		fileRead.close();
		
		return true;
	}


	static void Read_Png_Folder(string folder, vector<string>& filenames)
	{
		cv::glob(folder, filenames, false);
	}


	static Mat Read_Png_Grey(string filename)
	{
		return imread(filename, IMREAD_GRAYSCALE);
	}


	static Mat Read_Png_Color(string filename)
	{
		return imread(filename, IMREAD_COLOR);
	}


	static bool OpenFileDialog(LPCWSTR fileType, string& fileName)
	{

		OPENFILENAME ofn = { 0 };
		TCHAR szFile[260] = { 0 };

		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFile;
		ofn.nMaxFile = sizeof(szFile);
		ofn.lpstrFilter = fileType;
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (GetOpenFileName(&ofn) == TRUE)
		{
			std::wstring arr_w(szFile);
			fileName = std::string(arr_w.begin(), arr_w.end());

			return true;
		}
		else
		{
			return false;
		}
	}  

};