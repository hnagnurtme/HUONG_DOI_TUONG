#include <iostream>
#include "Candidate.h"
#include "TestCandidate.h"
using namespace std;
int main(){
    int size;
    cout << " Nhap so luong thi sinh : ";cin >> size;
    TestCandidate *danhsach = new TestCandidate(size);

    danhsach->NhapDanhSach();
    danhsach->XuatDanhSach();
    return 0;
}
