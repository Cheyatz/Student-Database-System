#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Student.hpp"
#include "Utils.hpp"

class Database {
	public:
		Database();
		bool openDatabase(std::string p_db);
		void createDatabase(std::string p_db_create);
		std::vector<Student> getStudents();
	
	private:
		std::vector<Student> m_students;
		std::map<std::string , std::string> m_props;
};

#endif
