#include <iostream>
#include "Dathuc.h"
using namespace std;

int main(){
    Dathuc dathuc1(3);
    Dathuc dathuc2(3);

    cout << "Nhap da thuc thu nhat:\n";
    cin >> dathuc1;

    cout << "Nhap da thuc thu hai:\n";
    cin >> dathuc2;

    Dathuc tong = dathuc1 + dathuc2;
    Dathuc hieu = dathuc1 - dathuc2;

    cout << "Tong hai da thuc: " << tong << endl;
    cout << "Hieu hai da thuc: " << hieu << endl;

    cout << "He so bac 2 cua da thuc thu nhat: " << dathuc1[2] << endl;

    return 0;
}
