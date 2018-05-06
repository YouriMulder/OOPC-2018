#include "furniture.hpp"
#include <iostream>
using namespace std;


int main(int argc, char **argv) {
	Furniture f;
	cout << "Before: \n";
	f.print();

	f.makeMoreHipster();

	cout << "After: \n";
	f.print();
}
