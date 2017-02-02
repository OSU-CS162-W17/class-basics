/*
 * This file contains implementations of the class methods of the Student
 * class defined in student.hpp.
 */

#include <iostream>
#include "student.hpp"

/*
 * This is a constant we'll use to simplify allocating arrays to hold student
 * grades.
 */
#define MAX_GRADES 100


/*
 * Here's the definition for the Student class's default constructor.  It
 * uses an initialization list to initialize the values of id and n_grades,
 * and it allocates a new array to hold the student's grades.
 */
Student::Student() : id(0), n_grades(0) {
  this->grades = new float[MAX_GRADES];
}


/*
 * Here's the definition for the Student class's parameterized constructor.
 * It uses an initialization list to initialize the values of name and id, with
 * the constructor's argument values and to initialize n_grades to 0.  It also
 * allocates a new array to hold the student's grades.
 */
Student::Student(std::string name, int id) : name(name), id(id), n_grades(0) {
  this->grades = new float[MAX_GRADES];
}


/*
 * This is the definition of the copy constructor for the Student class.  It
 * does what you'd expect and copies the values of the student's name, ID,
 * and number of grades, but importantly, it allocates a new array for the
 * student's grades and copies the existing grades into the newly-allocated
 * array.  This ensures that the two Student objects will not point to the
 * same place in memory.
 */
Student::Student(const Student& other) {
  this->name = other.name;
  this->id = other.id;
  this->n_grades = other.n_grades;

  // Here's where we allocate and copy the grades.
  this->grades = new float[MAX_GRADES];
  for (int i = 0; i < other.n_grades; i++) {
    this->grades[i] = other.grades[i];
  }
}


/*
 * This is the destructor for the Student class.  It does the important work
 * of freeing the memory allocated for the student's grades array.
 */
Student::~Student() {
  /*
   * Here, we print a message to let us know which student we're calling the
   * destructor for.
   */
  std::cout << "== In destructor for this student: " << this->id << std::endl;
  delete[] this->grades;
}


/*
 * This is the definition for the assignment operator for the Student class.
 * It's called whenever we use assignment (i.e. =) to copy the values of one
 * Student object into another Student object that's already been initialized.
 * Just like with the copy constructor, the assignment operator allocates a
 * new array for the student's grades and copies the existing grades into the
 * newly-allocated array to ensure that the two Student objects will not point
 * to the same place in memory.
 */
void Student::operator=(const Student& other) {
  this->name = other.name;
  this->id = other.id;
  this->n_grades = other.n_grades;

  this->grades = new float[MAX_GRADES];
  for (int i = 0; i < other.n_grades; i++) {
    this->grades[i] = other.grades[i];
  }
}


/*
 * This is the definition of our method to add a new grade to a Student objecy.
 * It checks to make sure the Student still has space in its grades array.
 */
void Student::add_grade(float grade) {
  if (this->n_grades < MAX_GRADES) {
    this->grades[this->n_grades++] = grade;
  }
}


/*
 * This is our function to print info about a given student to stdout (i.e. to
 * to std::cout).  It prints the address of the student's grades array so you
 * can verify that the copy constructor and assignment operator are indeed
 * allocating new arrays.  Try commenting out the copy constructor and/or
 * the assignment operator to verify that the grades arrays of copied Student
 * objects are the same when the default copy constructor and assignment
 * operator are used.
 */
void Student::print_student() {
  std::cout << "== " << this->name << " (" << this->id << "):" << std::endl;
  std::cout << "  grades array address: " << this->grades << std::endl;
  std::cout << "  grades:" << std::endl;
  for (int i = 0; i < this->n_grades; i++) {
    std::cout << "    " << this->grades[i] << std::endl;
  }
  std::cout << std::endl;
}
