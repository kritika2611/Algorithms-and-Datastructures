/***********************************************  INVERSION COUNT  ************************************************************************
Given an array, find the number of pairs with indexes (i,j) 
such that arr[i]>arr[j], and i<j

E.g-
arr=[1,5,2,6,3,0]
number of inverted pairs=8

INPUT
number of elementsin array i.e n
array

OUTPUT
total number of inverted pairs
****************************************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int cross_inversions(int s,int e,int *arr){
	int mid=(s+e)>>1;
	//two pointer approach
	int temp[10000]={0};
	int i=s, j=mid+1;
	int k=0;
	int count=0;

	while(i<=mid && j<=e){
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else{
			//inversion
			count+=mid-i+1;
			temp[k++]=arr[j++];
		}
	}

	while(i<=mid)
		temp[k++]=arr[i++];
	while(j<=e)
		temp[k++]=arr[j++];

	for(int i=s;i<=e;i++){
		arr[i]=temp[i-s];
	}

	return count;
}

int inversion_counts(int s,int e,int *arr){
	//base case
	if(s>=e)
		return 0;

	//recursive case
	int mid=(s+e)>>1;
	int a=inversion_counts(s,mid,arr);
	int b=inversion_counts(mid+1,e,arr);
	int c=cross_inversions(s,e,arr);
	
	return a+b+c;	
}

int main(){
	int n;
	cin>>n;
	int *arr=new int[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout<<inversion_counts(0,n-1,arr)<<endl;

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}