#include "furniture.hpp"
#include <iostream>
using namespace std;

// Stool class
Stool::Stool(unsigned int n_legs, unsigned int n_seats):
	n_legs(n_legs),
	n_seats(n_seats)
{}

void Stool::print_n_legs() {
	cout << "Amount of legs: " << n_legs << '\n';
}

void Stool::print_n_seats() {
	cout << "Amount of seats: " << n_seats << '\n';
}
void Stool::print() {
	cout << "The specifications of this stool are: \n";
	print_n_legs();
	print_n_seats();
}

void Stool::remove_legs(unsigned int n_removed_legs) {
	n_legs -= n_removed_legs;
}

// Table class
Table::Table(unsigned int n_legs, int length, int width):
	n_legs(n_legs),
	length(length),
	width(width)
{}

void Table::add_legs(unsigned int n_added_legs) {
	n_legs += n_added_legs;
}

void Table::print_n_legs() {
	cout << "Amount of legs: " << n_legs << '\n';
}

void Table::print_width() {
	cout << "Width: " << width << '\n';
}

void Table::print_length() {
	cout << "Length: " << length << '\n';
}

void Table::print() {
	cout << "The specifications of this table are: \n";
	print_n_legs();
	print_width();
	print_length();

}

// Funtiture class
Furniture::Furniture():
	stool_0(4,1),
	stool_1(4,1),
	stool_2(4,1),
	stool_3(4,1),
	table(6, 100, 50)
{}

void Furniture::makeMoreHipster() {
	stool_0.remove_legs(1);
	stool_1.remove_legs(1);
	stool_2.remove_legs(1);
	stool_3.remove_legs(1);
	table.add_legs(4);
}

void Furniture::print() {
	stool_0.print();
	cout << '\n';
	stool_1.print();
	cout << '\n';
	stool_2.print();
	cout << '\n';
	stool_3.print();
	cout << '\n';
	table.print();
	cout << '\n';
}
