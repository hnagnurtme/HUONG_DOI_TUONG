#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;
class Time{
protected:
    int hour;
    int minute;
    int second;
public :
    Time( int hour = 0, int minute = 0 , int second = 0);
    Time& operator ++ ();
    Time operator ++ (int);
    Time& operator -- ();
    Time operator -- (int);

    friend ostream& operator <<(ostream& out,const Time &Time);
    friend istream& operator >>(istream& in , Time & Time);

};

#endif