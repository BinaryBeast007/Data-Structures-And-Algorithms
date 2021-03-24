#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = NULL;
    }
};

class SinglyLinkedList {
public: 
    Node* head;
    SinglyLinkedList() {
        head = NULL;
    }
    // list operations
    void push_back(int);
    void push_front(int);
    void pop_back();
    void pop_front();
    void insert(int, int);
    int size();
    void erase(int);
    void reverse();
    void print_list();
};
void SinglyLinkedList::push_front(int data) {
    // Time complexity of push_front is O(1)
    // allocate Node
    Node* newNode = new Node();
    // assign data
    newNode->data = data;
    // assign next of new node as head
    newNode->next = head;
    // move the head to point to the new node
    head = newNode;
}
void SinglyLinkedList::push_back(int data) {
    // Time complexity of push_front is O(N)
    // allocate Node
    Node* newNode = new Node();
    // assign data
    newNode->data = data;
    // as it is the last Node, make next as NULL
    // not necessary cause we have made it NULL in Node constructor
    newNode->next = NULL;
    // If the Linked List is empty,  
    // then make the new node as head
    if(head == NULL) {
        head = newNode;
        return;
    }
    // else traverse till the last node
    Node* last = head;
    while(last->next != NULL) {
        last = last->next;
    }
    // Change the next of last node  
    last->next = newNode;
}
void SinglyLinkedList::insert(int pos, int data) {
    // Time complexity of insert is O(N)
    // insert at the beginning
    if(pos == 1) {
        push_front(data);
        return;
    }else if(pos == size()+1) { // insert at the end/tail
        push_back(data);
        return;
    }else if(pos > size()+1 || pos < 1) {  // returning if position is not valid
        cout << "invalid position to insert\n";
        return;
    }
    // traverse till pos-2
    Node* temp = head;
    for(int i=1; i<pos-1; i++) {
        temp = temp->next;
    }
    // temp will now point to pos-1 th node
    // allocate Node
    Node* newNode = new Node();
    // assign data
    newNode->data = data;
    // make newNode's next point to the next Node
    newNode->next = temp->next;
    // make link with previous Node & newNode
    temp->next = newNode;
}
int SinglyLinkedList::size() {
    // Time complexity of size is O(N)
    int listSize = 0;
    Node* temp = head;
    while(temp != NULL) {
        listSize++;
        temp = temp->next;
    }
    // returning the linked list size
    return listSize;
}
void SinglyLinkedList::erase(int pos) {
    // Time complexity of erase is O(N)
    // validating position
    if(pos < 1 || pos > size()) {
        cout << "invalid node position to delete\n";
        return;
    }
    Node* temp = head;
    // deleting the 1st node
    // pointing head to 2nd Node & release memory of 1st node
    if(pos == 1) {
        head = temp->next;
        delete temp;
        return;
    }
    // going to pos-2 node
    for(int i=1; i<pos-1; i++) {
        temp = temp->next;
    }
    // temp will now point to pos-1 th node
    // pointing to the node to be delete
    Node* nodeToDelete = temp->next;
    // connecting pos-1 node to pos+1 node
    temp->next = nodeToDelete->next;
    // deleting pos node
    delete nodeToDelete; 
}
void SinglyLinkedList::pop_front() {
    // Time complexity of pop_front is O(1)
    // checking if list is empty
    if(head == NULL) {
        cout << "error : can not pop from empty list\n";
        return;
    }
    // pointing to head node
    Node* temp = head;
    // changing the head node to next node
    head = temp->next;
    // deleting previous head node
    delete temp;
}
void SinglyLinkedList::pop_back() {
    // Time complexity of push_back is O(N)
    // checking if list is empty
    if(head == NULL) {
        cout << "error : can not pop from empty list\n";
        return;
    }
    Node* current = head, *prev = NULL;
    // traverse till last element
    while(current->next != NULL) {
        prev = current; // storing the 2nd last node
        current = current->next;
    }
    prev->next = NULL;  // setting null to 2nd last node to make it last
    delete current; // deleting last node
}
void SinglyLinkedList::reverse() {
    // Time complexity of reverse is O(N)
    Node *current, *prev, *next;
    current = head;
    prev = NULL;    // setting prev to NULL

    while(current != NULL) {
        next = current->next;   // storing the next
        current->next = prev;   // current node will point to the previous node
        prev = current; // prev will point to current 
        current = next; // restoring current to point to next for iterations
    }
    head = prev;    // setting head
}
void SinglyLinkedList::print_list() {
    // Time complexity of print_list is O(N)
    Node* temp = head;
    while(temp != NULL) {
        // while temp != NULL print data & move to next
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// Driver code
int main() {
    SinglyLinkedList* ls = new SinglyLinkedList();
    ls->push_back(121);
    ls->push_front(43);
    ls->insert(2, 67);
    cout << "size : " << ls->size() << "\n";
    ls->print_list();
    ls->reverse();
    ls->print_list();
    ls->pop_back();
    ls->print_list();
    ls->pop_front();
    ls->print_list();
    cout << "size : " << ls->size() << "\n";

    return 0;
}
