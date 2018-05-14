#include "victim.hpp"

victim::victim(window & w, const vector & start, const vector & end,
               int disapearStepSize):
	rectangle(w, start, end),
	disapearStepSize(disapearStepSize),
	isTouched(false)
{}

void victim::update() {
	if(isTouched) {
		if(size.x <= 0 && size.y <= 0) {
			isTouched = false;
			return;
		}

		if(size.x <= disapearStepSize) {
			size.x = 0;
		} else {
			size.x -= disapearStepSize;
			location.x += disapearStepSize/2;
		}

		if(size.y <= disapearStepSize) {
			size.y = 0;
		} else {
			size.y -= disapearStepSize;
			location.y += disapearStepSize/2;
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
