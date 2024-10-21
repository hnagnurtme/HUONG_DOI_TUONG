#include "Candidate.h"
#include <iostream>
#include <string>

using namespace std;

Candidate :: Candidate(int ma  , string ten ) {
        this->ma = ma;
        this->ten = ten;
        this->sinhnhat = new unsigned int [3];
        this->diem = new unsigned int[3];
}
Candidate :: ~Candidate(){
    delete[] sinhnhat;
    delete[] diem ;
}

void Candidate :: Nhap(){
    cout <<"Nhap thong tin co thi sinh :"<<endl;
    cout <<"Ma so thi sinh       : " ; cin >>ma;  getchar();
    cout <<"Ten thi sinh         : " ; getline(cin , ten);
    cout <<"Ngay thang nam sinh  : " ; cin >>sinhnhat[0];cin>> sinhnhat[1] ; cin >> sinhnhat[2];
    cout <<"Diem Toan Van Anh    : " ; cin >> diem[0]; cin>> diem[1]; cin>> diem[2];
}
        
void Candidate :: Xuat(){
    cout <<"Thong tin cua thi sinh :"  <<endl;
    cout <<"Ma so thi sinh       : " << ma <<endl; 
    cout <<"Ten thi sinh         : " << ten <<endl; 
    cout <<"Ngay thang nam sinh  : " << sinhnhat[0] <<"/"<<sinhnhat[1]<<"/"<<sinhnhat[2]<<endl;
    cout <<"Diem Toan Van Anh    : " << diem[0] << diem[1] << diem[2]<<endl;

}

int Candidate :: TongDiem(){
    return (diem[0]+ diem[1]+diem[2]);
}