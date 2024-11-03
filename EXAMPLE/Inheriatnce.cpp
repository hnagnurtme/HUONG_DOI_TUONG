#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() const {
        cout << "Base class" << endl;
    }
};

class Derived : public Base {
public:
    void display() const override {
        cout << "Derived class" << endl;
    }

    void derivedMethod() {
        cout << "Method specific to Derived class" << endl;
    }
};

int main() {
    Base* basePtr = new Derived(); // Con trỏ đến lớp cơ sở trỏ đến đối tượng lớp con

    basePtr->display(); // Gọi phương thức ảo: Kết quả: "Derived class"

    // basePtr->derivedMethod(); // Lỗi: không thể gọi phương thức riêng của lớp Derived

    delete basePtr; // Giải phóng bộ nhớ
    return 0;
}