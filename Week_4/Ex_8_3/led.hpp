#ifndef led_HPP
#define led_HPP

#include "hwlib.hpp"

namespace led {
	void doubleLed(hwlib::port_out_from_pins& pins, unsigned int firstOnLed, unsigned int msDelay);
	void doubleKitt(hwlib::port_out_from_pins& pins, unsigned int msDelay = 100);
}

#endif // led_HPP
