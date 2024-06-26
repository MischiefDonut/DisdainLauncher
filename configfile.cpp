#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <filesystem>
#include "launcher.h"

#ifdef _WIN32
	#include <windows.h>
	#include <shlobj.h>
#elif __APPLE__
	#include <unistd.h>
	#include <sys/types.h>
	#include <pwd.h>
#endif

std::string get_config_path()
{
	std::string path;
	#ifdef _WIN32
		char appdata[MAX_PATH];
		SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, appdata);
		path = std::string(appdata) + "\\HoNLauncher\\";
	#elif __APPLE__
		struct passwd *pw = getpwuid(getuid());
		path = std::string(pw->pw_dir) + "/Library/Preferences/HoNLauncher/";
	#else
		path = std::string(getenv("HOME")) + "/.config/HoNLauncher/";
	#endif
	return path;
}
std::string get_config_filename()
{
	return "Launcher.ini";
}

namespace fs = std::filesystem;

void save_options(std::string option1, std::string option2)
{
	std::string path = get_config_path();

	if (!fs::is_directory(path) || !fs::exists(path)) // Check if src folder exists
	{
		fs::create_directory(path); // create src folder
	}
	if (fs::exists(path) && !fs::is_directory(path))
	{
		std::cout << "Unable to make folder" << std::endl;
		return;
	}

	path += get_config_filename();

	std::ofstream config_file(path);

	if (config_file.is_open())
	{
		config_file << "Language=" << option1.c_str() << "\n";
		config_file << "VidMode=" << option2.c_str() << "\n";
		config_file.close();
	}
	else
	{
		std::cout << "Unable to open file - " << path << std::endl;
	}
}

std::map<std::string, std::string> load_options()
{
	std::map<std::string, std::string> options;
	std::ifstream config_file(get_config_path() + get_config_filename());
	if (config_file.is_open())
	{
		std::string line;
		while (getline(config_file, line))
		{
			auto delimiter_pos = line.find("=");
			auto name = line.substr(0, delimiter_pos);
			auto value = line.substr(delimiter_pos + 1);
			options[name] = value;
		}
		config_file.close();
	}
	else
	{
		std::cout << "Unable to open file" << std::endl;
	}
	return options;
}
