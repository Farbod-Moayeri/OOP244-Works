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

#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"

namespace sdds {

	class Line : public LblShape
	{
		int m_length{};
	public:
		Line();
		Line(const char string[], const int length);
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};
}
#endif // !SDDS_LINE_H
