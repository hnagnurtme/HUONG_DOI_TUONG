#include "DateTime.h"
#include <iostream>
using namespace std;

DateTime::DateTime(int day, int month, int year, int hour, int minute, int second)
    : Date(day, month, year), Time(hour, minute, second) {}

DateTime& DateTime::operator++() {
    ++second;
    if (second >= 60) {
        second = 0;
        ++minute;
        if (minute >= 60) {
            minute = 0;
            ++hour;
            if (hour >= 24) {
                hour = 0;
                ++(*static_cast<Date*>(this)); 
            }
        }
    }
    return *this;
}

DateTime DateTime::operator++(int) {
    DateTime temp = *this;
    ++(*this);
    return temp;
}

DateTime& DateTime::operator--() {
    --second;
    if (second < 0) {
        second = 59;
        --minute;
        if (minute < 0) {
            minute = 59;
            --hour;
            if (hour < 0) {
                hour = 23;
                --(*static_cast<Date*>(this)); 
            }
        }
    }
    return *this;
}

DateTime DateTime::operator--(int) {
    DateTime temp = *this;
    --(*this);
    return temp;
}

ostream& operator<<(ostream& out, const DateTime& dateTime) {
    out << static_cast<const Date&>(dateTime)<<" ";
    out << static_cast<const Time&>(dateTime);
    return out;
}

istream& operator>>(istream& in, DateTime& dateTime) {
    in >> static_cast<Date&>(dateTime);
    in >> static_cast<Time&>(dateTime);
    return in;
}
