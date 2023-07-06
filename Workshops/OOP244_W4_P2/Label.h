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

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

#include <iostream>

namespace sdds {
    class Label {
        char* l_String;
        int l_length;
        char l_frame[8 + 1];
        void setNull();
        void setStringEmpty();
    public:
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();
        void readLabel();
        std::ostream& printLabel()const;
    };
}

#endif // !SDDS_LABEL_H
