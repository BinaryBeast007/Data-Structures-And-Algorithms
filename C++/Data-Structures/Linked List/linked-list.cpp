#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    // Linkedlist operations
    LinkedList();
    Node* get_new_node(const int&);
    void push_back(const int&);
    void push_front(const int&);
    void pop_back();
    void pop_front();
    void insert(const int&, const int&);
    int size();
    void erase(const int&);
    void erase_data(const int&);
    bool search(const int&);
    void reverse();
    void print_list();
};
LinkedList::LinkedList() {
    head = NULL;
}
Node* LinkedList::get_new_node(const int& data) {
    // create a new node
    Node* newNode = new Node();
    // assign data to new node
    newNode->data = data;
    // set next as NULL
    newNode->next = NULL;
    // return the new node
    return newNode;
}
void LinkedList::push_back(const int &data) {
    // Time complexity of push_back is O(N)
    // get a new node with data
    Node* newNode = get_new_node(data);
    // if the list is empty then head will be the new node
    if(head == NULL) {
        head = newNode;
        return;
    }
    // if the list is not empty then traverse till the last node
    Node* temp = head;
    while(temp->next != NULL) {
        temp= temp->next;
    }
    // point the next field of last node to new node
    // now the new node becomes the last node
    temp->next = newNode;
}
void LinkedList::push_front(const int &data) {
    // Time complexity of push_front is O(1)
    Node* newNode = get_new_node(data);
    newNode->next = head;
    head = newNode;
}
void LinkedList::pop_back() {
    // Time complexity of pop_back is O(N)
    // checking if list is empty
    if(head == NULL) {
        cout << "error : can not delete from empty list\n";
        return;
    }
    Node* current = head, *prev = NULL;
    // traverse till last element
    while(current->next != NULL) {
        prev = current; // will store the 2nd last node
        current = current->next;
    }
    prev->next = NULL;  // making the 2nd last node as last node
    delete current; // deleting last node
}
void LinkedList::pop_front() {
    // Time complexity of pop_front is O(1)
    // checking if the list is empty
    if(head == NULL) {
        cout << "error : can not delete from empty list\n";
        return;
    }
    // temporarily storing the head node
    Node* temp = head;
    // changing the head node to next node
    head = head->next;
    // deleting previous head node
    delete temp;
}
void LinkedList::insert(const int& pos, const int& data) {
    // Time complexity of insert is O(N)
    int list_size = size(); 
    // validating position
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
    temp->next = newNode;
}
int LinkedList::size() {
    // Time complexity of size is O(N)
    int list_size = 0;
    Node* temp = head;
    while(temp != NULL) {
        list_size++;
        temp = temp->next;
    }
    return list_size;
}
void LinkedList::erase(const int& pos) {
    // Time complexity of erase is O(N)
    int list_size = size();
    if(pos < 1 || pos > list_size) {
        cout << "error : invalid position\n";
        return;
    }
    if(pos == 1) {
        pop_front();
        return;
    }
    Node* temp = head;
    for(int i=1; i<pos-1; i++) {
        temp = temp->next;
    }
    Node* nodeTobeDelete = temp->next;
    temp->next = nodeTobeDelete->next;
    delete nodeTobeDelete;
}
void LinkedList::erase_data(const int& data) {
    // Time complexity of erase_data is O(N)
    Node* temp = head;
    if(temp->data == data) {
        pop_front();
        return;
    }
    while(temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }
    Node* nodeToBeDelete = temp->next;
    temp->next = nodeToBeDelete->next;
    delete nodeToBeDelete;
}
bool LinkedList::search(const int& data) {
    Node* current = head; // Initialize current
    while (current != NULL) {
        if (current->data == data)
            return true;
        current = current->next;
    }
    return false;
}
void LinkedList::reverse() {
    // Time complexity of reverse is O(N)
    Node* curr = head, *prev = NULL, *next;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
void LinkedList::print_list() {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    LinkedList ls;
    ls.push_back(10);
    ls.push_front(2);
    ls.push_back(87);
    ls.insert(2, 45);
    cout << "size : " << ls.size() << "\n";
    ls.print_list();
    ls.pop_back();
    ls.pop_front();
    ls.print_list();
    ls.push_front(99);
    ls.push_back(37);
    ls.print_list();
    ls.erase(1);
    ls.print_list();
    ls.erase_data(10);
    ls.reverse();
    if(ls.search(37)) {
        cout << "data found\n";
    }else {
        cout << "data not found\n";
    }
    ls.print_list();

    return 0;
}
