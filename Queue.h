#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

// =============================================
// Queue using Circular Array
// =============================================
class QueueArray {
private:
    int* arr;       // dynamic array to hold queue elements
    int front;      // index of the front element
    int rear;       // index of the last element
    int size;       // current number of elements
    int capacity;   // maximum number of elements

public:
    QueueArray(int capacity = 10);
    ~QueueArray();

    void enqueue(int value);  // add to rear
    int  dequeue();           // remove from front
    int  peek();              // view front without removing
    bool isFull();
    bool isEmpty();
    void display();
};

// =============================================
// Queue using Linked List
// =============================================
class QueueLL {
private:
    node* front;   // pointer to first node  (dequeue end)
    node* rear;    // pointer to last node   (enqueue end)

public:
    QueueLL();
    ~QueueLL();

    void enqueue(int value);
    int  dequeue();
    int  peek();
    bool isFull();
    bool isEmpty();
    void display();
};

#endif
