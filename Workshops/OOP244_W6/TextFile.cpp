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
           if (m_filename != nullptr)
           {
               delete[] m_filename;
               m_filename = nullptr;
           }

           if (!isCopy)
           {
               m_filename = new char[strlen(fname) + 1];
               strcpy(m_filename, fname);
           }
           else
           {
               m_filename = new char[strlen(fname) + strlen("C_") + 1];
               strCpy(m_filename, "C_");
               strCat(m_filename, fname);
           }
       }
   }

   void TextFile::setNoOfLines()
   {
       int i{};
       char ch{};

       ifstream file{};
       file.open(m_filename, ios_base::in);

       if (file.is_open())
       {
           while (file.get(ch))
           {
               if (ch == '\n')
               {
                   i++;
               }
           }
       }
       else
       {
           cerr << "ERROR: Cannot open " << m_filename << " at member function setNoOfLines!";
           exit(1);
       }

       file.close();

       if (i == 0)
       {
           setEmpty();
       }
       else
       {
           m_noOfLines = i + 1;
       }

   }

   void TextFile::loadText()
   {
       int i{};
       ifstream file{};
       string singleLine{};
       file.open(m_filename, ios_base::in);

       if (m_filename != nullptr)
       {
           if (m_textLines != nullptr)
           {
               delete[] m_textLines;
               m_textLines = nullptr;
           }

           if (m_noOfLines > 0)
           {
               m_textLines = new Line[m_noOfLines];
               
               if (file.is_open())
               {
               
                   while (getline(file, singleLine))
                   {
                       m_textLines[i].m_value = new char[strLen(singleLine.c_str()) + 1];
                       strCpy(m_textLines[i].m_value, singleLine.c_str());
                       i++;
                   }
               }
               else
               {
                   cerr << "ERROR: Cannot open " << m_filename <<" at member function loadText!";
                   exit(1);
               }
           }

           m_noOfLines = i;

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