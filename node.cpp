#include <iostream> 
#include "node.h" 

Node::Node(Student* newStudent) {
	s = newStudent; 
	next = NULL; 
}

Node::~Node() {
	delete s; 
	next = NULL;
}

void Node::setNext(Node* newNext) {
	next = newNext;
}

Node* Node::getNext() {
	return next; 
}

void Node::setStudent(Student* newStudent) {
	newStudent = s;
}

Student* Node::getStudent() {
	return s; 
}	
