#ifndef STACK_H
#define STACK_H

#include "Node.h"

//Stack: Linked-List Implementation  
class StackLL {
private:
    node* top;

public:
    StackLL();
    ~StackLL();
    void push(int value);
    int pop();
    int peek();
    bool isEmpty();
};

// ── Stack: Dynamic-Array Implementation 
class StackArray {
private:
    int* arr;       // pointer to the heap-allocated array
    int  capacity;  // current max size of the array
    int  topIndex;  // index of the top element (-1 when empty)

    // Doubles the array capacity when the stack is full
    void resize();

public:
    StackArray(int initialCapacity = 4);
    ~StackArray();            // frees heap memory

    void push(int value);     // add to top; auto-grows if full
    int  pop();               // remove & return top; prints error on underflow
    int  peek();              // return top without removing; prints error if empty
    bool isEmpty();
    bool isFull();            // true when topIndex == capacity-1 (before resize)
};

#endif
