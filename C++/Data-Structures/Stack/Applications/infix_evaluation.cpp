#include <bits/stdc++.h>
using namespace std;

int precedence(char op){
	if(op == '+'||op == '-')
	    return 1;
	if(op == '*'||op == '/')
	    return 2;
	return 0;
}
double calculate(double a, double b, char op){
	switch(op){
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / (double)b;
        default: return 1;
	}
}
double evaluate(string exp){
	stack <double> values;
	stack <char> operators;
    int n = exp.length();
	for(int i = 0; i < n; i++){
		if(exp[i] == ' ' || exp[i] == '=') {
			continue;
        }else if(exp[i] == '(') {
			operators.push(exp[i]);
		}else if(isdigit(exp[i])) {
			double val = 0;
            string tmp = "";
			while(i < n) {
                if(isdigit(exp[i]) || exp[i] == '.') {
                    tmp += exp[i];
                }else {
                    break;
                }
				i++;
			}
            val = stod(tmp);
			values.push(val);
			i--;
		}else if(exp[i] == ')') {
			while(!operators.empty() && operators.top() != '(') {
				double val2 = values.top();
				values.pop();
				double val1 = values.top();
				values.pop();
				char op = operators.top();
				operators.pop();
				values.push(calculate(val1, val2, op));
			}
			if(!operators.empty()) {
			    operators.pop();
            }
		}else {
			while(!operators.empty() && precedence(operators.top()) >= precedence(exp[i])){
				double val2 = values.top();
				values.pop();
				double val1 = values.top();
				values.pop();
				char op = operators.top();
				operators.pop();
				values.push(calculate(val1, val2, op));
			}
			operators.push(exp[i]);
		}
	}
	while(!operators.empty()){
		double val2 = values.top();
		values.pop();
		double val1 = values.top();
		values.pop();
		char op = operators.top();
		operators.pop();
		values.push(calculate(val1, val2, op));
	}

	return values.top();
}

int main() {
    cout << "Enter an expression : ";
    string exp;
    getline(cin, exp);
	cout << fixed << setprecision(2) << evaluate(exp) << "\n";
	
	return 0;
}
