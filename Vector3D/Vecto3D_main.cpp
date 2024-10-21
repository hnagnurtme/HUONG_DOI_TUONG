#include "Vecto3D.h"
#include <iostream>
using namespace std;
int main(){
    Vecto3D v1, v2;
    v1.printCount();
    Vecto3D::printCount();
    cout<<"Nhap toa do v1:"<<endl;
    cin>>v1;
    cout<<"Nhap toa do v2:"<<endl;
    cin>>v2;
    cout<<"Toa do cua vecto v1 vua nhap :";
    cout<<v1;
    cout<<"Toa do cua vecto v2 vua nhap :";
    cout<<v2;
    cout<<"Do dai cua vecto v1:"<<v1.Dodai()<<endl;
    cout<<"Vecto tong v1 + v2: "<<v1+v2;
    Vecto3D *vp = new Vecto3D;
    vp->printCount();
    delete vp;
}