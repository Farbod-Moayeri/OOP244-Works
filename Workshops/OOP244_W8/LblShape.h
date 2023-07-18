#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include "Shape.h"

namespace sdds {
	class LblShape : public Shape {
		char* m_label{};
		char* label() const;
	public:
		LblShape(char string[] = nullptr);
		~LblShape();
		LblShape(const LblShape& inc) = delete;
		LblShape& operator=(const LblShape& right) = delete;
	};
}
#endif // !SDDS_LBLSHAPE_H

