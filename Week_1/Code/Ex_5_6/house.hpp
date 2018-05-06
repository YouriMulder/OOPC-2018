#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "filled_rectangle.hpp"
#include "line.hpp"
#include "window.hpp"
#include "triangle.hpp"
#include "circle.hpp"

class House {
private:
	window& w;
	int base_height, base_width;
	int bot_left_x, bot_left_y;

	int roof_height;
	int roof_bot_y;
	int roof_top_y;
	int roof_x0, roof_y0;
	int roof_x1, roof_y1;
	int roof_x2, roof_y2;

	int window_radius;

	Filled_rectangle base;
	Triangle roof;
	Circle framework;

public:
	House(window& w);
	House(window& w, const int& bot_left_x, const int& bot_left_y,
	      const int& base_height, const int& base_width, const int& roof_height);

	void draw();
};

#endif // HOUSE_HPP
