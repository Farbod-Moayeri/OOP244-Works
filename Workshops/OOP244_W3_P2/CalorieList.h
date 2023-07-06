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

#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"

namespace sdds {

    class CalorieList
    {
        int C_foodsAdded;
        int C_numFoods;
        int C_totalCals;
        Food* C_List;
        bool isValid()const;

    public:
        bool init(int num);
        bool add(const char name[], int calories, int type);
        void display()const;
        void deallocate();
        CalorieList();
        ~CalorieList();
    };

    
}
#endif // !SDDS_TRANSCRIPT_H
