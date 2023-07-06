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

#ifndef SDDS_FILE_H 
#define SDDS_FILE_H

#include "ShoppingRec.h"

namespace sdds {

	bool openFileForRead();

	bool openFileForOverwrite();

	void closeFile();

	bool freadShoppingRec(ShoppingRec* rec);

	void fwriteShoppintRec(const ShoppingRec* rec);

}

#endif