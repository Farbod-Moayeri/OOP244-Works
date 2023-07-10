/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version 1.0
// Date 2023-07-10
// Author Farbod Moayeri
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds {

	void clearBuffer();
	bool getInt(int &src);
	bool getInt(int& src, std::istream& is);
	unsigned getUnsignedRange(const int min, const int max, const char errMsg[] = nullptr);

}
#endif // SDDS_UTILS_H__
