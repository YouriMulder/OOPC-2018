// example:
// definition of the functions of a rectangle object

#include "rectangle.hpp"
#include <iostream>

rectangle::rectangle(window & w, const vector & start, const vector & end,
                     bool filled, const vector & bounce):
	drawable(w, start, end - start, bounce),
	end(end),
	left(w, vector(start.x, start.y), vector(start.x, end.y)),
	right(w, vector(end.x,   start.y), vector(end.x,   end.y)),
	top(w, vector(start.x, start.y), vector(end.x,   start.y)),
	bottom(w, vector(start.x, end.y), vector(end.x,   end.y)),
	filled(filled)
{}

void rectangle::draw() {
	left.draw();
	right.draw();
	top.draw();
	bottom.draw();

	if(filled) {
		int locationXEnd = location.x + size.x;
		int locationYEnd = location.y + size.y;

		for(int x = location.x; x < locationXEnd; x++) {
			for(int y = location.y; y < locationYEnd; y++) {
				w.draw(vector(x, y));
			}
		}
	}
}
