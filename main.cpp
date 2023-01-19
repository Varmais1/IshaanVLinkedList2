#include <iostream>
#include <cstring>
#include "node.h"

Node* findLast(Node* head);

int main() {
  cout << "Working" << endl;
  Node* head = NULL;
  bool listCreated = false;
  char firstName[60];
  char lastName[60];
  strcpy(firstName, "Ishaan");
  strcpy(lastName, "Varma");
  Student* IshaanV = new Student(firstName, lastName, 418487, 4.00);
  Node* first = new Node(IshaanV);
  Student* newStudent = first->getStudent();
  cout << "newStudent first name: " << first->getStudent()->firstName << endl;
  head = first;
  return 0;
  
}

Node* findLast(Node* head) {
  if(head->getNext() != NULL) {
    return findLast(head->getNext());
  }
  else {
    return head;
  }
}
