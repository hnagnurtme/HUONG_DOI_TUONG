#include "Vecto3D.h"
#include <iostream>
#include <math.h>
using namespace std;
int Vecto3D::count = 0;
Vecto3D::Vecto3D(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
    count++;
}
void Vecto3D::Nhap(){
    cout<<"Toa do x:"; cin>>x;
    cout<<"Toa do y:"; cin>>y;
    cout<<"Toa do z:"; cin>>z;
}
void Vecto3D::Xuat() const{
    cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
}
double Vecto3D::Dodai() const{
    return sqrt(x*x+y*y+z*z);
}
void Vecto3D::printCount(){
    cout<<"Co "<<count<<" vecto(s). "<<endl;
}
istream &operator >> (istream &in, Vecto3D &v){
    cout<<"Toa do x:"; in>>v.x;
    cout<<"Toa do y:"; in>>v.y;
    cout<<"Toa do z:"; in>>v.z;
    return in;
}
ostream &operator << (ostream &out, const Vecto3D &v){
    out<<"("<<v.x<<","<<v.y<<","<<v.z<<")"<<endl;
    return out;
}
Vecto3D Vecto3D::operator + (const Vecto3D &v){
    return Vecto3D(this->x + v.x,this->y + v.y, this->z + v.z);
}
