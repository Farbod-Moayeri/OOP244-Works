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

#ifndef SDDS_SHOPPINGLIST_H 
#define SDDS_SHOPPINGLIST_H

#define MAX_NO_OF_RECS 15

namespace sdds {

	bool loadList();

	void displayList();

	void removeBoughtItems();

	void removeItem(int index);

	bool saveList();

	void clearList();

	void toggleBought();

	void addItemToList();

	void removeItemfromList();

	bool listIsEmpty();

}
#endif
