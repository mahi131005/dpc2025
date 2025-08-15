#include<iostream>
using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int arr[] = {0,1,2,1,0,2,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	int low = 0;
	int mid = 0;
	int high = n-1;
	cout<<"Input Array: ";
	for(int i = 0; i<n; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	while(mid<=high) {
		if (arr[mid] == 0){
			swap(arr[low],arr[mid]);
			low++;
			mid++;
		}
		
		else if (arr[mid] == 1) {
			mid++;
		}
		
		else {
			swap(arr[mid], arr[high]);
			high--;
		}
	}
	cout<<"Output Array: ";
	for(int i = 0; i<n; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
