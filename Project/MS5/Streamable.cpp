///////////////////////////////////////////////////////
// MS5
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
// Section: NBB
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

using namespace std;
#include "Streamable.h"

namespace sdds {

    ostream& operator<<(ostream& left, const Streamable& right)
    {
        right.write(left);

        return left;
    }

    istream& operator>>(istream& left, Streamable& right)
    {
        right.read(left);

        return left;
    }
}
