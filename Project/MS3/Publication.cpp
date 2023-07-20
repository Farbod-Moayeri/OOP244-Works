#include <cstring>
#include <iomanip>
#include <string>
#include "Publication.h"
#include "Lib.h"

namespace sdds {
	Publication::~Publication()
	{
		delete[] m_title;
		m_title = nullptr;
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
	Publication::operator const char* () const
	{
		return m_title;
	}
	int Publication::getRef() const
	{
		return m_libRef;
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

		return os;
	}
	std::istream& Publication::read(std::istream& is)
	{
		char localTitle[SDDS_TITLE_WIDTH + 1];
		char localShelfId[SDDS_SHELF_ID_LEN + 1]{};
		int localMembership{};
		int localLibRef = -1;
		Date localDate{};
		
		delete[] m_title;
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date.setToToday();

		if (conIO(is))
		{
			std::cout << "Shelf No: ";
			is.getline(localShelfId, SDDS_SHELF_ID_LEN);
			if (is.get() != '\n')
			{
				is.setstate(std::ios_base::failbit);
			}
			// is.ignore(10000, '\n');
			is.getline(localTitle, SDDS_TITLE_WIDTH);
			is.ignore(10000, '\n');
			m_date.read();
			is.ignore(10000, '\n');
		}
		else
		{

		}
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
