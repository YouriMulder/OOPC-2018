#ifndef BRANCH_HPP
#define BRANCH_HPP

#include <array> 
#include "vector.hpp"
#include "line.hpp"
#include "hwlib-graphics.hpp"

class branch : public line {
private:
	int length;
	float angle;
	
public:
	branch(const vector& start, int length, int angle);
	void update();
};

#endif // BRANCH_HPP
