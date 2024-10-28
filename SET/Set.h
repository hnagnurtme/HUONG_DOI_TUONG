#ifndef SET_H
#define SET_H

#include <iostream>
#include <limits>
using namespace std;

template<typename T>
class Set {
private:
    int size;
    int n;
    T *data;

public:
    Set(int size = 2);
    Set(T data[], int size);
    Set(const Set<T>& set);
    ~Set();

    bool operator+(const T& x);
    bool operator-(const T& y);
    Set<T> operator+(const Set<T>& set);
    Set<T> operator-(const Set<T>& set);
    Set<T> operator*(const Set<T>& set);
    bool operator()(const T& x) const;
    T operator[](int i);
    Set<T>& operator=(const Set<T>& set);

    template <typename U>
    friend ostream& operator<<(ostream& out, const Set<U>& set);
};

template <typename T>
Set<T>::Set(int size) {
    this->size = size;
    this->n = 0;
    data = new T[size];
}

template <typename T>
Set<T>::Set(T data[], int size) {
    this->size = size;
    this->n = 0;
    this->data = new T[size];
    for (int i = 0; i < size; i++) {
        if (!operator()(data[i])) {
            this->data[n++] = data[i];
        }
    }
}

template <typename T>
Set<T>::Set(const Set<T>& set) {
    this->size = set.size;
    this->n = set.n;
    this->data = new T[size];
    for (int i = 0; i < n; i++) {
        this->data[i] = set.data[i];
    }
}

template <typename T>
Set<T>::~Set() {
    delete[] data;
}

template <typename T>
bool Set<T>::operator+(const T& x) {
    if (n >= size) return false;
    if (operator()(x)) return false;
    data[n++] = x;
    return true;
}

template <typename T>
bool Set<T>::operator-(const T& y) {
    if (n == 0) return false;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (data[i] == y) {
            index = i;
            break;
        }
    }
    if (index == -1) return false;
    for (int i = index; i < n - 1; i++) {
        data[i] = data[i + 1];
    }
    n--;
    return true;
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& set) {
    if (this == &set) return *this;
    delete[] data;
    this->size = set.size;
    this->n = set.n;
    this->data = new T[size];
    for (int i = 0; i < n; i++) {
        this->data[i] = set.data[i];
    }
    return *this;
}

template <typename T>
Set<T> Set<T>::operator*(const Set<T>& set) {
    Set<T> intersection(min(this->n, set.n));
    for (int i = 0; i < this->n; i++) {
        if (set.operator()(this->data[i])) {
            intersection + this->data[i];
        }
    }
    return intersection;
}

template <typename T>
Set<T> Set<T>::operator+(const Set<T>& set) {
    Set<T> unionSet(this->n + set.n);
    for (int i = 0; i < this->n; i++) {
        unionSet + this->data[i];
    }
    for (int i = 0; i < set.n; i++) {
        unionSet + set.data[i];
    }
    return unionSet;
}

template <typename T>
Set<T> Set<T>::operator-(const Set<T>& set) {
    Set<T> difference(this->n);
    for (int i = 0; i < this->n; i++) {
        if (!set.operator()(this->data[i])) {
            difference + this->data[i];
        }
    }
    return difference;
}

template <typename T>
bool Set<T>::operator()(const T& x) const {
    for (int i = 0; i < n; i++) {
        if (data[i] == x) return true;
    }
    return false;
}

template <typename T>
T Set<T>::operator[](int i) {
    if (i >= 0 && i < n) return data[i];
    return T();
}

template <typename T>
ostream& operator<<(ostream& out, const Set<T>& set) {
    for (int i = 0; i < set.n; i++) {
        out << set.data[i] << " ";
    }
    return out;
}

#endif
