#include <iostream>
#include "book.hpp"
using namespace std;

void book::print() {
	print_title();
	print_author();
	print_text();
}

void book::print_title() {
	cout << title << endl;
}

void book::print_author() {
	cout << author << endl;
}

void book::print_text() {
	cout << text << endl;
}
