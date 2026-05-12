#include "Stack.h"
#include <iostream>
using namespace std;

// ── StackLL (Linked-List) ─────────────────────────────────────────────────────

StackLL::StackLL() {
    top = NULL;
}

StackLL::~StackLL() {
    while (top != NULL) {
        node* temp = top;
        top = top->next;
        delete temp;
    }
}

void StackLL::push(int value){

    node* new_node;
    new_node = new node;

    new_node->data = value;

    new_node->next = top; 

    top = new_node;


}

int StackLL::pop(){
    int value;

    if(top == NULL){
        cout << "stack underflow.  \n" ;
        return -1;
    }

    else{
        node* first_node = top;
        top = first_node->next;
        value = first_node->data;
        delete(first_node);
        return value;

    }

}

int StackLL::peek(){

    if(top == NULL){
        cout << "stack underflow.  \n" ;
        return -1;
    }
    else{
        return top->data;
    }


}

bool StackLL::isEmpty(){
    return top == NULL;
}


// ── StackArray (Dynamic Array) ────────────────────────────────────────────────

// Constructor: allocate the initial array on the heap
StackArray::StackArray(int initialCapacity) {
    capacity = initialCapacity;
    arr      = new int[capacity];
    topIndex = -1;             // -1 means the stack is empty
}

// Destructor: every `new` must have a matching `delete`
StackArray::~StackArray() {
    delete[] arr;
}

// Double the capacity when the stack is full
void StackArray::resize() {
    int newCapacity = capacity * 2;
    int* newArr     = new int[newCapacity];   // allocate larger array

    // Copy existing elements to the new array
    for (int i = 0; i <= topIndex; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;          // free the old array
    arr      = newArr;
    capacity = newCapacity;

    cout << "Stack grew to capacity " << capacity << ".\n";
}

// push: add value on top; print overflow message then resize automatically
void StackArray::push(int value) {
    if (isFull()) {
        // Stack Overflow — capacity reached, growing the array
        cout << "Stack Overflow! Resizing from " << capacity << " to " << capacity * 2 << ".\n";
        resize();
    }

    topIndex++;
    arr[topIndex] = value;
}

// pop: remove and return the top value
int StackArray::pop() {
    if (isEmpty()) {
        cout << "Stack underflow.\n";
        return -1;
    }

    int value = arr[topIndex];
    topIndex--;
    return value;
}

// peek: return top value without removing it
int StackArray::peek() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        return -1;
    }

    return arr[topIndex];
}

bool StackArray::isEmpty() {
    return topIndex == -1;
}

// isFull: true when the array has no more room (before a resize)
bool StackArray::isFull() {
    return topIndex == capacity - 1;
}
