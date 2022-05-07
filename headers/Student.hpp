#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Utils.hpp"

class Student {
	public : 
		Student(std::string p_name , std::string p_fName , std::string p_mName , char p_grade , int p_age , std::vector<int> p_marks);
		

		// GETTERS
		const std::string getName();
		const std::string getFatherName();
		const std::string getMotherName();
		const char getGrade();
		const int getAge();
		const std::vector<int> getMarks();

	private:
		std::string m_name;
		std::string m_fName;
		std::string m_mName;
		char m_grade;
		int m_age;
		std::vector<int> m_marks;

};

#endif
