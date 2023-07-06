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
#include "CalorieList.h"
//#include "Food.h"
//#include "cstring.h"

using namespace std;

namespace sdds {

	bool sdds::CalorieList::isValid() const
	{
		bool isit = true;
		int i;

		for (i = 0; i < C_numFoods; i++)
		{
			if (!C_List[i].isValid())
			{
				isit = false;
			}
		}

		return isit;

	}

	bool sdds::CalorieList::init(int num)
	{
		bool isDone = false;

		if (num > 0)
		{
			C_List = nullptr;
			C_List = new Food[num];
			C_numFoods = num;
			C_foodsAdded = 0;
			C_totalCals = 0;
			isDone = true;
		}

		return isDone;
	}


	bool sdds::CalorieList::add(const char name[], int calories, int type)
	{
		int i;
		bool added = false;

		for (i = C_foodsAdded; i < C_numFoods && !added; i++)
		{
			if (C_List[i].isEmpty())
			{
				C_List[i].add(name, calories, type);
				C_totalCals += calories;
				C_foodsAdded++;
				added = true;
			}
		}

		return added;
	}

	void sdds::CalorieList::display() const
	{
		int i;
		bool isit = isValid();

		if (isit)
		{
			cout << "+----------------------------------------------------+" << endl;
			cout << "|  Daily Calorie Consumption                         |" << endl;
			cout << "+--------------------------------+------+------------+" << endl;
		}
		else
		{
			cout << "+----------------------------------------------------+" << endl;
			cout << "| Invalid Calorie Consumption list                   |" << endl;
			cout << "+--------------------------------+------+------------+" << endl;
		}

		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;

		for (i = 0; i < C_numFoods; i++)
		{
			C_List[i].display();
		}

		if (isit)
		{
			cout << "+--------------------------------+------+------------+" << endl;
			cout << "|    Total Calories for today: " << right << setw(8) << C_totalCals << " |            |" << endl;
			cout << "+----------------------------------------------------+" << endl;
		}
		else
		{
			cout << "+--------------------------------+------+------------+" << endl;
			cout << "|    Invalid Calorie Consumption list                |" << endl;
			cout << "+----------------------------------------------------+" << endl;
		}
	}


	void sdds::CalorieList::deallocate()
	{
		if (C_List != nullptr)
		{
			delete[] C_List;
			C_List = nullptr;
		}
	}

	sdds::CalorieList::CalorieList()
	{
		C_foodsAdded = 0;
		C_numFoods = 0;
		C_totalCals = 0;
		C_List = nullptr;
	}

	sdds::CalorieList::~CalorieList()
	{
		deallocate();
	}
}