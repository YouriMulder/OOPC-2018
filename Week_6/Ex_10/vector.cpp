#include "vector.hpp"
#include <cmath>

vector::vector(int x, int y):
	x(x), y(y)
{}

// Enter angle in degrees
vector vector::calculateEndVector(int length, float angle) const {
	angle *= 3.14/180;
	
	int dx = length * cos(angle);
	int dy = length * sin(angle);
	
	return vector(x + dx, y + dy);
}


