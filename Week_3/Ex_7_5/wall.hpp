#ifndef WALL_HPP
#define WALL_HPP

#include "rectangle.hpp"
#include "vector.hpp"

class wall : public rectangle {
private:
	unsigned int updateInterval;
	unsigned int updateCount;

public:
	wall(window &w, const vector & start, const vector & end, int updateInterval,
	     const vector& bounce);
	void update() override;
};

#endif // WALL_HPP
