#include "book.hpp"
#include <iostream>

int main(int argc, char **argv) {
	book b("Dit boek gaat helemaal nergens over", "Youri Mulder", "C++ voor dummies");
	b.print();
	std::cout << "heo" << std::endl;
}
