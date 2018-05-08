#include "victim.hpp"

victim::victim(window & w, const vector & start, const vector & end,
               int dissapearStepSize):
	rectangle(w, start, end),
	dissapearStepSize(dissapearStepSize),
	isTouched(false)
{}

void victim::update() {
	if(isTouched) {
		if(size.x <= 0 && size.y <= 0) {
			isTouched = false;
			return;
		}

		if(size.x <= dissapearStepSize) {
			size.x = 0;
		} else {
			size.x -= dissapearStepSize;
			location.x += dissapearStepSize/2;
		}

		if(size.y <= dissapearStepSize) {
			size.y = 0;
		} else {
			size.y -= dissapearStepSize;
			location.y += dissapearStepSize/2;
		}
		rectangle::update();
	}
}

void victim::interact(drawable & other) {
	if(this != & other) {
		if(overlaps(other)) {
			isTouched = true;
		}
	}
}
