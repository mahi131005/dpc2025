#include<iostream>
#include<map>
using namespace std;

int ElementRepeatedKTimes(int arr[],int size, int k) {
	map<int, int> freq;
	
	for (int i = 0; i<size; i++){
		freq[arr[i]]++;
	}
	
	for (int i = 0; i<size; i++){
		if (freq[arr[i]] == k){
			return arr[i];
		}
	}
	
	return -1;
	
}

int main() {
	int n,k;
	cout<<"Enter size: ";
	cin>>n;
	int arr[n];
	cout<<"Enter array elements: "; 
	for (int i = 0; i<n; i++){
		cin>>arr[i];
	}
	cout<<"Enter k: ";
	cin>>k;
	cout<<"Output: "<<ElementRepeatedKTimes(arr,n,k)<<endl;
	
	
	return 0;
}
