#include "TestCandidate.h"
#include "Candidate.h"
#include <iostream>
using namespace std;

TestCandidate :: TestCandidate(int size ){
    this->size = size;
    ListCandidate = new Candidate[size];
}
TestCandidate :: ~TestCandidate(){
    delete[] ListCandidate;
}

void TestCandidate ::  NhapDanhSach(){
    for(int i = 0; i < size;i++){
        cout <<" Thi sinh thu "<<i<<endl;
        ListCandidate[i].Nhap();
    }
    
}

void TestCandidate :: XuatDanhSach(){
    for(int i = 0; i < size;i++){
        cout <<" Thi sinh co tong diem tren 15 :"<<endl;
        if (ListCandidate[i].TongDiem() >15)  ListCandidate[i].Xuat();
    }
}
