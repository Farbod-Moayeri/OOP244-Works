///////////////////////////////////////////////////////
// Workshop 8
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include "Shape.h"

namespace sdds {
	class LblShape : public Shape {
		char* m_label{};
	protected:
		const char* label() const;
	public:
		LblShape() {};
		LblShape(const char string[]);
		virtual ~LblShape();
		LblShape(const LblShape& inc) = delete;
		LblShape& operator=(const LblShape& right) = delete;
		void getSpecs(std::istream& is);
	};
}
#endif // !SDDS_LBLSHAPE_H

