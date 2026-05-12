#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;

int main() {

    // =============================================
    // 1. Singly Linked List
    // =============================================
    cout << "===== Testing Linked List =====\n";
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtHead(5);
    cout << "List after inserting 10, 20 at end and 5 at head:\n";
    list.display();          // expected: 5  10  20
    cout << "\n";
    list.deleteValue(10);
    cout << "List after deleting 10:\n";
    list.display();          // expected: 5  20
    cout << "\n\n";

    // =============================================
    // 2. Stack – Linked List
    // =============================================
    cout << "===== Testing Stack (Linked List) =====\n";
    StackLL stackLL;
    stackLL.push(100);
    stackLL.push(200);
    stackLL.push(300);
    cout << "Top element:    " << stackLL.peek() << "\n";   // 300
    cout << "Popped element: " << stackLL.pop()  << "\n";   // 300
    cout << "New top:        " << stackLL.peek() << "\n";   // 200
    cout << "\n";

    // =============================================
    // 3. Stack – Dynamic Array
    // =============================================
    cout << "===== Testing Stack (Dynamic Array) =====\n";
    StackArray stackArr;
    stackArr.push(10);
    stackArr.push(20);
    stackArr.push(30);
    cout << "Top element:    " << stackArr.peek() << "\n";  // 30
    cout << "Popped element: " << stackArr.pop()  << "\n";  // 30
    cout << "New top:        " << stackArr.peek() << "\n";  // 20

    // Test overflow
    StackArray smallStack(2);
    smallStack.push(1);
    smallStack.push(2);
    smallStack.push(3);   // will print Stack Overflow message then resize
    cout << "\n";

    // =============================================
    // 4. Queue – Circular Array
    // =============================================
    cout << "===== Testing Queue (Circular Array) =====\n";
    QueueArray qArr(5);
    qArr.enqueue(10);
    qArr.enqueue(20);
    qArr.enqueue(30);
    cout << "Queue after enqueue 10, 20, 30:\n";
    qArr.display();                                          // 10 20 30
    cout << "Front element:    " << qArr.peek()     << "\n"; // 10
    cout << "Dequeued element: " << qArr.dequeue()  << "\n"; // 10
    cout << "Queue after dequeue:\n";
    qArr.display();                                          // 20 30

    // Test the circular wrap-around: fill the 2 empty slots at the end
    qArr.enqueue(40);
    qArr.enqueue(50);
    // Now rear has wrapped around; dequeue 20 to free a slot
    cout << "After enqueue 40, 50 (full), dequeue one:\n";
    qArr.dequeue();          // removes 20
    qArr.enqueue(60);        // 60 goes into the wrapped slot at index 0
    cout << "Final queue (30 40 50 60):\n";
    qArr.display();
    cout << "\n";

    // =============================================
    // 5. Queue – Linked List
    // =============================================
    cout << "===== Testing Queue (Linked List) =====\n";
    QueueLL qLL;
    qLL.enqueue(1);
    qLL.enqueue(2);
    qLL.enqueue(3);
    cout << "Queue after enqueue 1, 2, 3:\n";
    qLL.display();                                           // 1 2 3
    cout << "Front element:    " << qLL.peek()    << "\n";  // 1
    cout << "Dequeued element: " << qLL.dequeue() << "\n";  // 1
    cout << "Queue after dequeue:\n";
    qLL.display();                                           // 2 3
    cout << "\n";

    return 0;
}
