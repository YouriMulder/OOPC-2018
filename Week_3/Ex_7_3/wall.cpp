#include "wall.hpp"

Wall::Wall(window& w, const vector& start, const vector& end,
	int update_interval):
	rectangle(w, start, end), w(w), update_interval(update_interval)
{}

void Wall::update() {

}

void Wall::draw() {

}
