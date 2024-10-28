#include <iostream>
#include "Matran.h"
using namespace std;

int main() {
    int size;
    cout << "Nhap kich thuoc cua ma tran: ";
    cin >> size;

    Matran<int> mat1(size);
    Matran<int> mat2(size);

    cout << "Nhap cac phan tu cho ma tran 1:" << endl;
    cin >> mat1;

    cout << "Nhap cac phan tu cho ma tran 2:" << endl;
    cin >> mat2;

    Matran<int> tong = mat1 + mat2;
    Matran<int> hieu = mat1 - mat2;
    Matran<int> tich = mat1 * mat2;

    cout << "Ma tran 1:" << endl;
    cout << mat1;

    cout << "Ma tran 2:" << endl;
    cout << mat2;

    cout << "Tong cua hai ma tran:" << endl;
    cout << tong;

    cout << "Hieu cua hai ma tran:" << endl;
    cout << hieu;

    cout << "Tich cua hai ma tran:" << endl;
    cout << tich;

    int i, j;
    cout << "Nhap hang va cot de truy xuat phan tu: ";
    cin >> i >> j;
    cout << "Phan tu tai vi tri (" << i << ", " << j << ") la: " << mat1(i, j) << endl;

    return 0;
}
