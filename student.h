/*Name: Ishaan Varma
  Date: 1/17/2023
  Purpose: where the student class is defined
*/
//header gaurd and includes
#ifndef STUDENT_H
#define STUDENT_H
#include <cstring>
#include <iostream>

using namespace std;

//creates the class
class Student {
 public:
  //variables to store information  about the student
  char firstName[60];
  char lastName[60];
  int id;
  float GPA;
  Student();
  //constructors
  Student(char nfirstName[60], char nlastName[60], int nid, float nGPA);
};

#endif
