#include "Menu.h"
#include "cstring.h"


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

		}

	}

}