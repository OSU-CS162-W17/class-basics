/*
 * This file contains a class definition for representing a student.  The
 * implementation for this class is in student.cpp.
 */

#ifndef STUDENT_HPP
#define STUDENT_HPP

/*
 * Here's the class we'll use to represent a student.  It contains four data
 * members, one to hold the student's name and one for their ID number, and
 * importantly, a pointer which will point to a dynamically-allocated array
 * of floats to hold the student's grades.  There's also a data member to store
 * the number of grades in the array.
 */
class Student {
private:
  std::string name;
  int id;
  float* grades;
  int n_grades;
public:
  /*
   * Here are declarations for a default constructor and a parameterized
   * constructor to initialize a student with a given name and ID number.
   */
  Student();
  Student(std::string name, int id);

  /*
   * Because our Student class contains a data memebr that points to a piece
   * of dynamically-allocated memory (the grades array), it's extremely
   * important to implement a copy constructor, for which we have the
   * declaration here.  Implementing our own copy constructor will allow us to
   * make a copy of the grades array in a new chunk of dynamically-allocated
   * memory instead of just pointing to the same array in the same memory
   * location pointed to by the Student object being copied.  We'll see the
   * implementation of this in student.cpp.
   */
  Student(const Student& other);

  /*
   * Again, because our Student class contains a pointer to dynamically
   * allocated memory, we need to have a destructor that frees that memory.
   * This is the declaration of the destructor.
   */
  ~Student();

  /*
   * Just like with the copy constructor, it's important to implement an
   * assignment operator (=) for our Student class so we can make a copy of the
   * grades array when we're making a copy of a Student object via assignment.
   * This is the declaration of our assignment operator.
   */
  void operator=(const Student& other);

  /*
   * Below are declarations of two class member methods, one for adding a grade
   * to the student's list of grades and one for printing a student's info out
   * to stdout (i.e. using std::cout).
   */
  void add_grade(float grade);
  void print_student();
};

#endif
