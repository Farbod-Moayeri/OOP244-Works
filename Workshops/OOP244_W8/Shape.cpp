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

#include "Shape.h"

namespace sdds {

    std::ostream& operator<<(std::ostream& left, const Shape& right)
    {
        right.draw(left);
        return left;
    }
    std::istream& operator>>(std::istream& left, Shape& right)
    {
        right.getSpecs(left);
        return left;
    }
}
