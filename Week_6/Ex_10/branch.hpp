#ifndef BRANCH_HPP
#define BRANCH_HPP

#include "vector.hpp"
#include "line.hpp"
#include "hwlib-graphics.hpp"

class branch : public line {
public:
	static const int invalidLayer = -1;
	int length;
	float angle;
	int layer;
	bool gotChilds;

public:
	branch(const vector& start = vector(0,0), int length = 0, int angle = 0,
	       int layer = invalidLayer);
};

#endif // BRANCH_HPP
