/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Utils.h"

namespace sdds {

    void clearBuffer()
    {
        while (getchar() != '\n')
        {
            
        }
    }

    bool getUnsigned(unsigned& src)
    {
        bool passed = true;
        
        unsigned value{};

        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            clearBuffer();
            passed = false;
        }
        else
        {
            src = value;
        }
       
        return passed;
    }

    unsigned getUnsignedRange(unsigned min, unsigned max, char errMsg[])
    {
        unsigned Value{};
        bool isValid;

        do {
            isValid = true;
            if (getUnsigned(Value))
            {
                if (!(Value > (min - 1) && Value < (max + 1)))
                {
                    isValid = false;
                    if (errMsg != nullptr)
                    {
                        std::cout << errMsg;
                    }
                }
            }
        } while (!isValid);

        return Value;
    }
}