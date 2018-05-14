#include "hwlib.hpp"
#include "led.hpp"
int main( void ){	
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
   
	auto led9  = hwlib::target::pin_out( hwlib::target::pins::d9 );
	auto led10 = hwlib::target::pin_out( hwlib::target::pins::d10 );
	auto led11 = hwlib::target::pin_out( hwlib::target::pins::d11 );
	auto led12 = hwlib::target::pin_out( hwlib::target::pins::d12 );
	
	const int amountOfLeds = 4;
	hwlib::target::pin_out* leds[amountOfLeds] = { &led9, &led10, &led11, &led12 };
	while(true) {
		led::doubleLedKitt(leds, amountOfLeds, 1000);
	}
}