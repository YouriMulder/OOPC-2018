#include "led.hpp"

namespace led {		
	void doubleLed (hwlib::port_out_from_pins& pins, unsigned int firstOnLed, unsigned int msDelay ) {
		pins.set( 0x03 << firstOnLed );
		hwlib::wait_ms( msDelay );
		pins.set( 0x00 );
	}
	
	void doubleKitt( hwlib::port_out_from_pins& pins, unsigned int msDelay ) {
		for( unsigned int i = 0; i < pins.number_of_pins() - 1; i++ ) {
			doubleLed( pins, i, msDelay );
		}
		for( unsigned int i = pins.number_of_pins() - 3; i > 0; i-- ) {
			doubleLed( pins, i, msDelay );
		}
	}
	
	uint16_t intToBits(unsigned int value) {
		uint16_t bits = 0;
		for(unsigned int i = 0; i < value; i++) {
			bits = bits | (0x01 << i);
		}
		return bits;
	}
	
	// note that the input pins are active low
	void increaseDecreasePort( hwlib::port_out_from_pins& leds, hwlib::pin_in& increasePin, hwlib::pin_in& decreasePin ) {
		unsigned int ledValue = 0;
		bool increasePreviousState, decreasePreviousState = false;
		
		for(;;) {			
			ledValue += ( ledValue < leds.number_of_pins() && 
						  increasePreviousState != increasePin.get() && 
						  !increasePin.get() );
			ledValue -= ( ledValue > 0 &&
						  decreasePreviousState != decreasePin.get() && 
						  !decreasePin.get() );
			
			leds.set(intToBits(ledValue));
			
			increasePreviousState = increasePin.get();
			decreasePreviousState = decreasePin.get();
			hwlib::wait_ms(1);
		}
	}
	
}