#include "branch.hpp"

branch::branch(const vector& start, int length, int angle):
	line(start, start.calculateEndVector(length, angle)), length(length), angle(angle)
{}


void branch::update() {
	char in;
	hwlib::cin >> in;
	if(in == 'w') {
		angle += -3.14/4;

	}
	end = start.calculateEndVector(length, angle);
}



