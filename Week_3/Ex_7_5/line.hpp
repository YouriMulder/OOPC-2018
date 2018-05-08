#ifndef LINE_HPP
#define LINE_HPP

#include "window.hpp"
#include "vector.hpp"
#include "drawable.hpp"

class line : public drawable {
private:
	vector end;
public:
	line(window & w, const vector & location, const vector & end):
		drawable(w, location, end - location),
		end(end)
	{}
	void draw() override;

	void setEnd(vector newEnd);
	void setStart(vector newStart);
	void setStartAndEnd(const vector & newStart, const vector & newEnd);

};

#endif // LINE_HPP
