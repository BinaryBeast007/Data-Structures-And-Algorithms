#include<iostream>
using namespace std;

#define MAX_SIZE 100

template<class T> class Queue {
    int front, rear, capacity;
    T arr[MAX_SIZE];
public:
    Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(T);
    T dequeue();
    int size();
    void display();
    T Front();
};

template<class T> Queue<T>::Queue() {
    front = rear = -1;
    capacity = 0;
}
template<class T> bool Queue<T>::isEmpty() {
    return (front == -1 && rear == -1);
}
template<class T> bool Queue<T>::isFull() {
    return ((rear+1)%MAX_SIZE == front);
}
template<class T> void Queue<T>::enqueue(T data) {
    if(isFull()) {
        cout << "queue is full\n";
        return;
    }else if(isEmpty()) {
        front = rear = 0;
    }else {
        rear = (rear + 1)%MAX_SIZE;
    }
    arr[rear] = data;
}
template<class T> T Queue<T>::dequeue() {
    if(isEmpty()) {
        cout << "error : can not dequeue from empty queue\n";
        exit(0);
    }else if(front == rear) {
        T data = arr[front];
        front = rear = -1;
        return data;
    }else {
        T data = arr[front];
        front = (front + 1)%MAX_SIZE;
        return data;
    }
}
template<class T> int Queue<T>::size() {
    int size = (rear+MAX_SIZE-front)%MAX_SIZE+1;
    return isEmpty() ? 0 : size;
}
template<class T> T Queue<T>::Front() {
    if(isEmpty()) {
        cout << "Error: cannot return front from empty queue\n";
        exit(0);
    }else {
        return arr[front];
    }
}
template<class T> void Queue<T>::display() {
    int n = size();
    for(int i=0; i<n; i++) {
        int index = (front+i)%MAX_SIZE;
        cout << arr[index] << " ";
    }
    cout << "\n";
}

int main() {
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.enqueue(50);
    q.enqueue(100);
    cout << "size : " << q.size() << '\n';
    cout << "front element : " << q.Front() << '\n';
    cout << "queue : "; 
    q.display();

    return 0;
}
