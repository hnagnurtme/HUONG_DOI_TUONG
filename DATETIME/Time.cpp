#include "Time.h"
#include <iostream>
using namespace std;

Time::Time(int hour, int minute, int second) : hour(hour), minute(minute), second(second) {}

Time& Time::operator++() {
    second++;
    if (second >= 60) {
        second = 0;
        minute++;
        if (minute >= 60) {
            minute = 0;
            hour++;
            if (hour >= 24) {
                hour = 0;
            }
        }
    }
    return *this;
}

Time Time::operator++(int) {
    Time temp = *this;
    ++(*this);  
    return temp;
}

Time& Time::operator--() {
    second--;
    if (second < 0) {
        second = 59;
        minute--;
        if (minute < 0) {
            minute = 59;
            hour--;
            if (hour < 0) {
                hour = 23;
            }
        }
    }
    return *this;
}

Time Time::operator--(int) {
    Time temp = *this;
    --(*this);  
    return temp;
}

ostream& operator<<(ostream& out, const Time& time) {
    out << (time.hour < 10 ? "0" : "") << time.hour << ":"
        << (time.minute < 10 ? "0" : "") << time.minute << ":"
        << (time.second < 10 ? "0" : "") << time.second;
    return out;
}

istream& operator>>(istream& in, Time& time) {
    char colon;
    in >> time.hour >> colon >> time.minute >> colon >> time.second;
    return in;
}