/*
 * This is a small application to demoinstrate some slightly more advanced
 * class stuff (copy constructor, assignment operator, destructor) using our
 * Student class.
 */

#include <iostream>
#include "student.hpp"


int main(int argc, char** argv) {

  // Here, we're statically allocating a new Student and adding some grades.
  Student s1("Luke Skywalker", 933123456);
  s1.add_grade(4.0);
  s1.add_grade(3.75);
  s1.print_student();

  /*
   * Here, we're dynamically allocating a Student, adding a grade, and then
   * deleting the Student object.  You should see the message from this
   * Student's destructor print as soon as we delete it.
   */
  Student* s2 = new Student("Darth Vader", 933654321);
  s2->add_grade(1.0);
  s2->print_student();
  delete s2;

  /*
   * Here, we're dynamically allocating an array of Student objects.  Because
   * this is an array of objects, the default constructor is called for each
   * object immediately upon the array's allocation.  We immediately free the
   * array using delete[], which will, in turn cause the destructor to be
   * called for each object in the array.  You should see the destructor
   * message print for these Students after the destructor for the dynamically
   * allocated Student above.
   */
  Student* students = new Student[2];
  delete[] students;

  /*
   * Here, we're dynamically allocating an array of *pointers* to Student
   * objects.  Because these are pointers, the constructors will not be
   * called until we allocate the individual objects themselves, which we do
   * in the for loop below using the parameterized constructor.
   */
  Student** students_dyn = new Student*[3];
  for (int i = 0; i < 3; i++) {
    students_dyn[i] = new Student("", (i + 1) * 10);
  }

  /*
   * Here, we're creating a new statically-allocated Student object using the
   * copy constructor.  Alternatively, you can comment the first line below
   * and uncomment the two lines below it to create a new Student object using
   * the default constructor and then to use the assignment operator to copy
   * another student's values into the just-created object.  In either case,
   * you can verify that the memory address of the new Student's grades array
   * is different than the address of the Student being copied when.
   */
  Student s3 = s1;
  // Student s3;
  // s3 = s1;
  s3.add_grade(3.5);
  s3.print_student();

  /*
   * Finally, here, we're freeing the memory dynamically allocated to our
   * of pointers to Student objects.  First, we free the individual Student
   * objects themselves.  Each time one of these Student objects is deleted,
   * you will see the message from its destructor printed (you should verify
   * that these destructors are not called if you comment out the for loop
   * below).  Once the individual Student objects are freed, we can free the
   * array of pointers.
   */
  for (int i = 0; i < 3; i++) {
    delete students_dyn[i];
  }
  delete[] students_dyn;

  /*
   * At the very end of our program, the statically-allocated Student objects
   * lose scope, which is what triggers their destructors to be called.  You
   * should see messages from these Students' destructors at the very end of
   * the program's output.
   */
}
