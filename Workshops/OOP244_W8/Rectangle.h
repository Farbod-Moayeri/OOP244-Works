#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "Line.h"

namespace sdds {
	class Rectangle : public Line {
		int m_width{};
		int m_height{};

		Rectangle();
		Rectangle(char label[], const int width, const int height);

		~Rectangle() {};


	};
}
#endif // !SDDS_RECTANGLE_H
