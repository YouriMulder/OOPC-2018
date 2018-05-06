#include "circle.hpp"
#include "window.hpp"
#include <math.h>
#include <iostream>
#define PI 3.14159

Circle::Circle(window& w, const int& x, const int& y, const int& radius):
	w(w),
	x(x),
	y(y),
	radius(radius)
{}

void Circle::draw() {
	// angle is 0.001 because it makes the circle round
	// otherwise there will be a little dot on the right
	for(double angle=0.001; angle<=PI*2 ; angle+=0.001) {
		w.draw(x + radius*cos(angle), y + radius*sin(angle));
	}
}
