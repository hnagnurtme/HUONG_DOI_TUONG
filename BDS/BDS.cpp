#include "BDS.h"
#include <iostream>
#include <math.h>
using namespace std;
float Shape::tongDientich = 0;
int Shape::Nhap(){
    cin >> kichthuoc;
    getchar();
    cout <<" Nhap dia chi : ";
    getline(cin,diachi);
}

void Shape::Xuat(){
    cout <<kichthuoc;
    cout <<" Dia chi : " <<diachi <<" ";
}


int Circle::Nhap(){
    cout << " Nhap ban kinh ";
    Shape::Nhap();
}

void Circle::Xuat(){
    cout <<" Kich thuoc : ";
    Shape::Xuat();
}

float Circle ::ChuVi(){
    Shape::tongDientich +=  2*kichthuoc*3.14;
    return 2*kichthuoc*3.14;
}
float Circle ::DienTich(){
    Shape::tongDientich += kichthuoc*kichthuoc*3.14;
    return kichthuoc*kichthuoc*3.14;
}
int Square::Nhap(){
    cout << " Nhap ban kinh ";
    Shape::Nhap();
}

void Square::Xuat(){
    cout <<" Kich thuoc : ";
    Shape::Xuat();
}

float Square::ChuVi(){
    Shape::tongDientich +=kichthuoc*4;
    return kichthuoc*4;
}
float Square::DienTich(){
    Shape::tongDientich +=kichthuoc*kichthuoc;
    return kichthuoc*kichthuoc;
}
int TamGiacDeu::Nhap(){
    cout << " Nhap ban kinh ";
    Shape::Nhap();
}
float TamGiacDeu::ChuVi(){
    Shape::tongDientich += kichthuoc*3;
    return kichthuoc*3;
}

float TamGiacDeu::DienTich(){
    Shape::tongDientich += kichthuoc*kichthuoc*sqrt(3)/4;
    return kichthuoc*kichthuoc*sqrt(3)/4;
}
void TamGiacDeu::Xuat(){
    cout <<" Kich thuoc : ";
    Shape::Xuat();
}