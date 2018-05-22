#ifndef TREE_HPP
#define TREE_HPP

#include "branch.hpp"
#include <array>

class tree {
public:
	tree(const vector& start, int length, int angle);

	float shrinkSize = 0.80;
	int angleOffset = 45;
	static const int amountOfBranches = 100;
	branch branches[amountOfBranches];


public:
	int getHighestLayer();
	int getFirstEmptyBranchIndex();
	void addNewBranchChilds(const branch& parentBranch);
	void addNewLayer();
	void addNewLayers(unsigned int amountOfNewLayers);
	void draw(hwlib::window& w);
};

#endif // TREE_HPP
