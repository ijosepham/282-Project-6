// Point.h
///////////

#pragma once
#include <iostream>

using namespace std;

template <class T, class U>
class Point
{
private:
	T x;
	U y;
public:
	// constructors
	Point() {
		x = NULL;
		y = NULL;
	}
	Point(T newX, U newY) {
		x = newX;
		y = newY;
	}
	
	// setters
	void setX(T newX) {
		x = newX;
	}
	void setY(U newY) {
		y = newY;
	}

	// getters
	T getX() {
		return x;
	}
	U getY() {
		return y;
	}

	// friends cin/cout
	friend ostream& operator<<(ostream& out, const Point& p) {
		out << "(" << p.x << ", " << p.y << ")";
		return out;
	}

	friend istream& operator>>(istream& in, Point& p) {
		cout << "Enter a value for x: ";
		in >> p.x;
		cout << "Enter a value for y: ";
		in >> p.y;
		return in;
	}

	~Point() {
		// destructor
	}
};

