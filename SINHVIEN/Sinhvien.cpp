#include "Sinhvien.h"
#include <iostream>
using namespace std;

Sinhvien::Sinhvien(int ID, double diem) {
    MSSV = ID;
    DTB = diem;
}

Sinhvien::Sinhvien(const Sinhvien &sv) {
    MSSV = sv.MSSV;
    DTB = sv.DTB;
}

Sinhvien::~Sinhvien() {
    
}

void Sinhvien::ShowSV() {
    cout << "MSSV: " << MSSV << endl;
    cout << "Diem trung binh: " << DTB << endl;
}


int Sinhvien :: GetMSSV(){
    return MSSV;
}

double Sinhvien :: GetDTB(){
    return DTB;
}