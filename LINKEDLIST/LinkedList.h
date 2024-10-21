#ifndef LinkedList_H
#define LinkedList_H
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next ;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class LinkedList{
private:
    Node *head;
    Node *tail;
public:
    LinkedList();
    LinkedList(const LinkedList &linkedlist);
    ~LinkedList();

    bool Add_Front(int x);
    bool Add_End(int x);
    bool Add_After_Position(int pos,int x);

    bool Delete_Front(int &x);
    bool Delete_End(int &x);
    bool Delete_In_Position(int pos,int &x);

    bool Add_After_Value(int value_add,int x);
    bool Delete_With_Value(int x);

    friend ostream& operator << (ostream &out,const LinkedList &linkedlist); 
    friend bool Sorting(LinkedList &linkedlist, bool (*ComFunction)(int, int));
};
bool Increase(int a, int b);
bool Decrease(int a, int b);
#endif