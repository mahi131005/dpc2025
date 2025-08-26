#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValid (string str) {
	stack<char> st;
	
	for (int i = 0; i<str.length(); i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '['){
			st.push(str[i]);
		}
		
		else {
			if (st.size() == 0) {
				return false;
			}
			
			if ((st.top() == '(' && str[i] == ')')||
				(st.top() == '{' && str[i] == '}') ||
				(st.top() == '[' && str[i] == ']')
			) {
				st.pop();
			}
			
			else {
				return false;
			}	
		}
	}
	
	return st.size() == 0;
}

int main () {
	string s;
	cout<<"Enter input: ";
	getline(cin, s);
	
	bool result = isValid(s);
	
	if (result){
		cout<<"true";
	}
	else {
		cout<<"false";
	}
	
	return 0;
}
