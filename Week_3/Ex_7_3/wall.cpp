#include "wall.hpp"
#include <iostream>

wall::wall(window &w, const vector &start, const vector &end, int updateInterval):
	rectangle(w, start, end, 0),
	updateInterval(updateInterval),
	updateCount(0)
 {}
 
void wall::update() {
	if(updateCount == updateInterval) {
		filled = !filled;
		updateCount = 0;
	} else {
		updateCount++;
	}
}

