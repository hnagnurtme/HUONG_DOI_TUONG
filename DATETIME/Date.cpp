#include "Date.h"
#include <iostream>

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

Date& Date::operator++() {
    static const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    day++;
    if (day > daysInMonth[month - 1]) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

Date Date::operator++(int) {
    Date temp = *this;
    ++(*this);
    return temp;
}

Date& Date::operator--() {
    static const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day = daysInMonth[month - 1];
    }
    return *this;
}

Date Date::operator--(int) {
    Date temp = *this;
    --(*this);
    return temp;
}

ostream& operator <<(ostream& out,const  Date &date) {
    out << (date.day < 10 ? "0" : "") << date.day << "/"
        << (date.month < 10 ? "0" : "") << date.month << "/"
        << date.year;
    return out;
}

istream& operator>>(istream& in, Date& date) {
    char slash;
    in >> date.day >> slash >> date.month >> slash >> date.year;
    return in;
}