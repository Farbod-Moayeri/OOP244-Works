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

#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_

namespace sdds {

    const int NAME_LENGTH = 30;

    class Food
    {
        char f_Name[NAME_LENGTH + 1];
        int f_Cals;
        int f_Type;
        void empty();
    public:
        bool isValid()const;
        bool isEmpty()const;
        bool add(const char name[], int calories, int type);
        void display()const;
        Food();
        ~Food();
    };
}
#endif // !SDDS_TRANSCRIPT_H
