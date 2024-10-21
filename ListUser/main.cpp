#include <iostream>
#include "DataStructures.h"

using namespace std;

int main() {
    // Tạo một vector với dung lượng ban đầu là 5
    Vector<int> vec(5);

    // Thêm các phần tử vào cuối vector
    vec.pushback(10);
    vec.pushback(20);
    vec.pushback(30);

    // Thêm phần tử vào đầu vector
    vec.pushfront(5);

    // In ra các phần tử trong vector
    cout << "Vector elements: ";
    for (int i = 0; i < vec.getSize(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // Xóa phần tử cuối và phần tử đầu
    vec.popback();
    vec.popfront();

    // In ra các phần tử còn lại
    cout << "After popback and popfront, vector elements: ";
    for (int i = 0; i < vec.getSize(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // Xóa phần tử ở vị trí 0
    vec.remove(0);

    // In ra các phần tử sau khi xóa
    cout << "After removing element at position 0, vector elements: ";
    for (int i = 0; i < vec.getSize(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}
