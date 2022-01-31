#ifndef STUDENT_H
#define STUDENT_H

class Student{
public:
	// data for students
	char* first_name; 
	char* last_name;
	int student_id;
	float GPA;
	
	Student(char* first_name, char* last_name, int student_id, float GPA);
	// destructors
	~Student();
};

#endif
