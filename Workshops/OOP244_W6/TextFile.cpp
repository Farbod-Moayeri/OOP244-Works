///////////////////////////////////////////////////////
// Workshop 6
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

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
               strCpy(m_filename, fname);
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

       if (m_filename != nullptr)
       {
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

   }

   void TextFile::loadText()
   {
       int i{};
       ifstream file{};
       string singleLine{};
      

       if (m_filename != nullptr)
       {
           file.open(m_filename, ios_base::in);

           if (m_textLines != nullptr)
           {
               delete[] m_textLines;
               m_textLines = nullptr;
           }

           if (m_noOfLines > 0)
           {
               if (file.is_open())
               {
                   m_textLines = new Line[m_noOfLines];

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

           file.close();

           m_noOfLines = i;

       }
   }

   void TextFile::saveAs(const char* fileName) const
   {
       unsigned int i;
       ofstream file{};

       if (fileName != nullptr)
       {
           file.open(fileName, ios_base::in);

           if (file.is_open())
           {
               for (i = 0; i < m_noOfLines; i++)
               {
                   file << m_textLines[i] << endl;
               }
           }
           else
           {
               cerr << "ERROR: Cannot open " << m_filename << " at member function saveAs!";
               exit(1);
           }

           file.close();
       }
   }

   void TextFile::setEmpty()
   {
       if (m_textLines != nullptr)
       {
           delete[] m_textLines;
           m_textLines = nullptr;
       }
       
       if (m_filename != nullptr)
       {
           delete[] m_filename;
           m_filename = nullptr;
       }
    
       m_noOfLines = 0;
   }

   TextFile::TextFile(unsigned pageSize)
   {
       setEmpty();
       m_pageSize = pageSize;
   }

   TextFile::TextFile(const char* filename, unsigned pageSize)
   {
       
       m_pageSize = pageSize;
       setEmpty();

       if (filename != nullptr && filename[0] != '\0')
       {
           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);

           setNoOfLines();

           loadText();
       }
   }

   TextFile::TextFile(const TextFile& inc)
   {
       int i;
       ifstream file{};

       if (this != &inc)
       {
           this->m_pageSize = inc.m_pageSize;
           setEmpty();

           if (inc.m_filename != nullptr && inc.m_noOfLines > 0 && inc.m_textLines != nullptr)
           {
               setFilename(inc.m_filename, true);

               m_noOfLines = inc.m_noOfLines;

               loadText();

               saveAs(m_filename);

           }
       }
   }

   TextFile& TextFile::operator=(const TextFile& inc)
   {
       if (inc && this)
       {
           this->setEmpty();
           this->setFilename(inc.m_filename, false); //???
           
           this->setNoOfLines();
           this->loadText();
       }
   }

   TextFile::~TextFile()
   {
       if (m_textLines != nullptr)
       {
           delete[] m_textLines;
           m_textLines = nullptr;
       }

       if (m_filename != nullptr)
       {
           delete[] m_filename;
           m_textLines = nullptr;
       }
      
   }

   std::ostream& TextFile::view(std::ostream& ostr) const
   {
       int i;
       int length;

       if (this)
       {
           length = strLen(m_filename);

           ostr << m_filename << endl;
           for (i = 0; i < length; i++)
           {
               ostr << '=';
           }
           cout << endl;
           for (i = 0; i < m_noOfLines; i++)
           {
               ostr << this->m_textLines[i].m_value << endl;
               if (i%m_pageSize == 0)
               {
                   ostr << "Hit ENTER to continue...";
                   do {

                   } while (cin.get() != '\n');
               }
           }
           ostr << endl;
       }

       return ostr;
           
   }


   std::istream& TextFile::getFile(std::istream& istr)
   {
       string temp;

       if (&istr != nullptr)
       {
           setEmpty();
           istr >> temp;

           m_filename = new char[strlen(temp.c_str()) + 1];
           strCpy(m_filename, temp.c_str());
           // istr.ignore(10000, '\n); ??????

           setNoOfLines();
           loadText();

           
       }

       return istr;
   }

   TextFile::operator bool() const
   {
       bool isit = false;

       if (m_filename != nullptr && m_filename[0] != '\0' && m_textLines != nullptr && m_noOfLines > 0)
       {
           isit = true;
       }

       return isit;
   }

   unsigned TextFile::lines() const
   {
       return m_noOfLines;
   }

   const char* TextFile::name() const
   {
       return m_filename;
   }

   const char* TextFile::operator[](unsigned index) const
   {
       if (this)
       {
           if (index >= m_noOfLines)
           {
               index -= m_noOfLines;
           }
       }
       else
       {
           return nullptr;
       }

       return m_textLines[index].m_value;
   }

   std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
   {
       if (&ostr != nullptr && &text != nullptr)
       {
           text.view(ostr);

           cout << text;
       }

       return ostr;
   }

   std::istream& operator>>(std::istream& istr, TextFile& text)
   {
       if (&istr != nullptr && &text != nullptr)
       {
           text.getFile(istr);
           
       }

       return istr;
   }

}