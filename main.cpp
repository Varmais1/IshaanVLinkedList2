/*
Name: Ishaan Varma
Date: 1/27/2023
Purpose: where the program is run, where the linked list is, and where all linked list manipulation functions are kept.
 */
//includes
#include <iostream>
#include <cstring>
#include "node.h"
#include <iomanip>

//finds and returns the last element of the linked list
Node* findLast(Node* head);
//makes all characters in a character array lower case
void singlelowercase(char sentence[]);
//creates a new nodes through constructors
Node* createNewNode(char nfirstName[60], char nlastName[60], int nid, float nGPA);
//inserts a nodes into a linked list sorted based upon the id from least to greatest
void insertNode(Node* &head, Node* current, Node* previous, Node* insert);
//prints all of the students
void printNodes(Node* head);
//deletes a node from the linked list
void deleteNode(Node* &head, Node* current, Node* previous, int id);

//for convenience
using namespace std;

//main
int main() {
  //cout << "Working" << endl;
  //define the head pointer, as well as creation variables to make creating a node easier
  Node* head = NULL;
  bool listCreated = false;
  char firstName[60];
  char lastName[60];
  int id;
  float GPA;
  //creates two nodes with students for testing purposes
  /*
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
  head->setNext(second);*/

  //holds the users command
  char command[10];
  cout << "Type in a command." << endl;

  //have the program run
  while(true) {
    //get a command
    cout << "The available commands are add, delete, print, and quit." << endl;
    cin >> command;
    singlelowercase(command);
    //if the user says quit, stop the infinite loop, which will end the program
    if(strcmp(command, "quit")==0) {
      break;
    }
    //if add, get student information, and insert an anonymous object into the linked list 
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
    //if delete, get the right id number and call the delete function
    else if(strcmp(command, "delete")==0) {
      cout << "What is the id of the student whose record you wish to delete?" << endl;
      cin >> id;
      deleteNode(head, head, NULL, id);
    }
    //if print, call the printNodes function
    else if(strcmp(command, "print") == 0) {
      printNodes(head);
    }
    //tells the user that the input was invalid
    else {
      cout << "Please enter add, delete, print, or quit." << endl;
    }
    //formatting
    cout << endl;
  }
  return 0;
  
}
//returns the last node of the linked list
Node* findLast(Node* head) {
  if(head->getNext() != NULL) {
    return findLast(head->getNext());
  }
  else {
    return head;
  }
}

//creates a node through constructors anonymously
Node* createNewNode(char nfirstName[60], char nlastName[60], int nid, float nGPA) {
  Student* newStudent = new Student(nfirstName,nlastName,nid,nGPA);
  Node* newNode = new Node(newStudent);
  return newNode;
}

//inserts a node into a linked list based on its id number
void insertNode(Node* &head, Node* current, Node* previous, Node* insert) {
  //if nod element exists in the linked list, set the head pointer to the element
  if(head == NULL && previous == NULL) {
    //cout << "head before: " << head;
    head = insert;
    //cout << "head after: " << head;
    //cout << "insert: " << insert;
    return;
  }
  //if element to be inserted has the highest id number, set the previous elements next to it.
  else if(head == NULL && previous != NULL) {
    previous->setNext(insert);
    //cout << "Clause 2" << endl;
    return;
  }
  //if the id number is less than the next node, add it in before it
  else if(insert->getStudent()->id < head->getStudent()->id) {
    cout << "Clause 3" << endl;
    insert->setNext(head);
    //uneeded check, but I put in in at the time, so it stays
    if(previous != NULL) {
      previous->setNext(insert);
    }
    else {
      head = insert;
    }
    return;
  }
  //if the id of the element is greater than the current element it is being compared against, compare it against the next node.
  else {
    Node* next = head->getNext();
    insertNode(next, current->getNext(), current, insert);
    return;
  }
}

//prints the nodes
void printNodes(Node* head) {
  //the the head pointer is null, exit the function
  if(head == NULL) {
    cout << "There are no student records. Typical of some administrators." << endl;
    return;
  }
  //formatting code
  cout << fixed;
  cout << endl;
  //prints out the various aspects of the student
  Student* printer = head->getStudent();
  cout << "Name:\t" << printer->firstName << " " << printer->lastName << endl;
  cout << "id:  \t" << printer->id << endl;
  cout << "GPA: \t" << setprecision(2) << printer->GPA << endl;
  cout << endl;
  //if the next node exists, do this function to print it out using recursion
  if(head->getNext() != NULL) {
    printNodes(head->getNext());
  }
  return;
}

//function for deleting nodes
void deleteNode(Node* &head, Node* current, Node* previous, int id) {
  //checks for invalid input
  if(head == NULL || current == NULL) {
    cout << "Either there are no student records, or a valid id wasn't entered." << endl;
    return;
  }
  //checks if the node has the right id
  if(current->getStudent()->id == id) {
    //if the node isn't the first element in the array
    if(previous != NULL) {
      //set the previous nodes next to the node after the one being deleted
      previous->setNext(current->getNext());
      //cout << "Clause 1." << endl;
      //delete the current node and the object it was assigned to.
      delete head;
      
    }
    //if the element is the first node
    else {
      //set the head pointer to the second node
      head = head->getNext();
      //cout << "Clause 2." << endl;
      //delete the current node, but not the head pointer
      delete current;
      
    }
    return;
  }
  //if the element does not have the right id
  else {
    //do the function again for the next node
    Node* nhead = head->getNext();
    deleteNode(nhead, current->getNext(), current, id);
    //cout << "Clause 3." << endl;
    return;
  }
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
