#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter array size:";
	cin>>n;
	int arr[n];
	cout<<"Enter array elements: ";
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Array: ";
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int max_right;
	max_right=arr[n-1];
	int leader[n];
	int l_count=0;
	leader[l_count++]=max_right;
	for(int i=n-2;i>=0;i--)
	{
		if (arr[i]>max_right)
		{
			max_right=arr[i];
			leader[l_count++]=max_right;
		}
	}
	cout<<"Leaders: ";
	for(int i=l_count-1;i>=0;i--)
	{
		cout<<leader[i]<<" ";
	}
	return 0;
}
