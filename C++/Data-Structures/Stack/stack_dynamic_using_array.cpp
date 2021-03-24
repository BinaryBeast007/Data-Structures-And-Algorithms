#include<iostream>
using namespace std;

class Stack {
    int top, *arr, stackSize;
public:
    Stack(int);
    ~Stack();
    void push(int);
    int pop();
    bool isEmpty();
    bool isFull();
    int peek();
    int size();
    int capacity();
    void resize(int);
    void display();
};
Stack::Stack(int size) {
    if(size < 1) {
        cout << "invalid size\n";
        return;
    }else {
        top = -1;
        stackSize = size;
        arr = new int[stackSize];
    }
}
Stack::~Stack() {
    delete[] arr;
}
void Stack::push(int x) {
    if(isFull()) {
        resize(stackSize*2);
    }
    arr[++top] = x;
}
int Stack::pop() {
    if(isEmpty()) {
        cout << "stack underflow\n";
        return 0;
    }else {
        return arr[top--];
    }
}
bool Stack::isEmpty() {
    return (top == -1);
}
bool Stack::isFull() {
    return (top == stackSize-1);
}
int Stack::peek() {
    if(isEmpty()) {
        cout << "stack is empty\n";
        return 0;
    }else {
        return arr[top];
    }
}
int Stack::size() {
    return (top+1);
}
int Stack::capacity() {
    return (stackSize);
}
void Stack::resize(int size) {
    if(size <= this->size()) {
        cout << "can't resize\n";
        return;
    }else {
        int *tempStack = new int[size];
        for(int i=0; i<this->size(); i++) {
            tempStack[i] = arr[i];
        }
        stackSize = size;
        delete[] arr;
        arr = tempStack;
    }
}
void Stack::display() {
    for(int i=top; i>=0; i--){
        cout << arr[i] << " ";
    }
    cout << '\n';
}

// Driver code
int main() {
    Stack st(2);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.pop();
    st.resize(100);
    st.display();
    cout << "total elements : " << st.size() << '\n';
    cout << "capacity : " << st.capacity() << '\n';
    cout << "top element : " << st.peek() << '\n';
    cout << "is empty : " << st.isEmpty() << '\n';
    cout << "is full : " << st.isFull() << '\n';

    return 0;
}
