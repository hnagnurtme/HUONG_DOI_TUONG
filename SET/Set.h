#ifndef SET_H
#define SET_H

#include <iostream>
using namespace std;
class Set{
private:
    int size;
    int n;
    int *data;
public:
    Set(int size = 2);
    Set(int data[] ,int size);
    Set(const Set &set);
    ~Set();

    bool operator + (int &x);
    bool operator - (const int &y);

    Set operator + (const Set &set);
    Set operator - (const Set &set);
    Set operator * (const Set &set);

    bool operator () (const int &x);
    int operator [] (int i);

    Set operator = ( const Set &set);
    friend ostream& operator << (ostream &out ,const Set &set);
};

#endif
