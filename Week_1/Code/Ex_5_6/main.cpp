// example:
// using a line that requires its window

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "filled_rectangle.hpp"
#include "house.hpp"
#include "circle.hpp"

int main(int argc, char **argv) {
	window w(128, 64, 2);
	line diagonal_line(w, 5, 5, 30, 40);
	diagonal_line.print();

	//Filled_rectangle rect(w, 40, 40, 45, 45);
	//rect.draw();

	House h(w);
	House h2(w,90,60,20,30,20);
	h.draw();
	h2.draw();

	return 0;
}
