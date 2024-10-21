#ifndef Dathuc_H
#define Dathuc_H
#include <iostream>
using namespace std;
class Dathuc{
private:
    int n;
    int *heso;
public:
    Dathuc(int n = 3);
    Dathuc(int heso[], int size);
    Dathuc(const Dathuc &dathuc);
    ~Dathuc();

    Dathuc operator + (const Dathuc &dathuc);
    Dathuc operator - (const Dathuc &dathuc);

    Dathuc& operator = (const Dathuc &dathuc);

    friend  istream& operator >> (istream &in, Dathuc &dathuc);
    friend ostream& operator << (ostream &out,const  Dathuc &dathhuc);
    Dathuc operator << (const Dathuc &dathuc);
    int& operator [] (int i);



};
#endif