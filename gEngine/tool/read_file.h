#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

static std::string readFile(const char* filePath)
{
	std::ifstream inFile(filePath);
	if (!inFile.is_open())
	{
		std::cout << "ÎÄ±¾ " << filePath << " ´ò¿¨Ê§°Ü " << std::endl;
	}
	std::stringstream ss;
	ss << inFile.rdbuf();
	return ss.str();
}