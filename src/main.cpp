#include <iostream>

// Custom Header
#include "Database.hpp"
#include "Utils.hpp"

Database chooseOpenDatabase() {
	Database db;
	while (true) {
		clear();
		std::cout << "Database Name : " << std::endl;

		std::string dbNameInput;
		std::cin >> dbNameInput;
		
		if(db.openDatabase(dbNameInput)) break; 
		else {
			clear();
			std::cout << "INVALID DATABASE NAME" << std::endl;
			std::cin.get();
		}
	}

	return db;
}

int main() {
	clear();
	std::cout << "STUDENT DATABASE SYSTEM | COPYRIGHT @ 2022" << std::endl;
	std::cout << "Welcome , Please choose an option" << std::endl;

	while (true) {
		std::cout << "1. Open an existing database" << std::endl;
		std::cout << "2. Create a new database" << std::endl;

		char mainOption;
		std::cin >> mainOption;
		switch (mainOption) {
			case '1' : {
				// OPEN A NEW DATABASE
				Database db = chooseOpenDatabase();
				// std::vector<Student> students = db.getStudents();
				while (true) {
					int studentCounter = 1;
					for ( Student student : db.getStudents() ) {
						std::cout << studentCounter << ". " << student.getName() << std::endl;
						studentCounter++;
					}

					int studentOptionInput;
					std::cin >> studentOptionInput;
					if (!(studentOptionInput > 0 && studentOptionInput < db.getStudents().size() + 1 )) {
						std::cout << "NO STUDENT WITH THAT ID FOUND" << std::endl;
						std::cin.get();
						clear();
						continue;
					}

					// VALID OPTION 
					Student choosedStudent = db.getStudents()[studentOptionInput - 1];
					std::cout << "STUDENT : " << choosedStudent.getName() << std::endl;
					std::cin.get();
				}
				break;
		 }

			case '2' : 
				break;

			default:
				clear();
				break;
		}
	}

	return 0;
}
