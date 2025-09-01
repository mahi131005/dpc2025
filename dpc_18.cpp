#include<iostream>
#include<cmath>
using namespace std;

int DivisorLength(int n) {
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i == n / i) {
                count += 1; 
            } else {
                count += 2; 
            }
        }
    }
    return count;
}

int main(){
	int n;
	cout<<"Enter n: ";
	cin>>n;
	cout<<DivisorLength(n);
	
	return 0;
}
