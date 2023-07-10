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
#include <string>
#include <regex>
#include "Utils.h"

using namespace std;

namespace sdds {

    void clearBuffer()
    {
        while (getchar() != '\n')
        {
            
        }
    }

    bool getInt(int& src)
    {
        bool passed = true;
        
        unsigned value{};
        
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            clearBuffer();
            passed = false;
        }
        else
        {
            src = value;
        }
       
        return passed;
    }

    bool getInt(int& src, std::istream& is)
    {
        bool passed = true;

        is >> src;

        if (is.fail()) {
            is.clear();
            //clearBuffer();
            passed = false;
        }

        return passed;
    }

    unsigned getUnsignedRange(const int min, const int max, const char errMsg[])
    {
        int Value{};
        bool isValid;

        do {
            isValid = true;
            if (getInt(Value))
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