#include <bits/stdc++.h>

using namespace std;

void print(int a[10]){
	for(int i=0;i<=9;i++){
		cout<<a[i]<<" ,";
	}
	cout<<endl;
}

void rev_print(int x[10]){

	for(int i=0; i<=9;i++){
		cout<<x[9-i]<<" ,";
	}
	cout<<endl;
}

int main(){
	int arr[10];

	//input in array
	for(int i=0;i<=9;i++){
		cin>>arr[i];
	}
	cout<<sizeof(arr)/sizeof(int)<<endl;
	print(arr);
	//update 
	for(int i=0;i<=9;i++){
		arr[i]=arr[i]*arr[i];
	}
	print(arr);
	rev_print(arr);
	return 0;

}