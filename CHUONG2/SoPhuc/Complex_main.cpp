#include <iostream>
#include "Complex.h"

using namespace std;

int main(){
    Complex *so1 = new Complex();
    Complex *so2 = new Complex();

    so1->Nhap();
    so2->Nhap();

    Complex res = Complex(Cong(*so1,*so2));
    res.Xuat();

    Complex res2 = Complex(Tru(*so1,*so2));
    res2.Xuat();

    Complex res3 = Complex(Nhan(*so1,*so2));
    res3.Xuat();

    Complex res4 = Complex(Chia(*so1,*so2));
    res4.Xuat();

    return 0;
}