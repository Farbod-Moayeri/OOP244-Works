///////////////////////////////////////////////////////
// Workshop 4
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H

#include "Label.h"

namespace sdds {
    class LabelMaker {
        
        int m_Ltotal;
        Label* m_Labels;

    public:
        LabelMaker(int noOfLabels);
        void readLabels();
        void printLabels();
        ~LabelMaker();
    };
}

#endif // !SDDS_LABELMAKER_H