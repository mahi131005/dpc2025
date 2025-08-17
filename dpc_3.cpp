#include<iostream>
using namespace std;

int main() {
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	int arr[n+1];
	for (int i = 0; i<=n; i++){
		cout<<"Enter element: ";
		cin>>arr[i];
	}
	
	int slow, fast;
	
	slow = arr[0];
	fast = arr[0];
	
	do {
		slow = arr[slow];
		fast = arr[arr[fast]];
	} while (slow!=fast);
	
	slow = arr[0];
	
	while (slow!=fast) {
		slow = arr[slow];
		fast = arr[fast];
	}
	
	cout<<"Input Array: ";
	for (int i = 0; i<=n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Duplicate Element: "<<slow<<endl;
	
	
	return 0;
}
