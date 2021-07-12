#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList();
    Node* get_new_node(const int&);
    void push_back(const int&);
    void push_front(const int&);
    void pop_back();
    void pop_front();
    void insert(const int&, const int&);
    int size();
    void erase(const int&);
    void erase_data(const int&);
    void reverse_print();
    void print_list();
};
DoublyLinkedList::DoublyLinkedList() {
    head = NULL;
}
Node* DoublyLinkedList::get_new_node(const int& data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void DoublyLinkedList::push_front(const int& data) {
    Node* newNode = get_new_node(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void DoublyLinkedList::push_back(const int& data) {
    Node* newNode = get_new_node(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
}
void DoublyLinkedList::pop_back() {
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    // if there is only one element present in the list 
    if(temp->prev == NULL) {
        delete temp;
        head = NULL;
        return;
    }
    temp->prev->next = NULL;
    delete temp;
}
void DoublyLinkedList::pop_front() {
    if(head == NULL) {
        cout << "error : can not delete from empty list\n";
        return;
    }
    Node* temp = head;
    // if there is only one element present in the list 
    if(temp->next == NULL) {
        delete temp;
        head = NULL;
        return;
    }
    head = head->next;
    head->prev = NULL;
    delete temp;
}
int DoublyLinkedList::size() {
    int list_size = 0;
    Node* temp = head;
    while(temp != NULL) {
        list_size++;
        temp = temp->next;
    }
    return list_size;
}
void DoublyLinkedList::insert(const int& pos, const int& data) {
    int list_size = size(); 
    // validating positionerase_data
    if(pos < 1 || pos > list_size+1) {
        cout << "error : invalid position\n";
        return;
    }
    if(pos == 1) {
        push_front(data);
        return;
    }
    if(pos == list_size+1) {
        push_back(data);
        return;
    }
    // traverse till pos - 1 
    Node* temp = head;
    for(int i=1; i<pos-1; i++) {
        temp = temp->next;
    }
    Node* newNode = get_new_node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
void DoublyLinkedList::erase(const int& pos) {
    int list_size = size();
    if(pos < 1 || pos > list_size) {
        cout << "error : invalid position\n";
        return;
    }
    if(pos == 1) {
        pop_front();
        return;
    }
    if(pos == list_size) {
        pop_back();
        return;
    }
    Node* temp = head;
    for(int i=1; i<pos; i++) {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}
void DoublyLinkedList::erase_data(const int& data) {
    Node* temp = head;
    if(head->data == data) {
        pop_front();
        return;
    }
    while(temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    // data not found
    if(temp == NULL) {
        return;
    }
    if(temp->next == NULL) {
        pop_back();
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}
void DoublyLinkedList::reverse_print() {
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << "\n";
}
void DoublyLinkedList::print_list() {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    DoublyLinkedList ls;
    ls.push_back(5);
    ls.push_front(3);
    ls.pop_back();
    ls.pop_front();
    ls.insert(1, 1);
    ls.insert(2, 1);
    ls.insert(2, 22);
    ls.insert(3, 322);
    ls.print_list();
    ls.erase(1);
    ls.erase(2);
    ls.erase_data(6);
    ls.print_list();
    ls.reverse_print();
    
    return 0;
}
