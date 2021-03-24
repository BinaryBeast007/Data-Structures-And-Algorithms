#include<iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
    int top, arr[MAX_SIZE];
public:
    Stack();
    ~Stack();
    void push(int);
    int pop();
    bool isEmpty();
    bool isFull();
    int peek();
    int size();
    void display();
};

Stack::Stack() {
    // initializing top as -1
    // stack is currently empty
    top = -1;
}
Stack::~Stack() {}
void Stack::push(int data) {
    // checking if stack is full or not
    if(isFull()) {
        cout << "error : stack overflow\n";
    }else {
        // if stack is not full, increment top & insert data at top index
        arr[++top] = data;
    }
}
int Stack::pop() {
    // checking if stack is empty or not
    if(isEmpty()) {
        cout << "error : stack underflow\n";
        return 0;
    }else {
        // if stack is not empty, return top value & decrement top
        return arr[top--];
    }
}
bool Stack::isEmpty() {
    // if top == -1, stack is empty, return true else return false
    return (top == -1);
}
bool Stack::isFull() {
    // if top == MAX_SIZE-1, stack is full, return true else return false
    return (top == MAX_SIZE-1);
}
int Stack::peek() {
    // checking if stack is empty
    if(isEmpty()) {
        cout << "stack is empty\n";
        return 0;
    }else {
        // if stack is not empty, return top value
        return arr[top];
    }
}
int Stack::size() {
    // stack size is top+1
    return (top+1);
}
void Stack::display() {
    // starting from top & decrementing till 0 & printing the values 
    for(int i=top; i>=0; i--){
        cout << arr[i] << " ";
    }
    cout << '\n';
}

// Driver code
int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.pop();
    st.display();
    cout << "total elements : " << st.size() << '\n';
    cout << "top element : " << st.peek() << '\n';
    st.isEmpty() ? puts("stack is empty") : puts("stack is not empty");
    st.isFull() ? puts("stack is full") : puts("stack is not full");

    return 0;
}
