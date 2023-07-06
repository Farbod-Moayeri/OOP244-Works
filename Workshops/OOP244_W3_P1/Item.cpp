///////////////////////////////////////////////////////
// Workshop 3
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Item.h"

using namespace std;

namespace sdds {

	void Item::setName(const char* name)
	{
		if (name != nullptr)
		{
			strnCpy(m_itemName, name, MAX_LENGTH);
		}
	}

	void Item::setEmpty()
	{
		m_itemName[0] = '\0';
		m_price = 0.0;
		m_taxed = false;
	}

	void Item::set(const char* name, double price, bool taxed)
	{
		if (name == nullptr || price < 0.0)
		{
			setEmpty();
		}
		else
		{
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	void Item::display() const
	{
		if (isValid())
		{
			//cout << std::left << std::setfill('.') << std::setw(20) << "| " << m_itemName << " | "
			//	<< std::right << std::setfill(" ") << std::setw(7) << std::setprecision(2) << m_price << " | ";

			cout << left << "| "   << setfill('.') << setw(20) << m_itemName  << " | "
				<< right << setfill(' ') << setw(7) << setprecision(2) << fixed << m_price << " | ";
			if (m_taxed)
			{
				cout << "Yes";
			}
			else
			{
				cout << "No ";
			}
			cout << " |" << endl;
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}

	bool Item::isValid() const
	{
		bool isIt = false;

		if (m_itemName[0] == '\0' && m_price == 0.0 && m_taxed == false)
		{
			isIt = false;
		}
		else
		{
			isIt = true;
		}

		return isIt;
	}

	double Item::price() const
	{
		return m_price;
	}

	double Item::tax() const
	{
		return m_price * (TAX_RATE);
	}

	Item::Item()
	{
		setEmpty();
	}

	Item::~Item()
	{
		// No memory to free or file to close
		// No cleanup in general so this shall remain empty
	}


}
