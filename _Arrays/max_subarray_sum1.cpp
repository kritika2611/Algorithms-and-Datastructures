#include <bits/stdc++.h>

using namespace std;

void print_subarr(int i, int j, int arr[]){
	//printing the output
	for(int k=i;k<=j;k++){
		cout<<arr[k]<<" ";
	}
	cout<<endl;
}

int main(){
	int n;
	int arr[n];
	int current_sum=0;
	int max_sum=0;
	int left=-1;
	int right=-1;
	cout<<"enter the size of the array: "<<endl;
	cin>>n;
	cout<<"enter the array: ";
	//input
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			current_sum=0;
			for (int k=i;k<=j;k++){
				current_sum+=arr[k];
			}
			if (current_sum>max_sum){
				max_sum=current_sum;
				left=i;
				right=j;
			}
		}
	}
	cout<<"the max sum of the subarr is: "<<max_sum<<endl;
	print_subarr(left,right,arr);

	return 0;
}