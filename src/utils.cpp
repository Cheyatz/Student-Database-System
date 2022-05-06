#include "Utils.hpp"

char* getCurrentTime() {
	time_t now = std::time(0);
	char* time = std::ctime(&now);
	return time;
}

void clear() {
	for(int clr_c = 0 ; clr_c < 100 ; clr_c++) {
		std::cout << std::endl;
	}
}

Exception::Exception(const char* p_exp) {
	exp = p_exp;
}


// Check if path exists
bool isPathExist(const std::string &s) {
  struct stat buffer;
  return (stat (s.c_str(), &buffer) == 0);
}

namespace Parser {
	//
	// @return
	// std::map<std::string , std::string>
	//
	std::map<std::string , std::string> loadConfig(std::string p_configPath) {

		std::fstream file;
		file.open(p_configPath);

		if(!file.good())
			throw std::invalid_argument("Couldn't Open the file");

		std::string line;
		std::map<std::string , std::string> props;

		while(std::getline(file, line)) {
			// If the first letter is whitespace
			// Skip the line
			if(line[0] == ' ' || !line[0]) 
				continue;

			std::string property;
			std::string value;
			bool isProperty = true;

			// Map over every character
			for ( auto chr : line ) {
				// Change to value mode if equal sign is found
				if(chr == '=') {
					isProperty = false;
					continue;
				}

				if(isProperty) 
					property += chr;
				else 
					value += chr;
			}

			// Assign the property map
			props[property] = value;
		}

		return props;
	}

	// Parses comma seperated values to a vector of strings
	// @used_here : to convert students from config file to list
	std::vector<std::string> parseCSV(std::string p_unparsedString) {

		std::vector<std::string> studentList;
		std::string name = "";

		for ( char chr : p_unparsedString ) {
			if(chr == ',' || chr == '\0') {
				studentList.push_back(name);
				name = "";
				continue;
			}
			name += chr;
		}

		studentList.push_back(name);
		return studentList;
	}
}
