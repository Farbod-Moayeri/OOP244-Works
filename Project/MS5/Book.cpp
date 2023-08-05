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

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <cstring>

using namespace std;

#include "Book.h"

namespace sdds {
	// One argument constructor
	Book::Book(const char author[])
	{
		if (author != nullptr)
		{
			m_author = new char[strlen(author) + 1];
			strcpy(m_author, author);
		}
	}
	// destructor
	Book::~Book()
	{
		delete[] m_author;
	}
	// copy constructor
	Book::Book(const Book& src) : Publication::Publication(src)
	{
		if (src.m_author != nullptr)
		{
			delete[] m_author;
			m_author = new char[strlen(src.m_author) + 1];
			strcpy(m_author, src.m_author);
		}
	}
	// copy assignment
	Book& Book::operator=(const Book& src)
	{

		if (this != &src)
		{
			Publication::operator=(src);
			if (src.m_author != nullptr)
			{
				delete[] m_author;
				m_author = nullptr;
				m_author = new char[strlen(src.m_author) + 1];
				strcpy(m_author, src.m_author);
			}

		}

		return *this;
	}

	// Returns character 'B'
	char Book::type() const
	{
		return 'B';
	}

	// Writes author name to either file or terminal
	std::ostream& Book::write(std::ostream& os) const
	{
		Publication::write(os);
		if (conIO(os))
		{
			if (m_author != nullptr)
			{
				string truncAuth = m_author;
				truncAuth = truncAuth.substr(0, SDDS_AUTHOR_WIDTH);
				os << " ";
				os << setw(SDDS_AUTHOR_WIDTH) << truncAuth;
				os << " |";
			}
		}
		else
		{
			os << '\t';
			if (m_author != nullptr)
			{
				os << m_author;
			}
			if (type() == 'B')
			{
				os << endl;
			}
		}

		return os;
	}
	// Reads author name from either file or terminal and sets m_author attribute to it
	std::istream& Book::read(std::istream& is)
	{
		char localAuthor[256 + 1]{};
		Publication::read(is);
		delete[] m_author;
		m_author = nullptr;

		if (conIO(is))
		{
			//is.ignore(10000, '\n'); // for newline
			cout << "Author: ";
			is.get(localAuthor, 256, '\n'); //
		}
		else
		{
			is.ignore();
			is.get(localAuthor, 256,'\n');
			//is.ignore('\t');
		}

		if (is.good())
		{
			m_author = new char[strlen(localAuthor) + 1];
			strcpy(m_author, localAuthor);
		}

		return is;
	}

	// sets member id using base class and then resets date to current date
	void Book::set(int member_id)
	{
		Publication::set(member_id);
		Publication::resetDate();
	}

	// return true if the author's name exists and is not empty and the base class's operator bool() has returned true
	Book::operator bool() const
	{
		bool isit = false;

		if (m_author != nullptr && m_author[0] != '\0' && Publication::operator bool())
		{
			isit = true;
		}

		return isit;
	}
}
