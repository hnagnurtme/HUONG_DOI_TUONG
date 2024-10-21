#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <iostream>
#include <initializer_list>
#include <stdexcept>

using namespace std;

template <typename DataType>
class Vector {

private:
    void resize();

    DataType* data;
    long size;
    long capacity;
public:
    Vector(long capacity = 10);
    Vector(const Vector &vector);
    Vector(initializer_list<DataType> list);
    Vector<DataType>& operator=(const Vector &other);

    DataType& operator[](int position);
    const DataType& operator[](int position) const;

    ~Vector();

    long getSize() const;
    long getCapacity() const;

    bool isEmpty() const;
    bool isFull() const;

    void pushback(const DataType& value);
    void pushfront(const DataType& value);
    void popback();
    void popfront();
    void remove(int position);

};

template <typename DataType>
Vector<DataType>::Vector(long capacity) : capacity(capacity), size(0) {
    data = new DataType[capacity];
}

template <typename DataType>
Vector<DataType>::Vector(const Vector &vector) : capacity(vector.capacity), size(vector.size) {
    data = new DataType[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = vector.data[i];
    }
}

template <typename DataType>
Vector<DataType>::Vector(std::initializer_list<DataType> list) : capacity(list.size()), size(list.size()) {
    data = new DataType[capacity];
    int i = 0;
    for (const auto& item : list) {
        data[i++] = item;
    }
}

template <typename DataType>
Vector<DataType>& Vector<DataType>::operator=(const Vector &other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        size = other.size;
        data = new DataType[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename DataType>
DataType& Vector<DataType>::operator[](int position) {
    if (position < 0 || position >= size) {
        throw out_of_range("Index out of bounds");
    }
    return data[position];
}

template <typename DataType>
const DataType& Vector<DataType>::operator[](int position) const {
    if (position < 0 || position >= size) {
        throw out_of_range("Index out of bounds");
    }
    return data[position];
}

template <typename DataType>
Vector<DataType>::~Vector() {
    delete[] data;
}

template <typename DataType>
long Vector<DataType>::getSize() const {
    return size;
}

template <typename DataType>
long Vector<DataType>::getCapacity() const {
    return capacity;
}

template <typename DataType>
bool Vector<DataType>::isEmpty() const {
    return size == 0;
}

template <typename DataType>
bool Vector<DataType>::isFull() const {
    return size == capacity;
}

template <typename DataType>
void Vector<DataType>::pushback(const DataType& value) {
    if (isFull()) {
        resize();
    }
    data[size++] = value;
}

template <typename DataType>
void Vector<DataType>::pushfront(const DataType& value) {
    if (isFull()) {
        resize();
    }
    for (int i = size; i > 0; i--) {
        data[i] = data[i - 1];
    }
    data[0] = value;
    size++;
}

template <typename DataType>
void Vector<DataType>::popback() {
    if (!isEmpty()) {
        size--;
    }
}

template <typename DataType>
void Vector<DataType>::popfront() {
    if (!isEmpty()) {
        for (int i = 0; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }
}

template <typename DataType>
void Vector<DataType>::remove(int position) {
    if (position < 0 || position >= size) {
        throw out_of_range("Index out of bounds");
    }
    for (int i = position; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
}

template <typename DataType>
void Vector<DataType>::resize() {
    capacity *= 2;
    DataType* newData = new DataType[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

#endif // DATASTRUCTURES_H
