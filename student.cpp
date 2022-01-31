#include "student.h"
#include <string.h>

Student::~Student(){
	// deletes heap-allocated strings
	delete this->last_name;
	delete this->first_name;
}
Student::Student(char* first_name, char* last_name, int id, float GPA){
	/*char* first_name = new char[strlen(first_name_)];
	strcpy(first_name, first_name_);
	char* last_name = new char[strlen(last_name_)];
	strcpy(last_name, last_name_);*/

	this->first_name = new char[strlen(first_name)];
	strcpy(this->first_name, first_name);

	this->last_name = new char[strlen(last_name)];
	strcpy(this->last_name, last_name);


	this->student_id = id;
	this->GPA = GPA;
}
