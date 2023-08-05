///////////////////////////////////////////////////////
// MS5
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
// Section: NBB
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

#include <iostream>

namespace sdds {

	const unsigned MAX_MENU_ITEMS = 20;

	class Menu;

	class MenuItem {
		char* m_item{};
		unsigned m_length{};
		// default constructor
		MenuItem(const char string[] = nullptr);
		// Rule of three : Not meant to be copied in any way
		MenuItem(const MenuItem& src) = delete;
		MenuItem& operator=(const MenuItem& src) = delete; 
		virtual ~MenuItem();
		// Determines if there is text in the menu, if there is true
		operator bool()const;
		// returns the address of m_item
		operator const char* const() const;
		// outputs m_item into ostream if it is not null
		std::ostream& displayItem(std::ostream& ostr)const;
		// Owner class Menu *wink wink*
		friend class Menu;
	};

	class Menu {
		
		MenuItem* m_ItemArray[MAX_MENU_ITEMS]{};
		unsigned m_numItems{};
		MenuItem m_title{};

		// Rule of three - not meant to be copied
		Menu(const Menu& src) = delete;
		Menu& operator=(const Menu& src) = delete;
		
		// owned
		friend MenuItem;
	public:

		Menu(const char string[] = nullptr);
		virtual ~Menu();
		operator bool()const;
		operator unsigned() const;
		operator int() const;
		unsigned operator~() const;
		Menu& operator<<(const char* menuitemContent);
		Menu& operator=(const char* title); //MS2: NEW
		const char* operator[](unsigned index) const;
		std::ostream& displayTitle(std::ostream& ostr = std::cout)const;
		std::ostream& displayMenu(std::ostream& ostr = std::cout)const;
		unsigned run(const char errMsg[] = "Invalid Selection, try again: ") const;
	};

	
	std::ostream& operator<<(std::ostream& ostr, const Menu& right);

}
#endif // !SDDS_MENU_H__