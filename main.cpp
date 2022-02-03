#include "node.h" // gets node to do linked list operations
#include <iomanip> // for setprecision
#include <iostream> // input/output
#include <cstring> // string operations
#include <limits> // for numeric_limits

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

typedef Node* list; // for ease of readability. instead of Node*, you can use list to represent the whole list


void internal_add(Student* s, list& head, Node* prev, Node* curr, int student_id){
	// Nihal P. helped me with this function
	
	// head is the static head
	// curr is the moving current
	// prev is always 1 behind curr
	// student_id is the id of the one we're looking at
	if(head == NULL){
		head = new Node(s); // create the linked list if its empty
	}
	else if(curr == NULL){ // if you're at the end of the list
		prev->setNext(new Node(s));
		prev->getNext()->setNext(NULL);
		delete curr;
	}
	else if(student_id < head->getStudent()->student_id){ // id < head id
		Node* temp = head;
		head = new Node(s);
		head->setNext(temp);
	}
	else if(student_id < curr->getStudent()->student_id){ // id < curr id
		prev->setNext(new Node(s));
		prev->getNext()->setNext(curr);
	}
	else{
		internal_add(s, head, curr, curr->getNext(), student_id); // recurse
	}
}

void add(list& l){ // get input and call the internal_add
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


	Student* s = new Student(first_name, last_name, student_id, GPA); // create input
	Node* n = new Node(s); // create container node for student
	
	internal_add(s, l, l, l, student_id); // call recursive function
} 

void print(Node* curr){ // prints all users
	std::cout << "Students:\n";

	if(curr == NULL) return; // stop if list is empty or we're at the end
	char* first_name = curr->getStudent()->first_name;
	char* last_name = curr->getStudent()->last_name;
	float GPA = curr->getStudent()->GPA;
	int id = curr->getStudent()->student_id;

	std::cout << first_name << " " << last_name << "\t" << "(gpa=" << std::setprecision(3)<< GPA << ", id=" << id << ")\n"; // print
	print(curr->getNext()); // recurse
	
}


void internal_delete(list& head, Node* prev, Node* curr, int student_id){ // deletes a user
	if(head == NULL){
		std::cout << "Nothing to delete in an empty list, try adding items\n";
		return;
	}
	
	if(curr == NULL){
		return;
	}

	if(student_id == curr->getStudent()->student_id){ // if we're at the right node
		if(curr == head){ // popping from start
			head = head->getNext(); // skip the first element
			curr->setNext(NULL);
			delete curr; // delete from heap
			return;
		}
		prev->setNext(curr->getNext()); // skip over current
		curr->setNext(NULL); // detach list
		delete curr;
		return;
	}
	internal_delete(head, curr, curr->getNext(), student_id); // recurse if all other conditions didn't pass
}

void sdelete(list& head){
	std::cout << "Student ID: ";
	int student_id = get_type<int>();
	internal_delete(head, head, head, student_id); // calls recursive function
}

void average(list& head){ // averages student GPAs
	Node* curr = head; // keep track of current
	float sum = 0;
	int count = 0;
	
	do{
		sum += curr->getStudent()->GPA;
		count++;
		curr = curr->getNext(); // go to next node

	}while(curr != NULL);
	std::cout << std::setprecision(3) << (sum / count) << "\n"; // print average with 2 digits past the decimal
	
}


int main(){
	list database = NULL; // start with empty database
	while(true){
		char input[256];
		std::cout << "Enter Command (ADD, PRINT, DELETE, MEAN, QUIT): ";
		std::cin >> input;
		switch(input[0]){ // we really only have to check first letter because all of the input conditions have different first letters
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
				if(database != NULL){ // `delete NULL` results in an error, so we only delete if there's stuff in the database
					delete database;
				}
				std::cout << "Thanks For Using This Program!\n";
				exit(0);
				break;
		}

	}
}
