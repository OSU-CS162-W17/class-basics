/*
 * This is a small application to demonstrate how to use our Point class.
 */

#include <iostream>
#include "point.hpp"

int main(int argc, char** argv) {

  /*
   * Below are several examples of how to statically allocate Point objects
   * (i.e. to allocate them on the call stack) using the various constructors
   * we defined:
   *   * p1 is initialized with the default constructor, since we aren't
   *     supplying any arguments when we initialize it.
   *   * p2 is initialized with the parameterized constructor, since we're
   *     passing values for its X and Y coordinates as arguments.
   *   * p3 is initialized using the copy constructor; it will have the same
   *     coordinates as p2, which is passed explicitly as an argument to the
   *     copy constructor.
   *   * p4 is also initialized using the copy constructor, but it's called
   *     implicitly here to make a copy of p2.
   */
  Point p1, p2(-4, -20);
  Point p3(p2);
  Point p4 = p2;

  /*
   * We can also allocate objects dynamically (i.e. on the heap).  Here are
   * several examples where Point objects are dynamically allocated and
   * initialized with our various constructors:
   *   * p5 is initialized with the default constructor.
   *   * p6 is initialized with the parameterized constructor.
   *   * p7 is initialized with the copy constructor.
   */
  Point* p5 = new Point;
  Point* p6 = new Point(2, 7);
  Point* p7 = new Point(p2);

  /*
   * We can also allocate arrays of objects.  Here, we allocate an array of
   * 10 points.  It's important to note that the default constructor is
   * called here for *all* of the points in the array.  This could be
   * undesirable if the default constructor is expensive and/or if we're
   * allocating a large array.
   */
  Point* points = new Point[10];

  /*
   * In order to avoid having the default constructor called for all of the
   * objects in an array being allocated, we can instead allocate an array
   * of pointers to objects.  Then, we may allocate each object in the array
   * individually whenever we want to.  The constructor will only be called
   * when we allocate the individual objects, like we do using the
   * parameterized constructor in the for loop below.
   */
  Point** points2 = new Point*[10];
  for (int i = 0; i < 10; i ++) {
    points2[i] = new Point(i, i * 2);
  }

  /*
   * Importantly, because our Point class's x and y members are private, we
   * cannot access or modify them directly, as we try to do in the commented
   * lines below.  If uncommented, any of those lines would result in a
   * compile-time error.  Instead of trying to directly access our objects'
   * private data members, we must instead use the public interface of
   * accessors and mutators.
   */
  // p1.x = 8;
  // p1.y = 4;
  // p7->x = 3;
  // p7->y = 10;
  // std::cout << "p1: " << p1.x << ", " << p1.y << std::endl;
  // std::cout << "p7: " << p7->x << ", " << p7->y << std::endl;

  /*
   * Here is how we use our accessor functions to access the coordinates of
   * our Point objects.  When we have an object as a value, like with our
   * statically allocated Points, we use the dot operator (.) to call the
   * get_x() and get_y() methods.
   */
  std::cout << "p1: " << p1.get_x() << ", " << p1.get_y() << std::endl;
  std::cout << "p2: " << p2.get_x() << ", " << p2.get_y() << std::endl;
  std::cout << "p3: " << p3.get_x() << ", " << p3.get_y() << std::endl;
  std::cout << "p4: " << p4.get_x() << ", " << p4.get_y() << std::endl;

  /*
   * When we have a pointer to an object, as we do with our dynamically
   * allocated points, we use the arrow operator (->) to call our accessors.
   */
  std::cout << "p5: " << p5->get_x() << ", " << p5->get_y() << std::endl;
  std::cout << "p6: " << p6->get_x() << ", " << p6->get_y() << std::endl;
  std::cout << "p7: " << p7->get_x() << ", " << p7->get_y() << std::endl;
  std::cout << std::endl;

  /*
   * Here's how to use our mutator function to set the coordinates of our
   * Point objects.  Again, for objects as values, we use the dot operator (.)
   * to call the class method, while for object pointers, we need to
   * dereference by using the arrow operator (->).
   *
   * Here, we also print the addresses of the Point objects we're modifying,
   * so you can compare with the address of "this" printed inside set_xy().
   */
  std::cout << "Address of p1: " << &p1 << std::endl;
  p1.set_xy(8, 4);
  std::cout << "Address pointed to by p7: " << p7 << std::endl;
  p7->set_xy(3, 10);
  std::cout << "After set_xy(), p1: " << p1.get_x() << ", " << p1.get_y()
    << std::endl;
  std::cout << "After set_xy(), p7: " << p7->get_x() << ", " << p7->get_y()
    << std::endl;
  std::cout << std::endl;

  /*
   * Here's how we'd use our translate() class method to translate a Point
   * object's coordinates.
   */
  p1.translate(-5, 10);
  std::cout << "After translate(), p1: " << p1.get_x() << ", " << p1.get_y()
    << std::endl;

  /*
   * As always, we need to call delete once for every call we've made to new.
   * Here, we use delete to free our dynamically allocated Point objects.
   */
  delete p5;
  delete p6;
  delete p7;

  /*
   * To free a dynamically-allocated array of objects (just like with any
   * other dynamically-allocated array), we need to use the delete[] operator.
   */
  delete[] points;

  /*
   * For our dynamically-allocated array of object pointers, we need to free
   * each individual dynamically-allocated object within the array before we
   * free the array itself.
   */
  for (int i = 0; i < 10; i++) {
    delete points2[i];
  }
  delete[] points2;

}
