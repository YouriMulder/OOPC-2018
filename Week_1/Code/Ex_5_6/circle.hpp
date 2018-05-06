#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "window.hpp"

class Circle {
	window w;
	int x, y;
	int radius;

public:
	Circle(window& w, const int& x, const int& y, const int& radius);
	void draw();
};

#endif // CIRCLE_HPP
