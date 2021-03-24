#include<iostream>
#include"stack_generic_using_array.h"
using namespace std;

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
    cout << "capacity : " << st.capacity() << '\n';
    cout << "top element : " << st.peek() << '\n';
    cout << "is empty : " << st.isEmpty() << '\n';
    cout << "is full : " << st.isFull() << '\n';

    return 0;
}
