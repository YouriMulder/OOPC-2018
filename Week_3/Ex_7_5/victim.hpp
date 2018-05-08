#ifndef VICTIM_HPP
#define VICTIM_HPP

#include "vector.hpp"
#include "rectangle.hpp"

class victim : public rectangle {
public:
	int dissapearStepSize;
	bool isTouched;

public:
	victim(window & w, const vector & start, const vector & end,
	       int dissapearStepSize);
	void update() override;
	void interact(drawable & other) override;
};

#endif // VICTIM_HPP
