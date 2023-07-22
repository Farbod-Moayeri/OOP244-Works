///////////////////////////////////////////////////////
// MS3
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
    bool Streamable::conIO(const ios& ios)
    {
        bool isit = false;

        if (ios)
        {
            isit = true;
        }

        return isit;
    }

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
