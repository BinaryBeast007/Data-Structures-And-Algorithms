#include<iostream>
using namespace std;

#define MAX_SIZE 100

template<class T> class Stack {
    int top, capacity;
    T *arr;
public:
    Stack();
    Stack(int);
    ~Stack();
    void push(int);
    int pop();
    bool isEmpty();
    bool isFull();
    int Top();
    int size();
    int Capacity();
    void resize(int);
    void display();
};

template<class T> Stack<T>::Stack() {
    // initializing top as -1
    // stack is currently empty
    top = -1;
    this->capacity = MAX_SIZE;
    arr = new T[this->capacity];
}
template<class T> Stack<T>::Stack(int size) {
    if(size < 1) {
        cout << "error : invalid size\n";
        return;
    }
    top = -1;
    this->capacity = size;
    arr = new T[this->capacity];
}
template<class T> Stack<T>::~Stack() {
    delete arr;
}
template<class T> void Stack<T>::push(int data) {
    // checking if stack is full or not
    if(isFull()) {
        resize(this->capacity*2); // if full resize with twice size of current capacity
    }
    // increment top & insert data at top index
    arr[++top] = data;
}
template<class T> int Stack<T>::pop() {
    // checking if stack is empty or not
    if(isEmpty()) {
        cout << "error : stack underflow\n";
        return 0;
    }else {
        // if stack is not empty, return top value & decrement top
        return arr[top--];
    }
}
template<class T> bool Stack<T>::isEmpty() {
    // if top == -1, stack is empty, return true else return false
    return (top == -1);
}
template<class T> bool Stack<T>::isFull() {
    // if top == MAX_SIZE-1, stack is full, return true else return false
    return (top == MAX_SIZE-1);
}
template<class T> int Stack<T>::Top() {
    // checking if stack is empty
    if(isEmpty()) {
        cout << "stack is empty\n";
        return 0;
    }else {
        // if stack is not empty, return top value
        return arr[top];
    }
}
template<class T> int Stack<T>::size() {
    // stack size is top+1
    return (top+1);
}
template<class T> int Stack<T>::Capacity() {
    return this->capacity;
}
template<class T> void Stack<T>::resize(int newSize) {
    // validating size
    if(newSize <= this->size()) {
        cout << "error : can't resize\n";
        return;
    }
    // temporary array with newSize
    T *tempStack = new T[newSize];
    for(int i=0; i<this->size(); i++) {
        tempStack[i] = arr[i]; // coping all data to temporary array
    }
    this->capacity = newSize; 
    delete[] arr; // deleting old array
    arr = tempStack; // assigning new array to old one
}
template<class T> void Stack<T>::display() {
    // starting from top & decrementing till 0 & printing the values 
    for(int i=top; i>=0; i--){
        cout << arr[i] << " ";
    }
    cout << '\n';
}
// Driver code
int main() {
    Stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.pop();
    st.resize(10);
    st.display();
    cout << "total elements : " << st.size() << '\n';
    cout << "capacity : " << st.Capacity() << '\n';
    cout << "top element : " << st.Top() << '\n';
    st.isEmpty() ? puts("stack is empty") : puts("stack is not empty");
    st.isFull() ? puts("stack is full") : puts("stack is not full");

    return 0;
}
