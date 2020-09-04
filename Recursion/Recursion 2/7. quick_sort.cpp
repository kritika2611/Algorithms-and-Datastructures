#include <bits/stdc++.h>

using namespace std;

int partition(int s,int e,int *arr){
	int i=s-1;
	int j=s;
	int pivot=arr[e];
	while(j<e){
		if(arr[j]<=pivot){
			i+=1;
			swap(arr[i],arr[j]);
			j++;
		}
		else if(arr[j]>pivot)
			j++;
	}
	swap(arr[e],arr[i+1]);
	return i+1;
}

void quick_sort(int s,int e,int *arr){
	//base case
	if(s>=e)
		return;

	//recursive case
	int p=partition(s,e,arr);
	quick_sort(s,p-1,arr);
	quick_sort(p+1,e,arr);
	return;

}

int main(){
	int n;
	cin>>n;

	int *arr=new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	quick_sort(0,n-1,arr);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}