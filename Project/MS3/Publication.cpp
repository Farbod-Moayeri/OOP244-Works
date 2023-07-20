#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include <string>
#include "Publication.h"


namespace sdds {
	Publication::~Publication()
	{
		delete[] m_title;
		//m_title = nullptr;S
	}
	Publication::Publication(const Publication& inc)
	{
		// might be good to validate inc?
		m_title = new char[strlen(inc) + 1];
		strcpy(m_title, inc);
		strcpy(m_shelfId, inc.getShelf());
		m_membership = inc.getMem();
		m_date = inc.checkoutDate();
	}
	Publication& Publication::operator=(const Publication& inc)
	{
		
		if (this != &inc && inc != nullptr) 
		{
			delete[] m_title;
			m_title = new char[strlen(inc) + 1];
			strcpy(m_title, inc);
			strcpy(m_shelfId, inc.getShelf());
			m_membership = inc.getMem();
			m_date = inc.checkoutDate();
		}

		return *this;
	}
	void Publication::set(int member_id)
	{
		if (m_membership == 0 && member_id > 9999 && member_id < 100000)
		{
			m_membership = member_id;
		}
	}

	void Publication::setRef(int value)
	{
		if (value > -1 && m_libRef == -1)
		{
			m_libRef = value;
		}
	}

	void Publication::resetDate()
	{
		m_date.setToToday();
	}

	char Publication::type() const
	{
		return 'P';
	}

	bool Publication::onLoan() const
	{
		bool isit = false;
		
		if (m_membership != 0)
		{
			isit = true;
		}

		return isit;
	}

	Date Publication::checkoutDate() const
	{
		return m_date;
	}

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
	Publication::operator const char* const() const
	{
		return m_title;
	}
	int Publication::getRef() const
	{
		return m_libRef;
	}
	const char* Publication::getShelf() const
	{
		return m_shelfId;
	}
	int Publication::getMem() const
	{
		return m_membership;
	}
	bool Publication::conIO(std::ios& io) const
	{
		bool isit = false;

		if (&io == &std::cout || &io == &std::cin)
		{
			isit = true;
		}

		return isit;
	}
	std::ostream& Publication::write(std::ostream& os) const
	{
		if (*this != nullptr)
		{
			if (conIO(os))
			{
				os << "| " << std::setw(SDDS_SHELF_ID_LEN) << m_shelfId << " | " << std::left << std::setw(SDDS_TITLE_WIDTH)
					<< std::setfill('.') << m_title << std::setfill(' ') << " | " << std::setw(5);
				if (m_membership != 0)
				{
					os << m_membership;
				}
				else
				{
					os << "N/A";
				}
				os << " | " << std::setw(10) << m_date << " | ";
			}
			else
			{
				os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t' << m_title << '\t' << m_membership << '\t' << m_date;
			}
		}

		return os;
	}
	std::istream& Publication::read(std::istream& is)
	{
		char localTitle[SDDS_TITLE_WIDTH + 1];
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
			std::cout << "Shelf No: ";
			is.getline(localShelfId, SDDS_SHELF_ID_LEN); // check how getline works
			buf = is.get();
			if (buf != '\n')
			{
				is.setstate(std::ios_base::failbit);
			}
			std::cout << "Title: ";
			is.getline(localTitle, SDDS_TITLE_WIDTH);
			is.ignore(10000, '\n');
			std::cout << "Date: ";
			localDate.read(is);
			if (localDate.errCode() != 0)
			{
				is.setstate(std::ios_base::failbit);
			}
			is.ignore(10000, '\n');
		}
		else
		{
			// change this to ensure is.get does break
			is >> localLibRef;
			while (is.get() != '\t') {}
			is.getline(localShelfId, SDDS_SHELF_ID_LEN);
			while (is.get() != '\t') {}
			is.getline(localTitle, SDDS_TITLE_WIDTH);
			while (is.get() != '\t') {}
			is >> localMembership;
			while (is.get() != '\t') {}
			localDate.read(is);
			if (localDate.errCode() != 0)
			{
				is.setstate(std::ios_base::failbit);
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
