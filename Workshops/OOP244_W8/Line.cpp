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

#include <istream>
#include "Line.h"

namespace sdds {

	Line::Line() : LblShape::LblShape()
	{
		m_length = 0;
	}

	Line::Line(char string[], const int length) : LblShape::LblShape(string)
	{
		m_length = length;
	}

	void Line::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(10000, '\n');
	}

	void Line::draw(std::ostream& os)
	{
		int i{};

		if (m_length > 0 && label() != nullptr)
		{
			os << label() << '\n';
			for (i = 0; i < m_length; i++)
			{
				os << '=';
			}
		}
	}

}

