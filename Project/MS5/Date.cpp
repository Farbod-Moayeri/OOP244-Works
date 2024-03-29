// Final Project Milestone 5
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;
#include "Date.h"
#include "Utils.h"

namespace sdds {
    // MS3 testing stuff
    bool sdds_test = false;
    int sdds_year = 2023;
    int sdds_mon = 12;
    int sdds_day = 25;
   
   bool Date::validate() {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
         errCode(YEAR_ERROR);
      }
      else if (m_mon < 1 || m_mon > 12) {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays()) {
         errCode(DAY_ERROR);
      }
      return !bad();
   }

   void Date::errCode(int readErrorCode) {
       m_ErrorCode = readErrorCode;
   }
   int Date::systemYear()const {
       /*time_t t = time(NULL);
       tm lt = *localtime(&t);
       return lt.tm_year + 1900; MS2 and before*/ 
       int theYear = sdds_year;
       if (!sdds_test) {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           theYear = lt.tm_year + 1900;
       }
       return theYear;
   }
   bool Date::bad()const {
       return m_ErrorCode != 0;
   }
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }
   
   
   int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01 
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }
   void Date::setToToday() {
       if (sdds_test) {
           m_day = sdds_day;
           m_mon = sdds_mon;
           m_year = sdds_year;
       }
       else {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           m_day = lt.tm_mday;
           m_mon = lt.tm_mon + 1;
           m_year = lt.tm_year + 1900;
       }
       errCode(NO_ERROR);
   }
   Date::Date() :m_CUR_YEAR(systemYear()) {
      setToToday();
   }
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }
   int Date::errCode()const {
       return m_ErrorCode;
   }
   const char* const Date::dateStatus()const {
      return DATE_ERROR[errCode()];
   }
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }
   std::istream& Date::read(std::istream& is)
   {
        char a{};
        int day = -1, month = -1, year = -1;

        errCode(NO_ERROR);

        if (m_ErrorCode != NO_ERROR)
        {
            cout << dateStatus();
        }

        if (ut.getInt(year, is))
        {
            a = is.get();
            if (a == '/' || a == '-')
            {
                if (ut.getInt(month, is))
                {
                    a = is.get();
                    if (a == '/' || a == '-')
                    {
                        if(ut.getInt(day, is)){}
                        else
                        {
                            errCode(CIN_FAILED);
                        }
                    }
                    else
                    {
                        errCode(CIN_FAILED);
                    }
                }
                else
                {
                    errCode(CIN_FAILED);
                }
                   
            }
            else
            {
                errCode(CIN_FAILED);
            }
               
        }
        else
        {
            errCode(CIN_FAILED);
        }
           
        if (m_ErrorCode != CIN_FAILED)
        {
            m_day = day;
            m_mon = month;
            m_year = year;


            validate();
            
        }
        
           
       
       

       return is;
   }
   std::ostream& Date::write(std::ostream& os) const
   {
       if (!*this)
       {
           os << dateStatus();
       }
       else
       {
           os << m_year << '/' << right << setw(2) << setfill('0') << m_mon << '/' << right << setw(2) << setfill('0') << m_day << setfill(' ') << setw(0);
       }

       return os;
   }
   

   Date::operator bool() const
   {
       return !this->bad();
   }
   
   
   
   bool Date::operator==(const Date& right) const
   {
       return this->daysSince0001_1_1() == right.daysSince0001_1_1();
   }
   bool Date::operator!=(const Date& right) const
   {
       return this->daysSince0001_1_1() != right.daysSince0001_1_1();
   }
   bool Date::operator>=(const Date& right) const
   {
       return this->daysSince0001_1_1() >= right.daysSince0001_1_1();
   }
   bool Date::operator<=(const Date& right) const
   {
       return this->daysSince0001_1_1() <= right.daysSince0001_1_1();
   }
   bool Date::operator<(const Date& right) const
   {
       return this->daysSince0001_1_1() < right.daysSince0001_1_1();
   }
   bool Date::operator>(const Date& right) const
   {
       return this->daysSince0001_1_1() > right.daysSince0001_1_1();
   }
   int Date::operator-(const Date& right) const
   {
       return this->daysSince0001_1_1() - right.daysSince0001_1_1();
   }


   std::ostream& operator<<(std::ostream& os, const Date& right) {
      return right.write(os);
   }
   std::istream& operator>>(std::istream& is, Date& right) {
      return right.read(is);
   }


}
