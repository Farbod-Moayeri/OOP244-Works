#include <cstring>
#include "Publication.h"

namespace sdds {


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
		
	}
	std::istream& Publication::read(std::istream& is)
	{
		// TODO: insert return statement here
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
