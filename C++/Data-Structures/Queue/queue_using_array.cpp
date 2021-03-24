#include<iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
    int front, rear, arr[MAX_SIZE];
public:
    Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int);
    int dequeue();
    int size();
    void display();
    int Front();
};
Queue::Queue() {
    front = rear = -1;
}
bool Queue::isEmpty() {
    return (front == -1 && rear == -1);
}
bool Queue::isFull() {
    return (rear == MAX_SIZE-1);
}
void Queue::enqueue(int x) {
    if(isFull()) {
        cout << "queue is full\n";
        return;
    }else if(isEmpty()) {
        front = rear = 0;
    }else {
        rear++;
    }
    arr[rear] = x;
}
int Queue::dequeue() {
    if(isEmpty()) {
        cout << "queue is empty\n";
        return 0;
    }else if(front == rear) {
        int x = arr[front];
        front = rear = -1;
        return x;
    }else {
        return arr[front++];
    }
}
int Queue::size() {
    return (rear-front+1);
}
int Queue::Front() {
    if(isEmpty()) {
        cout << "queue is empty\n";
        return 0;
    }else {
        return arr[front];
    }
}
void Queue::display() {
    for(int i=front; i<=rear; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    Queue q;
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
