#pragma once
#include <initializer_list>
#include <stdexcept>

using namespace std;

template <typename DataType>
class Node {
public:
    DataType data;
    Node* next;
    Node* prev;
    Node(const DataType& value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename DataType>
class Vector {
private:
    Node<DataType>* head;
    Node<DataType>* tail;
    long size;

public:
    Vector();
    Vector(const Vector &vector);
    Vector(std::initializer_list<DataType> list);
    Vector<DataType>& operator=(const Vector &other);
    DataType& operator[](int position);
    const DataType& operator[](int position) const;
    Node<DataType>* operator()(const DataType& value);
    void deleteElement(const DataType& value);
    ~Vector();
    long getSize() const;
    bool isEmpty() const;
    void pushback(const DataType& value);
    void pushfront(const DataType& value);
    void popback();
    void popfront();
    void remove(int position);
};

template <typename DataType>
Vector<DataType>::Vector() : head(nullptr), tail(nullptr), size(0) {}

template <typename DataType>
Vector<DataType>::Vector(const Vector &vector) : head(nullptr), tail(nullptr), size(0) {
    Node<DataType>* current = vector.head;
    while (current) {
        pushback(current->data);
        current = current->next;
    }
}

template <typename DataType>
Vector<DataType>::Vector(std::initializer_list<DataType> list) : head(nullptr), tail(nullptr), size(0) {
    for (const auto& item : list) {
        pushback(item);
    }
}

template <typename DataType>
Vector<DataType>& Vector<DataType>::operator=(const Vector &other) {
    if (this != &other) {
        while (!isEmpty()) {
            popback();
        }
        Node<DataType>* current = other.head;
        while (current) {
            pushback(current->data);
            current = current->next;
        }
    }
    return *this;
}

template <typename DataType>
DataType& Vector<DataType>::operator[](int position) {
    if (position < 0 || position >= size) {
        throw out_of_range("Index out of bounds");
    }
    Node<DataType>* current = head;
    for (int i = 0; i < position; ++i) {
        current = current->next;
    }
    return current->data;
}

template <typename DataType>
const DataType& Vector<DataType>::operator[](int position) const {
    if (position < 0 || position >= size) {
        throw out_of_range("Index out of bounds");
    }
    Node<DataType>* current = head;
    for (int i = 0; i < position; ++i) {
        current = current->next;
    }
    return current->data;
}

template <typename DataType>
Node<DataType>* Vector<DataType>::operator()(const DataType& value) {
    Node<DataType>* current = head;
    while (current) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template <typename DataType>
void Vector<DataType>::deleteElement(const DataType& value) {
    if (isEmpty()) {
        return;
    }
    if (head->data == value) {
        popfront();
        return;
    }
    Node<DataType>* current = head;
    while (current->next) {
        if (current->next->data == value) {
            Node<DataType>* temp = current->next;
            current->next = current->next->next;
            if (current->next) {
                current->next->prev = current;
            } else {
                tail = current;
            }
            delete temp;
            size--;
            return;
        }
        current = current->next;
    }
}

template <typename DataType>
Vector<DataType>::~Vector() {
    while (!isEmpty()) {
        popback();
    }
}

template <typename DataType>
long Vector<DataType>::getSize() const {
    return size;
}

template <typename DataType>
bool Vector<DataType>::isEmpty() const {
    return size == 0;
}

template <typename DataType>
void Vector<DataType>::pushback(const DataType& value) {
    Node<DataType>* newNode = new Node<DataType>(value);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

template <typename DataType>
void Vector<DataType>::pushfront(const DataType& value) {
    Node<DataType>* newNode = new Node<DataType>(value);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template <typename DataType>
void Vector<DataType>::popback() {
    if (isEmpty()) {
        return;
    }
    if (size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node<DataType>* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    size--;
}

template <typename DataType>
void Vector<DataType>::popfront() {
    if (isEmpty()) {
        return;
    }
    Node<DataType>* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
    size--;
}

template <typename DataType>
void Vector<DataType>::remove(int position) {
    if (position < 0 || position >= size) {
        throw out_of_range("Index out of bounds");
    }
    if (position == 0) {
        popfront();
    } else if (position == size - 1) {
        popback();
    } else {
        Node<DataType>* current = head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }
        Node<DataType>* temp = current;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete temp;
        size--;
    }
}
