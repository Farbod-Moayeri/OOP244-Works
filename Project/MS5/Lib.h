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

#ifndef SDDS_LIB_H
#define SDDS_LIB_H

namespace sdds {

    const int SDDS_MAX_LOAN_DAYS = 15;
    // maximum number of day a publication can be borrowed with no penalty
    const int SDDS_TITLE_WIDTH = 30;
    // The width in which the title of a publication should be printed on the console
    const int SDDS_AUTHOR_WIDTH = 15;
    // The width in which the author name of a book should be printed on the console
    const int SDDS_SHELF_ID_LEN = 4;
    // The width in which the shelf id of a publication should be printed on the console
    const int SDDS_PUBLICATION_FILE_NAME = 256;
    // The possible length the publication data file name can be
    const int SDDS_LIBRARY_CAPACITY = 5000; // 5000 normally
    // Maximum number of publications the library can hold
    const int SDDS_SEARCH_ALL = 1;
    const int SDDS_SEARCH_CHECKOUT = 2;
    const int SDDS_SEARCH_AVAILABLE = 3;
    // Search values for looking at library records
}

#endif // !1

