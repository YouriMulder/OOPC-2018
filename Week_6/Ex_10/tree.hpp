#ifndef TREE_HPP
#define TREE_HPP

#include "branch.hpp"
#include <array>

class tree {
public:
	tree(const vector& start, int length, int angle);

	float shrinkSize = 0.68;
	int angleOffset = 20;
	const int amountOfBranches = 2;
	branch branches[100];


public:
	void addNewLayer();
};

#endif // TREE_HPP
