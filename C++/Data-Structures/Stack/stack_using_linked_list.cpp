#include<iostream>
using namespace std;

template<class T> class Node {
public:
    T data;
    Node* next;
};
template<class T> class Stack {
    Node<T>* top;
public:
    Stack();
    void push(T);
    T pop();
    bool isEmpty();
    T peek();
    int size();
    void display();
};

template<class T> Stack<T>::Stack() {
    top = NULL;
}
template<class T> bool Stack<T>::isEmpty() {
    return (top == NULL);
}
template<class T> void Stack<T>::push(T data) {
    Node<T>* newNode = new Node<T>();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}
template<class T> T Stack<T>::pop() {
    if(top == NULL) {
        cout << "error : can not pop from empty stack\n";
        exit(0);
    }
    Node<T>* temp = top;
    T data = temp->data;
    top = temp->next;
    delete temp;
    return data;
}
template<class T> void Stack<T>::display() {
    Node<T>* temp = top;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
template<class T> int Stack<T>::size() {
    int stackSize = 0;
    Node<T>* temp = top;
    while(temp != NULL) {
        stackSize++;
        temp = temp->next;
    }
    return stackSize;
}
template<class T> T Stack<T>::peek() {
    if(top == NULL) {
        cout << "error : can't peek from empty stack\n";
        exit(0);
    }else {
        return top->data;
    }
}

int main() {
    Stack<double> st;
    st.push(10);
    st.push(20);
    st.push(9);
    st.pop();
    st.pop();
    st.display();
    cout << "top element : " << st.peek() << "\n";
    cout << "size : " << st.size() << "\n";
    cout << "is empty : " << st.isEmpty() << "\n";

    return 0;
}
