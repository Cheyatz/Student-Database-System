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
		
		// GETTERS
		std::vector<Student> getStudents();
		Student* getCurrentStudent() const;

		// SETTERS
		void setCurrentStudent(Student* const p_student);

		// DEBUG METHODS
		void sayCurrentStudentName();
	
	private:
		Student* m_currentStudent;
		std::vector<Student> m_students;
		std::map<std::string , std::string> m_props;
};

#endif
