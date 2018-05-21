#ifndef TREE_HPP
#define TREE_HPP

#include "branch.hpp"

class tree{
public:
	branch root;
	branch subRoot;
public:
	tree(const vector& start, int length, int angle);
	
};

#endif // TREE_HPP
