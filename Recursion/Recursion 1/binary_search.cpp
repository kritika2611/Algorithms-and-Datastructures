#include <bits/stdc++.h>

using namespace std;

int BinarySearch(int s,int e,int *arr,int key){
	int mid=(e+s)/2;
	//base case
	if(arr[mid]==key)
		return mid;
	else if(s>e)
		return -1;

	//recursive case
	if(arr[mid]>key)
		return BinarySearch(s,mid-1,arr,key);
	else if(arr[mid]<key)
		return BinarySearch(mid+1,e,arr,key);
}


int main(){
	int n,key;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	cin>>key;
	cout<<BinarySearch(0,n-1,arr,key);

	return 0;
}