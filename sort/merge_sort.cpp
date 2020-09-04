#include <bits/stdc++.h>

using namespace std;

void merge(int *arr,int s,int e){
	int mid=(s+e)>>1;
	int temp[100]={0};
	int i=s;
	int j=mid+1;
	int k=s;

	while(i<=mid && j<=e){
		if(arr[i]<arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}

	while(i<=mid)
		temp[k++]=arr[i++];
	
	while(j<=e)
		temp[k++]=arr[j++];

	//copying temp to the actual array
	for(int p=s;p<=e;p++){
		arr[p]=temp[p];
	}

}

void merge_sort(int *arr,int s,int e){
	//base case
	if(s>=e)
		return;
	//recursive case
	//1.divide
	int mid=(s+e)>>1;

	//2. sort
	merge_sort(arr,s,mid);
	merge_sort(arr,mid+1,e);

	//3.merge
	merge(arr,s,e);


}

int main(){
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	merge_sort(arr,0,n-1);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	return 0;
}