
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
namespace sdds {

	const unsigned MAX_MENU_ITEMS = 20;

	class Menu;

	class MenuItem {
		char* m_item{};
		unsigned m_length{};
		MenuItem(const char string[] = nullptr);
		MenuItem(const MenuItem& src) = delete;
		MenuItem& operator=(const MenuItem& src) = delete;
		~MenuItem();
		operator bool()const;
		operator const char* () const;
		std::ostream& displayItem(std::ostream& ostr)const;
		friend class Menu;
	};

	class Menu {
		Menu(const Menu& src) = delete;
		Menu& operator=(const Menu& src) = delete;
		char* m_title{};
		MenuItem *m_ItemArray[MAX_MENU_ITEMS];
		friend MenuItem;

	};

}
#endif // !SDDS_MENU_H__