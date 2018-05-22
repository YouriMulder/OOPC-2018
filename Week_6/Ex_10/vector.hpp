#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <ostream>

class vector {
public:
	int x;
	int y;

public:
	vector(int x, int y);
	vector calculateEndVector(int length, float angle) const;

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};


#endif // VECTOR_HPP
