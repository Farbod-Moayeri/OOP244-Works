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

#include <iostream>
#include <cstring>
//#include "cstring.h"
#include "Rectangle.h"

namespace sdds {
	Rectangle::Rectangle() : LblShape::LblShape()
	{
		m_width = 0;
		m_height = 0;
	}
	Rectangle::Rectangle(const char label[], const int width, const int height) : LblShape::LblShape(label)
	{
		int incWidth = strlen(label) + 2;
		if(height < 3 || width < incWidth) 
		{
			m_height = 0;
			m_width = 0;
		}
		else
		{
			m_height = height;
			m_width = width;
		}

	}
	void Rectangle::getSpecs(std::istream& is)
	{
		char buf{};

		LblShape::getSpecs(is);
		is >> m_width;
		is.get(buf);
		if (buf == ',')
		{
			is >> m_height;
		}
		is.ignore(10000, '\n');
	}

	void Rectangle::draw(std::ostream& os) const
	{
		int i{};
		int j{};

		int strLabel = strlen(label());
		if (m_width != 0 && m_height != 0)
		{
			os << '+';
			for (i = 0; i < m_width - 2; i++)
			{
				os << '-';
			}
			os << '+' << '\n';
			os << '|';
			os << std::left << label(); // added space
			for (i = 0; i < m_width - 2 - strLabel; i++)
			{
				os << ' ';
			}
			os << '|' << '\n';

			for (j = 0; j < m_height - 3; j++)
			{
				os << '|';
				for (i = 0; i < m_width - 2; i++)
				{
					os << ' ';
				}
				os << '|' << '\n';
			}

			os << '+';
			for (i = 0; i < m_width - 2; i++)
			{
				os << '-';
			}
			os << '+' ;
		}
	}

}