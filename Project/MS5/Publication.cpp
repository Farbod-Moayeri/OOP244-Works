///////////////////////////////////////////////////////
// MS4
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
#include <cstring> 
#include <iomanip>
#include <string>

using namespace std;
#include "Publication.h"

namespace sdds {
	Publication::~Publication()
	{
		delete[] m_title;
	}

	Publication::Publication(const Publication& inc)
	{
		if (inc != nullptr)
		{
			m_title = new char[strlen(inc) + 1];
			strcpy(m_title, inc);
			strcpy(m_shelfId, inc.getShelf());
			m_membership = inc.getMem();
			m_date = inc.checkoutDate();
		}
	}

	Publication& Publication::operator=(const Publication& inc)
	{
		
		if (this != &inc) 
		{
			if (inc != nullptr)
			{
				if (m_title != nullptr)
				{
					delete[] m_title;
					m_title = nullptr;
				}
				m_title = new char[strlen(inc.m_title) + 1];
				strcpy(m_title, inc);
				strcpy(m_shelfId, inc.getShelf());
				m_membership = inc.getMem();
				m_date = inc.checkoutDate();
			}
		}

		return *this;
	}


	// Sets the membership attribute to either zero or a five-digit integer.
	void Publication::set(int member_id)
	{
		if (m_membership == 0 && member_id > 9999 && member_id < 100000)
		{
			m_membership = member_id;
		}
	}

	// Sets the **libRef** attribute value
	void Publication::setRef(int value)
	{
		if (value > -1 && m_libRef == -1)
		{
			m_libRef = value;
		}
	}

	// Sets the date to the current date of the system.
	void Publication::resetDate()
	{
		m_date.setToToday();
	}

	// Returns the character 'P' to identify this object as a "Publication object"
	char Publication::type() const
	{
		return 'P';
	}

	// Returns true is the publication is checkout (membership is non-zero)
	bool Publication::onLoan() const
	{
		bool isit = false;
		
		if (m_membership != 0)
		{
			isit = true;
		}

		return isit;
	}

	// Returns the date attribute
	Date Publication::checkoutDate() const
	{
		return m_date;
	}

	// Returns true if the argument title appears anywhere in the title of the 
	// publication. Otherwise, it returns false; (use strstr() function in <cstring>)
	bool Publication::operator==(const char* title) const
	{
		bool isit = false;

		if (title != nullptr && m_title != nullptr)
		{
			if (strstr(m_title, title) != nullptr)
			{
				isit = true;
			}
		}

		return isit;
	}

	// Returns the title attribute
	Publication::operator const char* const() const
	{
		return m_title;
	}

	// Returns the libRef attirbute. 
	int Publication::getRef() const
	{
		return m_libRef;
	}

	// returns the shelfId attribute
	const char* const Publication::getShelf() const
	{
		return m_shelfId;
	}

	// returns the membership attribute
	int Publication::getMem() const
	{
		return m_membership;
	}
	// Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
	bool Publication::conIO(const std::ios& ios) const
	{
		bool isit = false;

		if (&ios == &cout || &ios == &cin)
		{
			isit = true;
		}

		return isit;
	}
	// writes onto source the publication
	ostream& Publication::write(ostream& os) const
	{
		if (*this != nullptr)
		{
			if (conIO(os))
			{
				string truncTitle = m_title;
				truncTitle = truncTitle.substr(0, SDDS_TITLE_WIDTH);

				os << "| " << setw(SDDS_SHELF_ID_LEN) << m_shelfId << " | " << left << setw(SDDS_TITLE_WIDTH)
					<< setfill('.') << truncTitle << setfill(' ') << " | " << setw(5);
				if (m_membership != 0)
				{
					os << m_membership;
				}
				else
				{
					os  << " N/A ";
				}
				os << " | " << m_date << " |";
			}
			else
			{
				os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t' << m_title << '\t' << m_membership << '\t' << m_date;
			}
		}

		return os;
	}
	// reads from the source the publication
	istream& Publication::read(istream& is)
	{
		char localTitle[1000 + 1];
		char localShelfId[SDDS_SHELF_ID_LEN + 1]{};
		int localMembership{};
		int localLibRef = -1;
		Date localDate{};
		char buf;
		
		delete[] m_title;
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date.setToToday();

		if (conIO(is))
		{
			cout << "Shelf No: ";
			is.get(localShelfId, SDDS_SHELF_ID_LEN + 1, '\n'); // check how getline works
			buf = is.get();
			if (buf != '\n')
			{
				is.setstate(ios_base::failbit);
			}
			cout << "Title: ";
			is.get(localTitle, 1000, '\n');
			is.ignore(10000, '\n');
			cout << "Date: ";
			localDate.read(is);
			if (localDate.errCode() != 0)
			{
				is.setstate(ios_base::failbit);
			}
			is.ignore(10000, '\n');
		}
		else
		{
			is >> localLibRef;
			is.ignore();
			is.get(localShelfId, SDDS_SHELF_ID_LEN + 1,'\t');
			is.ignore();
			is.get(localTitle, 1000,'\t');
			is.ignore();
			is >> localMembership;
			is.ignore();
			localDate.read(is);
			if (localDate.errCode() != 0)
			{
				is.setstate(ios_base::failbit);
			}
		}

		if (is.good())
		{
			m_title = new char[strlen(localTitle) + 1];
			strcpy(m_title, localTitle);
			strcpy(m_shelfId, localShelfId);
			m_membership = localMembership;
			m_date = localDate;
			m_libRef = localLibRef;
		}

		return is;
	}
	// returns true if shelfId and shelfTitle are valid 
	Publication::operator bool() const
	{
		bool isit = false;
		if (m_shelfId[0] != '\0' && m_title != nullptr)
		{
			isit = true;
		}

		return isit;
	}
}
