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

#include <fstream>
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
   }

   Text::Text(const char* filename)
   {
       if (filename != nullptr)
       {
           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);
       }
   }

   Text::Text(const Text& inc)
   {
       if (inc.m_filename != nullptr && inc.m_content != nullptr)
       {
           m_filename = new char[strLen(inc.m_filename) + 1];
           strCpy(m_filename, inc.m_filename);
           m_content = new char[strLen(inc.m_content) + 1];
           strCpy(m_content, inc.m_content);
       }
   }

   Text& Text::operator=(const Text& inc)
   {
       delete[] m_content;
       m_content = nullptr;
       delete[] m_filename;
       m_filename = nullptr;

       if (inc.m_filename != nullptr && inc.m_content != nullptr)
       {
           m_filename = new char[strLen(inc.m_filename) + 1];
           strCpy(m_filename, inc.m_filename);
           m_content = new char[strLen(inc.m_content) + 1];
           strCpy(m_content, inc.m_content);
       }
   }

   Text::~Text()
   {
       delete[] m_filename;
       delete[] m_content;
   }

   void Text::read()
   {

       int i{};
       delete[] m_content;
       m_content = nullptr;

       if (m_filename != nullptr)
       {
           m_content = new char(getFileLength() + 1);
           ifstream fin(m_filename);

           fin.get(m_content, '\0');
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