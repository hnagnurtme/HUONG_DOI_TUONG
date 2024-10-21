#include "Complex.h"
#include <iostream>

using namespace std;

Complex :: Complex(float thuc  , float ao ){
    this->thuc = thuc;
    this->ao = ao;
};

void Complex :: Nhap(){
    cout << " Nhap phan thuc ";
    cin >> thuc;
    cout <<" Nhap phn ao :";
    cin >> ao;
};

void Complex :: Xuat(){
    cout <<" So phuc do la "<< thuc <<" + "<<ao <<endl;

};

Complex Cong(const Complex &so1 , const Complex &so2){
    return Complex(so1.thuc + so2.thuc , so1.ao + so2.ao);
};

Complex Tru(const Complex &so1 , const Complex &so2){
    return Complex(so1.thuc - so2.thuc , so1.ao - so2.ao);
}

Complex Nhan(const Complex &so1 , const Complex &so2){
    return Complex(so1.thuc*so1.ao - so2.thuc*so2.ao,so1.thuc+ so2.ao - so2.thuc*so1.ao);
};

Complex Chia(const Complex &so1 , const Complex &so2){
    float res = so1.ao*so1.ao + so2.ao*so2.ao;
    return Complex(( so1.thuc*so1.ao + so2.thuc*so2.ao)/res   , (so2.thuc*so1.ao - so1.thuc*so2.ao) / res);

};
