///////////////////////////////////////////////////////
// Workshop 9
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
// Section: NBB
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////
//#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
//#include <cstring>
#include "Text.h"
#include "cstring.h"

using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   const char& Text::operator[](int index) const
   {
       return m_content[index];
   }

   Text& Text::setEmpty()
   {
       delete[] m_filename;
       m_filename = nullptr;
       delete[] m_content;
       m_content = nullptr;

       return *this;
   }

   Text::Text(const char* filename)
   {
       if (filename != nullptr)
       {
           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);
           read();
       }
   }

   Text::Text(const Text& inc)
   {
       if (inc.m_filename != nullptr)
       {
           m_filename = new char[strLen(inc.m_filename) + 1];
           strCpy(m_filename, inc.m_filename);
           if (inc.m_content != nullptr)
           {
               m_content = new char[strLen(inc.m_content) + 1];
               strCpy(m_content, inc.m_content);
           }
           //read();
       }
   }

   Text& Text::operator=(const Text& inc)
   {
       if (this != &inc)
       {
           if (m_filename != nullptr)
           {
               delete[] m_filename;
               m_filename = nullptr;
           }
           
           if (m_content != nullptr)
           {
               delete[] m_content;
               m_content = nullptr;
           }

           if (inc.m_filename != nullptr)
           {
               m_filename = new char[strLen(inc.m_filename) + 1];
               strCpy(m_filename, inc.m_filename);
               if (inc.m_content != nullptr)
               {
                   m_content = new char[strLen(inc.m_content) + 1];
                   strCpy(m_content, inc.m_content);
               }
               //read();
           }
       }

       return *this;
   }

   Text::~Text()
   {
       delete[] m_filename;
       delete[] m_content;
   }

   void Text::read()
   {
       char d = 'a';
       int i{0};

       if (m_filename != nullptr)
       {
           
           m_content = new char[getFileLength() + 1];
           ifstream fin(m_filename);

           while (fin.get(d))
           {
               m_content[i] = d;
               i++;
           }

           m_content[i] = '\0';
           fin.close();
       }
       else
       {
           setEmpty();
       }
   }

   void Text::write(std::ostream& os) const
   {
       if (m_content != nullptr)
       {
           os << m_content;
       }
   }

   std::ostream& operator<<(std::ostream& left, const Text& right)
   {
       right.write(left);
       return left;
   }

}