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

#ifndef SDDS_MOTOR_H_
#define SDDS_MOTOR_H_

#include <ostream>
namespace sdds {
	
	class MotorVehicle {
		char m_plateNum[9]{};
		char m_address[64]{};
		unsigned m_year{};

	public:
		MotorVehicle(const char licensePlate[], const unsigned creationYear);
		void moveTo(const char address[]);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& right);
	std::istream& operator>>(std::istream& is, MotorVehicle& right);

}
#endif // !SDDS_MOTOR_H_

