#include "line.hpp"

line::line(vector start, vector end):
	start(start), end(end)
{}

// hwlib
void line::swap( int_fast16_t & a, int_fast16_t & b ){
      auto t = a;
      a = b;
      b = t;
}

void line::draw(hwlib::window& w) {
	  int_fast16_t x0 = start.x;
      int_fast16_t y0 = start.y;
      int_fast16_t x1 = end.x;
      int_fast16_t y1 = end.y;
      // http://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
      // http://homepages.enterprise.net/murphy/thickline/index.html

      int_fast16_t Dx = x1 - x0;
      int_fast16_t Dy = y1 - y0;
      int_fast16_t steep = (abs(Dy) >= abs(Dx));

      if( steep ){
         swap( x0, y0 );
         swap( x1, y1 );

         // recompute Dx, Dy after swap
         Dx = x1 - x0;
         Dy = y1 - y0;
      }

      int_fast16_t xstep = 1;
      if( Dx < 0 ){
         xstep = -1;
         Dx = -Dx;
      }

      int_fast16_t ystep = 1;
      if( Dy < 0 ){
         ystep = -1;
         Dy = -Dy;
      }
      int_fast16_t TwoDy = 2*Dy;
      int_fast16_t TwoDyTwoDx = TwoDy - 2*Dx; // 2*Dy - 2*Dx
      int_fast16_t E = TwoDy - Dx; //2*Dy - Dx
      int_fast16_t y = y0;
      int_fast16_t xDraw, yDraw, x;
      for( x = x0; x != x1; x += xstep ){
         if (steep) {
            xDraw = y;
            yDraw = x;
         } else {
            xDraw = x;
            yDraw = y;
         }

         w.write( hwlib::location( xDraw, yDraw ) );

         if( E > 0 ){
            E += TwoDyTwoDx; //E += 2*Dy - 2*Dx;
            y = y + ystep;
         } else {
            E += TwoDy; //E += 2*Dy;
         }
      }
   }
