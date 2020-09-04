#include <bits/stdc++.h>

using namespace std;

int lower_b(int n, int arr[],int key){
	int idx=-1;
	int left=0;
	int right=n-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(arr[mid]<key)
			left=mid+1;
		else{
			right=mid-1;
			if(idx==-1 || arr[idx]>=arr[mid])
				idx=mid;
		}
	}
	return idx;
}

int main()
{
    int arr[]={1,2,5,8,8,8,8,8,10,12,15,20};
    int n=sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    
    cout<<lower_b(n,arr,key)<<endl;

    return 0;
}
