#include<iostream>
#include<string>
#include<map>
using namespace std;

int substringLength (const string& s) {
	int n=s.size();
	map<char, int> hash;
	for (int i = 0; i<256; i++){
		hash[i]=-1;
	}
	
	int l = 0, r = 0, maxlen = 0;
	
	while(r<n){
		if (hash[s[r]]!=-1){
			if(hash[s[r]]>=l){
				l=hash[s[r]]+1;
			}
		}
		
		int len = r - l + 1;
		maxlen = max(len, maxlen);
		
		hash[s[r]] = r;
		r++;
	}
	
	return maxlen;
}

int main() {
	string inputStr;
	cout<<"Enter string: ";
	getline (cin, inputStr);
	cout<<substringLength(inputStr);
}
