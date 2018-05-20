#include "hwlib-all.hpp"
#include "hwlib-defines.hpp"
#include "hwlib-panic.hpp"
#include "hwlib-common.hpp"
#include "hwlib-pin.hpp"
#include "hwlib-pin-dummies.hpp"
#include "hwlib-pin-decorators.hpp"
#include "hwlib-port.hpp"
#include "hwlib-port-from-pins.hpp"
#include "hwlib-port-decorators.hpp"
#include "hwlib-adc.hpp"
#include "hwlib-dac.hpp"
#include "hwlib-console.hpp"
#include "hwlib-graphics.hpp"
#include "hwlib-wait.hpp"
#include "hwlib-ostream.hpp"
#include "hwlib-i2c.hpp"
#include "hwlib-pcf8574a.hpp"
#include "hwlib-pcf8591.hpp"
#include "hwlib-spi.hpp"
#include "hwlib-hc595.hpp"
#include "hwlib-hd44780.hpp"
#include "hwlib-glcd-5510.hpp"
#include "hwlib-glcd-oled.hpp"
#include "hwlib-matrix-keypad.hpp"
#include "hwlib-string.hpp"
#include "hwlib-demo.hpp'

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
