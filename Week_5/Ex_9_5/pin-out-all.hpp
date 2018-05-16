#include "hwlib.hpp"

#include <array>

class pin_out_all : public hwlib::pin_out {
private:
   std::array< hwlib::pin_out *, 8 > list;     
   
public:

   pin_out_all( 
      hwlib::pin_out & p0, 
      hwlib::pin_out & p1 = hwlib::pin_out_dummy,  
      hwlib::pin_out & p2 = hwlib::pin_out_dummy, 
      hwlib::pin_out & p3 = hwlib::pin_out_dummy,
	  hwlib::pin_out & p4 = hwlib::pin_out_dummy,
	  hwlib::pin_out & p5 = hwlib::pin_out_dummy,
	  hwlib::pin_out & p6 = hwlib::pin_out_dummy,
	  hwlib::pin_out & p7 = hwlib::pin_out_dummy
   );
   
   void set(bool v, 
			hwlib::buffering buf = hwlib::buffering::unbuffered  
			) override;
};
