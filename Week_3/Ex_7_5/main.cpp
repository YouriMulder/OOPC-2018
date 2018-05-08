#include <array>
#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "wall.hpp"

int main() {
	window w(vector(128, 64), 2);

	int fillToggleInterval = 10;
	int wallWidth = 4;
	vector bounceVertical = vector(-1, 1);
	vector bounceHorizontal = vector(1, -1);

	wall top(w, vector(0,  0), vector(127,  0 + wallWidth),
	         fillToggleInterval, bounceHorizontal);
	wall right(w, vector(127 - wallWidth,  0), vector(127, 63),
	           fillToggleInterval, bounceVertical);
	wall bottom(w, vector(0, 63 - wallWidth), vector(127, 63),
	            fillToggleInterval, bounceHorizontal);
	wall left(w, vector(0,  0), vector(0 + wallWidth, 63),
	          fillToggleInterval, bounceVertical);
	ball b(w, vector(50, 20), 9, vector(5, 2));

	std::array< drawable *, 5 > objects = { &b, &top, &left, &right, &bottom };

	for(;;) {
		w.clear();
		for(auto & p : objects) {
			p->draw();
		}
		wait_ms(200);
		for(auto & p : objects) {
			p->update();
		}
		for(auto & p : objects) {
			for(auto & other : objects) {
				p->interact(*other);
			}
		}
	}
}
