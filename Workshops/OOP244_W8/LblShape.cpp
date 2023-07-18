///////////////////////////////////////////////////////
// Workshop 8
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "cstring.h"
#include "LblShape.h"

namespace sdds {


    char* LblShape::label() const
    {
        return m_label;
    }

    LblShape::LblShape(char string[])
    {
        if (string != nullptr)
        {
            m_label = new char[strLen(string) + 1];
            strCpy(m_label, string);
        }
    }

    LblShape::~LblShape()
    {
        delete[] m_label;
        m_label = nullptr;
    }
    void LblShape::getSpecs(std::istream& is)
    {
        char buf;
        std::string input{};

        while (is.get(buf) && buf != ',')
        {
            input += buf;
        }

        if (buf == ',')
        {
            delete[] m_label;
            m_label = new char[strLen(input.c_str()) + 1];
            strCpy(m_label, input.c_str());
        }
        
    }
}
