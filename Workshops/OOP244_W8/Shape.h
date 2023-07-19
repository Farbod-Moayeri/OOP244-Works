///////////////////////////////////////////////////////
// Workshop 8
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <ostream>

namespace sdds {
	class Shape {

	public:
		virtual void draw(std::ostream& os) const = 0;
		virtual void getSpecs(std::istream& is) = 0;
		virtual ~Shape() {};
	};

	std::ostream& operator<<(std::ostream& left, const Shape& right);
	std::istream& operator>>(std::istream& left, Shape& right);
}


#endif // !SDDS_SHAPE_H

