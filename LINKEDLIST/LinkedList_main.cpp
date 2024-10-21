#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList list;
    int x, pos, value_add;

    list.Add_Front(12);
    list.Add_Front(32);
    list.Add_Front(67);
    list.Add_Front(12121);
    list.Add_Front(88);
    cout <<"======================================\n\n";
    cout << "Danh sach hien tai: " << list << endl;

    cout << "Nhap gia tri de them vao dau danh sach: ";
    cin >> x;
    list.Add_Front(x);
    cout << "Danh sach hien tai: " << list << endl;

    cout << "Nhap gia tri de them vao cuoi danh sach: ";
    cin >> x;
    list.Add_End(x);
    cout <<"======================================\n\n";
    cout << "Danh sach hien tai: " << list << endl;

    cout << "Nhap vi tri muon them phan tu: ";
    cin >> pos;
    cout << "Nhap gia tri de them sau vi tri " << pos << ": ";
    cin >> x;
    list.Add_After_Position(pos, x);
    cout <<"======================================\n\n";
    cout << "Danh sach hien tai: " << list << endl;

    if (list.Delete_Front(x)) {
        cout << "Da xoa phan tu o dau danh sach, gia tri la: " << x << endl;
    } else {
        cout << "Danh sach rong, khong the xoa.\n";
    }
    cout <<"======================================\n";
    cout << "Danh sach hien tai: " << list << endl;

    if (list.Delete_End(x)) {
        cout << "Da xoa phan tu o cuoi danh sach, gia tri la: " << x << endl;
    } else {
        cout << "Danh sach rong, khong the xoa.\n";
    }
    cout <<"======================================\n";
    cout << "Danh sach hien tai: " << list << endl;

    cout << "Nhap gia tri ban muon them phan tu sau: ";
    cin >> value_add;
    cout << "Nhap gia tri de them sau gia tri " << value_add << ": ";
    cin >> x;
    if (list.Add_After_Value(value_add, x)) {
        cout << "Da them " << x << " sau gia tri " << value_add << endl;
    } else {
        cout << "Khong tim thay gia tri " << value_add << " trong danh sach.\n";
    }
    cout <<"======================================\n";
    cout << "Danh sach hien tai: " << list << endl;

    cout << "Nhap gia tri can xoa: ";
    cin >> x;
    if (list.Delete_With_Value(x)) {
        cout << "Da xoa phan tu co gia tri " << x << endl;
    } else {
        cout << "Khong tim thay gia tri " << x << " trong danh sach.\n";
    }
    cout <<"======================================\n";
    cout << "Danh sach hien tai: " << list << endl;
    cout <<" Chon sap xep tang dan (1) hay giam dan (2) :";
    int choice; cin>>choice;
    if( choice == 1){
        cout << "Sap xep danh sach theo thu tu tang dan.\n";
        Sorting(list, Increase);
        cout <<"======================================\n";
        cout << "Danh sach sau khi sap xep tang dan: " << list << endl;
    }
    
    if(choice == 2){
        cout << "Sap xep danh sach theo thu tu giam dan.\n";
        Sorting(list, Decrease);
        cout <<"======================================\n";
        cout << "Danh sach sau khi sap xep giam dan: " << list << endl;

    }
    

    return 0;
}
