#ifndef Stack_H
#define Stack_H

class Stack{
private:
    int capacity;
    int * data;
    int top;
public:
    Stack(int size = 1);
    ~Stack();
    bool push(int value);
    bool pop(int &value);
    bool isFull() const;
    bool isEmpty() const;
    int getTop() const;
};
#endif