#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Utils.hpp"

class Student {
	public : 
		Student(std::string p_name , std::string p_fName , std::string p_mName , char p_grade , int p_age);

		std::string getName();
		std::string getFatherName();
		std::string getMotherName();
		char getGrade();
		int getAge();

	private:
		std::string m_name;
		std::string m_fName;
		std::string m_mName;
		char m_grade;
		int m_age;

};

#endif
