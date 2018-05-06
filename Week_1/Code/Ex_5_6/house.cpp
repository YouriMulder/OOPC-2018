#include "house.hpp"
#include <iostream>
using namespace std;

House::House(window& w):
	w(w),
	base_height(20),
	base_width(40),
	bot_left_x(w.get_x_size()/2 - (base_width/2)),
	bot_left_y(w.get_y_size()),

	roof_height(20),
	roof_bot_y(bot_left_y - base_height),
	roof_top_y(bot_left_y - base_height - roof_height),
	roof_x0(bot_left_x),
	roof_x1(bot_left_x  + base_width/2),
	roof_x2(bot_left_x + base_width),

	window_radius(roof_height/4),

	base(w, bot_left_x, (bot_left_y - base_height), (bot_left_x + base_width),
	     bot_left_y),
	roof(w, roof_x0, roof_bot_y, roof_x1, roof_top_y, roof_x2, roof_bot_y),

	framework(w, roof_x1, roof_top_y + (roof_height/2), window_radius)
{}

House::House(window& w,
             const int& bot_left_x, const int& bot_left_y,
             const int& base_height, const int& base_width,
             const int& roof_height):
	w(w),
	base_height(base_height),
	base_width(base_width),
	bot_left_x(bot_left_x),
	bot_left_y(bot_left_y),

	roof_height(roof_height),
	roof_bot_y(bot_left_y - base_height),
	roof_top_y(bot_left_y - base_height - roof_height),
	roof_x0(bot_left_x),
	roof_x1(bot_left_x  + base_width/2),
	roof_x2(bot_left_x + base_width),

	window_radius(roof_height/5),

	base(w, bot_left_x, (bot_left_y - base_height), (bot_left_x + base_width),
	     bot_left_y),
	roof(w, roof_x0, roof_bot_y, roof_x1, roof_top_y, roof_x2, roof_bot_y),

	framework(w, roof_x1, roof_top_y + (roof_height/2), window_radius)
{}

void House::draw() {
	base.draw();
	roof.draw();
	framework.draw();
}
