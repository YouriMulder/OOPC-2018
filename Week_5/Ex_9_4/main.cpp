#include "hwlib.hpp"
#include "pin-out-invert.hpp"
#include "pin-out-all.hpp"

int main( void ){	
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	namespace target = hwlib::target;
	
//	auto led_9  = target::pin_out(target::pins::d9 );
//	auto led_10 = target::pin_out(target::pins::d10);
//	auto led_11 = target::pin_out(target::pins::d11);
//	auto led_12 = target::pin_out(target::pins::d12);
//	
//	auto ds   = target::pin_out(target::pins::d5);
//	auto shcp = target::pin_out(target::pins::d4);
//	auto stcp = target::pin_out(target::pins::d3);
//
//	auto spiBus  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
//					stcp, ds, hwlib::pin_in_dummy);
//
//	auto hc595 = hwlib::hc595(spiBus, shcp);
//	
//	auto all_1 = hwlib::pin_out_all(led_9, led_10, led_11, led_12);
//	auto all_2 = hwlib::pin_out_all(hc595.p0, hc595.p1, hc595.p2, hc595.p3);
//
//	
//	auto hwlib::hwlib::port_out_from_pins(all_1, all_2);
	
	hwlib::wait_ms(100);
	
	auto led9     = target::pin_out( target::pins::d9 );
	auto led10     = target::pin_out( target::pins::d10 );
	auto led11 = target::pin_out( target::pins::d11);
	auto led12 = target::pin_out( target::pins::d12 );
	
	auto ds   = target::pin_out(target::pins::d5);
	auto shcp = target::pin_out(target::pins::d4);
	auto stcp = target::pin_out(target::pins::d3);

	auto spiBus  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
					stcp, ds, hwlib::pin_in_dummy);

	auto hc595 = hwlib::hc595(spiBus, shcp);
	
	auto ledp0 = pin_out_invert(hc595.p0);
	auto ledp1 = pin_out_invert(hc595.p1);
	auto ledp2 = pin_out_invert(hc595.p2);
	auto ledp3 = pin_out_invert(hc595.p3);
	
	auto leds = pin_out_all(led9, led10, led11, led12, ledp0, ledp1, ledp2, ledp3);
	auto leds_port = hwlib::port_out_from_pins(leds, leds);
	for(;;) {
	hwlib::kitt(leds_port, 500);
	}
}