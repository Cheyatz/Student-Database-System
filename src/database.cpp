#include "Database.hpp"

// temp constants
std::string const CONFIG_FILE_NAME = "config.cfg";
std::string const DATABASE_FOLDER = "db";

Database::Database() {
	m_currentStudent = nullptr;
}

// DEBUG METHODS
void Database::sayCurrentStudentName() {
	std::cout << m_currentStudent->getName() << std::endl;
}

// GETTERS
std::vector<Student> Database::getStudents() { return m_students; }
Student* Database::getCurrentStudent() const { return m_currentStudent; }

// SETTERS
void Database::setCurrentStudent(Student* const p_student) { m_currentStudent = p_student; }

bool Database::openDatabase(std::string p_db) {
	try {
		struct stat buffer;

		std::string dbPath = DATABASE_FOLDER + "/" + p_db;
		std::string configPath = dbPath + "/" + CONFIG_FILE_NAME;

		if(!isPathExist(dbPath)) {
			// Directory doesn't exist
			std::cout << "PATH : " << dbPath << std::endl;
			throw Exception("PATH DOESN'T EXISTS");
		}

		// Directory exists
		// Check for config
		if(!isPathExist(configPath))
			// Config File doesn't exists
			throw Exception("Config file not found");

		// Config file also exists
		m_props = Parser::loadConfig(configPath);
		std::vector<std::string> students = Parser::parseCSV(m_props["students"]);		
		
		// Load students as Student objects
		for ( std::string studentName : students ) {
			std::ifstream studentConfigFile;
			std::string studentConfigFilePath = dbPath + "/" + studentName + ".student";
			studentConfigFile.open(studentConfigFilePath);

			if(!studentConfigFile.good())
				throw Exception(((std::string)"FAILED TO OPEN FILE OF " + studentName).c_str());
			
			// If Good
			std::map<std::string,std::string> studentProps = Parser::loadConfig(studentConfigFilePath);

			std::string const stdName = studentProps["name"];
			std::string const stdfName = studentProps["father_name"];
			std::string const stdmName = studentProps["mother_name"];
			std::string const unParsedStdmMarks = studentProps["marks"]; // In the form of n,n,n,n,n
			char const stdGrade = studentProps["grade"][0];
			int const stdAge = std::atoi((studentProps["age"]).c_str());

			// Parsing marks value into a vector
			std::vector<std::string> parsedString_stdmMarks = Parser::parseCSV(unParsedStdmMarks);
			std::vector<int> stdmMarks;
			for ( auto markInStr : parsedString_stdmMarks ) {
				stdmMarks.push_back(std::atoi(markInStr.c_str()));
				std::cout << std::atoi(markInStr.c_str()) << std::endl;
			}
			// Parsing marks value into a vector

			Student student(stdName , stdfName , stdmName , stdGrade , stdAge , stdmMarks);
			m_students.push_back(student);
		}

		return true;
	}
	catch (const Exception e) {
		std::cout << "ERROR OCCURED WHEN OPENING DATABASE : " << e.exp << std::endl;
		return false;
	}
}

void Database::createDatabase(std::string p_db_create) {
	// Create a database here
	
	std::string db_path = DATABASE_FOLDER + "/" + p_db_create;
	std::cout << "DATABASE TO CREATE : " << db_path << std::endl;
	
	if(isPathExist(db_path)) {
		std::cout << "Path already exists , cannot create a database" << std::endl;
		return;
	}

	std::cout << "Path doesn't exists , creating database" << std::endl;
	
	try {
		// Creating a directory
		if(mkdir(db_path.c_str() , 0777) == -1) {
			// Error while creating a directory
			throw Exception("Couldn't create directory");
		}

		// Directory Could be created
		// Creating a config file
		// -------------------------------------------------TODO-------------------------------------------------------
	}
	catch (Exception e) {
		std::cout << "Error occured while trying to create a database : " << p_db_create << " \n\n ERROR : " << e.exp << std::endl;
	}
}
