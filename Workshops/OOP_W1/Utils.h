///////////////////////////////////////////////////////
// Workshop 1
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

#ifndef SDDS_UTILS_H 
#define SDDS_UTILS_H

namespace sdds {

	void flushkeys();

	bool ValidYesResponse(char ch);

	bool yes();

	void readCstr(char cstr[], int len);

	int readInt(int min, int max);

}

#endif
