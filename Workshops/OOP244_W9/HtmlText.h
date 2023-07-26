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

#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
   class HtmlText :  public Text {
      char* m_title{};
      virtual HtmlText& setEmpty();
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);
      virtual ~HtmlText();
      HtmlText(const HtmlText& inc);
      HtmlText& operator=(const HtmlText& inc);
      virtual void write(std::ostream& os)const;


   };
}
#endif // !SDDS_HTMLTEXT_H__
