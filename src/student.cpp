#include "Student.hpp"

/*
		std::string m_name;
		std::string m_fName;
		std::string m_mName;
		char m_grade;
		int m_age;
 */

Student::Student(std::string p_name , std::string p_fName , std::string p_mName , char p_grade , int p_age) {
	m_name = p_name;
	m_fName = p_fName;
	m_mName = p_mName;
	m_grade = p_grade;
	m_age = p_age;
}


// GETTERS
std::string Student::getName() { return m_name; } 
std::string Student::getFatherName() { return m_fName; }
std::string Student::getMotherName() { return m_mName; }
char Student::getGrade() { return m_grade; }
int Student::getAge() { return m_age; }
