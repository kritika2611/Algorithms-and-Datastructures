#include <bits/stdc++.h>

using namespace std;

int find_l(int n, int arr[],int key){
    int l=0;
    int r=n-1;
    
    while(l<=r){
        int m=(l+r)/2;
        if(arr[m]==key)
            return m;
        //mid point lies on first part
        else if(arr[l]<=arr[m]){
            if(arr[l]<=key && key<=arr[m])
                r=m-1;
            else
                l=m+1;
        }
        //mid point lies on second part
        else if(arr[m]<=arr[r]){
            if(arr[m]<=key && key<=arr[r])
                l=m+1;
            else
                r=m-1;
        }
    }
    return -1;
}

int main()
{
    int arr[]={4,5,6,7,1,2,3};
    int n=sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    
    cout<<find_l(n,arr,key)<<endl;

    return 0;
}
