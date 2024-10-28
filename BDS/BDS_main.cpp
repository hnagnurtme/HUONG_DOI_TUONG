#include <iostream>
#include <vector>
#include "BDS.h"
using namespace std;

int main() {
    vector<Shape*> danhSachDat; 
    int loaiDat;
    Shape* manhDat = nullptr;

    do {
        cout << "Chon loai manh dat (1: Hinh tron, 2: Hinh vuong, 3: Hinh tam giac deu, 0: Thoat): ";
        cin >> loaiDat;

        switch (loaiDat) {
            case 1:
                manhDat = new Circle();
                break;
            case 2:
                manhDat = new Square();
                break;
            case 3:
                manhDat = new TamGiacDeu();
                break;
            case 0:
                cout << "Ket thuc nhap lieu." << endl;
                break;
            default:
                cout << "Loai manh dat khong hop le. Vui long nhap lai." << endl;
                continue;  
        }

        if (loaiDat == 1 || loaiDat == 2 || loaiDat == 3) {
            manhDat->Nhap();              
            danhSachDat.push_back(manhDat);  
        }

    } while (loaiDat != 0);

    float tongDienTich = 0;
    for (int i = 0; i < danhSachDat.size(); i++) {
        danhSachDat[i]->Xuat();
        cout << "       Chu vi: " << danhSachDat[i]->ChuVi() << "      ";
        cout << "       Dien tich: " << danhSachDat[i]->DienTich() << endl;
    }

    cout << "Tong dien tich cac manh dat: " << Shape::tongDientich << endl;
    return 0;
}
