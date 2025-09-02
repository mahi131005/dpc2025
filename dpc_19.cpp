#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int applyOperator(int a, int b, const string& op) {
    if(op == "+") 
		return a + b;
    if(op == "-") 
		return a - b;
    if(op == "*") 
		return a * b;
    if(op == "/") 
		return a / b; 
		
	
    return 0;
}

int EvalPostfixExp(const string& expr) {
    stack<int> st;
    stringstream ss(expr);
    string token;

    while(ss >> token) {
        if(isOperator(token)) {
            int right = st.top(); st.pop();
            int left = st.top(); st.pop();
            st.push(applyOperator(left, right, token));
        } else {
            stringstream convert(token);
            int num;
            convert >> num;
            st.push(num);
        }
    }

    return st.top();
}

int main() {
    string str;
    cout<<"Enter postfix expression (space separated): ";
    getline(cin, str);
    cout << EvalPostfixExp(str) << endl;
    return 0;
}
