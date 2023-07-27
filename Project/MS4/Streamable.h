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

#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include <ostream>
#include <ios>

namespace sdds {
	class Streamable {

	public:
		virtual std::ostream& write(std::ostream& os) const = 0; 
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool conIO(const std::ios& ios);
		virtual operator bool() const = 0;
		~Streamable() = default;
	};

	std::ostream& operator<<(std::ostream& left, const Streamable& right);
	std::istream& operator>>(std::istream& left, Streamable& right);
}
#endif // !SDDS_STREAMABLE_H
