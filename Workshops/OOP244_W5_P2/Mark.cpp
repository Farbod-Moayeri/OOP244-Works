///////////////////////////////////////////////////////
// Workshop 5
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

#include "Mark.h"

namespace sdds {
	void sdds::Mark::setEmpty()
	{
		this->m_Mark = -1;
	}

	int Mark::getMark() const
	{
		return m_Mark;
	}

	sdds::Mark::Mark()
	{
		m_Mark = 0;
	}

	sdds::Mark::Mark(const int number)
	{
		if (number > -1 && number < 101)
		{
			m_Mark = number;
		}
		else
		{
			setEmpty();
		}
	}

	sdds::Mark::operator bool() const
	{
		return (m_Mark > -1 && m_Mark < 101);
	}

	sdds::Mark::operator int() const
	{
		return *this ? m_Mark : 0;
	}

	Mark::operator double() const
	{
		double temp;

		if (*this)
		{
			if (m_Mark > 79)
			{
				temp = 4.0;
			}
			else if(m_Mark > 69)
			{
				temp = 3.0;
			}
			else if (m_Mark > 59)
			{
				temp = 2.0;
			}
			else if (m_Mark > 49)
			{
				temp = 1.0;
			}
			else
			{
				temp = 0.0;
			}
		}
		else
		{
			temp = 0.0;
		}

		return temp;
	}

	Mark::operator char() const
	{
		char temp;

		if (*this)
		{
			if (m_Mark > 79)
			{
				temp = 'A';
			}
			else if (m_Mark > 69)
			{
				temp = 'B';
			}
			else if (m_Mark > 59)
			{
				temp = 'C';
			}
			else if (m_Mark > 49)
			{
				temp = 'D';
			}
			else
			{
				temp = 'F';
			}
		}
		else
		{
			temp = 'X';
		}

		return temp;
	}

	bool sdds::Mark::operator~() const
	{
		return (m_Mark < 0);
	}

	Mark& Mark::operator=(const int src)
	{
		if (src > -1 && src < 101)
		{
			m_Mark = src;
		}
		else
		{
			setEmpty();
		}

		return *this;
	}

	Mark& sdds::Mark::operator+=(const int src) 
	{
		if (*this)
		{
			if ((src + m_Mark) < 101)
			{
				m_Mark += src;
			}
			else
			{
				setEmpty();
			}
		}
		
		return *this;
	}

	int& operator+=(int& src1, const Mark& src2)
	{

		if (src2)
		{
			src1 += src2.getMark();
		}

		return src1;
	}
}