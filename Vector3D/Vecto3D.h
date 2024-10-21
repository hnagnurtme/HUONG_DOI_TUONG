#ifndef Vecto3D_H
#define Vecto3D_H
#include <iostream>
using namespace std;
class Vecto3D {
        int x, y, z;
        static int count;
    public:
        Vecto3D(int =1, int =1, int =1);
        ~Vecto3D() {
            count--;
        }
        void Nhap();
        void Xuat() const;
        double Dodai() const;
        static void printCount();
        Vecto3D operator + (const Vecto3D &v);
        friend istream &operator >> (istream &in, Vecto3D &v);
        friend ostream &operator << (ostream &out, const Vecto3D &v);
};
#endif