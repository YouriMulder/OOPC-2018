#include "hwlib.hpp"

int main(void) {
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;

	auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl1);
	auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda1);
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl,sda);

	auto display = hwlib::glcd_oled(i2c_bus, 0x3C);

	for(;;) {
		display.clear();
		for(uint16_t i = 10; i < display.size.x - 10; i++) {
			display.write(hwlib::location(i, 10), hwlib::black);
		}
		hwlib::wait_ms(100);
	}
}
