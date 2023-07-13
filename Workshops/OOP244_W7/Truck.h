///////////////////////////////////////////////////////
// MS1
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
// Section: NBB
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

#ifndef SDDS_TRUCK_H_
#define SDDS_TRUCK_H_
#include "MotorVehicle.h"

namespace sdds {

	class Truck : public MotorVehicle {
		double m_maxWeight{};
		double m_currentWeight{};

	public:
		Truck(const char licensePlate[], const unsigned creationYear, const unsigned capacity, const char address[]);
		bool addCargo(const double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
		
	};

	std::ostream& operator<<(std::ostream& os, const Truck& right);
	std::istream& operator>>(std::istream& is, Truck& right);
	
}
#endif // !SDDS_TRUCK_H_
