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

#include <iostream>
#include "ShoppingList.h"
#include "Utils.h"

using namespace std;
using namespace sdds;

// set to false when compling on Linux
const bool APP_OS_WINDOWS = true;

int listMenu();

int main() {
    bool done = false;
    loadList();
    while (!done) {
        system(APP_OS_WINDOWS ? "cls" : "clear");
        switch (listMenu()) {
        case 1:
            toggleBought();
            break;
        case 2:
            addItemToList();
            break;
        case 3:
            removeItemfromList();
            break;
        case 4:
            removeBoughtItems();
            break;
        case 5:
            clearList();
            break;
        default:
            done = true;
        }
    }
    saveList();
    return 0;
}

int listMenu() {
    cout << "-->>> My Shopping List <<<--" << endl;
    displayList();
    cout << "----------------------------" << endl
        << "1- Toggle bought Item" << endl
        << "2- Add Shopping Item" << endl
        << "3- Remove Shopping Item" << endl
        << "4- Remove bought Items" << endl
        << "5- Clear List" << endl
        << "0- Exit" << endl << "> ";
    return readInt(0, 5);
}