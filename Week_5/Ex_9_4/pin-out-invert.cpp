#include "pin-out-invert.hpp"

void pin_out_invert::set(bool x, hwlib::buffering buf) {
	return slave.set(!x);
} 