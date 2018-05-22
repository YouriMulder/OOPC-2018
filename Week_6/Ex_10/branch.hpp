#ifndef BRANCH_HPP
#define BRANCH_HPP

#include "vector.hpp"
#include "line.hpp"
#include "hwlib-graphics.hpp"

class branch : public line {
public:
	int length;
	float angle;
	int branchDepth;
	bool gotChilds;

public:
	branch(const vector& start = vector(0,0), int length = 0, int angle = 0,
	       int branchDepth = -1);
	void update();

};

#endif // BRANCH_HPP
