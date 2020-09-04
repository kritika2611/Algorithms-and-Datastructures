#include <bits/stdc++.h>

using namespace std;

bool isSorted(int n,int *arr){
    //base case
    if(n==0 || n==1)
        return true;
    
    bool cond1=arr[0]<arr[1];
    bool cond2=isSorted(n-1,arr+1);
    if(cond1 && cond2){
        return true;
    }
    return false;
}

int main()
{
    int arr[]={1,2,5,7,9};
    int n=sizeof(arr)/sizeof(int);
    
    cout<<isSorted(n,arr);
    return 0;
}
