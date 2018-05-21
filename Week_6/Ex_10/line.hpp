#ifndef LINE_HPP
#define LINE_HPP

#include "vector.hpp"
#include "hwlib.hpp"
#include <stdlib.h>

// https://www.tutorialspoint.com/computer_graphics/line_generation_algorithm.htm
class line {
public:
	vector start;
	vector end;
	
private:
	static void swap( int_fast16_t & a, int_fast16_t & b );
public:
	line(vector start, vector end);

	void draw(hwlib::window& w);	
};

#endif // LINE_HPP
