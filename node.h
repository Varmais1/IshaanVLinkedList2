#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include "student.h"
using namespace std;

class Node{
 public:
  Node(Student* newStu);
  ~Node();
  void setStudent(Student* newStu); //set node to student
  Student* getStudent();//return student found in node
  void setNext(Node* newnext);//set next node
  Node* getNext();//return next node
 private:
  Student* value;
  Node* next;
};
#endif
