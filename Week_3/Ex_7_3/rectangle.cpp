// example:
// definition of the functions of a rectangle object

#include "rectangle.hpp"
#include <iostream>

rectangle::rectangle(window & w, const vector & start, const vector & end, bool filled):
	drawable(w, start, end - start),
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
		for(int y = 0; y < size.y; y++) {
			for(int x = 0; x < size.x; x++) {
				w.draw(vector(location.x + x, location.y + y));
			}
		}
	}
}
