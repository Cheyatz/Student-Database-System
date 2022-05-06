#ifndef UTILS_HPP
#define UTILS_HPP

#include <ctime>
#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <sys/stat.h>

char* getCurrentTime();
void clear();
bool isPathExist(const std::string &s);

namespace Parser {
	std::map<std::string , std::string> loadConfig(std::string p_configPath);
	std::vector<std::string> parseCSV(std::string p_unparsedString);
}

struct Exception {
	const char* exp;
	Exception(const char* p_exp );
};

#endif
