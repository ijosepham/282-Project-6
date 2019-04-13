#include "pch.h"
#include "Point.h"

using namespace std;

template < class T >
Point <T>::Point()
{
	x = null;
	y = null;
}

template < class T >
Point <T>::Point(T newX, T newY)
{
	x = newX;
	y = newY;
}

template < class T >
void Point <T>::setX(T newX)
{
	x = newX;
}

template < class T >
void Point <T>::setY(T newY)
{
	y = newY;
}

template < class T >
T Point <T>::getX()
{
	return x;
}

template < class T >
T Point <T>::getY()
{
	return y;
}

template < class T >
ostream& operator<<(ostream& out, Point <T> & p) 
{
	out << "(" << p.x << ", " << p.y << ")";
	return out;
}

template < class T >
istream& operator>>(istream& in, Point <T> & p)
{
	cout << "Enter a value for x: ";
	in << p.x;
	cout << endl << "Enter a value for y: ";
	in << p.y;
	return in;
}

template<class T>
Point <T>::~Point()
{
	// this is a destructor
}
