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
#include "Lib.h"
#include "Publication.h"


namespace sdds {


   class LibApp {
	   bool m_changed{};
       char m_pubFileName[SDDS_PUBLICATION_FILE_NAME + 1]{};
       Publication* m_PPA[SDDS_LIBRARY_CAPACITY]{};
       int m_NOLP{};
       int m_LLRN{};

       Menu m_publicationMenu;
	   Menu m_mainMenu;
	   Menu m_exitMenu;

       const Publication* const getPub(const int libRef) const;
	   bool confirm(const char* message);
       void load();  // prints: "Loading Data"<NEWLINE>
       void save();  // prints: "Saving Data"<NEWLINE>
       int search(const int type = SDDS_SEARCH_ALL) const;  // prints: "Searching for publication"<NEWLINE>

       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */
       void newPublication();
       void removePublication();
       void checkOutPub();
   public:
       // Rule of Three - Object is not meant to be copied in any way
       virtual ~LibApp();
       void LipApp(const LibApp inc) = delete;
       void operator=(const LibApp inc) = delete;
       LibApp(const char filename[]);
       void run();
   };
}
#endif // !SDDS_LIBAPP_H



