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

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <sstream>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {

	const double PI = 3.14159265;

	void Canister::setToDefault()
	{
		m_contentName = nullptr;
		m_diameter = 10.0;  
		m_height = 13.0;   
		m_contentVolume = 0.0;  
		m_usable = true;
	}

	void Canister::setName(const char* Cstr)
	{
		if (Cstr != nullptr && m_usable)
		{
			if (m_contentName != nullptr)
			{
				delete[] m_contentName;
				m_contentName = nullptr;
			}

			m_contentName = new char[strLen(Cstr) + 1];
			strCpy(m_contentName, Cstr);
		}
	}

	bool Canister::isEmpty() const
	{
		return volume() < 0.00001 ? true : false;
	}

	bool Canister::hasSameContent(const Canister& C) const
	{
		bool doThey = false;

		if (&C != nullptr && m_contentName != nullptr && C.m_contentName != nullptr)
		{
			if (strCmp(C.m_contentName, m_contentName) == 0)
			{
				doThey = true;
			}
		}

		return doThey;
	}

	Canister::Canister()
	{
		setToDefault();
	}

	Canister::Canister(const char* contentName)
	{
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter, const char* contentName)
	{
		setToDefault();

		if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0)
		{
			m_height = height;
			m_diameter = diameter;
			m_contentVolume = 0;
			setName(contentName);
		}
		else
		{
			m_usable = false;
		}
	}

	Canister::~Canister()
	{
		if (m_contentName != nullptr)
		{
			delete[] m_contentName;
			m_contentName = nullptr;
		}
	}

	Canister& Canister::setContent(const char* contentName)
	{

		if (contentName == nullptr)
		{
			m_usable = false;
		}
		else if (volume() == 0)
		{
			setName(contentName);
		}
		else if (strCmp(contentName, m_contentName) != 0)
		{
			m_usable = false;
		}

		return *this;
	}

	Canister& Canister::pour(double quantity)
	{
		if (m_usable==true && quantity + volume() <= capacity() && quantity > 0.0)
		{
			m_contentVolume += quantity;
		}
		else
		{
			m_usable = false;
		}

		return *this;
	}

	Canister& Canister::pour(Canister& C)
	{
		double total = 0;

		if (C.m_contentName != nullptr && m_usable == true && C.m_usable == true)
		{
			if (strCmp(C.m_contentName, m_contentName) == 0)
			{
				if (volume() + C.m_contentVolume <= capacity())
				{
					pour(C.m_contentVolume);
					C.m_contentVolume = 0;
				}
				else
				{
					total = C.m_contentVolume + m_contentVolume;
					total -= capacity();
					m_contentVolume = capacity();
					C.m_contentVolume = total;
				}
				
			}
			else if (strCmp(C.m_contentName, m_contentName) != 0 && volume() == 0)
			{
				if (m_contentVolume + C.m_contentVolume <= capacity())
				{
					setContent(C.m_contentName);
					pour(C.m_contentVolume);
					C.m_contentVolume = 0;
				}
				else
				{
					setContent(C.m_contentName);
					total = C.m_contentVolume + volume();
					total -= capacity();
					m_contentVolume = capacity();
					C.m_contentVolume = total;
				}
			}
			else
			{
				total = C.m_contentVolume + volume();
				total -= capacity();
				m_contentVolume = capacity();
				C.m_contentVolume = total;
				m_usable = false;
			}

		}
		else
		{
			m_usable = false;
		}

		return *this;

	}

	double Canister::volume() const
	{
		return m_contentVolume;
	}

	std::ostream& Canister::display() const
	{
		std::ostringstream temp;

		if (m_usable == false)
		{
			
			
			temp << setw(7) << fixed << setprecision(1) << std::showpoint << capacity() << "cc (" << m_height 
				 << "x" << m_diameter << ") Canister of Unusable content, discard!";
			

		}
		else if(m_contentName == nullptr)
		{
			temp << setw(7) << fixed << setprecision(1) << std::showpoint << capacity() << "cc (" << m_height 
				 << "x" << m_diameter << ") Canister";
		}
		else
		{
			temp << setw(7) << fixed << setprecision(1) << std::showpoint << capacity() << "cc (" << m_height << "x" 
				<< m_diameter << ") Canister of " << setw(7) << volume() << "cc   " << m_contentName;
		}
		

		return cout << temp.str();
	}

	double Canister::capacity() const
	{
		return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
	}

	void Canister::clear()
	{
		if (m_contentName != nullptr)
		{
			delete[] m_contentName;
			m_contentName = nullptr;
		}
		m_contentVolume = 0.0;
		m_usable = true;

	}

}