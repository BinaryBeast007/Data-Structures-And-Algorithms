#include<stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* head;
struct Node* get_new_node(int data) {
    // create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // assign data to new node
    newNode->data = data;
    // set next as NULL
    newNode->next = NULL;
    // return the new node
    return newNode;
}
void push_back(int data) {
    // Time complexity of push_back is O(N)
    // get a new node with data
    struct Node* newNode = get_new_node(data);
    // if the list is empty then head will be the new node
    if(head == NULL) {
        head = newNode;
        return;
    }
    // if the list is not empty then traverse till the last node
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp= temp->next;
    }
    // point the next field of last node to new node
    // now the new node becomes the last node
    temp->next = newNode;
}
void push_front(int data) {
    // Time complexity of push_front is O(1)
    struct Node* newNode = get_new_node(data);
    newNode->next = head;
    head = newNode;
}
void pop_back() {
    // Time complexity of pop_back is O(N)
    // checking if list is empty
    if(head == NULL) {
        printf("error : can not delete from empty list\n");
        return;
    }
    struct Node* current = head, *prev = NULL;
    // traverse till last element
    while(current->next != NULL) {
        prev = current; // will store the 2nd last node
        current = current->next;
    }
    prev->next = NULL;  // making the 2nd last node as last node
    free(current); // deleting last node
}
void pop_front() {
    // Time complexity of pop_front is O(1)
    // checking if the list is empty
    if(head == NULL) {
        printf("error : can not delete from empty list\n");
        return;
    }
    // temporarily storing the head node
    struct Node* temp = head;
    // changing the head node to next node
    head = head->next;
    // deleting previous head node
    free(temp);
}
int size() {
    // Time complexity of size is O(N)
    int list_size = 0;
    struct Node* temp = head;
    while(temp != NULL) {
        list_size++;
        temp = temp->next;
    }
    return list_size;
}
void insert(int pos, int data) {
    // Time complexity of insert is O(N)
    int list_size = size(); 
    // validating position
    if(pos < 1 || pos > list_size+1) {
        printf("error : invalid position\n");
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
    struct Node* temp = head;
    for(int i=1; i<pos-1; i++) {
        temp = temp->next;
    }
    struct Node* newNode = get_new_node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}
void erase(int pos) {
    // Time complexity of erase is O(N)
    int list_size = size();
    if(pos < 1 || pos > list_size) {
        printf("error : invalid position\n");
        return;
    }
    if(pos == 1) {
        pop_front();
        return;
    }
    struct Node* temp = head;
    for(int i=1; i<pos-1; i++) {
        temp = temp->next;
    }
    struct Node* nodeTobeDelete = temp->next;
    temp->next = nodeTobeDelete->next;
    free(nodeTobeDelete);
}
void erase_data(int data) {
    // Time complexity of erase_data is O(N)
    struct Node* temp = head;
    if(temp->data == data) {
        pop_front();
        return;
    }
    while(temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }
    struct Node* nodeToBeDelete = temp->next;
    temp->next = nodeToBeDelete->next;
    free(nodeToBeDelete);
}
void reverse() {
    // Time complexity of reverse is O(N)
    struct Node* curr = head, *prev = NULL, *next;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
void print_list() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    head = NULL;
    push_back(10);
    push_front(9);
    insert(1, 8);
    insert(4, 11);
    insert(2, 44);
    // pop_back();
    // pop_front();
    printf("size : %d\n", size());
    print_list();
    // erase_data(9);
    // erase(1);
    print_list();
    reverse();
    print_list();

    return 0;
}
