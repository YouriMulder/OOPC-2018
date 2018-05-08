#include <array>
#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "wall.hpp"
#include "victim.hpp"
#include <iostream>

int main() {
	int windowStart = 0;
	int windowWidth = 128;
	int windowHeight = 64;
	int usableWindowWidth = windowWidth - 1;
	int usableWindowHeight = windowHeight - 1;
	window w(vector(windowWidth, windowHeight), 2);

	int fillToggleInterval = 10;
	int wallWidth = 4;
	vector bounceVertical = vector(-1, 1);
	vector bounceHorizontal = vector(1, -1);

	wall top(w, vector(windowStart,  windowStart),
	         vector(usableWindowWidth,  wallWidth),
	         fillToggleInterval, bounceHorizontal);

	wall right(w, vector(usableWindowWidth - wallWidth,  windowStart),
	           vector(usableWindowWidth, usableWindowHeight),
	           fillToggleInterval, bounceVertical);

	wall bottom(w, vector(windowStart, usableWindowHeight - wallWidth),
	            vector(usableWindowWidth, usableWindowHeight),
	            fillToggleInterval, bounceHorizontal);

	wall left(w, vector(windowStart,  windowStart),
	          vector(windowStart + wallWidth, usableWindowHeight),
	          fillToggleInterval, bounceVertical);

	int victimWidth = 4;
	int victimHeight = 8;

	victim testVictim(w,
	                  vector(windowWidth/2 - victimWidth/2,
	                         windowHeight/2 - victimHeight/2),
	                  vector(windowWidth/2 + victimWidth/2,
	                         windowHeight/2 + victimHeight/2), 2);

	ball b(w, vector(50, 20), 9, vector(5, 2));

	std::array< drawable *, 6 > objects = { &b, &top, &left, &right, &bottom,
	                                        &testVictim
	                                      };

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
