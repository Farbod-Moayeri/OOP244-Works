///////////////////////////////////////////////////////
// Workshop 3
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "Food.h"
#include "cstring.h"

using namespace std;

namespace sdds {


	void sdds::Food::empty()
	{
		f_Name[0] = '\0';
		f_Cals = 0;
		f_Type = 0;
	}

	bool Food::isValid() const
	{
		bool isit = true;

		if (f_Name[0] == '\0' || f_Cals == 0 || f_Type == 0)
		{
			isit = false;
		}

		return isit;
	}

	bool Food::isEmpty() const
	{
		bool isit = false;

		if (f_Name[0] == '\0' && f_Cals == 0 && f_Type == 0)
		{
			isit = true;
		}

		return isit;
	}

	bool Food::add(const char name[], int calories, int type)
	{
		bool added = false;

		empty();

		if (name != nullptr)
		{
			if (name[0] != '\0' && calories > 0 && type > 0 && type < 5)
			{
				strnCpy(f_Name, name, NAME_LENGTH);
				f_Cals = calories;
				f_Type = type;
				added = true;
			}
		}

		return added;
	}

	void Food::display() const
	{
		if (!isEmpty())
		{
			cout << left << "| " << setfill('.') << setw(NAME_LENGTH) << f_Name << " | "
				<< right << setfill(' ') << setw(4) << f_Cals << " | " << left << setw(9);
			switch (f_Type)
			{
				case 1:
					cout << "Breakfast";
					break;
				case 2:
					cout << "Lunch";
					break;
				case 3:
					cout << "Dinner";
					break;
				case 4:
					cout << "Snack";
					break;
				default:
					cout << "ERROR";
					break;
			}

			cout << "  |" << endl;
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}

	Food::Food()
	{
		f_Name[0] = '\0';
		f_Cals = 0;
		f_Type = 0;
	}

	Food::~Food()
	{
		// Nothing to deconstruct, empty definition
	}

}