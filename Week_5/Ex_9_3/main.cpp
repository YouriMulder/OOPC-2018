#include "hwlib.hpp"
#include "pin-in-and.hpp"

int main( void ){	
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	namespace target = hwlib::target;
	
	auto led9 = target::pin_out(target::pins::d9);
	auto button1 = target::pin_in(target::pins::d7); 
	auto button2 = target::pin_in(target::pins::d6);
	auto buttonAnd = pin_in_and(button1, button2);
	
	while(true) {
		led9.set(buttonAnd.get());
	}
}