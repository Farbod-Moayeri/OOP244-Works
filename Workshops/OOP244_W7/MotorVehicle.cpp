///////////////////////////////////////////////////////
// Workshop 7
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

#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;

namespace sdds {

	MotorVehicle::MotorVehicle(const char licensePlate[], const unsigned creationYear)
	{
		// Assuming all parameters are valid
		strCpy(m_plateNum, licensePlate);
		m_year = creationYear;
		strCpy(m_address, "Factory");
	}
	void MotorVehicle::moveTo(const char address[])
	{
		if (address != nullptr)
		{
			if (strCmp(address, m_address) != 0)
			{
				cout << "|" << right << setw(8) << m_plateNum << "| |" << left << setw(20) << m_address << " ---> " << left << setw(20) << address << "|" << endl;
				strCpy(m_address, address);
			}
		}
	}
	std::ostream& MotorVehicle::write(std::ostream& os) const
	{

		os << "| " << m_year << " | " << m_plateNum << " | " << m_address;

		return os;
	}
	std::istream& MotorVehicle::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> m_year;
		in.clear();
		in.ignore(10000, '\n');
		cout << "License plate: ";
		in >> m_plateNum;
		in.clear();
		in.ignore(10000, '\n');
		cout << "Current location: ";
		in >> m_address;
		in.clear();

		return in;
	}
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& right)
	{
		right.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, MotorVehicle& right)
	{
		right.read(is);
		return is;
	}
}

