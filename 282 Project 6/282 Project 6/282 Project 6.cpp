// 282 Project 6.cpp
/////////////////////

#include "pch.h"
#include "Point.h"
#include "Line.h"
#include <iostream>
#include <string>

using namespace std;

// description: checks if two lines are paralell
// preconditions: l1, l2 - lines to compare
// postcondition:  T/F, if they're parallel or not
template <class T, class U, class V, class W>
bool isParallel(Line <T, U, V, W> l1, Line <T, U, V, W> l2) {
	if (l1.getSlope() == l2.getSlope()) {
		return true;
	}
	return false;
}

// description: checks if two lines are perpendicular
// preconditions: l1, l2 - lines to compare
// postcondition:  T/F, if they're perpendicular or not
template <class T, class U, class V, class W>
bool isPerpendicular(Line <T, U, V, W> l1, Line <T, U, V, W> l2) {
	// the slopes should be opposite and inverse
	// so 1/2 would be perp to -2/1; 1/2 * (-2/1) = - 1
	if (l1.getSlope() * l2.getSlope() == -1) {
		return true;
	}
	return false;
}

// description: checks if two lines are intersecting
// preconditions: l1, l2 - lines to compare
// postcondition:  T/F, if they're intersecting or not
template <class T, class U, class V, class W>
bool isIntersecting(Line <T, U, V, W> l1, Line <T, U, V, W> l2) {
	// the only time where two lines arent intersecting is when they're parallel
	if (isParallel(l1, l2)) {
		return false;
	}
	return true;
}

// description: gets the intersection of two lines
// preconditions: l1, l2 - lines to compare
// postcondition: point at which the two lines intesrect
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

// description: gets the amount of points the user will be entering
// postcondition: amount of points the user will enter
int getAmount() {
	int amount = 0;

	cout << "How many points will you add? ";
	cin >> amount;

	// amount has to be >=2

	return amount;
}

// description: gets an array of points that the user has entered
// preconditions: amount - amount of points they'll be entering
// postcondition: returns the array of all the points entered
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

// description: gets the best approximate line through all the points
// preconditions: array of points, and amount of points entered
// postcondition: line of best fit
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

	return Line <double, double, double, double> (0, b, 1, b + m);
}

int main()
{
	// line realtion
	cout << "Line Relations Tester: " << endl;
	// y = 1x + 0
	Line<double, double, double, double> line1(0, 0, 1, 1);

	// y = -x + 0
	Line<double, double, double, double> line2(-1, 1, 0, 0);

	// y = x + 1
	Line<double, double, double, double> line3(0, 1, 1, 2);

	// y = 2x + 3;
	Line<double, double, double, double> line4(0, 3, 1, 5);

	cout << "Line3: " << "\n" << line1 << "\n" <<
		"Line4: " << "\n" << line2 << "\n" <<
		"Line5: " << "\n" << line3 << "\n" <<
		"Line6: " << "\n" << line4 << "\n";

	// if the two lines are parallel
	if (isParallel(line1, line3)) {
		cout << "Line1 and Line3 are parallel." << endl;
	}
	if (isPerpendicular(line1, line2)) {
		cout << "Line1 and Line2 are perpendicular." << endl;
	}
	if (isIntersecting(line1, line4)) {
		cout << "Line1 and Line4 are intersecting." << endl;
		cout << "They intersect at " << getIntersection(line1, line4) << endl;
	}
	

	// best approximate line tester
	cout << endl << "Best Approximate Line Tester: " << endl;
	int amount = getAmount();
	Point <double, double>* pointArray = getPoints(amount);
	Line <double, double, double, double> line = bestApproximate(pointArray, amount);
	cout << line;
	

	// insertion operator tester for lines;
	cout << endl << "Line Inseriton Tester: " << endl;
	Line<double, double, double, double> l1;
	cin >> l1;
	cout << endl << line << "\n\n";


	cout << endl << "Point Inseriton Tester: " << endl;
	Point<double, double> point;
	cin >> point;
	cout << endl << point << "\n\n";
	

	return 0;
}
