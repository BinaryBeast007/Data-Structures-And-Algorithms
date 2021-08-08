#include<iostream>
using namespace std;

#define MAX_SIZE 1000

class Stack {
    int top;
    char arr[MAX_SIZE];
public:
    Stack();
    void push(char);
    void pop();
    char Top();
    bool isEmpty();
    bool isFull();
};

Stack::Stack() {
    // initializing top as -1
    // stack is currently empty
    top = -1;
}
void Stack::push(char data) {
    // checking if stack is full or not
    if(isFull()) {
        cout << "error : stack overflow\n";
    }else {
        // if stack is not full, increment top & insert data at top index
        arr[++top] = data;
    }
}
void Stack::pop() {
    // checking if stack is empty or not
    if(isEmpty()) {
        cout << "error : stack underflow\n";
    }else {
        // if stack is not empty, decrement top
        top--;
    }
}
char Stack::Top() {
    // checking if stack is empty
    if(isEmpty()) {
        cout << "stack is empty\n";
        return '\0';
    }else {
        // if stack is not empty, return top value
        return arr[top];
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

bool areParenthesesBalanced(string exp) {
    Stack stk;
    for(int i=0; i<exp.length(); i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            stk.push(exp[i]);
            continue;
        }
        if(stk.isEmpty()) {
            return false;
        }
        switch (exp[i]) {
        case ')':
            if(stk.Top() != '(') {
                return false;
            }else {
                stk.pop();
            }
            break;
 
        case '}':
            if(stk.Top() != '{') {
                return false;
            }else {
                stk.pop();
            }
            break;
 
        case ']':
            if(stk.Top() != '[') {
                return false;
            }else {
                stk.pop();
            }
            break;
        }
    }
    return stk.isEmpty();
}

// Driver code
int main() {
    string exp = "()(())";
    if(areParenthesesBalanced(exp)) {
        cout << "Parentheses are balanced\n";
    }else {
        cout << "Parentheses are not balanced\n";
    }

    return 0;
}
