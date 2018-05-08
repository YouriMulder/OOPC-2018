#include "wall.hpp"

wall::wall(window &w, const vector &start, const vector &end, int updateInterval,
           const vector & bounce):
	rectangle(w, start, end, 0, bounce),
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
