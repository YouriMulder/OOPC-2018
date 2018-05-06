#ifndef WALL_HPP
#define WALL_HPP

#include "window.hpp"
#include "rectangle.hpp"
#include "vector.hpp"

class Wall : public rectangle {
private:
	window &w;

	bool filled;
	int update_interval;
	int update_count;

public:
	Wall(window& w, const vector& start, const vector& end,
		int update_interval);

	void update();
	void draw();

};

#endif /* WALL_HPP */
