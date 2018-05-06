#ifndef FILLED_RECTANGLE_HPP
#define FILLED_RECTANGLE_HPP

#include "window.hpp"

class Filled_rectangle {
	window& w;
	int p_start_x;
	int p_start_y;
	int p_end_x;
	int p_end_y;

public:
	Filled_rectangle(window& w, const int& p_start_x, const int& p_start_y,
	                 const int& p_end_x, const int& p_end_y);

	void draw();
};

#endif // FILLED_RECTANGLE
