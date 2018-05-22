#include "tree.hpp"
#include "hwlib.hpp"


tree::tree(const vector& start, int length, int angle) {
	branch root = branch(start, length, angle, 0);
	branches[0] = root;
}

void tree::addNewLayer() {

}
