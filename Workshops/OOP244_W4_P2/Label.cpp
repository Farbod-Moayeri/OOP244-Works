///////////////////////////////////////////////////////
// Workshop 4
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

#include <sstream>
#include <iostream>
#include "Label.h"
#include "cstring.h"

using namespace std;

namespace sdds {

	const int MAX_CHARS = 70;


	void Label::setNull()
	{
		l_String = nullptr;
		l_length = 0;
		l_frame[0] = '\0';
		strCpy(l_frame, "+-+|+-+|");
	}

	void Label::setStringEmpty()
	{
		if (l_String != nullptr)
		{
			delete[] l_String;
			l_String = nullptr;
		}

		l_String = new char[2];
		l_String[0] = '\0';
	}

	Label::Label()
	{
		setNull();
		setStringEmpty();
	}

	Label::Label(const char* frameArg)
	{
		setNull();
		setStringEmpty();
		if (frameArg != nullptr)
		{
			if (strLen(frameArg) == 8)
			{
				strCpy(l_frame, frameArg);
			}
		}
	}

	Label::Label(const char* frameArg, const char* content)
	{
		setNull();

		if (frameArg != nullptr)
		{
			if (strLen(frameArg) == 8)
			{
				strCpy(l_frame, frameArg);
			}
		}

		if (content != nullptr) 
		{
			l_length = strLen(content);

			if (l_length > MAX_CHARS + 1)
			{
				l_length = MAX_CHARS;
			}

			if (l_String != nullptr)
			{
				delete[] l_String;
				l_String = nullptr;
			}

			l_String = new char[l_length + 1];

			strnCpy(l_String, content, l_length);
		}
		else
		{
			setStringEmpty();
		}

	}

	Label::~Label()
	{
		if (l_String != nullptr)
		{
			delete[] l_String;
			l_String = nullptr;
		}
	}

	void Label::readLabel()
	{
		string temp;

		getline(cin, temp);

		if (std::cin.fail()) {
			std::cin.clear();                    
			std::cin.ignore(10000, '\n');
			setStringEmpty();
			l_length = 1;
		}
		else
		{
			l_length = strLen(temp.c_str());

			if (l_length > MAX_CHARS + 1)
			{
				l_length = MAX_CHARS;
			}

			if (l_String != nullptr)
			{
				delete[] l_String;
				l_String = nullptr;
			}

			l_String = new char[l_length + 1];

			
			strnCpy(l_String, temp.c_str(), l_length);
			
			
		}
	}

	std::ostream& Label::printLabel() const
	{
		int i;

		ostringstream temp;

		if (l_String[0] != '\0')
		{
			temp << l_frame[0];

			for (i = 0; i < l_length + 2; i++)
			{
				temp << l_frame[1];
			}

			temp << l_frame[2] << endl;
			temp << l_frame[7];

			for (i = 0; i < l_length + 2; i++)
			{
				temp << " ";
			}

			temp << l_frame[3] << endl;
			temp << l_frame[7] << " " << l_String << " " << l_frame[3] << endl;
			temp << l_frame[7];

			for (i = 0; i < l_length + 2; i++)
			{
				temp << " ";
			}

			temp << l_frame[3] << endl;
			temp << l_frame[6];

			for (i = 0; i < l_length + 2; i++)
			{
				temp << l_frame[5];
			}
			temp << l_frame[4];

		}

		return cout << temp.str();
	}

}


