/*
 * This file contains the implementations of methods for our Point class
 * defined in point.hpp.
 */

#include <iostream>
#include "point.hpp"

/*
 * This is the definition of our Point class's default constructor.  It simply
 * initializes both the X and Y coordinate to -1.
 */
Point::Point() {
  /*
   * Note the use of the "this" keyword here.  The "this" keyword gives us a
   * pointer to the object for which this method was called.  Since this is
   * a constructor, "this" gives us a pointer to the object being created.  We
   * can use "this", as we do here, to make sure we're accessing the data
   * members of the class.
   */
  this->x = -1;
  this->y = -1;
}

/*
 * Here, commented out, is an alternative way to define the default
 * constructor using an initialization list.  The initialization list here
 * does the exact same thing as the default constructor defined above, setting
 * the values of the Point object's X and Y coordinates both to -1.
 */
// Point::Point() : x(-1), y(-1) {
//   // Empty.
// }

/*
 * Here's the definition of our parameterized constructor.  This constructor
 * uses an initialization list to initialize the values of the new Point
 * object's X and Y coordinates to the values of the arguments x and y passed
 * to the constructor.
 */
Point::Point(int x, int y) : x(x), y(y) {
  // Empty.
}

/*
 * Here, commented out, is an alternative definition of our parameterized
 * constructor that doesn't use an initialization list.  This constructor
 * does the exact same thing as the one above that uses an initialization
 * list, setting the values of the new Point object's X and Y coordinates to
 * the arguments x and y passed to the constructor.
 */
// Point::Point(int x, int y) {
//   this->x = x;
//   this->y = y;
// }

/*
 * This is the definition of our copy constructor.  It simply initializes the
 * X and Y coordinates of the new Point object to the values of the X and Y
 * coordinates of another Point object p, which is being copied.
 */
Point::Point(const Point& p) {
  this->x = p.x;
  this->y = p.y;
}

/*
 * This is the definition of our mutator for setting the X and Y coordinates
 * of a Point object.
 */
void Point::set_xy(int x, int y) {
  /*
   * To convince you that the "this" keyword is actually a pointer, we're
   * printing it out here.  Check the value printed in the terminal.  It's a
   * memory address!
   */
  std::cout << "Inside set_xy(), the value of this: " << this << std::endl;
  this->x = x;
  this->y = y;
}

/*
 * This is the definition of our accessor for getting the value of a Point
 * object's X coordinate.
 */
int Point::get_x() {
  return this->x;
}

/*
 * This is the definition of our accessor for getting the value of a Point
 * object's Y coordinate.
 */
int Point::get_y() {
  return this->y;
}

/*
 * This is the definition of our class method for translating a point's
 * coordinates by some specified change in X and Y.
 */
void Point::translate(int dx, int dy) {
  this->x += dx;
  this->y += dy;
}
