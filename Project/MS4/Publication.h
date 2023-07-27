///////////////////////////////////////////////////////
// MS3
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
// Section: NBB
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

namespace sdds {
	const int MAX_LENGTH_TITLE = 255;

	class Publication : public Streamable{
		char* m_title{};
		char m_shelfId[SDDS_SHELF_ID_LEN + 1]{};
		int m_membership{};
		int m_libRef{ -1 };
		Date m_date{};
	public:
		Publication() = default;

		// RULE OF THREE
		~Publication();
		Publication(const Publication& inc);
		Publication& operator=(const Publication& inc);
		// RULE OF THREE
		
		// Sets the membership attribute to either zero or a five-digit integer.
		virtual void set(int member_id);
		// Sets the **libRef** attribute value
		void setRef(int value);
		// Sets the date to the current date of the system.
		void resetDate();
		// Returns the character 'P' to identify this object as a "Publication object"
		virtual char type()const;
		// Returns true is the publication is checkout (membership is non-zero)
		bool onLoan()const;
		// Returns the date attribute
		Date checkoutDate()const;
		// Returns true if the argument title appears anywhere in the title of the 
		// publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		bool operator==(const char* title)const;
		// Returns the title attribute
		operator const char* const()const;
		// Returns the libRef attirbute. 
		int getRef()const;
		// returns the shelfId attribute
		const char* const getShelf() const;
		// returns the membership attribute
		int getMem() const;
		// Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
		bool conIO(std::ios& io)const;
		// writes onto source the publication
		virtual std::ostream& write(std::ostream& os) const;
		// reads from the source the publication
		virtual std::istream& read(std::istream& is);
		// returns true if shelfId and shelfTitle are valid 
		virtual operator bool() const;
		
	};
}
#endif // !SDDS_PUBLICATION_H
