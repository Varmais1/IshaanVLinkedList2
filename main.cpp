#include <iostream>
#include <cstring>
#include "node.h"


Node* findLast(Node* head);
void lowercase(char sentence[]);
Node* createNewNode(char nfirstName[60], char nlastName[60], int nid, float nGPA);

int main() {
  //cout << "Working" << endl;
  Node* head = NULL;
  bool listCreated = false;
  bool run = true;
  char firstName[60];
  char lastName[60];
  int id;
  float GPA;
  /*strcpy(firstName, "Ishaan");
  strcpy(lastName, "Varma");
  Student* IshaanV = new Student(firstName, lastName, 418487, 4.00);
  Node* first = new Node(IshaanV);
  Student* newStudent = first->getStudent();
  cout << "newStudent first name: " << first->getStudent()->firstName << endl;
  head = first;*/
  char command[10];
  while(run == true) {
    cin >> command;
    lowercase(command);
    if(strcmp(command, "quit")==0) {
      run == false;
    }
    else if(strcmp(command, "add") ==0) {
      cout << "Enter the first name." << endl;
      cin >> firstName;
      cout << "Enter the last name." << endl;
      cin >> lastName;
      cout << "Enter the id number. Please enter a number." << endl;
      cin >> id;
      cout << "Enter the GPA of the student. Please enter a number." << endl;
      cin >> GPA;
      
    }
    else if(strcmp(command, "delete")==0) {

    }
    else if(strcpm(command, "print") == 0) {
      
    }
  }
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

Node* createNewNode(char nfirstName[60], char nlastName[60], int nid, float nGPA) {
  Student* newStudent = new Student(nfristName,nlastName,nid,nGPA);
  Node* newNode = new Node(newStudent);
  return newNode;
};

//makes all letters lowercase
void lowercase(char sentence[]) {
  //iterating variable
  int i = 0;
  //go through the char array
  while(true) {
    int charVal = (int) sentence[i];
    //if the letter is capital, make it lowercase using ASCII
    if(65<=charVal && charVal <= 90) {
      sentence[i] = (char)(charVal+32);
    }
    //if the character is the null character, 
    else if(sentence[i] == '\0') {
      break;
    }
     //increment the variable
    i++;
  }
}
