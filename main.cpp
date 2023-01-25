#include <iostream>
#include <cstring>
#include "node.h"
#include <iomanip>

Node* findLast(Node* head);
void singlelowercase(char sentence[]);
Node* createNewNode(char nfirstName[60], char nlastName[60], int nid, float nGPA);
void insertNode(Node* &head, Node* current, Node* previous, Node* insert);
void printNodes(Node* head);
using namespace std;

int main() {
  //cout << "Working" << endl;
  Node* head = NULL;
  bool listCreated = false;
  char firstName[60];
  char lastName[60];
  int id;
  float GPA;
  strcpy(firstName, "Ishaan");
  strcpy(lastName, "Varma");
  Student* IshaanV = new Student(firstName, lastName, 418487, 4.00);
  Node* first = new Node(IshaanV);
  Student* newStudent = first->getStudent();
  //cout << "newStudent first name: " << first->getStudent()->firstName << endl;
  head = first;
  strcpy(firstName, "Rohan");
  strcpy(lastName, "Verma");
  Student* RohanV = new Student(firstName, lastName, 434287, 4.00);
  Node* second = new Node(RohanV);
  head->setNext(second);
  
  char command[10];
  cout << "Type in a command." << endl;
  cout << "The available commands are add, delete, print, and quit." << endl;
  while(true) {
    cin >> command;
    singlelowercase(command);
    if(strcmp(command, "quit")==0) {
      break;
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
      insertNode(head, head, NULL, createNewNode(firstName, lastName, id, GPA));
      
    }
    else if(strcmp(command, "delete")==0) {

    }
    else if(strcmp(command, "print") == 0) {
      printNodes(head);
    }
    else {
      cout << "Please enter add, delete, print, or quit." << endl;
    }
    cout << endl;
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
  Student* newStudent = new Student(nfirstName,nlastName,nid,nGPA);
  Node* newNode = new Node(newStudent);
  return newNode;
}

void insertNode(Node* &head, Node* current, Node* previous, Node* insert) {
  if(head == NULL && previous == NULL) {
    cout << "head before: " << head;
    head = insert;
    cout << "head after: " << head;
    cout << "insert: " << insert;
    return;
  }
  else if(head == NULL && previous != NULL) {
    previous->setNext(insert);
    cout << "Clause 2" << endl;
    return;
  }
  else if(insert->getStudent()->id < head->getStudent()->id) {
    cout << "Clause 3" << endl;
    insert->setNext(head);
    if(previous != NULL) {
      previous->setNext(insert);
    }
    else {
      head = insert;
    }
    return;
  }
  else {
    Node* next = head->getNext();
    insertNode(next, current->getNext(), current, insert);
    return;
  }
}

void printNodes(Node* head) {
  cout << fixed;
  cout << endl;
  Student* printer = head->getStudent();
  cout << "Name:\t" << printer->firstName << " " << printer->lastName << endl;
  cout << "id:  \t" << printer->id << endl;
  cout << "GPA: \t" << setprecision(2) << printer->GPA << endl;
  cout << endl;
  if(head->getNext() != NULL) {
    printNodes(head->getNext());
  }
  return;
}

//makes all letters lowercase
void singlelowercase(char sentence[]) {
  //iterating variable
  int i = 0;
  //go through the char array
  while(true) {
    int charVal = (int) sentence[i];
    //if the letter is capital, make it singlelowercase using ASCII
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
