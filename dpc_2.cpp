#include<iostream>
using namespace std;

int main() {
	int n;
	cout<<"Enter value of n for range (1 to n): ";
	cin>>n;
	
	int arr[n-1];
	long long sum = 0;
	
	for (int i = 0; i<n-1; i++) {
		cout<<"Enter element: ";
		cin>>arr[i];
		sum+=arr[i];
	}
	
	long long total = (long long)(n*(n+1))/2;
	cout<<"Input Array: ";
	for (int i = 0; i<n-1; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Missing Number: "<<total - sum<<endl;
}
