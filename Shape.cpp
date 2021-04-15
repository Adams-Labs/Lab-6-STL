#include "Shape.hpp"

/**
 * The stream insertion operator << is NOT a member of the class!
 * It is declared as a friend.
 * Since it is not a member it cannot be inherited, which means
 * that we cannot override it to support polymorphism ...
 * and we like polymorphism.
 * So what we do is:
 * 1) Write the operator<< function so that it USES a member
 * function (printMe).
 * 2) Since printMe is a member, it can be inherited and
 * overridden, thereby giving use the polymorphic behaviour
 * that we wanted.
 */
std::ostream & operator<<(std::ostream &out, Shape &shape) {
    shape.printMe(out);

    return out;
}