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

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <ostream>

namespace sdds {
   class Text {
      char* m_filename{};
      char* m_content{};
      int getFileLength()const;
   protected:
      virtual const char& operator[](int index)const;
   public:
      virtual Text& setEmpty();
      Text(const char* filename=nullptr);
      Text(const Text& inc);
      Text& operator=(const Text& inc);
      virtual ~Text();


      void read();
      virtual void write(std::ostream& os)const;
   };
    
   std::ostream& operator<<(std::ostream& left, const Text& right);
}
#endif // !SDDS_TEXT_H__

