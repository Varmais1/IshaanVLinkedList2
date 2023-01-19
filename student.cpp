/*Name: Ishaan Varma
  Date: 1/17/2023
  Purpose: Where the constructors of the Student class are implemented
*/
#include "Student.h"
#include <cstring>

//default constructor, set char arrays to empty strings, and set ints and floats to 0
Student::Student() {
  strcpy(firstName, "");
  strcpy(lastName, "");
  id = 0;
  GPA = 0.00;
}

//constructor
Student::Student(char nfirstName[60], char nlastName[60], int nid, float nGPA) {
  strcpy(firstName,nfirstName);
  strcpy(lastName,nlastName);
  id = nid;
  GPA = nGPA;
}
