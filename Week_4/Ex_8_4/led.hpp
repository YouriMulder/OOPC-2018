#ifndef led_HPP
#define led_HPP

#include "hwlib.hpp"

namespace led {
	void doubleLedKitt(hwlib::target::pin_out** pins, unsigned int amountOfPins, unsigned int msDelay = 100);
	void increaseDecreasePort(hwlib::port_in_out_from_pins& leds, hwlib::pin_in& increasePin, hwlib::pin_in& decreasePin);
}

#endif // led_HPP
