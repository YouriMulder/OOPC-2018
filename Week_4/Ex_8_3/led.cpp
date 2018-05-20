#include "led.hpp"

namespace led {		
	void doubleLed(hwlib::port_out_from_pins& pins, unsigned int firstOnLed, unsigned int msDelay) {
		pins.set(0x03 << firstOnLed);
		hwlib::wait_ms(msDelay);
		pins.set(0x00);
	}
	
	void doubleKitt(hwlib::port_out_from_pins& pins, unsigned int msDelay) {
		for(unsigned int i = 0; i < pins.number_of_pins() - 1; i++) {
			doubleLed(pins, i, msDelay);
		}
		for(unsigned int i = pins.number_of_pins() - 3; i > 0; i--) {
			doubleLed(pins, i, msDelay);
		}
	}
}