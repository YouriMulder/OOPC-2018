#include "hwlib.hpp"
#include "led.hpp"

int main( void ){	
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	auto led9  = hwlib::target::pin_in_out(  hwlib::target::pins::d9  );
	auto led10 = hwlib::target::pin_in_out(  hwlib::target::pins::d10 );
	auto led11 = hwlib::target::pin_in_out(  hwlib::target::pins::d11 );
	auto led12 = hwlib::target::pin_in_out(  hwlib::target::pins::d12 );
	auto leds = hwlib::port_in_out_from_pins( led9, led10, led11, led12);
	leds.direction_set_output();
	auto buttonDecrease = hwlib::target::pin_in( hwlib::target::pins::d7  ); 
	auto buttonIncrease = hwlib::target::pin_in( hwlib::target::pins::d6  ); 
	
	// wait for the termial
	hwlib::wait_ms(100);
	
	bool stillPressed = false;
	while(true) {
		if(!stillPressed) {
			led::increaseDecreasePort(leds, buttonIncrease, buttonDecrease);
		}
		stillPressed = !(buttonDecrease.get() && buttonIncrease.get());
		hwlib::wait_ms(1);
	}
}