#include "pin-in-and.hpp"

pin_in_and::pin_in_and(hwlib::pin_in & slave1, hwlib::pin_in & slave2):
	slave1(slave1), slave2(slave2) {}
	
bool pin_in_and::get(hwlib::buffering buf){
		return (slave1.get() && slave2.get());
}
