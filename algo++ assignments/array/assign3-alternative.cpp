#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,target;
    cin>>n;
    int *arr=new int[n];
    //taking input
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>target;
    //sorting array
    sort(arr,arr+n);
    int l=0;
    int r=n-1;
    while(l<r){
        if(arr[l]+arr[r]==target){
            cout<<arr[l]<<" and "<<arr[r]<<endl;
            l++;
            r--;
        }
        else if(arr[l]+arr[r]<target)
            l++;
        else
            r--;
    }
    return 0;
}