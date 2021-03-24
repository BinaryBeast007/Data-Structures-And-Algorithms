#include<iostream>
using namespace std;

template<class T> class Node {
public:
    T data;
    Node* next;
    Node() {
        data = 0;
        next = NULL;
    }
};
template<class T> class Queue {
public:
    Node<T>* front, *rear;
    
    Queue();
    void enqueue(T);
    void dequeue();
    bool isEmpty();
    void display();
};

template<class T> Queue<T>::Queue() {
    front = rear = NULL;
}
template<class T> void Queue<T>::enqueue(T data) {
    Node<T>* temp = new Node<T>();
    temp->data = data;
    if(front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}
template<class T> void Queue<T>::dequeue() {
    Node<T>* temp = front;
    if(front == NULL) {
        return;
    }
    if(front == rear) {
        front = rear = NULL;
    }else {
        front = front->next;
    }
    delete temp;
}
template<class T> bool Queue<T>::isEmpty() {
    return (front == NULL && rear == NULL);
}
template<class T> void Queue<T>::display() {
    Node<T>* temp = front;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    } 
    cout << "\n";
}

int main() {
    Queue<double> q;
    q.enqueue(1000.34);
    q.enqueue(98.2326);
    q.enqueue(7.6715451);
    q.dequeue();
    q.dequeue();
    q.isEmpty() ? puts("queue is empty") : puts("queue is not empty"); 
    q.display();

    return 0;
}
