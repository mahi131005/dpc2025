#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void primeFactors (int n) {
	vector<int> factors;
	for (int i = 2; i * i <=n; i++){
		while (isPrime(i) && n%i == 0){
			factors.push_back(i);
			n=n/i;
		}
	}
	if (n>1){
		factors.push_back(n);
	}
	cout<<"[ ";
	for (int j = 0; j < factors.size(); j++){
		cout<<factors[j]<<" ";
	}
	cout<<"]";
}

int main(){
	int n;
	cout<<"Enter number: ";
	cin>>n;
	primeFactors(n);
	return 0;
}
