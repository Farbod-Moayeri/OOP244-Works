///////////////////////////////////////////////////////
// Workshop 5
// Name: Farbod Moayeri
// Id: 134395227
// Email: fmoayeri2@myseneca.ca
///////////////////////////////////////////////////////
// I have done all the coding by myself and only copied
// the code that my professor provided to complete my 
// workshops and assignments.
///////////////////////////////////////////////////////

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_


namespace sdds {
    class Mark {
        int m_Mark;
        void setEmpty();
    public:
        int getMark() const;
        Mark();
        Mark(const int number);
        operator bool() const;
        operator int() const;
        operator double() const;
        operator char() const;
        bool operator~() const;
        Mark& operator=(const int src);
        Mark& operator+=(const int src);

    };

    int& operator+=(int& src1, const Mark& src2);

}
#endif // SDDS_MARK_H_