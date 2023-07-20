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
		~Streamable() {};
	};

	const Streamable& operator<<(std::ostream& left, const Streamable& right);
	Streamable& operator>>(std::istream& left, Streamable& right);
}
#endif // !SDDS_STREAMABLE_H
