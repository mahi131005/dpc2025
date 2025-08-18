#include<iostream>
#include<cmath>
using namespace std;

void swapIfGreater (int arr1[], int arr2[], int i, int j){
	if (arr1[i] > arr2[j]) {
		swap(arr1[i],arr2[j]);
	}
}

void merge (int arr1[], int arr2[], int n, int m){
	int len = n + m;
	int gap = (len/2) + (len%2);
	
	while(gap > 0) {
		int left = 0;
		int right = left + gap;
		
		while (right < len){
			if (left < n && right >= n){
				swapIfGreater (arr1, arr2, left, right - n);
			}
			
			else if (left >= n){
				swapIfGreater (arr2, arr2, left - n, right - n);
			}
			
			else {
				swapIfGreater (arr1, arr1, left, right);
			}
			
			left++, right++;
		}
		
		if (gap == 1){
			break;
		}
		
		gap = (gap/2) + (gap%2);
	}
}

int main() {
	int n1, n2;
	cout<<"Enter size of arr1: ";
	cin>>n1;
	cout<<"Enter size of arr2: ";
	cin>>n2;
	int arr1[n1], arr2[n2];
	
	cout<<"Enter elements for arr1: ";
	for(int i = 0; i<n1; i++) {
		cin>>arr1[i];
	}
	
	cout<<"Enter elements for arr2: ";
	for(int i = 0; i<n2; i++) {
		cin>>arr2[i];
	}
	
	merge(arr1, arr2, n1, n2);
	
	cout<<"Arr1: ";
	for(int i = 0; i<n1; i++) {
		cout<<arr1[i]<<" ";
	}
	cout<<"\nArr2: ";
	for(int i = 0; i<n2; i++) {
		cout<<arr2[i]<<" ";
	}
	
	return 0;
}
