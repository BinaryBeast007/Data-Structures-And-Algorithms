// generic singly linked list
#include<iostream>
using namespace std;

template<class T> class Node {
public:
    T data;
    Node<T>* next;
    Node() {
        data = 0;
        next = NULL;
    }
};

template<class T> class SinglyLinkedList {
public: 
    Node<T>* head;
    SinglyLinkedList() {
        head = NULL;
    }
    // list operations
    Node<T>* get_new_node(T);
    void push_back(T);
    void push_front(T);
    void pop_back();
    void pop_front();
    void insert(int, T);
    int size();
    void erase(int);
    void reverse();
    void print_list();
};

template<class T> Node<T>* SinglyLinkedList<T>::get_new_node(T data) {
    // allocate Node
    Node<T>* newNode = new Node<T>();
    // assign data
    newNode->data = data;
    // returning node
    return newNode;
}
template<class T> void SinglyLinkedList<T>::push_front(T data) {
    // Time complexity of push_front is O(1)
    // getting a new Node
    Node<T>* newNode = get_new_node(data);
    // assign next of new node as head
    newNode->next = head;
    // move the head to point to the new node
    head = newNode;
}
template<class T> void SinglyLinkedList<T>::push_back(T data) {
    // Time complexity of push_front is O(N)
    // getting a new Node
    Node<T>* newNode = get_new_node(data);
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
    Node<T>* last = head;
    while(last->next != NULL) {
        last = last->next;
    }
    // Change the next of last node  
    last->next = newNode;
}
template<class T> void SinglyLinkedList<T>::insert(int pos, T data) {
    // Time complexity of insert is O(N)
    // insert at the beginning
    if(pos == 1) {
        push_front(data);
        return;
    }else if(pos == size()+1) { // insert at the end/tail
        push_back(data);
        return;
    }else if(pos > size()+1 || pos < 1) {  // returning if position is not valid
        cout << "error : invalid position to insert\n";
        return;
    }
    // traverse till pos-2
    Node<T>* temp = head;
    for(int i=1; i<pos-1; i++) {
        temp = temp->next;
    }
    // temp will now point to pos-1 th node
    // getting a new Node
    Node<T>* newNode = get_new_node(data);
    // make newNode's next point to the next Node
    newNode->next = temp->next;
    // make link with previous Node & newNode
    temp->next = newNode;
}
template<class T> int SinglyLinkedList<T>::size() {
    // Time complexity of size is O(N)
    int listSize = 0;
    Node<T>* temp = head;
    while(temp != NULL) {
        listSize++;
        temp = temp->next;
    }
    // returning the linked list size
    return listSize;
}
template<class T> void SinglyLinkedList<T>::erase(int pos) {
    // Time complexity of erase is O(N)
    // validating position
    if(pos < 1 || pos > size()) {
        cout << "error : invalid node position to delete\n";
        return;
    }
    Node<T>* temp = head;
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
    Node<T>* nodeToDelete = temp->next;
    // connecting pos-1 node to pos+1 node
    temp->next = nodeToDelete->next;
    // deleting pos node
    delete nodeToDelete; 
}
template<class T> void SinglyLinkedList<T>::pop_front() {
    // Time complexity of pop_front is O(1)
    // checking if list is empty
    if(head == NULL) {
        cout << "error : can not pop from empty list\n";
        return;
    }
    // pointing to head node
    Node<T>* temp = head;
    // changing the head node to next node
    head = temp->next;
    // deleting previous head node
    delete temp;
}
template<class T> void SinglyLinkedList<T>::pop_back() {
    // Time complexity of push_back is O(N)
    // checking if list is empty
    if(head == NULL) {
        cout << "error : can not pop from empty list\n";
        return;
    }
    Node<T>* current = head, *prev = NULL;
    // traverse till last element
    while(current->next != NULL) {
        prev = current; // storing the 2nd last node
        current = current->next;
    }
    prev->next = NULL;  // setting null to 2nd last node to make it last
    delete current; // deleting last node
}
template<class T> void SinglyLinkedList<T>::reverse() {
    // Time complexity of reverse is O(N)
    Node<T> *current, *prev, *next;
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
template<class T> void SinglyLinkedList<T>::print_list() {
    // Time complexity of print_list is O(N)
    Node<T>* temp = head;
    while(temp != NULL) {
        // while temp != NULL print data & move to next
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// Driver code
int main() {
    SinglyLinkedList<int>* ls = new SinglyLinkedList<int>();
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
