#include<bits/stdc++.h>
using namespace std;

bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch== '^');
}
double performOperation(int operand1, int operand2, char operation) {
    double result;
    switch(operation) {
        case '+': result = operand1 + operand2; break; 
        case '-': result = operand1 - operand2; break; 
        case '*': result = operand1 * operand2; break; 
        case '/': result = operand1 / (double) operand2; break; 
        case '^': result = pow(operand1, operand2); break; 
    }
    return result;
}
double postfixEvaluation(string exp) {
    stack<double> st;
    for(int i=0; i<exp.length(); i++) {
        if(isDigit(exp[i])) {
            st.push(exp[i] - '0');
        }else if(isOperator(exp[i])) {
            int op2 = st.top(); 
            st.pop();
            int op1 = st.top();
            st.pop();
            st.push(performOperation(op1, op2, exp[i]));
        }
    }
    return st.top();
}

int main() {
    string expression = "6 9 + 4 2 ^ +";
    cout << "expression : " << expression << "\n";
    cout << "result : " << postfixEvaluation(expression) << "\n";

    return 0;
}
