#include "Streamable.h"

namespace sdds {
    bool Streamable::conIO(const std::ios& ios)
    {
        bool isit = false;

        if (ios)
        {
            isit = true;
        }

        return isit;
    }

    const Streamable& operator<<(std::ostream& left, const Streamable& right)
    {
        right.write(left);

        return right;
    }

    Streamable& operator>>(std::istream& left, Streamable& right)
    {
        right.read(left);

        return right;
    }
}
