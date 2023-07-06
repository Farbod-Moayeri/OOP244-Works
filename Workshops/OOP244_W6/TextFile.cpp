#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
   }


   void TextFile::setFilename(const char* fname, bool isCopy)
   {
       if (fname != nullptr)
       {
           if (!isCopy)
           {
               if (m_filename != nullptr)
               {
                   delete[] m_filename;
                   m_filename = nullptr;
               }

               m_filename = new char[strlen(fname) + 1];

           }
           else
           {

           }
       }
   }

   void TextFile::setEmpty()
   {
       delete[] m_textLines;
       m_textLines = nullptr;
       delete[] m_filename;
       m_filename = nullptr;
       m_noOfLines = 0;
   }

}