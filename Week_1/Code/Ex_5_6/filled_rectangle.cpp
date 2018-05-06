#include "filled_rectangle.hpp"

Filled_rectangle::Filled_rectangle(window& w, const int& p_start_x,
                                   const int& p_start_y, const int& p_end_x,
                                   const int& p_end_y):
	w(w),
	p_start_x(p_start_x),
	p_start_y(p_start_y),
	p_end_x(p_end_x),
	p_end_y(p_end_y)
{}

void Filled_rectangle::draw() {
	for(int x = 0; x <= (p_end_x - p_start_x); x++) {
		for(int y = 0; y <= (p_end_y - p_start_y); y++) {
			w.draw(p_start_x + x, p_start_y + y);
		}
	}
}
