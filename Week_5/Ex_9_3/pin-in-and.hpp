#ifndef PIN_IN_AND_HPP
#define PIN_IN_AND_HPP

#include "hwlib.hpp"

class pin_in_and : public hwlib::pin_in {
private:
	hwlib::pin_in & slave1;
	hwlib::pin_in & slave2;
	
public:
	pin_in_and(hwlib::pin_in & slave1, hwlib::pin_in & slave2);
	bool get(hwlib::buffering buf = hwlib::buffering::unbuffered) override;

};

#endif // PIN_IN_AND_HPP
