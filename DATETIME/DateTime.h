#ifndef DATETIME_H
#define DATETIME_H

#include "Date.h"
#include "Time.h"

class DateTime : public Date, public Time {
public:
    DateTime(int day = 1, int month = 1, int year = 2000, int hour = 0, int minute = 0, int second = 0);

    DateTime& operator++();     
    DateTime operator++(int);   
    DateTime& operator--();     
    DateTime operator--(int);   

    friend ostream& operator<<(ostream& out, const DateTime& dateTime);
    friend istream& operator>>(istream& in, DateTime& dateTime);
};

#endif
