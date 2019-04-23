// Point.h
///////////

#pragma once
#include <iostream>

using namespace std;

template <class T, class U>
class Point
{
private:
	// represents the x coordinate of the function
	T x;

	// represents the y coordinate of the function
	U y;
public:
	// description: default constructor
	Point() {
		x = NULL;
		y = NULL;
	}

	// description: overloaded constructor
	// preconditions: newX, newY - x and y for the point
	Point(T newX, U newY) {
		x = newX;
		y = newY;
	}
	
	// description: sets the x to a new value
	// preconditions: newX - x to set to
	void setX(T newX) {
		x = newX;
	}

	// description: sets the y to a new value
	// preconditions: newY - y to set to
	void setY(U newY) {
		y = newY;
	}

	// description: returns the x-coordinate of the point
	// postcondition: x - x coordinate of the point
	T getX() {
		return x;
	}

	// description: returns the y-coordinate of the point
	// postcondition: y - y coordinate of the point
	U getY() {
		return y;
	}

	// desrcription: prints out the ordered pair of the point
	// preconditions: out - ostream to ouptut
	//				  p - point to print out
	// postcondition: out - the thing to print out
	friend ostream& operator<<(ostream& out, const Point& p) {
		out << "(" << p.x << ", " << p.y << ")";
		return out;
	}

	// desrcription: takes in arguments to assign to the point
	// preconditions: in - istream to take in input
	//				  point - point to change 
	// postcondition: in - istream
	friend istream& operator>>(istream& in, Point& p) {
		cout << "Enter a value for x: ";
		in >> p.x;
		cout << "Enter a value for y: ";
		in >> p.y;
		return in;
	}

	// description: destructor
	~Point() {
		// destructor
	}
};

