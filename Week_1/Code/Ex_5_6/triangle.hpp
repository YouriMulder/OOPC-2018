#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "line.hpp"
#include "window.hpp"

class Triangle {
private:
	line l0, l1, l2;
public:
	Triangle(window& w, const int& x0, const int& y0, const int& x1, const int& y1, const int& x2, const int& y2);
	void draw();
};

#endif // TRIANGLE_HPP
