#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

LinkedList::LinkedList(const LinkedList &linkedlist) {
    if (linkedlist.head == nullptr) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = new Node(linkedlist.head->data);
        Node *current = head;
        Node *temp = linkedlist.head->next;

        while (temp != nullptr) {
            current->next = new Node(temp->data);
            current = current->next;
            temp = temp->next;
        }
        tail = current; 
    }
}

LinkedList::~LinkedList() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
}

bool LinkedList::Add_Front(int x) {
    Node *newnode = new Node(x);
    if (newnode == nullptr) return false; 
    if (head == nullptr) {
        head = tail = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
    return true;
}

bool LinkedList::Add_End(int x) {
    Node *newnode = new Node(x);
    if (newnode == nullptr) return false; 
    if (head == nullptr) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
    return true;
}

bool LinkedList::Add_After_Position(int pos, int x) {
    if (pos < 0) return false;
    Node *current = head;
    int count = 0;
    while (current != nullptr && count < pos) {
        count++;
        current = current->next;
    }

    if (current == nullptr) return false;

    Node *newnode = new Node(x);
    if (newnode == nullptr) return false; 
    newnode->next = current->next;
    current->next = newnode;
    if (newnode->next == nullptr) tail = newnode;
    return true;
}

bool LinkedList::Delete_Front(int &x) {
    if (head == nullptr) {
        return false;
    }
    Node *temp = head;
    x = head->data;
    head = head->next;
    if (head == nullptr) tail = nullptr; 
    delete temp;
    return true;
}

bool LinkedList::Delete_End(int &x) {
    if (head == nullptr) return false;
    if (head == tail) {
        return Delete_Front(x);
    }

    Node *current = head;
    while (current->next != tail) {
        current = current->next;
    }
    x = tail->data;
    delete tail;
    tail = current;
    tail->next = nullptr;
    return true; 
}

bool LinkedList::Delete_In_Position(int pos, int &x) {
    if (pos < 0 || head == nullptr) return false; 

    Node *current = head;
    int count = 0;
    while (current != nullptr && count < pos - 1) {
        current = current->next;
        count++;
    }
    if (current == nullptr || current->next == nullptr) return false;

    Node *temp = current->next;
    x = temp->data;
    current->next = temp->next;
    if (temp == tail) tail = current;
    delete temp;
    return true;
}

bool LinkedList::Add_After_Value(int value_add, int x) {
    Node *current = head;
    while (current != nullptr && current->data != value_add) {
        current = current->next;
    }
    if (current == nullptr) return false;  
    Node *newNode = new Node(x);
    if (newNode == nullptr) return false;
    newNode->next = current->next;
    current->next = newNode;
    if (newNode->next == nullptr) tail = newNode;  
    return true;
}

bool LinkedList::Delete_With_Value(int x) {
    if (head == nullptr) return false;
    if (head->data == x) {
        return Delete_Front(x);
    }
    Node *current = head;
    while (current->next != nullptr && current->next->data != x) {
        current = current->next;
    }
    if (current->next == nullptr) return false;  
    Node *temp = current->next;
    current->next = temp->next;
    if (temp == tail) tail = current;
    delete temp;
    return true;
}

ostream& operator << (ostream &out, const LinkedList &linkedlist) {
    Node *current = linkedlist.head;
    while (current != nullptr) {
        out << current->data << " ";
        current = current->next;
    }
    return out;
}

bool Sorting(LinkedList &linkedlist, bool (*ComFunction)(int, int)) {
    if (linkedlist.head == nullptr || linkedlist.head->next == nullptr) {
        return false;  
    }

    if (ComFunction == nullptr) {
        ComFunction = Increase; 
    }

    Node *sorted = nullptr;  
    Node *current = linkedlist.head;  
    while (current != nullptr) {
        Node *next = current->next;

        if (sorted == nullptr || ComFunction(sorted->data, current->data)) {
            current->next = sorted;
            sorted = current;
        } else {
            Node *sortedCurrent = sorted;
            while (sortedCurrent->next != nullptr && !ComFunction(sortedCurrent->next->data, current->data)) {
                sortedCurrent = sortedCurrent->next;
            }
            current->next = sortedCurrent->next;
            sortedCurrent->next = current;
        }
        current = next;
    }

    linkedlist.head = sorted;


    if (sorted == nullptr) {
        linkedlist.tail = nullptr;
    } else {
        linkedlist.tail = sorted;
        while (linkedlist.tail->next != nullptr) {
            linkedlist.tail = linkedlist.tail->next;
        }
    }

    return true;
}


bool Increase(int a, int b) {
    return a > b;
}

bool Decrease(int a, int b) {
    return a < b;
}