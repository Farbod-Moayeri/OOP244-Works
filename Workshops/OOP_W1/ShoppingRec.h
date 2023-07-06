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

#ifndef SDDS_SHOPPINGREC_H 
#define SDDS_SHOPPINGREC_H

#define MAX_TITLE_LENGTH 50
#define MAX_QUANTITY_VALUE 50

namespace sdds {

    struct ShoppingRec
    {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };

    ShoppingRec getShoppingRec();

    void displayShoppingRec(const ShoppingRec* shp);

    void toggleBoughtFlag(ShoppingRec* rec);

    bool isShoppingRecEmpty(const ShoppingRec* shp);

}
#endif
