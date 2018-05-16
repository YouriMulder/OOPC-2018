#ifndef LED_HPP
#define LED_HPP

#include "hwlib.hpp"

namespace led {
	uint16_t IntToBits(unsigned int value);
	void doubleLedKitt(hwlib::target::pin_out** pins, unsigned int amountOfPins, unsigned int msDelay = 100);
	void increaseDecreasePort(hwlib::port_out_from_pins& leds, hwlib::pin_in& increasePin, hwlib::pin_in& decreasePin);
}

#endif // led_HPP
