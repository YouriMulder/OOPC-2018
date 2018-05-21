#include "led.hpp"

namespace led {		
	uint16_t intToBits(unsigned int value) {
		uint16_t bits = 0;
		for(unsigned int i = 0; i < value; i++) {
			bits = bits | (0x01 << i);
		}
		return bits;
	}
	
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
	void increaseDecreasePort(hwlib::port_out_from_pins& leds, hwlib::pin_in& increasePin, hwlib::pin_in& decreasePin) {
		unsigned int ledValue = 0;
		bool increasePreviousState, decreasePreviousState = false;
		
		for(;;) {			
			ledValue += (ledValue < leds.number_of_pins() && increasePreviousState != increasePin.get() && !increasePin.get());
			ledValue -= (ledValue > 0 && !decreasePin.get() && decreasePreviousState != decreasePin.get() && !decreasePin.get());
			
			leds.set(intToBits(ledValue));
			
			increasePreviousState = increasePin.get();
			decreasePreviousState = decreasePin.get();
			hwlib::wait_ms(100);
		}
	}
	
}
	