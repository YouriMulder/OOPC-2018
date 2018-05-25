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
};


#endif // VECTOR_HPP
