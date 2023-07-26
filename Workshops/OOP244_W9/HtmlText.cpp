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
		Text::operator=(inc);
		if (inc.m_title != nullptr)
		{
			m_title = new char[strLen(inc.m_title) + 1];
			strCpy(m_title, inc.m_title);
		}
	}
	void HtmlText::write(std::ostream& os) const
	{
		int i{};
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

		if (m_title != nullptr)
		{
			os << "<h1>" << m_title << "</h1>\n";
		}

		for (int i = 0; m_content[i] != '\0'; i++)
    {
        switch (m_content[i])
        {
        case '<':
            os << "&lt;";
            break;
        case '>':
            os << "&gt;";
            break;
        case '\n':
            os << "<br />\n";
            break;
        case ' ':
            if (!ms)
            {
                os << ' ';
                ms = true;
            }
            else
            {
                os << "&nbsp;";
            }
            break;
        default:
            os << m_content[i];
            ms = false;
            break;
        }
    }

    os << "</body></html>\n";
		
	}
}