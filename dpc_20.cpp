#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int> &st, int temp){
	if (st.empty() || st.top() >= temp){
		st.push(temp);
		return;
	}
	
	int val = st.top();
	st.pop();
	insert(st,temp);
	st.push(val);
	
	return;
}


void sortStack(stack<int> &st){
	if (st.size() == 1 || st.empty()){
		return;
	}
	
	int temp = st.top();
	st.pop();
	sortStack(st);
	insert(st, temp);
	
	return;
}

int main(){
	stack<int> st;
    int value;

    cout << "Enter values to push into the stack (end input with Ctrl+Z): ";
    while (cin >> value) {
        st.push(value);
    }
    
    sortStack(st);
    cout << "[";
	while (!st.empty()) {
	    cout << st.top();
	    st.pop();
	    if (!st.empty()) cout << " ";
	}
	cout << "]" << endl;
    return 0;
}
