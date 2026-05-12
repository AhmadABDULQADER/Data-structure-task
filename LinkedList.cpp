#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = NULL;
}

LinkedList::~LinkedList() {
    node* current = head;
    while (current != NULL) {
        node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::insertAtEnd(int value){

    node *new_node, *last;
    new_node = new node;
    new_node->data = value;

    if(head == NULL){
        head = new_node;
        new_node->next = NULL;
    }
    


    else{

        last = head;

        while(last-> next != NULL){
            last = last->next;
        }

        last->next = new_node;
        new_node->next = NULL;

    }

}

void LinkedList::insertAtHead(int value){
    node* new_node;
    new_node = new node;

    new_node->data = value;

    new_node->next = head; 

    head = new_node;


}

void LinkedList::deleteValue(int value){
    if (head == NULL) return;  // empty list — nothing to delete

    node *current, *previous;
    current = head;
    previous = head;

    if (current->data == value){
        head = current->next;
        delete(current);
        return;
    }

    while(current != NULL && current->data != value){
        previous = current;
        current = current->next;
    }

    if (current == NULL) return;  // value not found in list

    previous->next = current->next;
    delete(current);
}

void LinkedList::display(){

    node* current;

    if(head == NULL){
        cout << "Linked list is empty";
    }

    else{

        current = head;

        while(current != NULL){
            cout << current->data << "\t";
            current = current->next;
        }
    }
}
