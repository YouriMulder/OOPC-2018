#include "hwlib.hpp"
#include "led.hpp"

int main( void ){	
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	namespace target = hwlib::target;
	
	auto led9  = target::pin_out( target::pins::d9  );
	auto led10 = target::pin_out( target::pins::d10 );
	auto led11 = target::pin_out( target::pins::d11 );
	auto led12 = target::pin_out( target::pins::d12 );
	auto buttonDecrease = target::pin_in( target::pins::d7 ); 
	auto buttonIncrease = target::pin_in( target::pins::d6 );
	
	auto ds   = target::pin_out( target::pins::d5 );
	auto shcp = target::pin_out( target::pins::d4 );
	auto stcp = target::pin_out( target::pins::d3 );

	auto spiBus  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
					stcp, ds, hwlib::pin_in_dummy );

	auto hc595 = hwlib::hc595( spiBus, shcp );
		
	auto leds = hwlib::port_out_from_pins( 
      hc595.p0, 
      hc595.p1, 
      hc595.p2,
	  hc595.p3,
	  led12,
      led11,
      led10, 
	  led9 
   );

	
	hwlib::wait_ms(100);


	led::increaseDecreasePort(leds, buttonIncrease, buttonDecrease);
}