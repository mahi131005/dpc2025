#include<iostream>
using namespace std;

int findTotalWater (int height[], int n){
	int leftMax = 0;
	int rightMax = 0;
	int total = 0;
	int l=0;
	int r=n-1;
	
	while (l<r) {
		if(height[l] <= height[r]){
			if(leftMax > height[l]){
				total += leftMax - height[l];
			}
			else {
				leftMax = height[l];
			}
			l++;
		}
		
		else {
			if(rightMax > height[r]){
				total += rightMax - height[r];
			}
			else {
				rightMax = height[r];
			}
			r--;
		}
	}
	
	return total;
}

int main() {
	int n;
	cout<<"Enter array size: ";
	cin>>n;
	int height[n];
	cout<<"Enter array elements: ";
	for(int i=0; i<n; i++){
		cin>>height[i];
	}
	
	cout<<"Total amount of water: "<<findTotalWater(height,n);
	return 0;
}
