#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(int capacity)
{
    this->capacity = capacity;
    this->top = -1;
    this->data = new int[capacity];
}
Stack::~Stack()
{
    delete[] data;
}
bool Stack::push(int value)
{
    if (isFull())
        return false;
    data[++top] = value;
    return true;
}
bool Stack::pop(int &value)
{
    if (isEmpty())
        return false;
    value = data[top--];
    return true;
}
bool Stack::isFull() const
{
    return top == capacity - 1;
}
bool Stack::isEmpty() const
{
    return top == -1;
}
int Stack::getTop() const
{
    return data[top];
}