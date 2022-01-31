#include "node.h"
#include <iostream>
#include <cstring>

template<typename T>
T get_type(){ // gets input of a type, ignoring all other types
	T input;
	while(!(std::cin >> input)){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the whole buffer
		std::cout << "Invalid input, please try again: ";
	}
	return input;
}

int main(){

	Student* s = new Student("nikhil", "nayak", 456660, 4.0f);

	Node n = Node(s);

	std::cout << n.getStudent()->GPA << "\n";
}


void add(){
	char first_name[256];
	std::cout << "First name: ";
	std::cin >> first_name;

	char last_name[256];
	std::cout << "Last name: ";
	std::cin >> last_name;

	int student_id;
	std::cout << "Student id: ";
	student_id = get_type<int>();

	float GPA;
	std::cout << "GPA: ";
	GPA = get_type<float>();

}



