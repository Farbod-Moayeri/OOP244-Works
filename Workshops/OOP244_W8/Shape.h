
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <ostream>

namespace sdds {
	class Shape {
		virtual void draw(std::ostream& os) = 0;
		virtual void getSpecs(std::istream& is) = 0;
		virtual ~Shape() = 0;
	};
}


#endif // !SDDS_SHAPE_H

