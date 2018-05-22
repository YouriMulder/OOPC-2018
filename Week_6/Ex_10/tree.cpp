#include "tree.hpp"
#include "hwlib.hpp"


tree::tree(const vector& start, int length, int angle) {
	branch root = branch(start, length, angle, 0);
	branches[0] = root;
}

int tree::getHighestLayer() {
	int highestLayer = 0;
	for(const branch& b : branches) {
		if(b.layer > highestLayer) {
			highestLayer = b.layer;
		} else if(b.layer == -1) {
			return highestLayer;
		}
	}
	return highestLayer;
}

int tree::getFirstEmptyBranchIndex() {
	for(unsigned int i = 0; i < amountOfBranches; i++) {
		if(branches[i].layer == branch::invalidLayer) {
			return i;
		}
	}
	return -1;
}

void tree::addNewBranchChilds(const branch& parentBranch) {
	int firstEmptyBranch = getFirstEmptyBranchIndex();
	if(firstEmptyBranch != branch::invalidLayer) {
		branches[firstEmptyBranch] = branch(parentBranch.end, parentBranch.length * shrinkSize, 
		parentBranch.angle - angleOffset, parentBranch.layer + 1);
	}
	
	firstEmptyBranch = getFirstEmptyBranchIndex();
	if(firstEmptyBranch != branch::invalidLayer) {
		branches[firstEmptyBranch] = branch(parentBranch.end, parentBranch.length * shrinkSize, 
		parentBranch.angle + angleOffset, parentBranch.layer + 1);
	}
}

void tree::addNewLayer() {
	int currentHighestLayer = getHighestLayer();
	for(const branch& b : branches) {
		if(b.layer == currentHighestLayer) {
			addNewBranchChilds(b);
		}
	}
}

void tree::addNewLayers(unsigned int amountOfNewLayers) {
	for(unsigned int i = 0; i < amountOfNewLayers; i++) {
		addNewLayer();
	}
}

void tree::draw(hwlib::window& w) {
	for(branch& b : branches) {
		if(b.layer == branch::invalidLayer) { return; }
		b.draw(w);
	}
}