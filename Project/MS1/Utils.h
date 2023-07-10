/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version 
// Date	
// Author	
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
