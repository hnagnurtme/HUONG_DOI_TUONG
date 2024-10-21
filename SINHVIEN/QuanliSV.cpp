#include "QuanliSV.h"
#include <iostream>
using namespace std;

QuanliSV::QuanliSV(int size) {
    data = new Sinhvien[size];
    this->count = 0;
    this->maxsize = size;
}

QuanliSV::~QuanliSV() {
    delete[] data;
}

void QuanliSV::Add(Sinhvien sv) {
    if (count < maxsize) {
        data[count] = sv;
        count++;
    } else {
        cout << "Danh sach sinh vien da day!" << endl;
    }
}

void QuanliSV::Add_Range(Sinhvien svArr[], int n) {
    for (int i = 0; i < n; i++) {
        Add(svArr[i]);
    }
}

int QuanliSV::IndexOf(Sinhvien sv) {
    for (int i = 0; i < count; i++) {
        if (data[i].GetMSSV() == sv.GetMSSV()) {
            return i;
        }
    }
    return -1;
}

void QuanliSV::RemoveAt(int index) {
    if (index >= 0 && index < count) {
        for (int i = index; i < count - 1; i++) {
            data[i] = data[i + 1];
        }
        count--;
    } else {
        cout << "Index khong hop le!" << endl;
    }
}

void QuanliSV::Remove(Sinhvien sv) {
    int index = IndexOf(sv);
    if (index != -1) {
        RemoveAt(index);
    } else {
        cout << "Khong tim thay sinh vien!" << endl;
    }
}

void QuanliSV::Show() {
    for (int i = 0; i < count; i++) {
        data[i].ShowSV();
    }
}

void QuanliSV::Update(Sinhvien sv) {
    int index = IndexOf(sv);
    if (index != -1) {
        data[index] = sv;
    } else {
        cout << "Khong tim thay sinh vien!" << endl;
    }
}

void QuanliSV::Sort_DiemTB() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (data[i].GetDTB() > data[j].GetDTB()) {
                Sinhvien temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}
