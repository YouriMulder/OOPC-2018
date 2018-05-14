#ifndef VICTIM_HPP
#define VICTIM_HPP

#include "vector.hpp"
#include "rectangle.hpp"

class victim : public rectangle {
private:
	int disapearStepSize;
	bool isTouched;

public:
	victim(window & w, const vector & start, const vector & end,
	       int disapearStepSize);
	void update() override;
	void interact(drawable & other) override;
};

#endif // VICTIM_HPP
