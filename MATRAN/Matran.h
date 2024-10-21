#ifndef Matran_H
#define Matran_H
#include <iostream>
using namespace std;

class Matran {
private:
    int n;
    int **data;
public:
    Matran(int n = 2);
    Matran(const Matran &matran);
    ~Matran();

    Matran operator+(const Matran &matran);
    Matran operator-(const Matran &matran);
    Matran operator*(const Matran &matran);
    Matran& operator=(const Matran &matran);

    int operator ()(int , int);

    friend istream& operator>>(istream& in, Matran &matran);
    friend ostream& operator<<(ostream& out, const Matran &matran);
};

#endif
