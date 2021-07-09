#include<iostream>
#include"stack.h"
using namespace std;

class Queue {
    Stack<int> s1, s2;
public:
    void enqueue(int);
    void dequeue();
    bool isEmpty();
    bool isFull();
    int Front();
    void display();
};
// enqueue data to the queue
void Queue::enqueue(int data) {
    if(isFull()) {
        cout << "error : queue is full\n";
        return;
    }
    // pushing data to the first stack
    s1.push(data);
}
// dequeue data from queue
void Queue::dequeue() {
    if(isEmpty()) {
        cout << "error : queue is empty\n";
        return;
    }
    if(s2.isEmpty()) {
        while(!s1.isEmpty()) {
            s2.push(s1.Top());
            s1.pop();
        }
    }
    // pop data from 2nd stack
    // dequeueing data
    s2.pop();
}
bool Queue::isEmpty() {
    // if both stacks are empty then queue is empty
    return (s1.isEmpty() && s2.isEmpty());
}
bool Queue::isFull() {
    return s1.isFull();
}
int Queue::Front() {
    if(isEmpty()) {
        cout << "error : queue is empty\n";
        return 0;
    }if(!s2.isEmpty()) {
        return s2.Top();
    }else {
        while(!s1.isEmpty()) {
            s2.push(s1.Top());
            s1.pop();
        }
        return s2.Top();
    }
}
void Queue::display() {
    while(!s1.isEmpty()) {
        s2.push(s1.Top());
        s1.pop();
    }
    while(!s2.isEmpty()) {
        cout << s2.Top() << " ";
        s2.pop();
    }
}

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    cout << "Front element : " << q.Front() << "\n";
    q.display();

    return 0;
}
