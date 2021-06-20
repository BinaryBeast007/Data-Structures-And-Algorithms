#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch== '^');
} 
bool isOperand(char ch) {
	return ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}
int precedence(char ch) {
    int prec = 0;
    switch(ch) {
        case '+':
        case '-':
            prec = 1;
            break;
        case '*':
        case '/':
            prec = 2;
            break;
        case '^':
            prec = 3;
            break;
        default:
            prec = -1;
            break;
    }
    return prec;
}
string infixToPostfix(string exp) {
    string postfix = "";
    stack<int> st;
    for(int i=0; i<exp.length(); i++) {
        if(isOperand(exp[i])) {
            postfix += exp[i];
        }else if(isOperator(exp[i])) {
            while(!st.empty() && precedence(exp[i]) <= precedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
    }
    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main() {
    string infix = "A+B*C-E/F*G+H";
    string posfix = infixToPostfix(infix);

    cout << "infix\t: " << infix << "\n";
    cout << "postfix\t: " << posfix << "\n";

    return 0;
}
