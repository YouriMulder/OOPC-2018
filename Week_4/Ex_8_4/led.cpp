#include "led.hpp"

namespace led {		
	void doubleLedKitt(hwlib::target::pin_out** pins, unsigned int amountOfPins, unsigned int msDelay) {
		for(unsigned int i = 0; i < amountOfPins - 1; ++i) {
			pins[i    ]->set(1);
			pins[i + 1]->set(1);
			hwlib::wait_ms(msDelay);
			pins[i    ]->set(0);
			pins[i + 1]->set(0);
		}
		for(unsigned int i = amountOfPins - 3; i > 0; --i) {
			pins[i    ]->set(1);
			pins[i + 1]->set(1);
			hwlib::wait_ms(msDelay);
			pins[i    ]->set(0);
			pins[i + 1]->set(0);
		}
	}
	
	// note that the input pins are active low
	void increaseDecreasePort(hwlib::port_in_out_from_pins& leds, hwlib::pin_in& increasePin, hwlib::pin_in& decreasePin) {
		if(!increasePin.get()) {		
			leds.set(leds.get()*2+1);
		}
		if(!decreasePin.get()) {
			leds.set(leds.get()/2);
		}
	}
	
}