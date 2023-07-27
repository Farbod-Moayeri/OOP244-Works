///////////////////////////////////////////////////////
// Workshop 9
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
// Section: NBB
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

#include "HtmlText.h"
#include "cstring.h"

namespace sdds {
	HtmlText& HtmlText::setEmpty()
	{
		delete[] m_title;
		m_title = nullptr;
		Text::setEmpty();

		return *this;
	}

	HtmlText::HtmlText(const char* filename, const char* title) : Text::Text(filename)
	{
		if (title != nullptr)
		{
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
		else
		{
			setEmpty();
		}
	}
	HtmlText::~HtmlText()
	{
		delete[] m_title;
	}
	HtmlText::HtmlText(const HtmlText& inc) : Text::Text(inc)
	{
		if (inc.m_title != nullptr)
		{
			m_title = new char[strLen(inc.m_title) + 1];
			strCpy(m_title, inc.m_title);
		}
		else
		{
			setEmpty();
		}
	}
	HtmlText& HtmlText::operator=(const HtmlText& inc)
	{
		if (this != &inc)
		{
			if (m_title != nullptr)
			{
				delete[] m_title;
				m_title = nullptr;
			}

			Text::operator=(inc);
			if (inc.m_title != nullptr)
			{
				m_title = new char[strLen(inc.m_title) + 1];
				strCpy(m_title, inc.m_title);
			}
			else
			{
				setEmpty();
			}
		}

		return *this;
	}
	void HtmlText::write(std::ostream& os) const
	{
		bool ms = false;
		os << "<html><head><title>";

		if (m_title != nullptr)
		{
			os << m_title;
		}
		else
		{
			os << "No Title";
		}

		os << "</title></head>\n<body>\n";

		if ("</title>\n\n" != nullptr)
		{
			os << "<h1>" << m_title << "</h1>\n";
		}

		for (int i = 0;  Text::operator[](i) != '\0'; i++)
		{
			switch (Text::operator[](i))
			{
			case '<':
				os << "&lt;";
				ms = false;
				break;
			case '>':
				os << "&gt;";
				ms = false;
				break;
			case '\n':
				os << "<br />\n";
				ms = false;
				break;
			case ' ':
				if (ms)
				{
					os << "&nbsp;";
				}
				else
				{
					ms = true;
					os << ' ';
				}
				break;
			default:
				os << Text::operator[](i);
				ms = false;
				break;
			}
		}

		os << "</body>\n</html>";
		
	}
}