#include<bits/stdc++.h>
using namespace std;

int binary_search(int n, int *arr,int key){
	int start,end,mid;
	bool flag=true;
	start=0;
	end=n-1;
	while(start<=end){
		mid=(start+end)/2;
		if (arr[mid]==key){
			cout<<mid<<endl;
			return mid;
		}
		else if(arr[mid]<key)
			start=mid+1;
		else
			end=mid-1;
	}
	return -1;
}

int main(){
	int n,key;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>key;
	cout<<binary_search(n,arr,key)<<endl;;
	return 0;
}