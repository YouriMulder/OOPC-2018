#include "branch.hpp"

branch::branch(const vector& start, int length, int angle, int layer):
	line(start, start.calculateEndVector(length, angle)), length(length),
	angle(angle), layer(layer), gotChilds(false) {
}