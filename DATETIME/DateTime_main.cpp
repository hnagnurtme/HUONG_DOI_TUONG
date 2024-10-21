#include <iostream>
#include "DateTime.h"

using namespace std;

int main() {
    int day, month, year, hour, minute, second;

    cout << "Nhap ngay (dd mm yyyy): ";
    cin >> day >> month >> year;
    cout << "Nhap gio (hh mm ss): ";
    cin >> hour >> minute >> second;

    DateTime dateTime(day, month, year, hour, minute, second);

    cout << "Ngay gio da nhap: " << dateTime << endl;

    ++dateTime;
    cout << "Sau khi tang 1 giay: " << dateTime << endl;

    --dateTime;
    cout << "Sau khi giam 1 giay: " << dateTime << endl;

    return 0;
}
