#ifndef led_HPP
#define led_HPP

#include "hwlib.hpp"

namespace led {
	void doubleLedKitt(hwlib::target::pin_out** pins, unsigned int amountOfPins, unsigned int msDelay = 100);
}

#endif // led_HPP
