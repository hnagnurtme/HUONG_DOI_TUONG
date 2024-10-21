#include "QuanliSV.h"
#include "Sinhvien.h"
#include <iostream>
using namespace std;

int main() {
    QuanliSV qlsv(5);

    Sinhvien sv1(101, 8.5);
    Sinhvien sv2(102, 7.2);
    Sinhvien sv3(103, 9.0);
    qlsv.Add(sv1);
    qlsv.Add(sv2);
    qlsv.Add(sv3);

    cout << "Danh sach sinh vien sau khi them 3 sinh vien:" << endl;
    qlsv.Show();
    cout << endl;

    Sinhvien svArr[2] = { Sinhvien(104, 6.8), Sinhvien(105, 7.5) };
    qlsv.Add_Range(svArr, 2);

    cout << "Danh sach sinh vien sau khi them 2 sinh vien nua:" << endl;
    qlsv.Show();
    cout << endl;

    Sinhvien svFind(103, 0);
    int index = qlsv.IndexOf(svFind);
    if (index != -1) {
        cout << "Sinh vien co MSSV 103 o vi tri: " << index << endl;
    } else {
        cout << "Khong tim thay sinh vien co MSSV 103." << endl;
    }
    cout << endl;

    Sinhvien svUpdate(102, 8.0);
    qlsv.Update(svUpdate);
    cout << "Danh sach sinh vien sau khi cap nhat diem trung binh MSSV 102:" << endl;
    qlsv.Show();
    cout << endl;

    qlsv.RemoveAt(1);
    cout << "Danh sach sinh vien sau khi xoa sinh vien tai vi tri 1:" << endl;
    qlsv.Show();
    cout << endl;

    Sinhvien svRemove(105, 0);
    qlsv.Remove(svRemove);
    cout << "Danh sach sinh vien sau khi xoa sinh vien co MSSV 105:" << endl;
    qlsv.Show();
    cout << endl;

    qlsv.Sort_DiemTB();
    cout << "Danh sach sinh vien sau khi sap xep theo diem trung binh:" << endl;
    qlsv.Show();
    cout << endl;

    return 0;
}
