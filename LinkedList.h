#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
private:
    node* head;

public:
    LinkedList();
    ~LinkedList();
    void insertAtEnd(int value);
    void insertAtHead(int value);
    void deleteValue(int value);
    void display();
};

#endif
