#ifndef FURNITURE_HPP
#define FURNITURE_HPP

class Stool {
private:
	unsigned int n_legs = 0;
	unsigned int n_seats = 0;

public:
	Stool(unsigned int n_legs, unsigned int n_seats);

	void remove_legs(unsigned int n_removed_legs);

	void print_n_legs();
	void print_n_seats();
	void print();
};

class Table {
private:
	unsigned int n_legs = 0;
	float length = 0;
	float width = 0;

public:
	Table(unsigned int n_legs, int length, int width);

	void add_legs(unsigned int n_added_legs);

	void print_n_legs();
	void print_width();
	void print_length();
	void print();
};

class Furniture {
private:
	Stool stool_0, stool_1, stool_2, stool_3;
	Table table;

public:
	Furniture();

	void makeMoreHipster();

	void print();
};

#endif // FURNITURE_HPP
