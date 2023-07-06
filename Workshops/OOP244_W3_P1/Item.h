///////////////////////////////////////////////////////
// Workshop 3
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_

#define MAX_LENGTH 20
#define TAX_RATE 0.13

namespace sdds {
    class Item {
        char m_itemName[MAX_LENGTH + 1];
        double m_price;
        bool m_taxed;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, double price, bool taxed);
        void display()const;
        bool isValid()const;
        double price()const;
        double tax()const;
        Item();
        ~Item();
    };
}

#endif // !SDDS_SUBJECT_H