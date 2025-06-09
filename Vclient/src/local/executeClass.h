#ifndef EXECUTE_CLASS_H
#define EXECUTE_CLASS_H
#include<fstream>
#include<sstream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <windows.h>

class Execute
{
public:
	static void file(std::string programPath);

	static void fileElevated(const std::string& programPath);

	static void command(const std::string& command);

};

#endif