#ifndef NODE_H
#define NODE_H
#include <iostream> 
#include "student.h"

class Node {
public:
//destructor, constructor 
Node(Student* newStudent); 
~Node(); 

//getters and setters
void setNext(Node* newNext); 
Node* getNext();
void setStudent(Student* newStudent); 
Student* getStudent();


private: 
Student* s; 
Node* next; 

};

#endif
