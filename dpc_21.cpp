#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int element) {
    if (st.empty()) {
        st.push(element);
        return;
    }
    int topElement = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(topElement);
}

void reverseStack(stack<int> &st) {
    if (st.empty()) {
        return;
    }
    int topElement = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topElement);
}

void printStack(stack<int> st) {
    if (st.empty()) {
        cout << "[]";
        return;
    }
    cout << "[";
    while (!st.empty()) {
        cout << st.top();
        st.pop();
        if (!st.empty()) cout << " ";
    }
    cout << "]";
}

int main() {
    stack<int> st;
    int value;

    cout << "Enter values to push into the stack (end input with Ctrl+Z): ";
    while (cin >> value) {
        st.push(value);
    }
    
    cout<<"Original Stack (top - bottom): ";
    printStack(st);
    cout<<endl;
    reverseStack(st);
    cout<<endl;
    cout<<"Reversed Stack (top - bottom): ";
    printStack(st);
    return 0;
}
