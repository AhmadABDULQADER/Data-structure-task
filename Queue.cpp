#include "Queue.h"
#include <iostream>
using namespace std;

// =============================================
//  QueueArray  (Circular Array)
// =============================================

QueueArray::QueueArray(int cap) {
    capacity = cap;
    arr   = new int[capacity];   // allocate dynamic array
    front = 0;
    rear  = -1;   // -1 means nothing has been enqueued yet
    size  = 0;
}

QueueArray::~QueueArray() {
    delete[] arr;   // free the dynamic array
}

bool QueueArray::isFull() {
    return size == capacity;
}

bool QueueArray::isEmpty() {
    return size == 0;
}

// Add a value to the rear of the queue.
// Uses the circular trick: (rear + 1) % capacity
// so that rear wraps back to index 0 when it reaches the end,
// reusing slots freed by dequeue().
void QueueArray::enqueue(int value) {
    if (isFull()) {
        cout << "Queue overflow – cannot enqueue " << value << "\n";
        return;
    }
    rear = (rear + 1) % capacity;   // wrap around if needed
    arr[rear] = value;
    size++;
}

// Remove and return the value at the front of the queue.
// Uses the same circular trick for front: (front + 1) % capacity
int QueueArray::dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow – queue is empty\n";
        return -1;
    }
    int value = arr[front];
    front = (front + 1) % capacity;  // wrap around if needed
    size--;
    return value;
}

// Return the front value without removing it.
int QueueArray::peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }
    return arr[front];
}

// Print all elements from front to rear in order.
void QueueArray::display() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }
    // Walk from front, wrapping around, for exactly 'size' steps
    for (int i = 0; i < size; i++) {
        cout << arr[(front + i) % capacity] << "\t";
    }
    cout << "\n";
}


// =============================================
//  QueueLL  (Linked List)
// =============================================

QueueLL::QueueLL() {
    front = NULL;
    rear  = NULL;
}

QueueLL::~QueueLL() {
    // Free every remaining node
    while (front != NULL) {
        node* temp = front;
        front = front->next;
        delete temp;
    }
}

// Enqueue: always add to the rear  (O(1) because we keep a rear pointer)
void QueueLL::enqueue(int value) {
    node* new_node = new node;
    new_node->data = value;
    new_node->next = NULL;

    if (rear == NULL) {
        // Queue was empty – new node is both front and rear
        front = new_node;
        rear  = new_node;
    } else {
        rear->next = new_node;
        rear       = new_node;
    }
}

// Dequeue: always remove from the front  (O(1))
int QueueLL::dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow – queue is empty\n";
        return -1;
    }
    node* temp  = front;
    int   value = temp->data;
    front = front->next;

    if (front == NULL) {
        // Queue became empty – rear must also be reset
        rear = NULL;
    }

    delete temp;
    return value;
}

int QueueLL::peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }
    return front->data;
}

bool QueueLL::isFull() {
    return false; // Linked list queue is never full (unless memory is exhausted)
}

bool QueueLL::isEmpty() {
    return front == NULL;
}

void QueueLL::display() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }
    node* current = front;
    while (current != NULL) {
        cout << current->data << "\t";
        current = current->next;
    }
    cout << "\n";
}
