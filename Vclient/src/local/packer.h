#ifndef PACKER_CLASS_H
#define PACKER_CLASS_H
#include<fstream>
#include<sstream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <windows.h>
#include <iomanip>
#include <vector>
class packer
{
public:
	// contents function to write binary data to a file
	static void write(const std::string& path, const unsigned char* data, size_t size);

	// read function to read binary data from a file
	static unsigned char* read(const std::string& path, size_t& outSize);
};

#endif