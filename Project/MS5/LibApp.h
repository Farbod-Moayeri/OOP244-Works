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

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include "Menu.h"

namespace sdds {


   class LibApp {
	   bool m_changed{};
       char m_pubFileName[]
	   Menu m_mainMenu;
	   Menu m_exitMenu;

	   bool confirm(const char* message);
       void load();  // prints: "Loading Data"<NEWLINE>
       void save();  // prints: "Saving Data"<NEWLINE>
       void search();  // prints: "Searching for publication"<NEWLINE>

       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */
       void newPublication();
       void removePublication();
       void checkOutPub();
   public:
       LibApp();
       void run();
   };
}
#endif // !SDDS_LIBAPP_H



