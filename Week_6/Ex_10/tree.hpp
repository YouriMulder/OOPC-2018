#ifndef TREE_HPP
#define TREE_HPP

#include "branch.hpp"
#include <array>

class tree : public branch {
public:
	tree(const vector& start, int length, int angle, int angleOffset = 45,
		float shrinkSize = 0.75);
	int angleOffset;
	float shrinkSize;

	static const int amountOfBranches = 100;
	branch branches[amountOfBranches];


public:
	int getHighestLayer();
	int getFirstEmptyBranchIndex();
	void addNewBranchChilds(branch& parentBranch);
	void addNewLayer();
	void addNewLayers(unsigned int amountOfNewLayers);
	void draw(hwlib::window& w);
};

#endif // TREE_HPP
