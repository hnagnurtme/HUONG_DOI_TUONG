#include "Set.h"
#include <iostream>
#include <limits>
using namespace std;

Set::Set(int size) {
    this->size = size;
    this->n = 0;
    data = new int[size];
}

Set::Set(int data[], int size) {
    this->size = size;
    this->n = size;
    this->data = new int[size];
    for (int i = 0; i < n; i++) {
        this->data[i] = data[i];
    }
}

Set::Set(const Set &set) {
    this->size = set.size;
    this->n = set.n;
    this->data = new int[size];
    for (int i = 0; i < n; i++) {
        this->data[i] = set.data[i];
    }
}

Set::~Set() {
    delete[] data;
}

bool Set::operator+(int &x) {
    if (n >= size) return false;
    for (int i = 0; i < n; i++) {
        if (data[i] == x) {
            cout << "Phan tu " << x << " da ton tai trong tap hop.\n";
            return false;
        }
    }
    data[n] = x;
    n++;
    return true;
}

bool Set::operator-(const int &y) {
    if (n == 0) return false;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (data[i] == y) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Khong ton tai " << y << " trong tap hop.\n";
        return false;
    }
    for (int i = index; i < n - 1; i++) {
        data[i] = data[i + 1];
    }
    n--;
    return true;
}

Set Set::operator=(const Set &set) {
    if (this == &set) return *this;
    delete[] data;
    this->size = set.size;
    this->n = set.n;
    this->data = new int[size];
    for (int i = 0; i < n; i++) {
        this->data[i] = set.data[i];
    }
    return *this;
}

Set Set::operator*(const Set &set) {
    Set intersection(min(this->n, set.n));
    for (int i = 0; i < this->n; i++) {
        for (int j = 0; j < set.n; j++) {
            if (this->data[i] == set.data[j]) {
                intersection + this->data[i];
                break;
            }
        }
    }
    return intersection;
}

Set Set::operator+(const Set &set) {
    Set unionSet(this->n + set.n);
    for (int i = 0; i < this->n; i++) {
        unionSet + this->data[i];
    }
    for (int i = 0; i < set.n; i++) {
        unionSet + set.data[i];
    }
    return unionSet;
}

Set Set::operator-(const Set &set) {
    Set difference(this->n);
    for (int i = 0; i < this->n; i++) {
        bool found = false;
        for (int j = 0; j < set.n; j++) {
            if (this->data[i] == set.data[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            difference + this->data[i];
        }
    }
    return difference;
}

bool Set::operator()(const int &x) {
    for (int i = 0; i < n; i++) {
        if (data[i] == x) return true;
    }
    return false;
}

int Set::operator[](int i) {
    if (i >= 0 && i < n) return data[i];
    else return INT_MIN;
}

ostream &operator<<(ostream &out, const Set &set) {
    for (int i = 0; i < set.n; i++) {
        out << set.data[i] << " ";
    }
    return out;
}
