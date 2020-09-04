#include <bits/stdc++.h>

using namespace std;

void bubble_sort1(int *arr,int n){
	//base case
	if(n==1 || n==0){
		return;
	}

	//recursive case
	for(int i=0;i<n-1;i++){
		if(arr[i+1]<arr[i])
			swap(arr[i+1],arr[i]);
	}
	bubble_sort1(arr,n-1);
}

void bubble_sort2(int *arr,int n,int i){
	//base case
	if(n==1 || n==0){
		return;
	}

	//recursive case
	if(i>=n-1){
		bubble_sort2(arr,n-1,0);
		return;
	}


	else if(arr[i]>arr[i+1]){
		swap(arr[i],arr[i+1]);
	}
	bubble_sort2(arr,n,i+1);
	
}

int main(){
	int n;
	cin>>n;

	int *arr=new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	bubble_sort2(arr,n,0);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	return 0;
}