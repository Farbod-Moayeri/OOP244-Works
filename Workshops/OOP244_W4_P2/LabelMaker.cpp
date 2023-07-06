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

#include <iostream>
#include "LabelMaker.h"

using namespace std;

namespace sdds {

	sdds::LabelMaker::LabelMaker(int noOfLabels)
	{
		m_Labels = nullptr;

		if (noOfLabels > 0)
		{
			m_Ltotal = noOfLabels;
		}
		else
		{
			m_Ltotal = 1;
		}

		m_Labels = new Label[m_Ltotal];

	}

	void sdds::LabelMaker::readLabels()
	{
		int i;
		cout << "Enter " << m_Ltotal << " labels:" << endl;

		for (i = 0; i < m_Ltotal; i++)
		{
			cout << "Enter label number " << i + 1 << endl << "> ";
			m_Labels[i].readLabel();
		}
	}

	void sdds::LabelMaker::printLabels()
	{
		int i;

		for (i = 0; i < m_Ltotal; i++)
		{
			m_Labels[i].printLabel();
			cout << endl;
		}
	}

	sdds::LabelMaker::~LabelMaker()
	{
		if (m_Labels != nullptr)
		{
			delete[] m_Labels;
			m_Labels = nullptr;
		}
	}
}
