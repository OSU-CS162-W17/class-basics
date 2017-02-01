/*
 * This file contains some more specific details of the benefits of using
 * initialization lists.
 */

#ifndef INITIALIZATION_LIST_DETAILS_HPP
#define INITIALIZATION_LIST_DETAILS_HPP

/*
 * Here's an example of a class where using an initialization list in the
 * constructor makes a difference beyond just syntax.  Here, class A has a
 * data member that is itself an object of the class std::string.  Because of
 * the way the constructor is written (without an initialization list), when
 * a new object of class A is created using the constructor defined here,
 * the following things will happen:
 *   1. A new std::string object will be created to be assigned to the new
 *      A object's str field.
 *   2. The default constructor for std::string will be called for the new
 *      std::string object.
 *   3. The constructor for A will be called.
 *   4. A copy of the argument s to A's constructor will be made and assigned
 *      to str.
 *
 * Note here that the default constructor for std::string is unnecessarily
 * called, and the work it does only serves to add extra instructions to our
 * program, since a new value is immediately assigned to str.
 */
class A {
private:
  std::string str;
public:
  A(s) {
    str = s;
  }
}

/*
 * For class B, we instead use an initialization list for the constructor.
 * The result is that, when a new object of class B is created using this
 * constructor, the copy constructor for std::string is called directly.
 * This, in turn, means that we aren't doing the extra work of calling the
 * default constructor on str, only to replace str with a new (copied) value.
 * Instead, the copy is done directly here via the initialization list.
 */
class B {
private:
  std::string str;
public:
  B(s) : str(s) {}
}

#endif
