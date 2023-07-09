
#include <iomanip>
#include "Menu.h"
#include "cstring.h"
#include "Utils.h"

using namespace std;

namespace sdds {


	sdds::MenuItem::MenuItem(const char string[])
	{
		// everything is already set to null
		if (string != nullptr && string[0] != '\0' && m_item == nullptr)
		{
			m_length = strLen(string);
			m_item = new char[m_length + 1];
			strCpy(m_item, string);
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
		if (string != nullptr)
		{
			if (m_title != nullptr)
			{
				delete[] m_title;
				m_title = nullptr;
			}

			m_title = new char[strLen(string) + 1];
			strCpy(m_title, string);
		}

	}

	Menu::operator bool() const
	{
		return (m_ItemArray != nullptr && m_numItems != 0);
	}

	Menu::operator unsigned() const
	{
		return this->m_numItems;
	}

	unsigned Menu::operator~() const
	{
		displayMenu(cout);
		return getUnsignedRange(1, m_numItems - 1);
	}

	Menu& Menu::operator<<(const char* menuitemContent)
	{
		unsigned i;

		if (menuitemContent != nullptr && m_numItems < MAX_MENU_ITEMS)
		{
			for (i = 0; i < MAX_MENU_ITEMS && m_ItemArray[i] != nullptr; i++){}
			if (i < m_numItems)
			{
				m_ItemArray = new MenuItem[1];
				
			}
		}

		return *this;
	}

	std::ostream& Menu::displayTitle(std::ostream& ostr) const
	{
		if (m_title != nullptr)
		{
			ostr << m_title;
		}
		return ostr;
	}

	std::ostream& Menu::displayMenu(std::ostream& ostr) const
	{
		unsigned i;

		if (*this)
		{
			displayTitle(ostr) << ":" << '\n';
			for (i = 0; i < m_numItems; i++)
			{
				ostr << right <<setw(2) << i + 1 << "- " << left << setw(0) << m_ItemArray[i] << '\n';
			}
			ostr << " 0- Exit" << '\n' << "> ";
		}
	}

	unsigned Menu::run() const
	{
		displayMenu(cout);
		return getUnsignedRange(1, m_numItems - 1);
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

}