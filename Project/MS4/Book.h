#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include "Publication.h"
namespace sdds {
	class Book : public Publication {
		char* m_author{};
	public:
		// default constructor
		Book(const char author[] = nullptr);
		//rule of three
		virtual ~Book();
		Book(const Book& src);
		Book& operator=(const Book& src);
		// Returns character 'B'
		virtual char type()const;
		// Writes author name to either file or terminal
		virtual std::ostream& write(std::ostream& os) const;
		// Reads author name from either file or terminal and sets m_author attribute to it
		virtual std::istream& read(std::istream& is);
		// sets member id using base class and then resets date to current date
		virtual void set(int member_id);
		// return true if the author's name exists and is not empty and the base class's operator bool() has returned true
		virtual operator bool() const;
	};
}
#endif // !SDDS_BOOK_H
