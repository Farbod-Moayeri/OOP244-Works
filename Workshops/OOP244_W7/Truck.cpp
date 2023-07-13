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
#include "Truck.h"

namespace sdds {
	Truck::Truck(const char licensePlate[], const unsigned creationYear, const unsigned capacity, const char address[]) 
		: MotorVehicle(licensePlate, creationYear), 
		m_maxWeight(capacity), m_currentWeight{}
	{
		if (address != nullptr)
		{
			MotorVehicle::moveTo(address);
		}
	}
	bool Truck::addCargo(const double cargo)
	{
		bool changed = false;

		if ((m_currentWeight + cargo) <= m_maxWeight)
		{
			m_currentWeight += cargo;
			changed = true;
		}

		return changed;
	}
	bool Truck::unloadCargo()
	{
		bool changed = false;

		if (m_currentWeight != 0)
		{
			m_currentWeight = 0;
			changed = true;
		}

		return changed;
	}
	std::ostream& Truck::write(std::ostream& os) const
	{
		MotorVehicle::write(os);

		os << " | " << m_currentWeight <<"/" << m_maxWeight;

		return os;
	}
	std::istream& Truck::read(std::istream& in)
	{
		MotorVehicle::read(in);

		in.ignore(10000, '\n');

		std::cout << "Capacity: ";
		in >> m_maxWeight;
		in.clear();
		in.ignore(10000, '\n');
		std::cout << "Cargo: ";
		in >> m_maxWeight;
		in.clear();

		return in;


	}
	std::ostream& operator<<(std::ostream& os, const Truck right)
	{
		right.write(os);

		return os;
	}
	std::istream& operator>>(std::istream& is, Truck right)
	{
		right.read(is);

		return is;
	}
}