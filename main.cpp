/* 
 * This is the main.cpp file for lab 07 that demonstrates the use of the STL and vector class functions.
 * 
 * File:   main.cpp
 * Author: Adam Claxton 
 *
 * Created on November 18, 2020, 7:38 PM
 */

#include <cstdlib>
#include <iostream>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include <vector>

using namespace std;

int main(int argc, char** argv) {

    // create some shapes 
    Circle c1(30, 5, 6);
    Circle c2(13, 45, 6);
    Rectangle r1(30.2, 6, 7, 8);
    Rectangle r2(54, 43, 2, 7);
    Rectangle r3(2, 2, 2, 2);

    // create an vector if shape objects 
    std::vector<Shape*> shapeVector;

    // put the shapes we made into the vector of shapes 
    try {
        shapeVector.push_back(&c1);
        shapeVector.push_back(&c2);
        shapeVector.push_back(&r1);
        shapeVector.push_back(&r2);
    } catch (bad_alloc& e) { // if any of the additions fail then return the error 
        cerr << "allocation of memory failed\n";
    }

    // print the current info about the vector using size, max size and capacity
    cout << "This Vector currently holds " << shapeVector.size() << " elements\n";\
    cout << "This Vector has a Max Size of " << shapeVector.max_size() << endl;
    cout << "The current Capacity of the Vector is " << shapeVector.capacity() << endl;
    cout << endl;

    // draw some shapes in different ways 
    shapeVector[0]->draw(); // draw the first element using the [] operator ([] has no exceptions) 
    shapeVector.front()->draw(); // draw the first element using the front function (front has no exceptions) 
    try {
        shapeVector.at(2)->draw(); // draw the 3rd element using the at function 
    } catch (out_of_range& e) { // if we try to access an element that is out of range we return an error 
        cerr << "You are out of Range\n";
    }

    // insert a shape at the beginning of the vector
    try {
        shapeVector.insert(shapeVector.begin(), &r3);
    } catch (bad_alloc& e) { // catch exception bad_alloc if the allocation of the memory fails 
        cerr << "Allocation failed \n";
    }

    cout << endl;

    //Draw all the shapes in the vector 
    std::vector<Shape*>::iterator i; // create an iterator that will step through our vector 
    for (i = shapeVector.begin(); i != shapeVector.end(); i++) { // start the iterator at the beginning and stop it at the end, step trough each element of the vector 
        (*i)->draw(); // draw the current element 

    }
    cout << endl;

    // delete and draw the shapes in the vector 
    while (!shapeVector.empty()) { // loop through while the vector still has elements in it 
        shapeVector.back()->draw(); // draw back most element
        shapeVector.pop_back(); // remove and destroy the backmost element (pop_back doesn't throw exceptions)  
    }

    cout << endl;

    // trying to throw an exception
    try {
        shapeVector.at(5)->draw(); // try to access a spot in the vector that doesn't exist 
    } catch (const std::out_of_range& e) { // catch the out of range error that it throws 
        cerr << "you are out of range\n";
    }

    return 0;

}

