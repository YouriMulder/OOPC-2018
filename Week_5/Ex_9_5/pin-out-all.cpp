#include "pin-out-all.hpp"
#include "hwlib.hpp"

pin_out_all::pin_out_all( 
      hwlib::pin_out & p0, 
      hwlib::pin_out & p1,  
      hwlib::pin_out & p2, 
      hwlib::pin_out & p3,
	  hwlib::pin_out & p4, 
      hwlib::pin_out & p5, 
	  hwlib::pin_out & p6, 
      hwlib::pin_out & p7 
   ): list{ &p0, &p1, &p2, &p3, &p4, &p5, &p6, &p7, }
{}

void pin_out_all::set(bool v, 
		hwlib::buffering buf){
			for( auto p  : list ){ p->set( v );}
		}