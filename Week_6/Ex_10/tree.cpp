#include "tree.hpp"

tree::tree(const vector& start, int length, int angle):
	root(start, length, angle), subRoot(root.end, length/2, angle + 20)
{}


