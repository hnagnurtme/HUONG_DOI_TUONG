#include <iostream>
#include "Set.h"

using namespace std;

void printSets(const Set<int>& set1, const Set<int>& set2) {
    cout <<"========================================\n";
    cout << "Tap hop 1 hien tai: " << set1 << endl;
    cout << "Tap hop 2 hien tai: " << set2 << endl;
}

int main() {
    int size;
    Set<int> set1(10);
    Set<int> set2(10);
    cout << "Nhap so luong phan tu tap hop 1: ";
    cin >> size;
    
    int* arr = new int[size];

    cout << "Nhap cac phan tu cua tap hop: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
        set1 + arr[i];
    }
    delete[] arr;

    cout << "Nhap so luong phan tu tap hop 2: ";
    cin >> size;
    
    int* arr2 = new int[size];

    cout << "Nhap cac phan tu cua tap hop: ";
    for (int i = 0; i < size; i++) {
        cin >> arr2[i];
        set2 + arr2[i];
    }
    delete[] arr2;

    printSets(set1, set2);

    int x;
    cout << "Nhap phan tu can them vao tap hop 1: ";
    cin >> x;
    if ((set1 + x)) {
        cout << "Da them phan tu " << x << " vao tap hop.\n";
    } else {
        cout << "Khong the them phan tu " << x << ".\n";
    }
    printSets(set1, set2);

    int y;
    cout << "Nhap phan tu can xoa khoi tap hop 2: ";
    cin >> y;
    if (set2 - y) {
        cout << "Da xoa phan tu " << y << " khoi tap hop 2.\n";
    } else {
        cout << "Khong the xoa phan tu " << y << ".\n";
    }
    printSets(set1, set2);

    int z;
    cout << "Nhap phan tu can kiem tra o tap hop 1: ";
    cin >> z;
    if (set1(z)) {
        cout << "Phan tu " << z << " ton tai trong tap hop.\n";
    } else {
        cout << "Phan tu " << z << " khong ton tai trong tap hop.\n";
    }

    Set<int> intersection = set1 * set2;
    cout << "Tap giao: " << intersection << endl;

    Set<int> unionSet = set1 + set2;
    cout << "Tap hop: " << unionSet << endl;

    Set<int> difference = set1 - set2;
    cout << "Tap hieu: " << difference << endl;

    printSets(set1, set2);

    return 0;
}
