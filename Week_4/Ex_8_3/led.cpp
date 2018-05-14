#include "led.hpp"

namespace led {		
	void doubleLedKitt(hwlib::target::pin_out** pins, unsigned int amountOfPins, unsigned int msDelay) {
		for(unsigned int i = 0; i < amountOfPins - 1; i++) {
			pins[i    ]->set(1);
			pins[i + 1]->set(1);
			hwlib::wait_ms(msDelay);
			pins[i    ]->set(0);
			pins[i + 1]->set(0);
		}
		for(unsigned int i = amountOfPins - 3; i > 0; i--) {
			pins[i    ]->set(1);
			pins[i + 1]->set(1);
			hwlib::wait_ms(msDelay);
			pins[i    ]->set(0);
			pins[i + 1]->set(0);
		}
	}
}