#include "node.h"
#include <iomanip>
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

typedef Node* list;


void internal_add(Student* s, list& head, Node* prev, Node* curr, int student_id){
	// head is the static head
	// curr is the moving current
	// prev is always 1 behind curr
	// student_id is the id of the one we're looking at
	if(head == NULL){
		head = new Node(s);	
	}
	else if(curr == NULL){
		prev->setNext(new Node(s));
		prev->getNext()->setNext(NULL);
		delete curr;
	}
	else if(student_id < head->getStudent()->student_id){
		Node* temp = head;
		head = new Node(s);
		head->setNext(temp);
	}
	else if(student_id < curr->getStudent()->student_id){
		prev->setNext(new Node(s));
		prev->getNext()->setNext(curr);
	}
	else{
		internal_add(s, head, curr, curr->getNext(), student_id);
	}
}

void add(list& l){
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


	Student* s = new Student(first_name, last_name, student_id, GPA);
	Node* n = new Node(s);
	
	internal_add(s, l, l, l, student_id);
}

void print(Node* curr){
	if(curr == NULL) return;
	char* first_name = curr->getStudent()->first_name;
	char* last_name = curr->getStudent()->last_name;
	float GPA = curr->getStudent()->GPA;
	int id = curr->getStudent()->student_id;

	std::cout << first_name << " " << last_name << "\t" << "(" << std::setprecision(3)<< GPA << ", " << id << ")\n";
	print(curr->getNext());
	
}


void internal_delete(list& head, Node* prev, Node* curr, int student_id){
	if(head == NULL){
		std::cout << "Nothing to delete in an empty list, try adding items\n";
		return;
	}
	
	if(curr == NULL){
		return;
		
	}

	if(student_id == curr->getStudent()->student_id){
		if(curr == head){ // popping

			head = head->getNext();
			curr->setNext(NULL);
			delete curr;
			return;
		}
		prev->setNext(curr->getNext()); // skip over current
		curr->setNext(NULL); // detach list
		delete curr;
		return;

	}
	internal_delete(head, curr, curr->getNext(), student_id);
}

void sdelete(list& head){
	std::cout << "Student ID: ";
	int student_id = get_type<int>();
	internal_delete(head, head, head, student_id);
}

void average(list& head){
	Node* curr = head;
	float sum = 0;
	int count = 0;
	
	do{
		sum += curr->getStudent()->GPA;
		count++;
		curr = curr->getNext();

	}while(curr != NULL);
	std::cout << std::setprecision(3) << (sum / count) << "\n";
	
}


int main(){
	list database = NULL;
	while(true){
		char input[256];
		std::cout << "Enter Command (ADD, PRINT, DELETE, MEAN, QUIT): ";
		std::cin >> input;
		switch(input[0]){
			case 'A':
				add(database);
				break;
			case 'P':
				print(database);
				break;
			case 'D':
				sdelete(database);
				break;
			case 'M':
				average(database);
				break;
			case 'Q':
				if(database != NULL){
					delete database;
				}
				std::cout << "Thanks For Using This Program!\n";
				exit(0);
				break;
		}

	}

	add(database);
	print(database);
	sdelete(database);
	print(database);
}
