#include "branch.hpp"

branch::branch(const vector& start, int length, int angle, int branchDepth):
	line(start, start.calculateEndVector(length, angle)), length(length),
	angle(angle), gotChilds(false) {
}


void branch::update() {
	char in;
	hwlib::cin >> in;
	if(in == 'w') {
		angle += -3.14/4;

	}
	end = start.calculateEndVector(length, angle);
}
