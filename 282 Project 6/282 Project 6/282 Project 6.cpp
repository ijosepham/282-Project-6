// 282 Project 6.cpp
/////////////////////

#include "pch.h"
#include "Point.h"
#include "Line.h"
#include <iostream>
#include <string>

using namespace std;

template <class T, class U, class V, class W>
bool isParallel(Line <T, U, V, W> l1, Line <T, U, V, W> l2) {
	if (l1.getSlope() == l2.getSlope()) {
		return true;
	}
	return false;
}

template <class T, class U, class V, class W>
bool isPerpendicular(Line <T, U, V, W> l1, Line <T, U, V, W> l2) {
	// the slopes should be opposite and inverse
	// so 1/2 would be perp to -2/1; 1/2 * (-2/1) = - 1
	if (l1.getSlope() * l2.getSlope() == -1) {
		return true;
	}
	return false;
}

template <class T, class U, class V, class W>
bool isIntersecting(Line <T, U, V, W> l1, Line <T, U, V, W> l2) {
	// the only time where two lines arent intersecting is when they're parallel
	if (isParallel(l1, l2)) {
		return false;
	}
	return true;
}

template <class T, class U, class V, class W>
Point<double, double> getIntersection(Line <T, U, V, W> l1, Line <T, U, V, W> l2) {
	double x = 0;
	double y = 0;

	// (m1)x + b1 = (m2)x + b2
	// x(m1 - m2) = b2 - b1
	// x = (b2 - b1)/(m1 - m2)

	x = (l2.getYIntersect() - l1.getYIntersect()) / (l1.getSlope() - l2.getSlope());
	
	// y = mx + b
	y = l1.getSlope() * x + l1.getYIntersect();

	return Point<double, double> (x, y);
}

int getAmount() {
	int amount = 0;

	cout << "How many points will you add? ";
	cin >> amount;

	// amount has to be >=2

	return amount;
}

Point<double, double>* getPoints(int amount) {
	// make an array of pointers of the given length
	Point<double, double>* pointArray = new Point<double, double> [amount];

	Point<double, double> temp;

	for (int i = 0; i < amount; i++) {
		cout << "Point " << i + 1 << ": " << endl;
		cin >> temp;
		pointArray[i] = temp;
		cout << endl;
	}

	return pointArray;
}

Line <double, double, double, double> bestApproximate(Point<double, double>* pointArray, int amount) {
	double x = 0;
	double y = 0;
	double xy = 0;
	double xx = 0;
	double m = 0;

	for (int i = 0; i < amount; i++) {
		x += pointArray[i].getX();
		y += pointArray[i].getY();
		xy += pointArray[i].getX() * pointArray[i].getY();
		xx += (pointArray[i].getX() * pointArray[i].getX());
	}

	m = (amount * xy - x * y) / (amount * xx - (x * x));

	// y = mx + b
	// b = y - mx
	double b = (y - m * x) / amount;

	Point <double, double> p1(x, y);
	Point <double, double> p2(0, b);
	return Line <double, double, double, double> (p1, p2);
}

int main()
{
	/**
	// best approximate line tester
	cout << "Best Approximate Line Tester: " << endl;
	int amount = getAmount();
	Point <double, double>* pointArray = getPoints(amount);
	Line <double, double, double, double> line = bestApproximate(pointArray, amount);
	cout << line;
	

	// insertion operator tester for lines;
	cout << "Inseriton Tester: " << endl;
	Line<double, double, double, double> l1;
	cin >> l1;
	cout << endl << l1 << "\n\n";

	Line<double, double, double, double> l2;
	cin >> l2;
	cout << endl << l2 << "\n\n";
	*/

	// line realtion
	cout << "Line Relations Tester: " << endl;
	// y = 1x + 0
	Line<double, double, double, double> l3(0, 0, 1, 1);

	// y = -x + 0
	Line<double, double, double, double> l4(-1, 1, 0, 0);

	// y = x + 1
	Line<double, double, double, double> l5(0, 1, 1, 2);

	// y = 2x + 3;
	Line<double, double, double, double> l6(0, 3, 1, 5);

	cout << "Line3: " << "\n" << l3 << "\n" << 
		"Line4: " << "\n" << l4 << "\n" << 
		"Line5: " << "\n" << l5 << "\n" << 
		"Line6: " << "\n" << l6 << "\n";

	// if the two lines are parallel
	if (isParallel(l3, l5)) {
		cout << "Line3 and Line5 are parallel." << endl;
	}
	if (isPerpendicular(l3, l4)) {
		cout << "Line3 and Line4 are perpendicular." << endl;
	}
	if (isIntersecting(l3, l6)) {
		cout << "Line3 and Line6 are intersecting." << endl;
		cout << "They intersect at " << getIntersection(l3, l6) << endl;
	}

}
