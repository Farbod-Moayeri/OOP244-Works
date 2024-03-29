#define _CRT_SECURE_NO_WARNINGS
///////////////////////////////////////////////////////
// MS1
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
// Section: NBB
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

#include <cstring>
#include <iomanip>
#include "Menu.h"
//#include "cstring.h" *wierd matrix error message that states that my strLen and strCpy functions do not have a reference, never happened before
#include "Utils.h"

using namespace std;

namespace sdds {


	sdds::MenuItem::MenuItem(const char string[])
	{
		// everything is already set to null
		if (string != nullptr && string[0] != '\0' && m_item == nullptr)
		{
			m_length = strlen(string);
			m_item = new char[m_length + 1];
			strcpy(m_item, string);
		}

	}


	sdds::MenuItem::~MenuItem()
	{
		if (m_item != nullptr)
		{
			delete[] m_item;
			m_item = nullptr;
		}
	}

	MenuItem::operator bool() const
	{
		return (m_item != nullptr && m_length != 0);
	}

	MenuItem::operator const char* () const
	{
		return m_item;
	}

	std::ostream& MenuItem::displayItem(std::ostream& ostr) const
	{
		if (&ostr != nullptr)
		{
			ostr << m_item;
		}

		return ostr;
	}

	sdds::Menu::Menu(const char string[])
	{

		unsigned len{};

		if (string != nullptr)
		{
			if (m_title.m_item != nullptr)
			{
				delete[] m_title.m_item;
				m_title.m_item = nullptr;
			}

			len = strlen(string);
			m_title.m_length = len;
			m_title.m_item = new char[len + 1];


			strcpy(m_title.m_item, string);
		}

	}

	Menu::~Menu()
	{
		unsigned i;

		if (m_ItemArray != nullptr)
		{
			for (i = 0; i < m_numItems; i++)
			{
				delete[] m_ItemArray[i];
				m_ItemArray[i] = nullptr;
			}
		}
	}

	Menu::operator bool() const
	{
		return (m_numItems > 0);
	}

	Menu::operator unsigned() const
	{
		return this->m_numItems;
	}

	Menu::operator int() const
	{
		return this->m_numItems;
	}

	unsigned Menu::operator~() const
	{
		return run();
	}

	Menu& Menu::operator<<(const char* menuitemContent)
	{
		unsigned i{};
		unsigned len{};

		if (menuitemContent != nullptr && m_numItems < MAX_MENU_ITEMS)
		{
			for (i = 0; i < MAX_MENU_ITEMS && m_ItemArray[i] != nullptr; i++){}
			if (i + 1 < MAX_MENU_ITEMS)
			{
				m_ItemArray[i] = new MenuItem[1];
				len = strlen(menuitemContent);
				m_ItemArray[i]->m_length = len;
				m_ItemArray[i]->m_item = new char[len + 1];
				strcpy(m_ItemArray[i]->m_item, menuitemContent);
				m_numItems++;
			}
		}

		return *this;
	}

	const char* Menu::operator[](unsigned index) const
	{
		unsigned i{};

		if (index > m_numItems)
		{
			i = index - m_numItems;
		}
		else
		{
			i = index;
		}

		return (const char*)m_ItemArray[i]->m_item;
	}

	std::ostream& Menu::displayTitle(std::ostream& ostr) const
	{
		if (m_title.m_item != nullptr)
		{
			ostr << m_title.m_item;
		}
		return ostr;
	}

	std::ostream& Menu::displayMenu(std::ostream& ostr) const
	{
		unsigned i;

		if (*this)
		{
			if (m_title.m_item != nullptr)
			{
				displayTitle(ostr) << ":" << '\n';
			}
			for (i = 0; i < m_numItems; i++)
			{
				if (m_ItemArray[i] != nullptr)
				{
					ostr << right << setw(2) << i + 1 << "- " << left << setw(0) << m_ItemArray[i]->m_item << '\n';
				}
				else
				{
					ostr << right << setw(2) << i + 1 << "- " << left << setw(0) << "Empty" << '\n';
				}
				
			}
			ostr << " 0- Exit" << '\n' << "> ";
		}

		return ostr;
	}

	unsigned Menu::run() const
	{
		unsigned temp;
		displayMenu(cout);
		temp = getUnsignedRange(0, m_numItems, "Invalid Selection, try again: ");
		return temp;
	}

	

	
	std::ostream& operator<<(ostream& ostr, const Menu& right)
	{
		right.displayTitle(ostr);

		return ostr;
	}

}