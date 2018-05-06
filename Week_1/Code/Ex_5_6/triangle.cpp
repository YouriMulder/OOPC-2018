#include "triangle.hpp"

Triangle::Triangle(window& w, const int& x0, const int& y0, const int& x1, const int& y1, const int& x2, const int& y2):
	l0(w,x0,y0,x1,y1),
	l1(w,x1,y1,x2,y2),
	l2(w,x2,y2,x0,y0)
{}

void Triangle::draw() {
	l0.print();
	l1.print();
	l2.print();
}
