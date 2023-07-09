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
	bool getUnsigned(unsigned &src);
	unsigned getUnsignedRange(unsigned min, unsigned max, char errMsg[] = nullptr);

}
#endif // SDDS_UTILS_H__
