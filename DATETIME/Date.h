#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;
class Date{
protected:
    int day;
    int month;
    int year;
public:
    Date(int day = 1, int month = 1, int year = 2024);
    Date& operator ++ ();
    Date operator ++ (int);
    Date& operator -- ();
    Date operator -- (int);

    friend ostream& operator <<(ostream& out, const Date &date);
    friend istream& operator >>(istream& in , Date & date);
    
};

#endif