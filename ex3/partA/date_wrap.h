#ifndef DATE_WRAP_H_
#define DATE_WRAP_H_

//#include "exceptions.h"
#include <iostream>

extern "C" {
 #include "date.h"
}
using std::ostream;
using std::cout;
using std::endl;

namespace mtm{
class DateWrap{
    Date date;

    static bool dateIsValid(int day,int month){
        if(day<1||day>30||month<1||month>12){
            return false;
        }
        return true;
    }

public:

    DateWrap(const int day,const int month,const int year);
    DateWrap(const DateWrap& date_to_copy);
    DateWrap(int days);
    int day() const;
    int month() const;
    int year() const;
    friend ostream& operator<<(ostream& os,const DateWrap& date);
    bool operator>(const DateWrap& cmp_date) const;
    bool operator<(const DateWrap& cmp_date) const;
    DateWrap operator++(int);
    ~DateWrap();
/*    int dateToInt()const;*/
    DateWrap& operator+=(int days);

    friend DateWrap operator+(const DateWrap& date1,const DateWrap& date2);
};

bool operator==(const DateWrap& date1,const DateWrap& date2);

bool operator>=(const DateWrap& date1,const DateWrap& date2);

bool operator<=(const DateWrap& date1,const DateWrap& date2);

bool operator!=(const DateWrap& date1,const DateWrap& date2);

int dateToInt(DateWrap date);

DateWrap operator+(int days,DateWrap date);

DateWrap operator+(DateWrap date,int days);

/*
DateWrap operator+(const int, const DateWrap& date);
*/
}
#endif