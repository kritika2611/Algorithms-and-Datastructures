#include <bits/stdc++.h>

using namespace std;

int main(){
	int arr[]={1,2,5,8,8,8,8,8,10,12,15,20};
    int n=sizeof(arr)/sizeof(int);

    int key;
    cin>>key;

    bool present=binary_search(arr,arr+n,key);
    
    int *lb=lower_bound(arr,arr+n,key);        //gives first bucket >= key
    int *ub=upper_bound(arr, arr+n, key);      //gives address of first bucket >key

    if(present){
    	int f=ub-lb;
    	cout<<"the element is present"<<endl;
    	cout<<"frequency of the element : "<<f;
    }
    else
    	cout<<"the element is absent";


	return 0;
}