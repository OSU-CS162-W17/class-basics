/*
 * This file contains a class definition for a 2D point.  It's typical to
 * write each class definition in a separate header file (with its
 * implementation in a separate .cpp file).
 */

#ifndef POINT_HPP
#define POINT_HPP

/*
 * This is a class representing a point in 2D space.
 */
class Point {

  /*
   * To achieve encapsulation, we generally give only private access to data
   * members of classes.  This means that those members can only be accessed
   * or modified within the class itself.  Keeping data members private in
   * this way allows us to protect them from unintended use that could
   * potentially break our class.
   *
   * For this class, we only have two data members, one representing the
   * point's X coordinat and one representing its Y coordinate.
   */
private:
  int x;
  int y;

  /*
   * The flipside of the encapsulation coin is that our classes need a good
   * public interface to make it easy to work with objects of our class.
   * The public interface is, naturally, given public access, which means we
   * can use it outside of the class (or inside).  A public interface usually
   * includes at least one constructor along with accessors and mutator and
   * often a destructor.
   */
public:

  /*
   * This is the declaration of the default constructor, which is called when
   * a new Point object is created without parameters to perform default
   * initialization of the object (e.g. initializing the values of data
   * members).  In general, a constructor can do many things, including
   * allocating memory.
   */
  Point();

  /*
   * This is the declaration of a parameterized constructor.  A parameterized
   * constructor can perform initialization and allocation just like the
   * default constructor, but it can be given arguments it can use in its
   * initializations and allocations.  The parametereized constructor here
   * takes arguments to specify the initial X and Y coordinates of the point
   * being created.
   */
  Point(int x, int y);

  /*
   * Our final constructor is a special type of parameterized constructor
   * called the copy constructor.  It specifically takes a constant reference
   * to another object of the same class and uses that object to initialize
   * the values of the one being created (copying it).  We use a reference
   * to the object being copied to avoid passing an entire object (which could
   * be very large) by value.  The object being copied is declared const so
   * changes may not be made to it.
   *
   * The copy constructor can be used explicitly but is also used implicitly
   * by C++ in several places:
   *   * When returning an object from a function.
   *   * When passing an object by value into a function.
   *   * When using assignment (=) to initialize an object, e.g. Point p2 = p1;
   */
  Point(const Point& p);

  /*
   * This is the declaration of a mutator method that can be used to set the
   * X and Y coordinates of a point object.
   */
  void set_xy(int x, int y);

  /*
   * These are declarations of accessor methods for getting the values of the
   * coordinates of a point object.
   */
  int get_x();
  int get_y();

  /*
   * This is the definition of a class method for translating a point object
   * by some specified change in X and Y.
   */
  void translate(int dx, int dy);

};


#endif
